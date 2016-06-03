/*
 * =====================================================================================
 *
 *       Filename:  proxy.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/03/2016 05:29:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include "proxy.h"
using namespace std;

void SubSubject::request()
{
	cout << "SubSubject request" << endl;
}

Proxy::Proxy(Subject *sub)
{
	m_sub = sub;
}

Proxy::~Proxy()
{
	delete m_sub;
}

void Proxy::request()
{
	cout << "proxy exec request from sub" << endl;
	m_sub->request();
}
