/*
 * BLAPDB2Json.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#include "BLAPDB2Json.h"

BLAPDB2Json::BLAPDB2Json(char* inFilename, char* outFilename) :
		ConvertTools(inFilename, outFilename) {

}
void BLAPDB2Json::convert() {

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	FILE* fptr = fopen(inputFilename, "r");
	ofstream outputFile(outputJsonFilename);
	char line[500];
	int counter = 1;
	BLAPDBResult result;
	outputFile << "{\n";
	while (fgets(line, 500, fptr) != NULL) {
		if ((strstr(line, ">") != NULL) && !result.isFirstStateReached()) {
			//set first block information
			char proteinName[7];
			char* pos1 = strstr(line, ">");
			sscanf(pos1 + 1, "%s", proteinName);
			string proteinNameStr(proteinName);
			result.setProteinName(proteinNameStr);
			while (strstr(line, "Length =") == NULL) {
				fgets(line, 500, fptr); //skip long name
			}
			char temp[10];
			int seqLen;
			sscanf(line, "%s = %d", temp, &seqLen);
			result.setLength(seqLen);
			//set first state reached
			result.setFirstStateReached(true);
		}
		if ((strstr(line, "Score =") != NULL)
				&& !result.isSecondStateReached()) {
			//set second block information
			float score;
			char* pos1 = strstr(line, "=");
			sscanf(pos1 + 1, "%f", &score);
			result.setScore(score);
			char* pos2 = strstr(pos1 + 1, "=");
			float eValue;
			sscanf(pos2 + 1, "%f", &eValue);
			result.setExpect(eValue);
			fgets(line, 500, fptr);
			pos1 = strstr(line, "(");
			int identities;
			sscanf(pos1 + 1, "%d", &identities);
			result.setIdentities(identities);
			pos2 = strstr(pos1 + 1, "(");
			int positives;
			sscanf(pos2 + 1, "%d", &positives);
			result.setPositives(positives);
			char* pos3 = strstr(pos2 + 1, "(");
			if (pos3 == NULL) {
				//there is no gaps
				result.setGaps(0);
			} else {
				int gaps;
				sscanf(pos3 + 1, "%d", &gaps);
				result.setGaps(gaps);
			}

			//set second state reached
			result.setSecondStateReached(true);
		}

		if ((strstr(line, "Query:") != NULL) && !result.isThirdStateReached()) {
			//set third block information
			int nInt1, nInt2;
			char var1[20], var2[20];
			char tmpQuery[200];
			sscanf(line, "%s %d %s %d", var1, &nInt1, tmpQuery, &nInt2);
			result.setQueryStart(nInt1);
			string tmpQueryStr(tmpQuery);
			result.setQuery(tmpQueryStr);
			result.setQueryEnd(nInt2);
			fgets(line, 500, fptr);
			string tmpLineStr(line);
			result.setAlignment(tmpLineStr);
			fgets(line, 500, fptr);
			char tmpSubject[200];
			sscanf(line, "%s %d %s %d", var1, &nInt1, tmpSubject, &nInt2);
			result.setSubjectStart(nInt1);
			string tmpSubjectStr(tmpSubject);
			result.setSubject(tmpSubjectStr);
			result.setSubjectEnd(nInt2);
			//set third state reached
			result.setThirdStateReached(true);
		}

		if ((strstr(line, "Query:") != NULL) && result.isThirdStateReached()) {
			//update third block information, so in this case
			//query, alignment and subject should be long string
			//the queryEnd and subjectEnd should also be updated
			int nInt1, nInt2;
			char var1[20], var2[20];
			char tmpQuery[200];
			sscanf(line, "%s %d %s %d", var1, &nInt1, tmpQuery, &nInt2);
			string newQuery = result.getQuery();
			newQuery += tmpQuery;
			result.setQuery(newQuery);
			result.setQueryEnd(nInt2);
			fgets(line, 500, fptr);
			string newAlignment = result.getAlignment();
			newAlignment += line;
			result.setAlignment(newAlignment);
			fgets(line, 500, fptr);
			char tmpSubject[200];
			sscanf(line, "%s %d %s %d", var1, &nInt1, tmpSubject, &nInt2);
			string newSubject = result.getSubject();
			newSubject += tmpSubject;
			result.setSubject(newSubject);
			result.setSubjectEnd(nInt2);

		}

		if ((strstr(line, "Score =") != NULL)
				&& result.isSecondStateReached()) {

			//first write the protein information to json
			BLAPDBResultVector.push_back(result);
			counter++;
			//then update the information and set the second state flag
			float score;
			char* pos1 = strstr(line, "=");
			sscanf(pos1 + 1, "%f", &score);
			result.setScore(score);
			char* pos2 = strstr(pos1 + 1, "=");
			float eValue;
			sscanf(pos2 + 1, "%f", &eValue);
			result.setExpect(eValue);
			fgets(line, 500, fptr);
			pos1 = strstr(line, "(");
			int identities;
			sscanf(pos1 + 1, "%d", &identities);
			result.setIdentities(identities);
			pos2 = strstr(pos1 + 1, "(");
			int positives;
			sscanf(pos2 + 1, "%d", &positives);
			result.setPositives(positives);
			char* pos3 = strstr(pos2 + 1, "(");
			if (pos3 == NULL) {
				//there is no gaps
				result.setGaps(0);
			} else {
				int gaps;
				sscanf(pos3 + 1, "%d", &gaps);
				result.setGaps(gaps);
			}

			result.setSecondStateReached(true);
			//unset the third block flag
			result.setThirdStateReached(false);

		}
		if ((strstr(line, ">") != NULL) && result.isFirstStateReached()) {

			//first write the protein information to json
			BLAPDBResultVector.push_back(result);
			counter++;
			//then update the information set the first state flag
			char proteinName[7];
			char* pos1 = strstr(line, ">");
			sscanf(pos1 + 1, "%s", proteinName);
			string proteinNameStr(proteinName);
			result.setProteinName(proteinNameStr);
			while (strstr(line, "Length =") == NULL) {
				fgets(line, 500, fptr); //skip long name
			}
			char temp[10];
			int seqLen;
			sscanf(line, "%s = %d", temp, &seqLen);
			result.setLength(seqLen);
			//unset second block flag and third block flag
			result.setSecondStateReached(false);
			result.setThirdStateReached(false);
		}

	}

	BLAPDBResultVector.push_back(result);

	fclose(fptr);


}

void BLAPDB2Json::write2JsonFile() {
	ofstream outputFile(outputJsonFilename);
	outputFile << "{" << "\n";

	for (int i = 0; i < BLAPDBResultVector.size(); i++) {
		outputFile << "\"protein" << i << "\":{\n";
		outputFile << "\t\"proteinName\":\""
				<< BLAPDBResultVector[i].getProteinName() << "\",\n";
		outputFile << "\t\"Length\":\"" << BLAPDBResultVector[i].getLength()
				<< "\",\n";
		outputFile << "\t\"Score\":\"" << BLAPDBResultVector[i].getScore()
				<< "\",\n";
		outputFile << "\t\"Expect\":\"" << BLAPDBResultVector[i].getExpect()
				<< "\",\n";
		outputFile << "\t\"Identities\":\""
				<< BLAPDBResultVector[i].getIdentities() << "\",\n";
		outputFile << "\t\"Positives\":\""
				<< BLAPDBResultVector[i].getPositives() << "\",\n";
		outputFile << "\t\"Gaps\":\"" << BLAPDBResultVector[i].getGaps()
				<< "\",\n";
		outputFile << "\t\"QueyStart\":\""
				<< BLAPDBResultVector[i].getQueryStart() << "\",\n";
		outputFile << "\t\"Query\":\"" << BLAPDBResultVector[i].getQuery()
				<< "\",\n";
		outputFile << "\t\"QueryEnd\":\"" << BLAPDBResultVector[i].getQueryEnd()
				<< "\",\n";
		outputFile << "\t\"Alignment\":\""
				<< BLAPDBResultVector[i].getAlignment() << "\",\n";
		outputFile << "\t\"SubjectStart\":\""
				<< BLAPDBResultVector[i].getSubjectStart() << "\",\n";
		outputFile << "\t\"Subject\":\"" << BLAPDBResultVector[i].getSubject()
				<< "\",\n";
		outputFile << "\t\"SubjectEnd\":\""
				<< BLAPDBResultVector[i].getSubjectEnd() << "\"\n";
		outputFile << "},\n";
	}
	outputFile << "\"finish\":\"end\"" << "\n";
	outputFile << "}" << "\n";

	outputFile.close();
}
BLAPDB2Json::~BLAPDB2Json() {
	// TODO Auto-generated destructor stub
}


