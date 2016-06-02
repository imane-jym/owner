/*
 * =====================================================================================
 *
 *       Filename:  facade.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/02/2016 03:47:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include "facade.h"

using namespace std;

Facade::Facade()
{
	m_sys1 = new SubSystem1();
	m_sys2 = new SubSystem2();
}

Facade::~Facade()
{
	delete m_sys1;
	delete m_sys2;
}

void Facade::operate()
{
	m_sys1->operate();
	m_sys2->operate();
}

void SubSystem1::operate()
{
	cout << "SubSystem1 opt" << endl;
}

void SubSystem2::operate()
{
	cout << "SubSystem2 opt" << endl;
}
