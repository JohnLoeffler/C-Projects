#pragma once
#ifndef TESTCRAWLER_H
#define TESTCRAWLER_H

#include "Crawler.h"

template <typename T>
class TestCrawler : public Crawler<T> {
		
protected:
		
public:
	TestCrawler();
	TestCrawler(T* start, int leglimit, T* end = nullptr, int nodelimit = -1);
	virtual ~TestCrawler();
	
	virtual int			SpawnLeg();
	virtual int			ManageNode(T* node);
	virtual int			AddVisited(T* node);
	virtual int			AddToVisit(T* node);
	virtual bool		Report(Result* results);
	virtual int			BeginCrawl();
};
template<typename T>
TestCrawler<T>::TestCrawler() :Crawler<T>() {
	printf("In TestCrawler::default_constructor\n");
}
template<typename T>
TestCrawler<T>::TestCrawler(T* start, int leglimit, T* end, int nodelimit) : Crawler<T>(start, leglimit, end, nodelimit) {
	printf("In TestCrawler::constructor\n");
}
template<typename T>
TestCrawler<T>::~TestCrawler() {
	printf("In TestCrawler::destructor\n");
}
template<typename T>
int TestCrawler<T>::SpawnLeg() {
	printf("In TestCrawler::SpawnLeg\n");
	return 0;
}
template<typename T>
int TestCrawler<T>::ManageNode(T* node) {
	printf("In TestCrawler::ManageNode\n");
	return 0;
}
template<typename T>
int TestCrawler<T>::AddVisited(T* node) {
	printf("In TestCrawler::AddVisited\n");
	return 0;
}
template<typename T>
int TestCrawler<T>::AddToVisit(T* node) {
	printf("In TestCrawler::AddToVisit\n");
	return 0;
}
template<typename T>
bool TestCrawler<T>::Report(Result* results) {
	printf("In TestCrawler::Report\n");
	return false;
}

template<typename T>
int TestCrawler<T>::BeginCrawl() {
	printf("In TestCrawler::BeginCrawl\n");
	return 0;
}
#endif // CRAWLER_H