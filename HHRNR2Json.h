/*
 * HHRNR2Json.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef HHRNR2JSON_H_
#define HHRNR2JSON_H_
#include "HHRNRResult.h"
#include "ConvertTools.h"
#include <vector>
using namespace std;
class HHRNR2Json: public ConvertTools {
public:
	HHRNR2Json(char*, char*);
	void convert();
	void writeAlignmentResults2JsonFile();
	virtual ~HHRNR2Json();


private:
	vector<HHRNRResult> HHRNRResultVector;
};

#endif /* HHRNR2JSON_H_ */
