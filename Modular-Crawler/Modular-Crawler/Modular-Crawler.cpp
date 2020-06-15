
#include "TestCrawler.h"

// TODO Create the TestCrawler object.

int main(){
	const char* start = new const char[11]{"start-node"};
	TestCrawler<const char*> crawler(&start, 10, nullptr, -1);

	crawler.AddToVisit(nullptr);
	crawler.AddVisited(nullptr);
	crawler.ManageNode(nullptr);
	crawler.SpawnLeg();
	crawler.Report(nullptr);
	crawler.BeginCrawl();
}