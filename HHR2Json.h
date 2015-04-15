/*
 * HHR2Json.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#ifndef HHR2JSON_H_
#define HHR2JSON_H_
#include "HHRResult.h"
#include "ConvertTools.h"
#include <vector>
using namespace std;
class HHR2Json: public ConvertTools {
public:
	HHR2Json(char*, char*);
	void convert();
	void write2JsonFile();
	virtual ~HHR2Json();


private:
	vector<HHRResult> HHRResultVector;
};

#endif /* HHR2JSON_H_ */
