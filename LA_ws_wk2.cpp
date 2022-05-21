int main() {
	A arr[3];	//DC\nDC\nDC\n
	arr[0] = arr[1]; //AO\n
	A x = arr[0]; //CC\n
	x = arr[1]; //AO\n
	A y(arr[2]); //CC\n
	cout << "DONE" << endl;
	Destructor! * 5
}

//Question 2.
#include <iostream>
#include <string>
using namespace std;

class Account {
public:
	Account(int x) {
		cash = x;
	}
	int cash;
};	//problem 4, missing a semicolon at the end of the account class.

class Billionaire {
public:
	you need to use initializer list to initialize the variable offshore 
	because there is no default constructor for it.
	Billionaire(string n){
		offshore = Account(1000000000);
		name = n;
	}

	Billionaire(string n)
		: account(10000)	/*problem, not initialized*/, name(n)
		{
			offshore = new Account(1000000000); //didn't have a "new"
		}

	//problem: no destructor
	~Billionaire()
	{
		delete offshore;
	}
	Account account;
	Account* offshore;
	string name;
};

int main() 
{
	Billionaire jim = Billionaire("Jimmy");
	cout << jim.name << " has "
	<< jim.account.cash + jim.offshore->cash << endl;
}
//the number doesn't add up. cash needs to be 10000.

Output: Jimmy has 1000010000


//problem 3:

#include <iostream>
using namespace std;
class B {
	int m_val;	//by definition, it is a private variable.
public:
	B(int x): m_val(x) {cout << "Wow such " << x << endl;}
	B(const B& other) {
		cout << "There's another me???" << endl;
		m_val = other.m_val;
	}
	~B() {
		cout << "Twas a good life" << endl;
	}
};

class A {
	int m_count;
	B* m_b;
public:
	A(): m_count(9.5) {
	cout << "Construct me with " << m_count << endl;
	m_b = new B(m_count+10);
}
	A(const A& other) {
		cout << "Copy me" << endl;
		m_count = other.m_count;
		m_b = (other.m_b != nullptr) ? new B(*other.m_b) : nullptr;
	}
	~A() {
		cout << "Goodbye cruel world" << endl;
		if (m_b)
			delete m_b;
	}
	int getCount() { return m_count; }
};

int main() {
	A a1, a2;
	A a3 = a2;
	B b1(a3.getCount());
	cout << "Where are we?" << endl;
}

/*
Construct me with 9
Wow such 19
Construct me with 9
Wow such 19
Copy me
There's another me???
Wow such 9
Where are we?
Twas a good life

Goodbye cruel world
Twas a good life

Goodbye cruel world
Twas a good life

Goodbye cruel world
Twas a good life
*/

//problem 4
class A
{
public:
	A(int sz)
		: n(sz)
	{
		arr = new int [n];
		b = new B();
	}

	A(const A& other)
	{
		n = other.n;
		str = other.str;
		b = nullptr ? nullptr : other.b;
		arr = new int [n];
		for (int i = 0; i < n; i++)
			arr[i] = other.arr[i]; 
	}

	A& operator=(const A& other)
	{
		if (this != other)
		{
			b = other.b;
			delete [] arr;
			str = other.str;
			n = other.n;
			arr = new int [n];
			for (int i = 0; i < n; i++)
				arr[i] = other.arr[i];
		}
		return *this;
	}

	~A()
	{
		delete b;
		delete [] arr;
	}
private:
	B* b;
	int* arr;
	int n;
	string str;
}


//Question 5.
#include <iostream>
#include <string>
using namespace std;

class Account {
public:
	Account(int x) {
		cash = x;
	}
	Account(const Account& other)
	{
		cash = other.cash;
	}

	Account& operator=(const Account& other)
	{
		if (this != other)
		{
			cash = other.cash;
		}
		return *this;
	}
	int cash;
};	//problem 4, missing a semicolon at the end of the account class.

class Billionaire {
public:
	Billionaire(string n)
		: account(10000)	/*problem, not initialized*/, name(n)
		{
			offshore = new Account(1000000000); //didn't have a "new"
		}
	Billionaire& operator=(const Billionaire& other)
	{
		if (this != other)
		{
			account = other.account;
			offshore = new Account(*other.offshore);	//	Should I do this?
			name = other.name;
		}
		return this;
	}
	
	~Billionaire()
	{
		delete offshore;
	}
	Account account;
	Account* offshore;
	string name;
};

int main() {
	Billionaire jim = Billionaire("Jimmy");
	Billionaire jimClone = jim;

	cout << jimClone.name << " has "
	<< jimClone.account.cash + jimClone.offshore->cash
	<< endl;

	cout << jim.name << " has "
	<< jim.account.cash + jim.offshore->cash << endl;
}

Output: Jimmy has 0
Jimmy has 1000010000

