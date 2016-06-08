/*
 * =====================================================================================
 *
 *       Filename:  prototype.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月08日 14时38分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "prototype.h"
#include <iostream>

using namespace std;

Prototype* SubPrototype::clone()
{
	cout << "SubPrototype clone" << endl;
	return new SubPrototype(*this); 
}
