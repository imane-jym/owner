/*
 * =====================================================================================
 *
 *       Filename:  factory.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2016 02:59:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "factory.h"
#include "product.h"

Factory::Factory()
{

}

Factory::~Factory()
{

}

Product* DeriveFactory::createProduct()
{
	return new Bike();
}
