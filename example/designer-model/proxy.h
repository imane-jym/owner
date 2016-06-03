/*
 * =====================================================================================
 *
 *       Filename:  proxy.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/03/2016 05:29:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __PROXY_H__
#define __PROXY_H__

class Subject
{
	public:
		virtual ~Subject() {}
		virtual void request() = 0;
	protected:
		Subject() {}
};

class SubSubject: public Subject
{
	public:
		SubSubject() {}
		~SubSubject() {}
		void request();	
};

class Proxy
{
	public:
		Proxy(Subject *Sub);
		~Proxy();
		void request();
	private:
		Subject *m_sub;
};
#endif
