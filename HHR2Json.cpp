/*
 * HHR2Json.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */

#include "HHR2Json.h"

HHR2Json::HHR2Json(char* inFilename, char* outFilename) :
		ConvertTools(inFilename, outFilename) {
}

void HHR2Json::convert() {

	char line[500];
	int counter = 0;
	FILE* inputFile = fopen(inputFilename, "r");
	ofstream outputFile(outputJsonFilename);
	HHRResult result;
	outputFile << "{" << "\n";
	while (fgets(line, 200, inputFile) != NULL) {

		if (strstr(line, ">") != NULL) {
			counter++;
			char proteinName[7];
			char* pos1 = strstr(line, ">");
			sscanf(pos1 + 1, "%s", proteinName);
			string proteinNameStr(proteinName);
			result.setProteinName(proteinNameStr);
			outputFile << "\"protein" << counter << "\":{\n";
			outputFile << "\t\"proteinName\":\"" << result.getProteinName()
					<< "\",\n";
			while (strstr(line, "Probab=") == NULL) {
				fgets(line, 500, inputFile); //skip long name
			}

			//get probab, E-value, Score, Aligned_cols, Identities, Similarity, Sum_probs

			pos1 = strstr(line, "=");
			float probab;
			sscanf(pos1 + 1, "%f", &probab);
			result.setProbab(probab);
			outputFile << "\t\"probab\":\"" << result.getProbab() << "\",\n";

			char* pos2 = strstr(pos1 + 1, "=");
			float eValue;
			sscanf(pos2 + 1, "%f", &eValue);
			result.setExpect(eValue);
			outputFile << "\t\"eValue\":\"" << result.getExpect() << "\",\n";

			char* pos3 = strstr(pos2 + 1, "=");
			float score;
			sscanf(pos3 + 1, "%f", &score);
			result.setScore(score);
			outputFile << "\t\"score\":\"" << result.getScore() << "\",\n";

			char* pos4 = strstr(pos3 + 1, "=");
			int alignedCols;
			sscanf(pos4 + 1, "%d", &alignedCols);
			result.setAlignedCols(alignedCols);
			outputFile << "\t\"alignedCols\":\"" << result.getAlignedCols()
					<< "\",\n";

			char* pos5 = strstr(pos4 + 1, "=");
			float identities;
			sscanf(pos5 + 1, "%f", &identities);
			result.setIdentities(identities);
			outputFile << "\t\"identities\":\"" << result.getIdentities()
					<< "\",\n";

			char* pos6 = strstr(pos5 + 1, "=");
			float similarity;
			sscanf(pos6 + 1, "%f", &similarity);
			result.setSimilarities(similarity);
			outputFile << "\t\"similarity\":\"" << result.getSimilarities()
					<< "\",\n";

			char* pos7 = strstr(pos6 + 1, "=");
			float sumProbs;
			sscanf(pos7 + 1, "%f", &sumProbs);
			result.setSumProbs(sumProbs);
			outputFile << "\t\"sumProbs\":\"" << result.getSumProbs()
					<< "\",\n";

			fgets(line, 200, inputFile); //blank

			//get the query

			fgets(line, 200, inputFile);
			int queryStart;
			char query[100];
			int queryEnd;
			sscanf(line + 17, "%d %s %d", &queryStart, query, &queryEnd);
			result.setQueryStart(queryStart);
			string strQuery(query);
			result.setQuery(strQuery);
			result.setQueryEnd(queryEnd);
			outputFile << "\t\"QueryStart\":\"" << queryStart << "\",\n";
			outputFile << "\t\"Query\":\"" << query << "\",\n";
			outputFile << "\t\"QueryEnd\":\"" << queryEnd << "\",\n";

			//get the Q Consensus
			fgets(line, 200, inputFile);
			int QConsensusStart;
			char QConsensus[100];
			int QConsensusEnd;
			sscanf(line + 17, "%d %s %d", &QConsensusStart, QConsensus,
					&QConsensusEnd);
			string strQConsensus(QConsensus);
			result.setQueryConsensus(strQConsensus);

			outputFile << "\t\"QueryConsensus\":\""
					<< result.getQueryConsensus() << "\",\n";

			//get alignment
			fgets(line, 200, inputFile);
			char alignment[100];
			sscanf(line + 17, "%s", alignment);
			string strAlignment(alignment);
			result.setAlignment(strAlignment);
			outputFile << "\t\"alignment\":\"" << result.getAlignment()
					<< "\",\n";

			//get the T Consensus
			fgets(line, 200, inputFile);
			int targetStart;
			char targetConsensus[100];
			int targetEnd;
			sscanf(line + 17, "%d %s %d", &targetStart, targetConsensus,
					&targetEnd);
			result.setTargetStart(targetStart);
			string strTargetConsensus(targetConsensus);
			result.setTargetConsensus(strTargetConsensus);
			result.setTargetEnd(targetEnd);

			outputFile << "\t\"TargetStart\":\"" << result.getTargetStart()
					<< "\",\n";
			outputFile << "\t\"TargetConsensus\":\""
					<< result.getTargetConsensus() << "\",\n";
			outputFile << "\t\"TargetEnd\":\"" << result.getTargetEnd()
					<< "\",\n";

			//get the Target
			fgets(line, 200, inputFile);

			char target[100];

			sscanf(line + 17, "%d %s %d", &targetStart, target, &targetEnd);
			string strTarget(target);
			result.setTarget(strTarget);
			outputFile << "\t\"target\":\"" << result.getTarget() << "\",\n";

			//get the TPred
			fgets(line, 200, inputFile);
			char tPred[100];
			sscanf(line + 17, "%s", tPred);
			string strTPred(tPred);
			result.setTargetSsPred(strTPred);
			outputFile << "\t\"tPred\":\"" << result.getTargetSsPred()
					<< "\"\n";

			outputFile << "},\n";
			counter++;
		}
	}
	outputFile << "\"finish\":\"end\"" << "\n";
	outputFile << "}" << "\n";
	fclose(inputFile);
	outputFile.close();

}

HHR2Json::~HHR2Json() {
	// TODO Auto-generated destructor stub
}

