/*
 * =====================================================================================
 *
 *       Filename:  visitor.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月12日 15时32分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "visitor.h"
#include <iostream>
using namespace std;

void SubVisitorA::visitA()
{
	cout << "SubVisitorA call visitA" << endl;
}

void SubVisitorA::visitB()
{
	cout << "SubVisitorB call visitB" << endl;
}

void SubVisitorB::visitA()
{
	cout << "SubVisitorB call visitA" << endl;
}

void SubVisitorB::visitB()
{
	cout << "SubVisitorB call visitB" << endl;
}

void ElementA::accept(Visitor *v)
{
	v->visitA();
	cout << "ElementA exec accept" << endl;
}
