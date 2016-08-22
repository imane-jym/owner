/*
 * =====================================================================================
 *
 *       Filename:  abstract_factor.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月01日 23时43分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__
class ProductA;
class ProductB;
class AbstractFactory
{
	public:
		virtual ProductA* createProductA () = 0;
		virtual ProductB* createProductB () = 0;
		virtual ~AbstractFactory() {}
	protected:
		AbstractFactory() {}
};

class Group1Factory: public AbstractFactory
{
	public:
		Group1Factory() {};
		~Group1Factory() {};
		ProductA* createProductA ();
		ProductB* createProductB ();
};

class Group2Factory: public AbstractFactory
{
	public:
		Group2Factory() {};
		~Group2Factory() {};
		ProductA* createProductA ();
		ProductB* createProductB ();
};
#endif
