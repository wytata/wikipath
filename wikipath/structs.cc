#include "structs.h"

bool operator<(wikiLink a, wikiLink b) {
	return a.url < b.url;
}
