"I'm a living thing"

void LL::deleteList(Node* p)
{
	if (head == nullptr)
		return;
	Node* p = head;
	head = head->next;
	delete p;
	deleteList(head);
}

void LL::deleteListHelper(Node* &head)
{
	if (head == nullptr)
		return;
	deleteListHelper(head->next);
	------------------------------
	delete head;
	head = nullptr;
}

void LL::deleteList()
{
	deleteListHelper(m_head);
}

//Method 2 of Problem 1
void LL::deleteList()
{
	if (head == nullptr)	return;
	Node* tmp = head;
	head = head->next;
	delete tmp;
	deleteList();
}



LA_Power(6, 2)
LA_Power(6 + 6, 1) 
LA_power(12 + 12, 0) + 24 = 0 + 12


I'm a living thing
add virtual to virtual void intro()

Problem 2
~Pet
Dog ran away!

Problem 4
No it won't. Class A would have to contain a virtual table for B and B will have to contain a virtual table for A. Whenever we call a function this would lead to circular operations(infinite)

Woof
Dog ran away!

//problem 2 recursion
bool isPalindrome(string foo)
{
	return isPalindromeHelper(foo, 0, foo.length() - 1);
}

bool isPalindromeHelper(string foo, int begin, int end)
{
	if (begin >= end)	return true;
	if (foo.at(begin) != foo.at(end))	return false;
	return isPalindromeHelper(foo, begin+1, end-1);
}

//problem 3 isPrime()
bool isPrime(int num)
{
	return isPrimeHelper(num);
}

bool isPrimeHelper(int num, int divisor = 2)
{
	if (divisor * divisor > num)	return true;	//important base case
	else if (num % divisor == 0)	return false;
	return isPrimeHelper(num, divisor + 1);
}

//problem 4 return the longest common subsequence of chars between s1 and s2
string longestCommonSubsequence(string ogs1, string ogs2,  s1, string s2)
{
	//base case 1
	if (s1.length() <= 0)	return "";
	else if (s2.length() <= 0)	return longestCommonSubsequence(ogs1, ogs2, s1+1, ogs2);
	if (s1[0] != s2[0])	return longestCommonSubsequence(ogs1, ogs2, s1, s2+1);
	else if (s1[0] == s2[0])	return s1[0] + longestCommonSubsequence(ogs1, ogs2, s1+1, s2+1);
}


//inheritance and polymorphism practice
class Animal {
public:
	Animal(string name) : m_name(name);
private:
	string m_name;
};

class Cat : public Animal {
public:
	Cat(string name, int amountOfYarn) : Animal(name), m_amountOfYarn(amountOfYarn);
private:
	int m_amountOfYarn;
};

class Himalayan : public Cat {
public:
	Himalayan(string name, int amountOfYarn) : Cat(name, amountOfYarn);
};

class Siamese: public Cat {
public:
	Siamese(string name, int amountOfYarn, string toyName) : Himalayan(name, amountOfYarn), m_toyName(toyName);
private:
	string m_toyName;
};

//question 2
class LivingThing {
private:
	int age;
};

class Person : public LivingThing {
public:
	Person(int a) { age = a; }
	void birthday() {
		age++;
	}
};

//the derived class Person has no permission to access any private variables or functions of the base class LivingThing.
Therefore, both the constructor and birthday() function for LivingThing would not run.


//recursive additional practice Q2
Node* merge(Node* l1, Node* l2)	//supply l2 into l1
{
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;

	if (l1->val <= l2->val)
	{
		head = l1;
		head->next = merge(l1->next, l2);
	}
}

