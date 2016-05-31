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
#endif
