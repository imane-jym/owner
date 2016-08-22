/*
 * =====================================================================================
 *
 *       Filename:  command.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月07日 23时48分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "command.h"
#include <iostream>
using namespace std;

void Reciever::Action()
{
	cout << "Reciever action" << endl;
}

void SubCommand::act()
{
	cout << "SubCommand act" << endl;
	m_pRev->Action();
}

void Invoke::Action()
{
	cout << "invoke act" << endl;
	m_pComm->act();
}
