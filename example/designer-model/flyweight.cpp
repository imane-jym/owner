/*
 * =====================================================================================
 *
 *       Filename:  fly_weight.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/03/2016 01:40:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "flyweight.h"
#include <iostream>
#include <string>
using namespace std;

Flyweight::Flyweight(const std::string &s):m_state(s)
{
}

Flyweight::~Flyweight()
{
}

SubFlyweight::SubFlyweight(const std::string &s):Flyweight(s)
{
}

SubFlyweight::~SubFlyweight()
{
}

void SubFlyweight::opt(const std::string &para)
{
	cout << "inner state " << GetState() <<  " out state " << para << endl;
}

Flyweight* FlyweightFactory::GetFlyweight(const std::string &s)
{
	std::map<std::string, Flyweight*>::iterator it = m_mapFw.find(s);
	if (it != m_mapFw.end())
	{
		cout << "already create obj " << s << endl;
		return it->second;	
	}
	Flyweight *p = new SubFlyweight(s);
	m_mapFw[s] = p;
	return p;
}
