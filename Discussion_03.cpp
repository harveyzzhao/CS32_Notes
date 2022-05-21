class Node
{
public:
	int val;
	Node* next;
	Node()
	{
		next = nullptr;
	}
	Node(int v)
	{
		val = v;
		next = nullptr;
	}
}

int main()
{
	Node* first = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);
	first->next = second;
	second->next = third;
}

void print(Node* head)
{
	Node* temp = head;
	while(temp != nullptr)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
}

Node* Find_Val(Node* head, int x)
{
	Node* p = head;
	while (p != nullptr)
	{
		if (p->val == x)
			break;
		p = p->next;
	}
	return p;
}

Node* Find_k_th(Node* head, int k)
{
	Node* p = head;
	for (int i = 0; i < k && p != nullptr; i++)
		p = p->next;
	return p;
}

//insert an element after p
void insertAfter(Node *p, int new_data)
{
	Node* new_node = new Node(new_data);
	new_node->next = p->next;
	p->next = new_node;
}

void insertAtRear(Node* head, int new_data)
{
	if (head == nullptr)
	{
		Node* n = new Node(new_data);
		return;
	}

	//traverse until the end of the linked list
	Node* p = head;
	while (p->next != nullptr)
		p = p->next;

	Node* n = new Node(new_data);
	n->next = p->next;
	p->next = n;
}

int Delete_One_Val(Node* head, int x)
{
	//when the list is empty
	if (head == nullptr)
		return -1;
	//when head has the value x
	Node* p = head;
	if (head->val == x)
	{
		head = head->next;
		delete p;
		return 1;
	}
	
	//delete normally
	//FIXME: Double check the logic here.
	while (p != nullptr || p->next != nullptr)
	{
		if (p->next->val == x)
		{
			p->next = p->next->next;
			delete p->next;
			return 1;
		}
		p = p->next;
	}
	return -1;



	//delete at the very end
}

//doubly linked list