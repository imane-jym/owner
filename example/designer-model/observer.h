/*
 * =====================================================================================
 *
 *       Filename:  observer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月08日 16时20分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include <string>
#include <list>

class OSubject;

class Observer
{
	public:
		virtual ~Observer() {};
		virtual void update(OSubject *sub) = 0;
		virtual void dump() = 0;
	protected:
		Observer() {};
		std::string m_state;
};

class ObserverA: public Observer
{
	public:
		ObserverA() {};
		~ObserverA() {};
		void update(OSubject *sub);
		void dump();
};

class ObserverB: public Observer
{
	public:
		ObserverB() {};
		~ObserverB() {};
		void update(OSubject *sub);
		void dump();
};

class OSubject
{
	public:
		virtual ~OSubject() {};
		virtual void notify();
		virtual void attach(Observer *obv);
		virtual void detach(Observer *obv);
		virtual void SetState(std::string a) = 0;
		virtual std::string GetState() = 0;
	protected:
		OSubject() {};
	private:
		std::list<Observer *> m_list;
};

class SubOSubject: public OSubject
{
	public:
		SubOSubject() {};
		~SubOSubject() {};
		void SetState(std::string a) { m_state = a;}
		std::string GetState() { return m_state;}
	private:
		std::string m_state;
};

#endif
