/*
 * =====================================================================================
 *
 *       Filename:  command.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月07日 23时49分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __COMMAND_H__
#define __COMMAND_H__
#include <iostream>
class Reciever	 
{
	public:
		Reciever() {}
		~Reciever() {}
		void Action();
};

class Command
{
	public:
		virtual ~Command() {};
		virtual void act() = 0;
	protected:
		Command() {}
};

class SubCommand: public Command
{
	public:
		SubCommand(Reciever *p) { m_pRev = p; }
		~SubCommand() { delete m_pRev; m_pRev = NULL; }
		void act();
	private:
		Reciever *m_pRev;
};

class Invoke
{
	public:
		Invoke(Command *pComm) { m_pComm = pComm; }
		~Invoke() { delete m_pComm; m_pComm = NULL; }
		void Action();
	private:
		Command *m_pComm;
};

template<class T>
class SimpleCommand: public Command
{
	public:
		typedef	void (T::*Act)();
		SimpleCommand(T* rev, Act f) {m_rev = rev; m_f = f;}
		~SimpleCommand() { delete m_rev; }
		void act()
		{
			std::cout << "SimpleCommand act" << std::endl;
			(m_rev->*m_f)();
		}
	private:
		T *m_rev;
		Act m_f;
};
#endif
