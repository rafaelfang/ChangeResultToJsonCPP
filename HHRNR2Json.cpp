/*
 * HHRNR2Json.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Chao
 */
#include "ConvertTools.h"
#include "HHRNR2Json.h"

HHRNR2Json::HHRNR2Json(char* inFilename, char* outFilename) :
		ConvertTools(inFilename, outFilename) {

}

void HHRNR2Json::convert() {
	char line[500];
	int counter = 0;
	FILE* inputFile = fopen(inputFilename, "r");

	HHRNRResult result;

	while (fgets(line, 200, inputFile) != NULL) {

		if (strstr(line, ">") != NULL) {
			counter++;
			char proteinName[7];
			char* pos1 = strstr(line, ">");
			sscanf(pos1 + 1, "%s", proteinName);
			string proteinNameStr(proteinName);
			result.setProteinName(proteinNameStr);

			while (strstr(line, "Probab=") == NULL) {
				fgets(line, 500, inputFile); //skip long name
			}

			//get probab, E-value, Score, Aligned_cols, Identities, Similarity, Sum_probs

			pos1 = strstr(line, "=");
			float probab;
			sscanf(pos1 + 1, "%f", &probab);
			result.setProbab(probab);

			char* pos2 = strstr(pos1 + 1, "=");
			float eValue;
			sscanf(pos2 + 1, "%f", &eValue);
			result.setExpect(eValue);

			char* pos3 = strstr(pos2 + 1, "=");
			float score;
			sscanf(pos3 + 1, "%f", &score);
			result.setScore(score);

			char* pos4 = strstr(pos3 + 1, "=");
			int alignedCols;
			sscanf(pos4 + 1, "%d", &alignedCols);
			result.setAlignedCols(alignedCols);

			char* pos5 = strstr(pos4 + 1, "=");
			float identities;
			sscanf(pos5 + 1, "%f", &identities);
			result.setIdentities(identities);

			char* pos6 = strstr(pos5 + 1, "=");
			float similarity;
			sscanf(pos6 + 1, "%f", &similarity);
			result.setSimilarities(similarity);

			char* pos7 = strstr(pos6 + 1, "=");
			float sumProbs;
			sscanf(pos7 + 1, "%f", &sumProbs);
			result.setSumProbs(sumProbs);

			fgets(line, 200, inputFile); //blank

			//get the query
			fgets(line, 200, inputFile);
			char query_ss_pred[100];
			sscanf(line + 17, "%s", query_ss_pred);
			string strQuery_ss_pred(query_ss_pred);
			result.setQuerySsPred(strQuery_ss_pred);

			fgets(line, 200, inputFile);
			int queryStart;
			char query[100];
			int queryEnd;
			sscanf(line + 17, "%d %s %d", &queryStart, query, &queryEnd);
			result.setQueryStart(queryStart);
			string strQuery(query);
			result.setQuery(strQuery);
			result.setQueryEnd(queryEnd);

			//get the Q Consensus
			fgets(line, 200, inputFile);
			int QConsensusStart;
			char QConsensus[100];
			int QConsensusEnd;
			sscanf(line + 17, "%d %s %d", &QConsensusStart, QConsensus,
					&QConsensusEnd);
			string strQConsensus(QConsensus);
			result.setQueryConsensus(strQConsensus);

			//get alignment
			fgets(line, 200, inputFile);
			char alignment[100];
			sscanf(line + 17, "%s", alignment);
			string strAlignment(alignment);
			result.setAlignment(strAlignment);

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

			//get the Target
			fgets(line, 200, inputFile);

			char target[100];

			sscanf(line + 17, "%d %s %d", &targetStart, target, &targetEnd);
			string strTarget(target);
			result.setTarget(strTarget);

			//get the TDssp
			fgets(line, 200, inputFile);
			char tDssp[100];
			sscanf(line + 17, "%s", tDssp);
			string strTDssp(tDssp);
			result.setTargetSsDssp(strTDssp);

			//get the TPred
			fgets(line, 200, inputFile);
			char tPred[100];
			sscanf(line + 17, "%s", tPred);
			string strTPred(tPred);
			result.setTargetSsPred(strTPred);
			counter++;
			HHRNRResultVector.push_back(result);
		}
	}
	//outputFile << "\"finish\":\"end\"" << "\n";
	//outputFile << "}" << "\n";
	fclose(inputFile);
	//outputFile.close();

}

void HHRNR2Json::write2JsonFile() {
	ofstream outputFile(outputJsonFilename);
	outputFile << "{" << "\n";
	for (int i = 0; i < HHRNRResultVector.size(); i++) {
		outputFile << "\"protein" << i << "\":{\n";
		outputFile << "\t\"proteinName\":\""
				<< HHRNRResultVector[i].getProteinName() << "\",\n";
		outputFile << "\t\"probab\":\"" << HHRNRResultVector[i].getProbab()
				<< "\",\n";
		outputFile << "\t\"eValue\":\"" << HHRNRResultVector[i].getExpect()
				<< "\",\n";
		outputFile << "\t\"score\":\"" << HHRNRResultVector[i].getScore()
				<< "\",\n";
		outputFile << "\t\"alignedCols\":\""
				<< HHRNRResultVector[i].getAlignedCols() << "\",\n";
		outputFile << "\t\"identities\":\""
				<< HHRNRResultVector[i].getIdentities() << "\",\n";
		outputFile << "\t\"similarity\":\""
				<< HHRNRResultVector[i].getSimilarities() << "\",\n";
		outputFile << "\t\"sumProbs\":\"" << HHRNRResultVector[i].getSumProbs()
				<< "\",\n";
		outputFile << "\t\"QuerySSPred\":\""
				<< HHRNRResultVector[i].getQuerySsPred() << "\",\n";
		outputFile << "\t\"QueryStart\":\""
				<< HHRNRResultVector[i].getQueryStart() << "\",\n";
		outputFile << "\t\"Query\":\"" << HHRNRResultVector[i].getQuery()
				<< "\",\n";
		outputFile << "\t\"QueryEnd\":\"" << HHRNRResultVector[i].getQueryEnd()
				<< "\",\n";
		outputFile << "\t\"QueryConsensus\":\""
				<< HHRNRResultVector[i].getQueryConsensus() << "\",\n";
		outputFile << "\t\"alignment\":\""
				<< HHRNRResultVector[i].getAlignment() << "\",\n";
		outputFile << "\t\"TargetStart\":\""
				<< HHRNRResultVector[i].getTargetStart() << "\",\n";
		outputFile << "\t\"TargetConsensus\":\""
				<< HHRNRResultVector[i].getTargetConsensus() << "\",\n";
		outputFile << "\t\"TargetEnd\":\""
				<< HHRNRResultVector[i].getTargetEnd() << "\",\n";
		outputFile << "\t\"target\":\"" << HHRNRResultVector[i].getTarget()
				<< "\",\n";
		outputFile << "\t\"tPred\":\"" << HHRNRResultVector[i].getTargetSsPred()
				<< "\"\n";
		outputFile << "},\n";
	}
	outputFile << "\"finish\":\"end\"" << "\n";
	outputFile << "}" << "\n";

	outputFile.close();
}
HHRNR2Json::~HHRNR2Json() {
	// TODO Auto-generated destructor stub
}

