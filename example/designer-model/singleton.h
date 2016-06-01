/*
 * =====================================================================================
 *
 *       Filename:  singleton.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 01时30分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <iostream>

class CSingleton
{
	public:
		static CSingleton *getInstance();
	protected:
		static CSingleton* m_pInstance;
		CSingleton();
};

#endif
