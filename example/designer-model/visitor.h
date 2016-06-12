/*
 * =====================================================================================
 *
 *       Filename:  visitor.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月12日 15时32分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __VISITOR_H__
#define __VISITOR_H__

class Visitor
{
	public:
		virtual ~Visitor() {};
		virtual void visitA() = 0;
		virtual void visitB() = 0;
	protected:
		Visitor() {};
};

class SubVisitorA: public Visitor
{
	public:
		virtual ~SubVisitorA() {};
		virtual void visitA();
		virtual void visitB();
		SubVisitorA() {};
};

class SubVisitorB: public Visitor
{
	public:
		virtual ~SubVisitorB() {};
		virtual void visitA();
		virtual void visitB();
		SubVisitorB() {};
};

class Element
{
	public:
		virtual ~Element() {};
		virtual void accept(Visitor *v) = 0;
	protected:
		Element() {};
};

class ElementA: public Element
{
	public:
		ElementA() {};
		~ElementA() {};
		void accept(Visitor *v);
};
#endif
