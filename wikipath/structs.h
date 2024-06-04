#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

struct wikiLink {
	wikiLink* prevWikiLink;
	std::string url;
	int depth;
};

bool operator<(wikiLink a, wikiLink b);

#endif // !STRUCTS_H
