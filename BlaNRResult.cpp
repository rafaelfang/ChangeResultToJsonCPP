/*
 * BlaNRResult.cpp
 *
 *  Created on: Apr 12, 2015
 *      Author: Chao
 */

#include "BlaNRResult.h"

BlaNRResult::BlaNRResult() {

}
string& BlaNRResult::getAlignment() {
	return alignment;
}

void BlaNRResult::setAlignment(string& alignment) {
	this->alignment = alignment;
}

float BlaNRResult::getExpect() {
	return expect;
}

void BlaNRResult::setExpect(float expect) {
	this->expect = expect;
}

bool BlaNRResult::isFirstStateReached() {
	return firstStateReached;
}

void BlaNRResult::setFirstStateReached(bool firstStateReached = false) {
	this->firstStateReached = firstStateReached;
}

int BlaNRResult::getGaps() {
	return gaps;
}

void BlaNRResult::setGaps(int gaps) {
	this->gaps = gaps;
}

int BlaNRResult::getIdentities() {
	return identities;
}

void BlaNRResult::setIdentities(int identities) {
	this->identities = identities;
}

int BlaNRResult::getLength() {
	return length;
}

void BlaNRResult::setLength(int length) {
	this->length = length;
}

int BlaNRResult::getPositives() {
	return positives;
}

void BlaNRResult::setPositives(int positives) {
	this->positives = positives;
}

string& BlaNRResult::getProteinName() {
	return proteinName;
}

void BlaNRResult::setProteinName(string& proteinName) {
	this->proteinName = proteinName;
}

string& BlaNRResult::getQuery() {
	return query;
}

void BlaNRResult::setQuery(string& query) {
	this->query = query;
}

int BlaNRResult::getQueryEnd() {
	return queryEnd;
}

void BlaNRResult::setQueryEnd(int queryEnd) {
	this->queryEnd = queryEnd;
}

int BlaNRResult::getQueryStart() {
	return queryStart;
}

void BlaNRResult::setQueryStart(int queryStart) {
	this->queryStart = queryStart;
}

float BlaNRResult::getScore() {
	return score;
}

void BlaNRResult::setScore(float score) {
	this->score = score;
}

bool BlaNRResult::isSecondStateReached() {
	return secondStateReached;
}

void BlaNRResult::setSecondStateReached(bool secondStateReached = false) {
	this->secondStateReached = secondStateReached;
}

string& BlaNRResult::getSubject() {
	return subject;
}

void BlaNRResult::setSubject(string& subject) {
	this->subject = subject;
}

int BlaNRResult::getSubjectEnd() {
	return subjectEnd;
}

void BlaNRResult::setSubjectEnd(int subjectEnd) {
	this->subjectEnd = subjectEnd;
}

int BlaNRResult::getSubjectStart() {
	return subjectStart;
}

void BlaNRResult::setSubjectStart(int subjectStart) {
	this->subjectStart = subjectStart;
}

bool BlaNRResult::isThirdStateReached() {
	return thirdStateReached;
}

void BlaNRResult::setThirdStateReached(bool thirdStateReached = false) {
	this->thirdStateReached = thirdStateReached;
}
BlaNRResult::~BlaNRResult() {
	// TODO Auto-generated destructor stub
}

