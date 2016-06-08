/*
 * =====================================================================================
 *
 *       Filename:  observer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月08日 16时20分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "observer.h"
#include <iostream>
using namespace std;

void ObserverA::update(OSubject *ob)
{
	m_state = ob->GetState();
	dump();
}

void ObserverA::dump()
{
	cout << "ObserverA " << m_state << endl;
}

void ObserverB::update(OSubject *ob)
{
	m_state = ob->GetState();
	dump();
}

void ObserverB::dump()
{
	cout << "ObserverB " << m_state << endl;
}

void OSubject::notify()
{
	std::list<Observer *>::iterator it;
	for (it = m_list.begin(); it != m_list.end(); it++)
	{
		(*it)->update(this);
	}
}

void OSubject::attach(Observer *obv)
{
	m_list.push_front(obv);
}

void OSubject::detach(Observer *obv)
{
	m_list.remove(obv);
}

