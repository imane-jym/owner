/*
 * =====================================================================================
 *
 *       Filename:  singleton.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 01时29分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "singleton.h"

CSingleton *CSingleton::m_pInstance = NULL;

CSingleton::CSingleton()
{

}

CSingleton *CSingleton::getInstance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CSingleton();
	}
	return m_pInstance;
}
