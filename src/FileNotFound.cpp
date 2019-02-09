/********************************************************************
 * Author       : Surya Tej Nimmakayala                             *
 * File Name    : FileNotFound.cpp                                  *
 * Date created : Feb 7, 2019                                       *
 * Description  : Implementation file for "FileNotFound" class. Has *
 *               code for methods declared in the definition of the *
 *               class "FileNotFound"(in FileNotFound.h)            *
 * Date modified:                                                   *
 * Change log   :                                                   *
 *                                                                  *
 ********************************************************************/

#include "FileNotFound.h"

FileNotFound::FileNotFound(std::string msg):runtime_error("FileNotFound:"+msg+" !"){

}


