#pragma once
#ifndef RESULT_H
#define RESULT_H

/**
*	An abstract struct that can be extended to hold data retrieved by a CrawlerLeg
*/
class Result {
public:
	Result(){}
	virtual ~Result(){};		
};
#endif	//	RESULT_H
