/***************************************************************************
 * Author       : Surya Tej Nimmakayala                                    *
 * File Name    : CompridoFellesUK.h                                       *
 * Date created : Feb 6, 2019                                              *
 * Description  : Header file for template class "CompridoFellesUK".       *
 *                Includes definition of the class along with declaration  *
 *                of relevant methods and data members.                    *
 *                                                                         *
 * Date modified:                                                          *
 * Change log   :                                                          *
 *                                                                         *
 ***************************************************************************/

#ifndef COMPRIDOFELLESUK_H_
#define COMPRIDOFELLESUK_H_

#include <string>
#include "FileNotFound.h"

class CompridoFellesUK {
public:

	/***********************************************************************
	 * pre-condition : None                                                *
	 * post-condition: Private data members initialized to default values. *
	 * return-type   : None                                                *
	 * parameter-list: None                                                *
	 * exception-list: None                                                *
	 ***********************************************************************/
	CompridoFellesUK();


	/************************************************************************
	 * pre-condition : None                                                 *
	 * post-condition: Input two sequences read from input file initialized *
	 *                 to the two private data members.                     *
	 * return-type   : None                                                 *
	 * parameter-list: Input file name passed in by client, the main()      *
	 *                 method in main.cpp.                                  *
	 * exception-list: If file with name stored in the parameter "inpFName" *
	 *                 doesn't exist, throw the "FileNotFound" exception.   *
	 ************************************************************************/
	CompridoFellesUK(std::string inpFName) throw(FileNotFound);


	/************************************************************************
	 * pre-condition : The private data member seq1 initialized with data   *
	 *                 from the input file.                                 *
	 * post-condition: Data stored in private members unchanged.            *
	 * return-type   : Input sequence 1, set in private data member seq1.   *
	 * parameter-list: None                                                 *
	 * exception-list: None                                                 *
	 ************************************************************************/
	std::string getInpSeq1() const;


	/************************************************************************
	 * pre-condition : The private data member seq2 initialized with data   *
	 *                 from the input file.                                 *
	 * post-condition: Data stored in private members unchanged.            *
	 * return-type   : Input sequence 2, set in private data member seq2.   *                                     *
	 * parameter-list: None                                                 *
	 * exception-list: None                                                 *
	 ************************************************************************/
	std::string getInpSeq2() const;



	/************************************************************************
	 * pre-condition : The private data members seq1, seq2 initialized with *
	 *                 data from the input file.                            *
	 * post-condition: Private members dynTab and lenLCS set with required  *
	 *                 data.                                                *
	 * return-type   : LCS length as an integer                             *
	 * parameter-list: None                                                 *
	 * exception-list: None                                                 *
	 ************************************************************************/
	int findCompridoFellesUK();


	/************************************************************************
	 * pre-condition : DynTab set with the required values.                 *
	 * post-condition: No change to private data members.                   *
	 * return-type   : LCS as a string.                                     *
	 * parameter-list: None                                                 *
	 * exception-list: None                                                 *
	 ************************************************************************/
	std::string getCompridoFellesUK() const;


	/************************************************************************
	 * pre-condition : DynTab set with the required values. This is only    *
	 *                 for debugging purposes.                              *
	 * post-condition: No change to private data members.                   *
	 * return-type   : Content of the dynamic table as a string.            *
	 * parameter-list: None                                                 *
	 * exception-list: None                                                 *
	 ************************************************************************/
	std::string getDynamicTableContent() const;



	/************************************************************************
	 * pre-condition : None.                                                *
	 * post-condition: The 2D array memory allocated on the heap for data   *
	 *                 member dynTab is released, if not already.           *
	 * return-type   : None                                                 *
	 * parameter-list: None                                                 *
	 * exception-list: None                                                 *
	 ************************************************************************/
	~CompridoFellesUK();

private:
	std::string seq1, seq2; // To store the two sequences
	int lenSeq1, lenSeq2; // To store the lengths of two sequences
	int **dynTab; // 2D array modeling the dynamic table
	int lenLCS; // length of longest common sequence


	/************************************************************************
	 * pre-condition : The private data members seq1, seq2 initialized with *
	 *                 data from the input file. The members dynTab, lenLCS *
	 *                 should also be initialized with appropriate values.  *
	 * post-condition: LCS for the sub-problem with input seqIdx1, seqIdx2  *
	 *                 set in the dynamic table, along with the lenLCS      *
	 *                 until this sub-problem.                              *
	 * return-type   : LCS length as an integer for the given combination   *
	 *                 of seqIdx1 and seqIdx2.                              *
	 * parameter-list: seqIdx1 - Index of character in sequence1            *
	 *                 seqIdx2 - Index of character in sequence2            *
	 *                 Both these indexes would be used to track the LCS    *
	 *                 lengths for a given combination of those indices.    *
	 * exception-list: None                                                 *
	 ************************************************************************/
	int recFindCompridoFellesUK(int seqIdx1, int seqIdx2);


};

#endif /* COMPRIDOFELLESUK_H_ */
