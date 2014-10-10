#include "stdafx.h"
#include "CharToIntParser.h"

CharToIntParser::CharToIntParser() {}

int* CharToIntParser::parse(std::string stringToParse) {
	if(stringToParse.size() < 1) {
		throw new std::exception("String too short!");
	}
	int *tab = new int[stringToParse.size()];
	for(int i = 0; i < stringToParse.size(); i++) {
		tab[i] = stringToParse[i] - 'A';
	}
	return tab;
}
