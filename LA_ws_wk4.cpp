#include <stack>
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

bool isValid(string parens)
{
    stack<char> m_stack;
    for (auto ch : parens)
    {
        switch(ch)
        {
            case '(':
            case '[':
                m_stack.push(ch);
                break;
            case ')':
                //pop until you see the same symbol. If there is any other symbols, return false;
                if (m_stack.empty() || m_stack.top() != '(')    return false;
                m_stack.pop();
                break;
            case ']':
                if (m_stack.empty() || m_stack.top() != '[')    return false;
                m_stack.pop();
                break;
            default:
                return false;
        }
    }
    if (!m_stack.empty())    return false;
    return true;
}

int main()
{
    //test isValid()
    assert(isValid("(((") == false);
    assert(isValid("") == true);
    assert(isValid("[()[[([][])]]]") == true);
    assert(isValid("((([(]))))") == false);
    assert(isValid("(()))") == false);
    assert(isValid("()[]") == true);
    assert(isValid("(([[]])") == false);
    cout << "all tests passed." << endl;
}


//problem 2
#include <iostream>
#include <cassert>
#include <queue>
#include <stack>
using namespace std;

//push the existing items in the queue to the stack
//pop each item in the queue once you push it to the queue
//
//while (!m_stack.empty())
//{
//    m_queue.push(m_stack.top());
//    m_stack.pop();
//}


void reverseQueue(queue<int>& Q)
{
    stack<int> s;
    while(!Q.empty())
    {
        s.push(Q.front());
        Q.pop();
    }

    while(!s.empty())
    {
        Q.push(s.top());
        s.pop();
    }
}


//problem 3. REVIEW THIS PROBLEM.
void findNextInts(const int sequence[], int results[], int n)
{
    if (n <= 0) return;
    stack<int> s;
    //push the 1st index in sequence to stack
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        //TODO: How did you come up with such a clever solution???
        while (!s.empty() && sequence[i] > sequence[s.top()])
        {
            results[s.top()] = sequence[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())
    {
        results[s.top()] = -1;
        s.pop();
    }
}

//problem 5
class Stack
{
public:
	bool empty() cosnt;
	size_t size() const;
	it top() const;
	void push(cosnt int& value);
	void pop();
private:
	queue<int> storage;
};

bool stack::empty() const {
	return storage.empty();
}

size_t Stack::size() const {
	return storage.size();
}

int Stack::top() const {
	return storage.back();
}

void Stack::push(const int& value) {
	storage.push(value);
}

void Stack::pop() {
		//flip through the stack until we run into the last value
	int numFlips = storage.size() - 1;
	for (int i = 0; i < numFlips; i++)
	{
		int currFront = storage.top();
		storage.pop();
		storage.push(currFront);
	}
	storage.pop();
}


//problem 6 - implement a queue with a stack
#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
using namespace std;

class Queue {
public:
    bool empty() const;
    size_t size() const;
    int front() const;
    int back() const;
    void push(const int& value);
    void pop();
private:
    stack<int> m_stack;
};

bool Queue::empty() const {
    return m_stack.empty();
}

size_t Queue::size() const {
    return m_stack.size();
}

int Queue::front() const {
    return m_stack.top();
}

int Queue::back() const {
    stack<int> m_stack_copy = m_stack;
    while (!m_stack_copy.empty() && m_stack_copy.size() != 1)
        m_stack_copy.pop();
    return m_stack_copy.top();
}

void Queue::push(const int& value) {
    //insert at the bottom of the stack
    stack<int> m_stack_new;
    m_stack_new.push(value);    //add the newest value to the bottom of the new stack.
    
    vector<int> m_stack_copy;
    //copy the items in m_stack to m_stack_copy
    while (!m_stack.empty())
    {
        m_stack_copy.push_back(m_stack.top());
        m_stack.pop();
    }
    
    while (!m_stack_copy.empty())
    {
        int bottomVal = m_stack_copy.back();
        m_stack_new.push(bottomVal);
        m_stack_copy.pop_back();
    }
    
    m_stack = m_stack_new;
}

void Queue::pop() {
    m_stack.pop();
}

//problem 6. implement a queue with a stack - version 2

//Method 2 - using two stacks
template<class Data>
class Queue
{
public:
    bool empty() const;
    size_t size() const;
    Data front() const;
    Data back() const;
    void push(const Data& value);
    void pop();
    void moveItems();
    
private:
    stack<Data> pushStorage;
    stack<Data> popStorage;
};

template<class Data>
bool Queue<Data>::empty() const
{
    return pushStorage.empty() && popStorage.empty();
}

template<class Data>
size_t Queue<Data>::size() const
{
    return pushStorage.size() + popStorage.size();
}

template<class Data>
Data Queue<Data>::front() const
{
    return popStorage.top();
}

template<class Data>
Data Queue<Data>::back() const
{
    return (size() == 1) ? popStorage.top() : pushStorage.top();
}

template<class Data>
void Queue<Data>::push(const Data& value)
{
    if (empty())    popStorage.push(value);
    else pushStorage.push(value);
}

template<class Data>
void Queue<Data>::pop()
{
    if (popStorage.size() > 0)
    {
        popStorage.pop();
        if (popStorage.empty() && !pushStorage.empty()) moveItems();
    }
    else    //if popStorage is empty
    {
        moveItems();    //attempt to move items over first
        popStorage.pop();   //pop from the popStorage
    }
}

template<class Data>
void Queue<Data>::moveItems()
{
    bool pushIsEmpty = true;
    Data back;
    if (pushStorage.size() > 1)
    {
        pushIsEmpty = false;
        back = pushStorage.top();
        pushStorage.pop();
    }
    
    while (!pushStorage.empty())
    {
        popStorage.push(pushStorage.top());
        pushStorage.pop();
    }
    
    if (pushIsEmpty == false)
    {
        pushStorage.push(back);
    }
}
