/*
 * =====================================================================================
 *
 *       Filename:  state.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月16日 14时13分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include "state.h"
using namespace std;

void Context::Operate()
{
	m_pS->OperateChangeState(this);
}

void StateA::OperateChangeState(Context *p)
{
	cout << "stateA opt" << endl;
	p->ChangeState(new StateB());
}

void StateB::OperateChangeState(Context *p)
{
	cout << "stateB opt" << endl;
	p->ChangeState(new StateA());
}
