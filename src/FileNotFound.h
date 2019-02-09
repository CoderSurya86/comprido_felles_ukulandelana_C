/******************************************************************
 * Author: Surya Tej Nimmakayala                                  *
 * File Name: FileNotFound.h                                      *
 * Date created: Feb 7, 2019                                      *
 * Description: Header file for class "FileNotFound".             *
 *              Includes definition of the class and declaration  *
 *              of relevant methods and data members.             *
 * Date modified:                                                 *
 * Change log:                                                    *
 *                                                                *
 ******************************************************************/

#ifndef FILENOTFOUND_H_
#define FILENOTFOUND_H_

#include <string>
#include <stdexcept>

class FileNotFound: public std::runtime_error {
public:

	/**************************************************************************
	 * pre-condition : None                                                   *
	 * post-condition: None                                                   *
	 * return-type   : None                                                   *
	 * parameter-list: Exception message passed during object instantiation.  *
	 * exception-list: None                                                   *
	 **************************************************************************/
	FileNotFound(std::string msg);
};

#endif /* COMPRIDO_FELLES_UKULANDELANA_C_SRC_FILENOTFOUND_H_ */
