/*
 * Item36.cpp
 *
 *  Created on: Feb 24, 2014
 *      Author: shashi
 */

#include "Item36.hpp"
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

using std::cout;
using std::ostream_iterator;
using std::equal_to;
using std::unique;
using std::tr1::bind;
using namespace std::tr1::placeholders;

typedef int elt;
typedef array<elt, 7> arr;
typedef arr::iterator arr_it;

template <class Func>
void apply(Func func)
{ // use func to eliminate duplicates in a range
  arr data = { 1, 1, 2, 3, 3, 3, 5 };
  arr_it end = unique(data.begin(), data.end(), func);
  copy(data.begin(), end, ostream_iterator<elt>(cout, " "));
  cout << '\n';
}

template <class Binder>
void show(Binder binder)
  { // apply bind object
  int i = 1;
  double d = 2.1;
  binder(i, d);
  }

void display(int val)
  { // bound function
  cout << val << '\n';
  }
int main()
{
	cout<<"It is not end... its end of begining..."<<endl;
	Circle circleImpl;
	Square squareImpl;
	Shape* shapePointer=&circleImpl;
	Shape* anotherShapePointer=&squareImpl;
	shapePointer->drawImpl();
	anotherShapePointer->drawImpl();
	GameLevel currentLevel;
	EvilBadGuyTemplate eng1(std::tr1::bind(&GameLevel::health,&currentLevel,std::tr1::placeholders::_1));
	/*
	 * The template function bind creates call wrappers that can have a different number of arguments
	 * and a different order of arguments from their target object.
	 * It's a generalization of the functions std::bind1st and std::bind2nd.
	 * Where each function from the Standard Library binds exactly one argument at a fixed position, bind binds as many arguments as you want (up to an implementation-specific limit) in any position you want.
	 * When you call bind, the first argument is the callable object that will be the target object of the returned object.
	 * There must be as many additional arguments in the call to bind as there are arguments to the callable object.
	 * These additional arguments tell bind how to determine the actual argument to be passed to the callable object.
	 * When the actual argument is simply a value, that value is passed to the callable object.
	 * When the actual argument is a placeholder (placeholders are named _1, _2, and so on, up to an implementation-specific limit), the value passed to the call wrapper's function call operator is passed to the callable object.
	 * For example, the call bind(cos, 1.0) creates an object whose function call operator ignores its arguments and returns cos(1.0).
	 * The call bind(cos, _1) returns an object whose function call operator ignores all its arguments except the first and returns
	 * the result of calling cos with its first argument [8]
	 * More Info @ http://www.drdobbs.com/c-function-objects-in-tr1/184401949?pgno=1
	 * position of this http://www.learncpp.com/cpp-tutorial/87-the-hidden-this-pointer/
	 */
	eng1.healthValue();
	apply(equal_to<int>());
	show(std::tr1::bind(display, _2));
}
