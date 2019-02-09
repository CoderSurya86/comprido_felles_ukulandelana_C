/***************************************************************************
 * Author       : Surya Tej Nimmakayala                                    *
 * Filename     : main.cpp                                                 *
 * Date created : Feb 5, 2019                                              *
 * Description  : File with code of main() to start the program execution. *
 * Date modified:                                                          *
 *                                                                         *
 * Change log   :                                                          *
 ***************************************************************************/

#include <iostream>
#include "CompridoFellesUK.h"
#include <exception>

int main(int argc, char* argv[]){

	if(argc != 2){
		std::cout << "\nIncorrect number of arguments !!\n";
		std::cout << "Usage: ./<executable-name> <input-sequence-file>";
		std::cout << "Sample Usage: ./computeLongestCommonSequence inputTwoSequences.txt\n";
		exit(-1);
	}

	try{
	    CompridoFellesUK lonCmnSq(argv[1]);
	    std::cout << "\nInput sequence # 1: " << lonCmnSq.getInpSeq1() << "\n";
	    std::cout << "Input sequence # 2: " << lonCmnSq.getInpSeq2() << "\n";
        std::cout << "\nLongest Common Sub-Sequence Length: " << lonCmnSq.findCompridoFellesUK() << "\n";
        std::cout << "\nLongest Common Sub-Sequence: " << lonCmnSq.getCompridoFellesUK() << "\n";
        std::cout << "\nDynamic Table Content: " << lonCmnSq.getDynamicTableContent() << "\n";
	}
	catch(std::exception& e){
		std::cout << e.what() << "\n";
	}

	return 0;

}




