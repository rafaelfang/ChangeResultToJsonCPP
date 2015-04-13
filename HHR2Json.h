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
using namespace std;
class HHR2Json: public ConvertTools {
public:
	HHR2Json(char*,char*);
	void convert();
	virtual ~HHR2Json();
};

#endif /* HHR2JSON_H_ */
