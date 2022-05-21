//data structures we used so far
	//fixed-size array: size known at compile time
	int arr[100];
	//dynamically allocarted fixed-size array: size customizable, fixed at compile time
	int n;
	cin >> n;
	int* b = new int[n];
	//resizable array
		//when the array is full, move everything into a bigger container.
		//requires a lot of shuffling when altering the array.

	//Linked list: requires significantly less operations to insert and delete items
		//head + body + nullptr

	struct Node
	{
		int value;
		Node* next;
	};
	Node* head;

	while (head != nullptr)	//this will cause a memory leak! we will lose our access to the head node
	{
		cout << head->value << endl;
		head = head->next;
	}

	correct:
	Node* p = head;
	while (p != nullptr)
	{
		cout << head->value << endl;
		p = p->next;
	}

	or 
	for (Node* p = head; p != nullptr; p = p->next)
		cout << p->value << endl;

//draw pictures and follow my design.
//find a specific value
Node* p;
// for (p = head, p->value != 18 && p != nullptr; p = p->next)	//the order within an if statement actually matters. In this line the program will run p->value != 18, and if p is nullptr it will result in an exception.
for (p = head; p != nullptr && p->value != 18; p = p->next)

//insert a 54 after the 18 in the list, if present.
Node* p;
for (p = head; p != nullptr && p->value != 18; p = p->next)


if (p != nullptr)
{
	... code to insert a 54 after the node p points to ...
	//create a new node
	Node* n = new Node;
	//assign the new node with value 54
	n->value = 54;
	//adjust the next pointer on 18
	// p->next = n;
	// n->next = p->next;	//FIXME: p->next is now assigned to n. n->next is now n
	n->next = p->next;
	p->next = n;
	//point the next pointer on 54
}

//advice for linked list: 
	//operate in the right order
	//set the uninitialized (new) nodes' parameters first
	//never accerss an uninitialized or nullptr p
		//whenever you write p->... make sure:
			//p has a well-defined value
			//p is not nullptr
	//draw pictures!
	//check five cases: middle, front, back of the linked list, one-element list, and empty list.
	
//DELETE a node after finding 18

//SPECIAL CASE: when deleting the node at the front of the list
head = p->next;
delete p;

//NORMAL CASE:
Node* tmp = p->next;	//to be deleted
p->next = p->next->next;
delete tmp;

//using tail pointer to easily access the back of the list
Node* head, *tail;
if (head == nullptr && tail == nullptr)
{
	head = new Node;
	tail = head;
}

//DELETE the node 18
//case I. empty list
if (head == nullptr)
	return;

//case II. if 18 is at the front of the list
if (head->value == 18)
{
	Node* temp = head;
	head = head->next;
	delete temp;
}

//case III. one-item list
if (head->next == nullptr)
	return;

//case IV. middle/end
Node* prev = head;
Node* target = head->next;
for (; target != nullptr && target->value != 18; prev = prev->next, target = target->next);
prev->next = target->next;
delete target;



//doubly linked list
struct Node
{
	int value;
	Node* prev;
	Node* next;
	Node(): prev(nullptr), next(nullptr){}
	Node(int val): value(val), prev(nullptr), next(nullptr){}
}

