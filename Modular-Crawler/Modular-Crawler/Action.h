#pragma once
#ifndef ACTION_H
#define ACTION_H

class Result;

/**
*	An abstract interface that defines the active behavior of the Crawler
*	@tparam T T represents a node in a data structure or an http URL
*/
template <typename T>
class Action{	
public: 
	Action() {}
	virtual ~Action() {};
	virtual Result Execute(const T& node) = 0;
};

#endif	//	ACTION_H
