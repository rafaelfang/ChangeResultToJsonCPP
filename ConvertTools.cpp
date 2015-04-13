/*
 * ConvertTools.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#include "ConvertTools.h"

ConvertTools::ConvertTools(char* theInputFilename,
		char* theOutputJsonFilename) {
	// TODO Auto-generated constructor stub
	inputFilename = theInputFilename;
	outputJsonFilename = theOutputJsonFilename;
}
void ConvertTools::trim(string& s) {

	size_t p = s.find_first_not_of(" \t");
	s.erase(0, p);

	p = s.find_last_not_of(" \t");
	if (string::npos != p)
		s.erase(p + 1);

}
ConvertTools::~ConvertTools() {
	// TODO Auto-generated destructor stub
}

