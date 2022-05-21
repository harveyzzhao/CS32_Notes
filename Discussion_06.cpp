Node* reverseList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	Node* res = reverseList(head->next);
	head->next->next = head;	//after you get all the way to the bottom of the call, there will only be two items, the current head pointer and the to-be head pointer. We set the 
	head->next = nullptr;//why wouldn't it be res->next?
	return res;
}

//template
#include <iostream>
#include <string>

template<typename Type1, typename Type2>
class Pair {
public:
	Pair(){	//be cautious on how you initialize the default types
		m_first = Type1();	// m_first = 0;
		m_second = Type2();	// m_second = "" ->this will not work if we choose type2 to be a double
	}
	Pair(Type1 first, Type2 second)
		: m_first(first), m_second(second){}
	void Set_Second(const Type2& second);
	Type1 Get_First() const;
	Type2 Get_Second() const {
		return m_second;
	}
private:
	Type1 m_first;
	Type2 m_second;
}

template<typename Type1, typename Type2>
void Pair<Type1, Type2>::Set_Second(const Type2& second)
{
	m_second = second;
}

template<typename Type1, typename Type2>
Type1 Pair<Type1, Type2>::Get_First() const {
	return m_first;
}


template<typename T>
//T can be int, bool, string, Pair, ...

//FIXED SOLUTION:
template<typename Type1, typename Type2>
bool operator>(const Pair<Type1, Type2>& a, const Pair<Type1, Type2>& b) {
	return a.Get_First() > b.Get_First();
}

bool Greater(const T&a, const T& b)
{
	if (a > b) {	//the greater than operator only works on the primary types of C++. Otherwise we wouldn't know which one is greater
		cout < "Yes\n";
		return true;
	}
	cout <<  "No\n";
	return false;
}

//Standard Template Library (STL)
	Ctype<EType> c;
	e.g. queue<Pair<string, double>> c;

//popular member functions:
vector<EType> v;
int main()
{
	vector<int> v;
	//inserts 15 to the last position
	v.push_back(15);
	int n = v.size();
	cout << "\n the last element is: " << v[n-1];
	//removes last element
	v.pop_back;
	v.push_back(3);
	cout << v.at(1);
}

//using iterator to iterate through the functions
Ctype<Etype>::iterator it;
using it++ to go to the next element;
get the element *it;

//traverse elements of an integer vecotr v;
vector<int>::iterator it;
for (it = v.begin(); it != v.end(); ++it)
{
	cout << *it << endl;
}

list<int>::iterator it = l.begin();
while(it != l.end())
{
	if ((*it) == val)
		it = l.erase(it);
	else
		it++;
}

int main()
{
	vector<int> vec = {10, 20, 30, 40};
	vector<int>::iterator it;
	it = vec.insert(vec.begin(), 3); //it set to the beginning of the array, vec set to 3, 10, 20, 30, 40
	vec.insert(it, 2);	//
	int i = 2;
	it = vec.insert(vec.begin() + i, 7);
	cout << "The vector elements are: ";
	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << *it << endl;
}