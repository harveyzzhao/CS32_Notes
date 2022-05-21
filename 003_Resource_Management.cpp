void h()
{
	string s("Hello");
	string t;
	...
}

class string
{
public:
	string(const char* value = "");	//default value being the default constructor
	string(const string& other);	//passed by reference, NOT BY VALUE -> infinite reference because the parameter needs to be copied too:((.
	// string();
	~string
	...
private:
	//class invariant:
		//	m_text is a pointer to a dynamically allocated array of m_len+1 characters
		//	m_len >= 0
		//	m_len == strlen(m_text)
	char* m_text;
	int m_len;
};

string::string(const char* value)	//incorrect implementation
{
	m_text = value;
	m_len = strlen(value);
}

instead, do this
string::string(const char* value)
{
	//assume nullptr represents an empty string
	if (value == nullptr)
	{
		value = "";
	}
	m_len = strlen(value);
	m_text = new char[m_len + 1];
	strcpy(m_text, value);	//strcpy takes in two pointers to characters, the first one being the recipient and the second being the giver.
}

always think about when someone passes in a nullptr.
think about writing a destructor every time.	
//we can try tweaking the default constructor and merge it with the custom constructor.
// string::string()
// {
// 	m_len = strlen("");
// 	m_text = new char[m_len + 1];
// 	strcpy(m_text, "");
// }

string::~string()
{
	delete [] m_text;
}

String::String(const String& other)
{
	m_len = other.m_len;	//NOT ONLY COPY CONSTRUCTOR, BUT ANY MEMBER FUNCTION of a certain class can call the private variables of all of its types
	m_text = new char[m_len + 1];
	strcpy(m_text, other.m_text);
}

String x(s);
String x = s;
passing a String by value to a function
returning a value from a function(not a pointer or reference)

String boo()	//as you can observe, String is a standalone value return type. 
					//No reference & and no pointer symbol *
{
	String result;
	...
	...
	return result;
}

//assignment operator - the compiler-generated assignment operator only handles manually copying values.
String& /*String& reason: a = (b = c) and the type of c is String&*/operator=(const String& rhs)
{
	if (this != &rhs)	//if the copied object is not the same with the recipient, do the following
	{
		delete [] m_text;
		m_text = new char[rhs.m_len + 1];
		strcpy(m_text, rhs.m_text);
		m_len = rhs.m_len;
	}
	return *this;
}

//BONUS: //v = (u = s); v.operator=(u.operator=(s));
//u = s; u.operator=(s);	this points to u, rhs is a reference to s.


//////////////////////////////
//modern assignment operator//
/////////////////////////////
//prevents memory leaks and allocating new memory without regard for its capacity.
void String::swap(String& other)
{	//copy and swap approach
	//swap m_text and other.m_text
	char* temp_m_text = m_text;
	m_text = other.m_text;
	other.m_text = temp_m_text;

	int temp_m_len = m_len;
	m_len = other.m_len;
	other.m_len = temp_m_len;
}

String& operator=(const String& rhs)
{
	if (this != &rhs)	//compare pointers address, not the objects themselves. The cost of checking is greater for values than address
	{
		String temp(rhs);
		swap(temp);
	}
	return *this;
}

// = is just a shorthand of .operator= when overloaded.
//"aliasing" - two or more ways to talk about the same object. - look out for two pointers or references to the same type - aliasing might occur

void transfer(Account& from, Account& to, double amt)
{
	if (amt > from.balance())
		exit(1);
	else
	{
		from.debit(amt);
		to.credit(amt);
	}
}
