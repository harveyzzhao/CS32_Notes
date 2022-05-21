//why use a stack instead of array or linked list?

//stack operations
	//create an empty stack
	//push an item onto the stack
		//what if the container is fixed?
	//pop an item from the stack
		//what if the stack is empty?
	//look at the top item on the stack
	//is the stack empty?
==========
	//look at any in the stack
	//How many items are in the stack?
	
QUEUE: INSERT AT TAIL, OUT AT HEAD
//Queue operations
	//create an empty queue
	//Enqueue an item
	//Dequeue an item(out)
	//Look at the front item in the queue
	//isempty
==========
	//look at the back item in the queue
	//look at any item in the queue
	//how many items in the queue

#include <stack>
using namespace std;

stack<int> s;
s.push(10);
s.push(20);
cout << s.top() << endl;
s.pop();	//pop returns a void value; need to access the top function.

//ALWAYS CHECK IF THE STACK IS EMPTY when accessing .top() or .pop()!s
if (s.empty())
	cout << "Stack is empty!" << endl;
else
	cout << s.top() << endl;
cout << s.size() << endl;


//////////////////////////////////////////////////////////////////////////////////////////
#include <queue>
using namespace std;

//head out, tail in
queue<int> q;
q.push(10);
q.push(20);
cout << q.front() << endl;
q.pop();
if (q.empty())
	cout << "Queue is empty!" << endl;
else
	cout << q.front()	<< endl;
cout << q.size() << endl;
cout << q.back() << endl;

//stack's applications:
	//Prefix notations
	f(x,y,z)
	add(sub(8,div(6,2)),1)
	+-8/621
	//infix notation
	8 - 6/2 + 1
	//Postfix notation
	8 6 2 / - 1 +

//we want to 
	//1. convert infix notations into postfix
		while (not at the end of the input sequence)
		{
			//If the current item is an operand, append it to the result sequence
			//Else if the top of the stack is (, push it onto the stack
			//else if the current item is ), pop operators off the stack appending them to the result sequence until you pop and (, which you do not append to the sequence.

			//else	//the current item is an operator
				//if the operator stack is empty, push the current operator onto the stack
				//else if the top of the stack is (, push the current operator onto the stack)
				//else if the current operator has precedence STRICTLY GREATER than that of the operator at the top of the stack,
					//push the current operator onto the operator stack
				//else
					//pop the top operator from the stack and append it to the result sequence
		}
		pop each operator off the stack and append it to the result sequence.
	//2. evaluate postfix

//implementing stacks using array
	//head is a dynamic index that is at the highest index in the array. Array does not allow accessing the previous index.
	//keep track of an integer top that points to the topth index in the array that is one element over the actual elements.
	//increment top when an element is inserted
	//top keeps track of the number of elements in the array.
	if (top >= ARRAYSIZE)
		do not allow more pushing
	if (top == 0)
		do not allow popping

//stack using linked list
	//use a singly linked list
	if (head == nullptr)
		head = new Node(val);
		return;
	Node* n = new Node(val);
	n->next = head;
	head = n;

//implement queue using array - ring buffer or circular array.
	//have two indices indicating head and tail. When tail reaches the end of the array we can trail it 
	//over to the front of the array and wrap around the head as well when it reaches the end.
	if (head == ARRAYSIZE)
		head = 0;
	if (tail == ARRAYSIZE)
		tail = 0;

	//once the size reaches its current capacity, assign another array double the size of the previous array. When the array is full and the queue cannot add more items, the head and tail will point to the same index in the array