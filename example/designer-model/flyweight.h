/*
 * =====================================================================================
 *
 *       Filename:  fly_weight.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/03/2016 01:40:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _FLY_WEIGHT_H_
#define _FLY_WEIGHT_H_
#include <map>
#include <string>

class Flyweight
{
	public:
		virtual ~Flyweight();
		virtual void opt(const std::string &para) = 0;
		std::string GetState() { return m_state; }
	protected:
		Flyweight(const std::string &s);
	private:
		std::string m_state;
};

class SubFlyweight: public Flyweight
{
	public:
		SubFlyweight(const std::string &s);
		~SubFlyweight();
		void opt(const std::string &para);
};

class FlyweightFactory
{
	public:
		FlyweightFactory() {}
		~FlyweightFactory() {}
		Flyweight *GetFlyweight(const std::string &s);
	private:
		std::map<std::string, Flyweight*> m_mapFw;
};
#endif
