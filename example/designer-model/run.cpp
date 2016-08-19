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

<<<<<<< HEAD
#include "abstract_factory.h"

#include "command.h"
=======
#include "facade.h"

#include "flyweight.h"

#include "proxy.h"

#include "prototype.h"

#include "observer.h"

#include "visitor.h"

#include "state.h"
using namespace std;
>>>>>>> f8d130382bfba71f82f928fc251db59409d7dc7a

int main(int argc, char *argv[])
{
	CSingleton *one = CSingleton::getInstance();	

	cout << "<<< Factory pattern >>>" << endl;
	Factory *fact = new DeriveFactory();
	Product *p1 = fact->createProduct();
	p1->display();

<<<<<<< HEAD
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
=======
	cout << "<<< Facade pattern >>>" << endl;
	Facade *fa = new Facade();
	fa->operate();

	cout << "<<< Flyweight pattern >>>" << endl;
	FlyweightFactory *fwFactory = new FlyweightFactory();
	fwFactory->GetFlyweight("hello")->opt("world");
	fwFactory->GetFlyweight("haha")->opt("!!!");
	fwFactory->GetFlyweight("hello")->opt("world2");

	cout << "<<< Proxy pattern >>>" << endl;
	SubSubject *pSub = new SubSubject();
	Proxy *p2 = new Proxy(pSub);
	p2->request();

	cout << "<<< prototype pattern >>>" << endl;
	Prototype *prot = new SubPrototype();	
	Prototype *prot2 = prot->clone();

	cout << "<<< observer pattern >>>" << endl;
	OSubject *pOSub = new SubOSubject();
	ObserverA *pObA = new ObserverA();
	ObserverB *pObB = new ObserverB();
	pOSub->attach(pObA);
	pOSub->attach(pObB);
	pOSub->SetState("old");
	pOSub->notify();
	pOSub->SetState("new");
	pOSub->notify();
	
	cout << "<<< visitor pattern >>>" << endl;
	Visitor *pV = new SubVisitorA();
	Element *pE = new ElementA();
	pE->accept(pV);

	cout << "<<< state pattern >>>" << endl;
	State *pS = new StateA();
	Context *pSub3 = new Context(pS);
	pSub3->Operate();
	pSub3->Operate();
	pSub3->Operate();
>>>>>>> f8d130382bfba71f82f928fc251db59409d7dc7a
	return 0;
}
