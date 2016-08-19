/*
 * =====================================================================================
 *
 *       Filename:  abstract_factor.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月01日 23时43分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "abstract_factory.h"
#include "product.h"
#include <iostream>
using namespace std;

ProductA* Group1Factory::createProductA()
{
	return new ProductA1();
}

ProductB* Group1Factory::createProductB()
{
	return new ProductB1();
}

ProductA* Group2Factory::createProductA()
{
	return new ProductA2();
}

ProductB* Group2Factory::createProductB()
{
	return new ProductB2();
}
