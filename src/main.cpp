/***************************************************************************
 * Author       : Surya Tej Nimmakayala                                    *
 * Filename     : main.cpp                                                 *
 * Date created : Feb 5, 2019                                              *
 * Description  : File with code of main() to start the program execution. *
 * Date modified:                                                          *
 *                                                                         *
 * Change log   :                                                          *
 ***************************************************************************/

#include<iostream>

int main(int argc, char* argv[]){

	if(argc != 2){
		std::cout << "\nIncorrect number of arguments !!\n";
		std::cout << "Usage: ./<executable-name> <input-sequence-file>";
		std::cout << "Sample Usage: ./computeLongestCommonSequence inputTwoSequences.txt\n";
		exit(-1);
	}

	std::cout << "argv[1]: " << argv[1] << "\n";

	return 0;

}




