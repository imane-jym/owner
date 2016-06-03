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

#include "facade.h"

#include "flyweight.h"

#include "proxy.h"
using namespace std;

int main(int argc, char *argv[])
{
	CSingleton *one = CSingleton::getInstance();	

	cout << "<<< Factory pattern >>>" << endl;
	Factory *fact = new DeriveFactory();
	Product *p1 = fact->createProduct();
	p1->display();

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
	return 0;
}
