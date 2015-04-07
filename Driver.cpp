#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>

#include "ConvertTools.h"

#include "HHR2Json.h"
#include "HHRNR2Json.h"
#include "BLANR2Json.h"
#include "BLAPDB2Json.h"
using namespace std;

int main(int argc, char* argv[]) {
	HHR2Json hhr2Json(argv[1]);
	hhr2Json.convert();
	HHRNR2Json hhrNR2Json(argv[2]);
	hhrNR2Json.convert();
	BLANR2Json blaNR2Json(argv[3]);
	blaNR2Json.convert();
	BLAPDB2Json blaPDB2Json(argv[4]);
	blaPDB2Json.convert();
}

