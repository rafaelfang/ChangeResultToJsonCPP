#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>

#include "ConvertTools.h"

#include "HHR2Json.h"
#include "HHRNR2Json.h"
#include "BLANR2Json.h"
#include "BLAPDB2Json.h"
#include "json/json.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 4) {
		cout << "not enough arguments" << endl;
		cout << "<executable> <type> <inputFilename> <outputJsonFilename> "
				<< endl;

	}

	// -hhr2Json query.hhr hhr.json
	if (strcmp(argv[1], "-hhr2Json") == 0) {

		HHR2Json hhr2Json(argv[2], argv[3]);
		hhr2Json.convert();
		hhr2Json.writeAlignmentResults2JsonFile();
	}
	// -hhrNR2Json query.hhrNR hhrNR.json
	if (strcmp(argv[1], "-hhrNR2Json") == 0) {
		HHRNR2Json hhrNR2Json(argv[2], argv[3]);
		hhrNR2Json.convert();
		hhrNR2Json.writeAlignmentResults2JsonFile();
	}
	// -blaNR2Json query.blaNR blaNR.json
	if (strcmp(argv[1], "-blaNR2Json") == 0) {
		BLANR2Json blaNR2Json(argv[2], argv[3]);
		blaNR2Json.convert();
		blaNR2Json.writeAlignmentResults2JsonFile();
	}
	// -blaPDB2Json query.blaPDB blaPDB.json
	if (strcmp(argv[1], "-blaPDB2Json") == 0) {
		BLAPDB2Json blaPDB2Json(argv[2], argv[3]);
		blaPDB2Json.convert();
		blaPDB2Json.writeAlignmentResults2JsonFile();
	}

}

