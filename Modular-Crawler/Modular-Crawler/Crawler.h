#pragma once
#ifndef CRAWLER_H
#define CRAWLER_H

#include <queue>
#include <vector>

class CrawlerLegs;
class Action;
class Result;

namespace JLutils {
	/**
	*	Abstract Crawler that can be extended to crawl data structures and data streams.
	*	@tparam T The type of node the Crawler is working with (i.e., a URL, a Node struct in a graph or tree)
	*/
	template <typename T>
	class Crawler {
		std::vector<CrawlerLegs*>	Legs;
		std::queue<T*>				VisitedNodes, NodesToVisit, NodesToSkip;
		T*							StartNode, *EndNode;
		int							NodeLimit, LegLimit;
	protected:		
		/** 
		*	Spawns a new CrawlerLeg 
		*	@return an int, either as data or as an error code 
		*/
		virtual int			SpawnLeg() = 0;
		/**
		*	Manages the addition and removal of a Node from the Crawler's node lists
		*	@return an int, either as data or as an error code 
		*/
		virtual int			ManageNode(T* node) = 0;
		/** 
		*	Adds a node to the 'Visited' list
		*	@return an int, either as data or as an error code 
		*/
		virtual int			AddVisited(T* node) = 0;
		/** 
		*	Adds a node to the 'Nodes to Visit' list
		*	@return an int, either as data or as an error code 
		*/
		virtual int			AddToVisit(T* node) = 0;
		/** 
		*	Checks whether the Crawler has reached the set limit for number of nodes it is allowed to crawl
		*	@return true if the limit has been reached, false otherwise or if the limit is set to -1, which means there is no limit set
		*/
		virtual inline bool	HasReachedNodeLimit() { return NodeLimit == -1 ? false: (VisitedNodes.size() + NodesToVisit.size()) == NodeLimit };
		/**
		*	Checks whether the Crawler has reached the set limit for number of legs it is allowed to spawn
		*	@return true if the limit has been reached, false otherwise or if the limit is set to -1, which means there is no limit set
		*/
		virtual inline bool	HasReachedLegLimit() { return (LegLimit == -1 ? false: (Legs.size() == LegLimit)) };
		/**
		*	Used by the CrawlerLegs to notify the Crawler that the leg's node has been processed and allows for returning data collected by the CrawlerLeg
		*	@param result A container or wrapper for passing the results of the CrawlerLeg's work to the Crawler
		*	@return bool Returns true to the calling CrawlerLeg to indicate whether the Result object it passed to the Crawler has been successfully received. False otherwise.
		*/
		virtual bool		Report(Result* results) = 0;
	public:
		/** 
		*	Constructor 
		*	@param start The node where the Crawler will begin its crawl
		*	@param leglimit The maximum number of legs the Crawler is allowed to operate at one time. Since CrawlerLegs utilize threads, you must set a maximum to prevent overproduction of threads  
		*	@param end An optional node that can be used as a terminal for the crawler. If "nullptr" passed or left blank, the Crawler will not consider a node as a possible stopping condition.
		*	@param nodelimit The maximum number of nodes allowable for the Crawler to process. Default value -1 signals that there is no limit and Crawler will run until it has no more nodes in its queue
		*/
		Crawler( T* start, int leglimit, T* end = nullptr, int nodelimit = -1) = 0;
		/**
		*	Destructor
		*/
		virtual ~Crawler() = 0;
		/**
		*	Begin crawling from the starting node
		*	@return an int, either as data or as an error code 
		*/
		virtual int BeginCrawl() = 0;
		
	};
}

#endif // CRAWLER_H