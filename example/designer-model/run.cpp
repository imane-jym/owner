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

#include "abstract_factory.h"

#include "command.h"

int main(int argc, char *argv[])
{
	CSingleton *one = CSingleton::getInstance();	

	Factory *fact = new DeriveFactory();
	Product *p1 = fact->createProduct();
	p1->display();

	AbstractFactory *abs1One = new Group1Factory();
	abs1One->createProductA();
	abs1One->createProductB();

	AbstractFactory *abs2One = new Group2Factory();
	abs2One->createProductA();
	abs2One->createProductB();

	Reciever *pRev = new Reciever();
	Command *pComm = new SubCommand(pRev);
	Invoke in(pComm);
	in.Action();

	Command *pComm2 = new SimpleCommand<Reciever>(pRev, &Reciever::Action);
	pComm2->act();
	return 0;
}
