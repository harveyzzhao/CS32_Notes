c++ has compile-time checking.
Inheritance: eliminate repetitiveness
How it works: group everything that shares something in common into one group.

//class hierarchies
//Shape - Superclass - generalization - BASE CLASS
	//Circle - subclass - specialization - DERIVED CLASS
	//Rectangle
    //We combine the common features of the derived classes into a feature in the base class
//language rules
	//Pointer/Object type conversions
		//Derived* ==> Base* - if I ask to bring a mammal, and you bring a dog, it works. We can pass in a parameter declared with base class type with a derived class pointer
		//Derived& ==> Base&

	//Heterogeneous collection: when we have a collection of different types under one container(usually of base class)

	//each derived class has a base class object embedded in it.
	//where is the base class object's address in the derived class object?
		//at the very top, because when the compiler automatically converts the derived objects into base class pointers/objects, it adds a constant to the top of the derived class pointer.
	//static-bound vs dynamic bound : the use of keyword "virtual" infront of the base class implementation
	//if static bound, any pre-created Circle object will correctly call its own draw() function, but any function called through f(Shape& s) will call the Shape's draw() function.
	//NEVER TRY OVERRIDING A NON-VIRTUAL FUNCTION!

class Shape
{
	virtual void move(double xnew, double ynew);    //we only make a function static-bound if we know absolutely that the function is the same across all classes.
	virtual void draw() const;
	double m_x;
	double m_y;
};

//the compiler recognizes that a derived class indeed belongs to the base class by add a constant 0 to the beginning of the memory of each object.

class Circle: public Shape	//a circle is a kind of Shape
{
	virtual void draw() const;	//override the implementation in Shape Class
	double m_r;
};

class Rectangle: public Shape	//A Rectangle is a kind of Shape
{
	virtual void draw() const;
    virtual double diag() const;    //since the diag() has the same formula across all shapes, we will
	double m_dx;
	double m_dy;
};

class WarningSymbol: public Shape
{
	virtual void move(double xnew, double ynew);
}

void Shape::move(double xnew, double ynew)
{
	m_x = xnew;
	m_y = ynew;
}

void Shape::draw() const
{

}

void Circle::draw() const
{
	...draw a circle of radius m_r...
}

void WarningSymbol::move(double xnew, double ynew)
{
	Shape::move(xnew, ynew);	//Specialization, the compiler will call the Shape's function first.
	...flash three times...
}



Shape* pic[100];

void f(Shape& x)
{
	x.move(10, 20);
	x.draw();
}

Circle c;
c.move(15, 5);  //an example of inheritance - circle is a derived class of shape
c.draw();   //if c has its own draw() function independent to its base class, it will call the correct function
f(c);

pic[0] = new Circle;
pic[1] = new Rectangle;
pic[2] = new Circle;

for (int k = 0; ...; k++)
	pic[k]->draw(); //if draw() isn't declared in the base class, then this code wouldn't compile because the compiler only knows what's inside the base class.

//static binding(done at compile time) vs dynamic binding(at run time) which body corresponds to that call. C++ has static binding by default. To enable dynamic binding, use the keyword "virtual" before the function declaration.
//You only have to declare virtual for the base class, but it will be helpful to declare virtual for the derived classes.

//NEVER ATTEMPT TO OVERRIDE A NON-VIRTUAL FUNCTION!


//each class will have its own virtual table that contains all functions that is declared virtual. They will be ordered from the base class's common functions to the individual functions.
//Each virtual table has slots that contains individual virtual functions and they point to each corresponding functions.

//how C++ compilers deal with recognizing which fnction to call once a function is declared virtual.
    //The compiler adds another virtual pointer that points to the correct class's virtual table, and every function will be invoked there.
example:
Shape* sp;
if (...)
    sp = new Shape;
else
    sp = new Rectangle;

sp->draw(); //call the function that sp->vptr[1] (in the virtual table) points to

//all functions have to be declared at the very base class: it will organize the virtual table in order and make sure it flows.

virtual void draw() const = 0;  //pure virtual function - THE CLASS BECOMES Abstract base class.
//***
//Once you declare a pure virtual function, its virtual table won't work and any attempt to
//allocate it dynamically or initialize an abstract base class will result in a compilation error.
//***

//if a derived class does not define the Pure Virtual function,
//the class will also be abstract base class and any attempt to declare it won't work.


//Polymorphism: same object with many types, multiple meanings for one function

class Shape
{
                                                //Shape::~Shape(){}  by default the destructor will not be virtual
    virtual ~Shape();
};

//if a class is designed to be a base classm, declare a destructor and make it virtual, and implement the destructor.
//However, if the base class is an abstract base class, do we need to make it virtual?
//YES. Look at the order of destruction. (Each derived class object contains a base class table)
//Step 1. Execute the body of the destructor
//2. Destroy the data members
//3. destroy the base part in the derived object.

//steps of construction
1. construct the base part (the base class table using the base classs constructor)
2. construct the data members
3. execute the body of the constructor

class Shape
{
public:
    Shape(double x, double y);
    virtual ~Shape();
    virtual void draw() const = 0;
private:
    double m_x;
    double m_y;
};

Shape::Shape(double x, double y)
    : m_x(x), m_y(y)
{}

class Circle: public Shape{
public:
    Circle(double r, double x, double y);
    Circle(double r);
    virtual void draw() const;
private:
    double m_r;
};

Circle::Circle(double r, double x, double y)
    : Shape(x, y), m_r(r)   //when the Circle class constructs its base class, it passes in a virtual pointer to the Circle class.
{
    if (r <= 0)
        ...
}

Circle::Circle(double r)
    ...





class Polygon: public Shape
{
    Node* head;
    ~Polygon();
};

class Circle: public Shape
{
public:
    Circle(double r, double x, double y);
    Circle(double r);
    virtual void draw() const;
private:
    double m_r;
};


//REMEMBER TO ALWAYS CONSTRUCT ANY BASE CLASS FIRST!
Circle::Circle(double r, double x, double y)
    : Shape(x, y), m_r(r)   /*m_x(x), m_y(y), m_r(r)*/   //causes an error because m_x and m_y belongs to the base class, which Circle class does NOT have access to
{   //calling the base class constructor passes another virtual pointer to Shape
    if (r <= 0)
        ...
}
Shape* sp;
if (...)
sp = new Polygon;
else
sp = ...;

delete sp;  //the compiler doesn't know what type sp is, and the compiler will only call the base class's destructor, resulting in memory leaks
