/*
 * HHR2Json.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef HHR2JSON_H_
#define HHR2JSON_H_
#include "HHRResult.h"
#include "ThreeDimCoordsResult.h"
#include "ConvertTools.h"

#include "Utility.h"
using namespace std;
class HHR2Json: public ConvertTools {
public:
	HHR2Json( char*, char*);
	void buildDirectory();
	void convert();
	void writeAlignmentResults2JsonFile();
	virtual ~HHR2Json();

private:
	vector<HHRResult> HHRResultVector;

};

#endif /* HHR2JSON_H_ */
