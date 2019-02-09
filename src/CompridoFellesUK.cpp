/***************************************************************************
 * Author       : Surya Tej Nimmakayala                                    *
 * File Name    : CompridoFellesUK.cpp                                     *
 * Date created : Feb 6, 2019                                              *
 * Description  : Implementation file for methods declared in the class    *
 *                "CompridoFellesUK"                                       *
 *                                                                         *
 * Date modified:                                                          *
 * Change log   :                                                          *
 *                                                                         *
 ***************************************************************************/

#include "CompridoFellesUK.h"
#include <fstream>
#include <algorithm>

CompridoFellesUK::CompridoFellesUK(){

	seq1 = "";
	seq2 = "";
	lenSeq1 = 0;
	lenSeq2 = 0;
	dynTab = nullptr;
	lenLCS = 0;

}


CompridoFellesUK::CompridoFellesUK(std::string inpFName) throw(FileNotFound){

	std::ifstream ifile(inpFName);

	if(ifile.is_open()){

		std::string lineStr="";

		getline(ifile, lineStr); // extract first sequence in line 1
		seq1 = lineStr; // set the first sequence in member: seq1


		getline(ifile, lineStr); // extract second sequence in line 2
		seq2 = lineStr; // set the second sequence in member: seq2

		ifile.close();


		// Set sequence lengths
		lenSeq1 = seq1.length();
		lenSeq2 = seq2.length();


		// Allocate/Initialize the memory for 2D array
		dynTab = new int*[lenSeq1+1];	// lenSeq1 number of rows

		for(int i=0; i < lenSeq1+1; i++)
			dynTab[i] = new int[lenSeq2+1]; // for each of the lenSeq1 rows, lenSeq2 columns

		for(int i=0;i < lenSeq1+1; i++)
			for(int j=0; j < lenSeq2+1; j++)
				dynTab[i][j] = 0;


		lenLCS = 0;

	}
	else{ // File with name stored in "inpFName" could not be successfully opened, so, throw an exception
		// to client.

		throw(FileNotFound(" Input file " + inpFName + " doesn't exist"));

	}

}


std::string CompridoFellesUK::getInpSeq1() const{

	return seq1;

}


std::string CompridoFellesUK::getInpSeq2() const{

	return seq2;

}


int CompridoFellesUK::findCompridoFellesUK(){


	return recFindCompridoFellesUK(1,1); // Starts from (1,1) instead of (0,0) as additional
	// row-0 & column-0 are set as valid out of bounds
	// with value 0.

}


int CompridoFellesUK::recFindCompridoFellesUK(int seqIdx1, int seqIdx2){

	if(seqIdx1 < lenSeq1+1){ // Executes only for valid row array index

		if(seq1[seqIdx1-1] == seq2[seqIdx2-1]){ // -1 as the sequence arrays start with index 0 and not 1.
			dynTab[seqIdx1][seqIdx2] = dynTab[seqIdx1-1][seqIdx2-1] + 1; // C(i,j) = C(i-1,j-1)+1
			lenLCS=dynTab[seqIdx1][seqIdx2];
		}
		else // not equal
			dynTab[seqIdx1][seqIdx2] = std::max(dynTab[seqIdx1-1][seqIdx2],dynTab[seqIdx1][seqIdx2-1]);

		seqIdx2++; // Next sub-problem in the row seqIdx1

		if(seqIdx2 == lenSeq2+1){ // Out of bounds idx: Time for reset to first sub-problem in the next row
			seqIdx1++; // next row
			seqIdx2=1; // virtual first column, given that 0 is for handling the out of bounds column
		}

		return recFindCompridoFellesUK(seqIdx1, seqIdx2);

	}
	else
		return lenLCS;

}


std::string CompridoFellesUK::getCompridoFellesUK() const{

	// Start from the bottom right corner of the table with the max. length of longest common sequence
	// between the two input sequences.

	int currSubProbSeqIdx1 = lenSeq1, currSubProbSeqIdx2 = lenSeq2;
	bool doneExtractingSequence = false;
	std::string lcs = ""; // For extracting the lcs

	// Iterative approach, but, could also be done with recursion with each recursive call
	// representing a sub-problem of a single step to be taken from bottom-right of the table
	// to the step of the first match in the common sequence. Effectively, the problem maps to
	// finding the path out of a maze with starting position as the bottom right of the table
	// and each sub-problem would be finding the next step from the 3 possible steps:
	// left, up or diagonal, until the sub-problem with lcs 1 is reached in the table of sub-problems.

	while(!doneExtractingSequence){

		int currLCSLen = dynTab[currSubProbSeqIdx1][currSubProbSeqIdx2];

		// Get lcs in the three prior possible sub-problems: left, up, diagonal entries in the dynamic table
		int lcsLenLeftSubProb =  dynTab[currSubProbSeqIdx1][currSubProbSeqIdx2-1];
		int lcsLenUpperSubProb = dynTab[currSubProbSeqIdx1-1][currSubProbSeqIdx2];
		int lcsLenDiagSubProb = dynTab[currSubProbSeqIdx1-1][currSubProbSeqIdx2-1];

		// Now, back-trace to the valid prior sub-problem from the above 3
		// Based on the indices set for both sequences the new lcs length will be
		// fetched at the beginning of the next iteration.

		if(lcsLenLeftSubProb == currLCSLen)
			currSubProbSeqIdx2=-1;
		else if(lcsLenUpperSubProb == currLCSLen)
			currSubProbSeqIdx1=-1;
		else if(lcsLenDiagSubProb == currLCSLen-1){ // current seq. index combo has a common
			// character in both sequences.
			lcs = seq1[currSubProbSeqIdx1] + lcs;

			currSubProbSeqIdx1=-1;
			currSubProbSeqIdx2=-1;

			if(lcsLenDiagSubProb == 0){ // Means currLCSLen == 1 and we have reached the first
				// matching character in the lcs.
				doneExtractingSequence = true;
			}
		} // end of if-else-if

	} // end of while(!doneExtractingSequence)

	return lcs;

}


std::string CompridoFellesUK::getDynamicTableContent() const{

	std::string tabContentStr = "\n";

	for(int i=0; i < lenSeq1+1; i++){
		for(int j=0; j < lenSeq2+1; j++){

			tabContentStr = tabContentStr + std::to_string(dynTab[i][j]);

		}
		tabContentStr = tabContentStr + "\n";
	}

	return tabContentStr;

}


CompridoFellesUK::~CompridoFellesUK(){

	if(dynTab != nullptr){

		for(int i=0; i < lenSeq1+1; i++)
			delete [] dynTab[i];

		delete [] dynTab;

	}

}
