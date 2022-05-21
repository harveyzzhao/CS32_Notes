class Circle
{
public:
	Circle(double x, double y, double r);
	void scale(double factor);
	void draw() const;

	//accessors:
	double radius() const;
private:
		//class invariant:
		//m_r >= 0
	double m_x;
	double m_y;
	double m_r;
};

double area(const Circle& x);

Circle::Circle(double x, double y, double r)
{
	if (m_r <= 0)
	{
		//for constructors, throw an exception if there is a problem in constructor
		cout << "cannot create a circle with radius " << r << endl;
		exit(1);
	}
		
	m_x = x;
	m_y = y;
	m_r = r;
}

//initializer list
Circle::Circle(double x, double y, double r)
	: m_x(x), m_y(y), m_r(r)	//member initializer list
{
	if (m_r <= 0)
	{
		//for constructors, throw an exception if there is a problem in constructor
		cout << "cannot create a circle with radius " << r << endl;
		exit(1);
	}
}

bool Circle::scale(double factor)
{
	if (factor <= 0) {return false;}
	m_r *= factor;
	return true;	//remember to always return a value in different cases.
}

double Circle::radius()
{
	return m_r;
}

//the implementation no longer compiles, because the Circle::radius() function is not const. 
//Only when you do that can you use a const reference.
double area(const Circle& x)
{
	const double PI = 4 * atan(1.0);
	return PI * x.radius() * x.radius();
}

#include <iostream>
using namespace std;

int main()
{
	Circle c(8, -3, 3.7);
	c.scale(2);
	c.draw();
	cout << area(c) << endl;
}




//////////example 2 - stick figure////////////
class StickFigure
{
public:
	StickFigure(double b1, double hd, string nm, double hx, double hy);
	..
private:
	string m_name;
	Circle m_head;
	double m_bodyLength;
};

StickFigure::StickFigure(double b1, double hd, string nm, double hx, double hy)
	: m_name(nm), m_head(hx, hy, hd/2), m_bodyLength(b1)	//since Circle class does not have a default constructor and initializer list 
																			//force call its DEFAULT constructor, we have to initialize it in the list.
{
	f (b1 <= 0 || hd <= 0)
		...error...
}

sf:
m_name;
m_head
	m_x,
	m_y,
	m_r;
m_bodyLength;

StickFigure sf(6, 4, "Fred", -2, 8);

