/*
 * =====================================================================================
 *
 *       Filename:  product.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2016 02:46:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "product.h"
#include <iostream>
using namespace std;

Product::Product()
{

}

Product::~Product()
{

}

Bike::Bike()
{

}

Bike::~Bike()
{

}

void Bike::display()
{
	cout << "it is bike" << endl;
}

ProductA1::ProductA1()
{
	cout << "ProductA1 construct" << endl;
}

ProductA1::~ProductA1()
{
	cout << "ProductA1 destruct" << endl;
}

ProductA2::ProductA2()
{
	cout << "ProductA2 construct" << endl;
}

ProductA2::~ProductA2()
{
	cout << "ProductA2 destruct" << endl;
}

ProductB1::ProductB1()
{
	cout << "ProductB1 construct" << endl;
}

ProductB1::~ProductB1()
{
	cout << "ProductB1 destruct" << endl;
}

ProductB2::ProductB2()
{
	cout << "ProductB2 construct" << endl;
}

ProductB2::~ProductB2()
{
	cout << "ProductB2 destruct" << endl;
}
