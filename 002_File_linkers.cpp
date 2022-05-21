Point.h
======
#ifndef POINT_INCLUDED
#define POINT_INCLUDED
class point
{
	...
};
#endif	//POINT_INCLUDED

Circle.h
========
#ifndef CIRCLE_INCLUDED
#define CIRCLE_INCLUDED
class Circle
{
	...
private:
	Point m_center;
	double m_radius;
};
#endif //CIRCLE_INCLUDED

myapp.cpp
========
#include "Circle.h"
#include "Point.h" - COMPILATION error without the include guard due to multiple declaration.
int main()
{
	Circle c(-2, 5, 10);
	...
}

to avoid multiple declaration, use #include guard

#ifndef XXX - If the name has not yet been defined before
#define XXX	- serves as a marker 

