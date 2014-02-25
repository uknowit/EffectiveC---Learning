/*
 * Item36.hpp
 *
 *  Created on: Feb 24, 2014
 *      Author: shashi
 */

#ifndef ITEM36_HPP_
#define ITEM36_HPP_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <tr1/functional>

/* Template method pattern via Non-virtual interface Idiom*/
class Shape
{
public:
	void drawImpl()
	{
		draw();
	}
private:
	virtual void draw()
	{
		std::cout<<"Calling draw of base==>"<<std::endl;
	}
};

class Circle:public Shape
{
private:
	virtual void draw()
	{
		std::cout<<"Calling draw of Circle......."<<std::endl;
	}
};

class Square:public Shape
{
private:
	virtual void draw()
	{
		std::cout<<"Calling draw of Square #########"<<std::endl;
	}

};

/*Strategy Pattern*/

class GameCharacter;
int defaultHealthCalc(const GameCharacter&);
class GameCharacter
{
public:
	typedef int (*HealthCalc)(const GameCharacter&);
	explicit GameCharacter(HealthCalc hc=defaultHealthCalc)
	:healthCalc(hc)
	 {}
	 int healthValue()const {return healthCalc(*this);}
private:
	HealthCalc healthCalc;
};


class EvilBadGuy:public GameCharacter
{
public:
	explicit EvilBadGuy(HealthCalc hcl = defaultHealthCalc)
	:GameCharacter(hcl){}
};

/*strategy pattern with tr1::function*/

class GameCharcterTemplate;
int defaultHealthFuncTemp(const GameCharcterTemplate&);

class GameCharcterTemplate {
public:
	typedef std::tr1::function<int (const GameCharcterTemplate&)> HealthCalcFuncTemp;
	explicit GameCharcterTemplate(HealthCalcFuncTemp hcf= defaultHealthFuncTemp)
	:healthFuncTemp(hcf){}
	int healthValue() const
	{return healthFuncTemp(*this);}

private:
	 HealthCalcFuncTemp healthFuncTemp;
};

class GameLevel {
public:
	float health(const GameCharcterTemplate&)const
	{
		std::cout<<"As always doing nothing.."<<this<<std::endl;
		return 0;
	}
};

class EvilBadGuyTemplate:public GameCharcterTemplate
{
public:
	explicit EvilBadGuyTemplate(HealthCalcFuncTemp hcl = defaultHealthFuncTemp):GameCharcterTemplate(hcl){}
};
#endif /* ITEM36_HPP_ */
