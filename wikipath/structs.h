#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <unordered_set>
#include <mutex>
#include <queue>

struct wikiLink {
	std::string prevUrl;
	std::string url;
	int depth;

	wikiLink(std::string prevUrl, std::string url, int depth) :
	prevUrl{prevUrl},
	url{url},
	depth{depth} {}

	bool operator<(wikiLink a) {
		return this->url < a.url;
	}

	struct wikiLinkGreater {
		bool operator()(wikiLink const& a, wikiLink const& b) const {
			return a.url > b.url;
		}
	};
};

struct wikiData {
	long numBytesParsed;
	std::unordered_set<std::string> processedURLs;
	std::priority_queue<wikiLink, std::vector<wikiLink>, wikiLink::wikiLinkGreater> unprocessedLinks;
	std::mutex bytesMutex;
	std::mutex processedMutex;
	std::mutex queueMutex;
};

#endif // !STRUCTS_H
