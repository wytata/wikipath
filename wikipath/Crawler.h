#ifndef CRAWLER_H
#define CRAWLER_H

#include <queue>
#include "structs.h"

using std::queue;

class Crawler {
	private:
		int uniqueURLs;	
		int numBytesParsed;
		std::priority_queue<wikiLink, std::vector<wikiLink>> unprocessedURLs;
		
	public:
		void run();
		void statsRun();
};

#endif // !CRAWLER_H
