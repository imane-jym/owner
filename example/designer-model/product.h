/*
 * =====================================================================================
 *
 *       Filename:  product.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2016 02:46:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __PRODUCT_H__
#define __PRODUCT_H__

class Product
{
	public:
		virtual ~Product();
		virtual void display() = 0;
	protected:
		Product();
};

class Bike: public Product
{
	public:
		Bike();
		~Bike();
		void display();
};

class ProductA
{
	public:
		virtual ~ProductA(){}
	protected:
		ProductA() {}
};

class ProductA1: public ProductA
{
	public:
		~ProductA1();
		ProductA1();
};

class ProductA2: public ProductA
{
	public:
		~ProductA2();
		ProductA2();
};

class ProductB
{
	public:
		virtual ~ProductB(){}
	protected:
		ProductB() {}
};

class ProductB1: public ProductB
{
	public:
		~ProductB1();
		ProductB1();
};

class ProductB2: public ProductB
{
	public:
		~ProductB2();
		ProductB2();
};
#endif
