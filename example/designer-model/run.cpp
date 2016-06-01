/*
 * =====================================================================================
 *
 *       Filename:  run.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月31日 01时32分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "singleton.h"

#include "product.h"
#include "factory.h"

int main(int argc, char *argv[])
{
	CSingleton *one = CSingleton::getInstance();	

	Factory *fact = new DeriveFactory();
	Product *p1 = fact->createProduct();
	p1->display();
	return 0;
}
