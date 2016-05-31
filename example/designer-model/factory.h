/*
 * =====================================================================================
 *
 *       Filename:  factory.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2016 02:59:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __FACTORY_H__
#define __FACTORY_H__

class Product;

class Factory
{
	public:
		virtual ~Factory();
		virtual Product* createProduct() = 0;
	protected:
		Factory();
};

class DeriveFactory: public Factory
{
	public:
		Product* createProduct();
};

#endif
