#include <cstring>

String S("Hello")

class String
{
public:
	String(const char* str = "");
	~String(){}
	String(const String& other)
	...

private:
	int m_len;
	char* m_content;
}

String::String(const char* str)
{
	if (str == nullptr)
		str = "";
	m_len = strlen(str);
	char = str;
}

copy constructor
void f(String t)
{
	...
}

void h()
{
	String s("Hello");
	f(s);
	...
}

String::String(const String& rhs)
{
	m_len = rhs.m_len;
	m_content = new String[m_len + 1];
	strcpy(m_text, rhs.m_text);
}

//when is copy constructor called?
String x(s);
String x = s;
When passing by value
Returning a value of a function

//assignment operator

//traditional way - relies on memory allocation and might result in errors if the memory is full
String& operator=(const String& rhs)
{
	if (this != rhs)
	{
		delete [] m_text;
		m_len = rhs.m_len;
		m_text = new char[m_len + 1];
		strcpy(m_text, rhs.m_text);
	}
	return *this;
}

//modern way - relies on the swap function
void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}


