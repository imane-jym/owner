/*
 * =====================================================================================
 *
 *       Filename:  facade.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/02/2016 03:47:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __FACADE_H__
#define __FACADE_H__

class SubSystem1
{
	public:
		SubSystem1() {}
		~SubSystem1() {}
		void operate();
};

class SubSystem2
{
	public:
		SubSystem2() {}
		~SubSystem2() {}
		void operate();
};

class Facade
{
	public:
		Facade();
		~Facade();
		void operate();

	private:
		SubSystem1 *m_sys1;
		SubSystem2 *m_sys2;
};
#endif
