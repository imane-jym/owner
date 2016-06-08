/*
 * =====================================================================================
 *
 *       Filename:  prototype.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月08日 14时38分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

class Prototype
{
	public:
		virtual ~Prototype() {};
		virtual Prototype* clone() = 0;
	protected:
		Prototype() {};
};

class SubPrototype: public Prototype
{
	public:
		virtual ~SubPrototype() {};
		virtual Prototype* clone();
		SubPrototype() {};
};

#endif
