/*
 * =====================================================================================
 *
 *       Filename:  state.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月16日 14时13分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __STATE_H__
#define __STATE_H__
class State;
class Context
{
	public:
		Context(State *p) { m_pS = p; }
		~Context() {};
		void ChangeState(State *p) { m_pS = p; }
		void Operate();
	private:
		State *m_pS;
};

class State
{
	public:
		virtual ~State() {}
		virtual void OperateChangeState(Context *p) = 0;
	protected:
		State() {};
};

class StateA: public State
{
	public:
		 ~StateA() {}
		void OperateChangeState(Context *p);
		StateA() {};
};

class StateB: public State
{
	public:
		 ~StateB() {}
		void OperateChangeState(Context *p);
		StateB() {};
};
#endif
