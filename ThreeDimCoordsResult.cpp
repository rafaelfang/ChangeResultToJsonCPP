/*
 * ThreeDimCoordsResult.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: Chao
 */

#include "ThreeDimCoordsResult.h"

ThreeDimCoordsResult::ThreeDimCoordsResult() {
	// TODO Auto-generated ructor stub

}

ThreeDimCoordsResult::~ThreeDimCoordsResult() {
	// TODO Auto-generated destructor stub
}

vector<float>& ThreeDimCoordsResult::getRowX() {
	return rowX;
}

void ThreeDimCoordsResult::setRowX(vector<float>& rowX) {
	this->rowX = rowX;
}

vector<float>& ThreeDimCoordsResult::getRowY() {
	return rowY;
}

void ThreeDimCoordsResult::setRowY(vector<float>& rowY) {
	this->rowY = rowY;
}

vector<float>& ThreeDimCoordsResult::getRowZ() {
	return rowZ;
}

void ThreeDimCoordsResult::setRowZ(vector<float>& rowZ) {
	this->rowZ = rowZ;
}

string& ThreeDimCoordsResult::getSubject() {
	return subject;
}

void ThreeDimCoordsResult::setSubject(string& subject) {
	this->subject = subject;
}

const string& ThreeDimCoordsResult::getProteinName() const {
	return proteinName;
}

void ThreeDimCoordsResult::setProteinName(const string& proteinName) {
	this->proteinName = proteinName;
}

int ThreeDimCoordsResult::getSubjectStart() const {
	return subjectStart;
}

void ThreeDimCoordsResult::setSubjectStart(int subjectStart) {
	this->subjectStart = subjectStart;
}
