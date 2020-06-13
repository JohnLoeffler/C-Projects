#pragma once
#ifndef CRAWLERLEG_H
#define CRAWLERLEG_H

namespace JLutils {

	class Action;
	class Result;
	class Crawler;

	template <typename T>
	class CrawlerLeg {
		Action*				Process;
		Result*				EndResult;
		const Crawler&		CrawlerBody;
	protected:
		
	public:
		/** Constructor */
		CrawlerLeg(Action* action, const Crawler& crawler) = 0;
		/** Destructor */
		virtual ~CrawlerLeg() = 0;	

		virtual int ProcessNode(T* node) = 0;
	};
}
#endif	//	CRAWLERLEG_H
