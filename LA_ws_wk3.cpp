//problem 1
int cmpr(Node *head, int *arr, int arr_size)	/* wrong header? does it work? int cmpr(Node* head, int arr[])*/
{
	//when lls is empty
	Node* p = head;
	int index = -1;
	for (index; index + 1 < arr_size && p != nullptr && p->val == arr[index + 1]; index++, p = p->next);	//p != nullptr should always precede accessors
	return index;
}

//another solution
int cmpr(Node* head, int* arr, int arr_size)
{
	int i = -1;
	Node* curr = head;
	while (i + 1 < arr_size && curr != nullptr && curr->val == arr[i+1])
	{
		i++;
		curr = curr->next;
	}
	return i;
}

//problem 2
LL::LL(const LL& other)
{
	if (other.head == nullptr)
	{
		head = nullptr;
		return;
	}
	
	//copy head pointer
	head = nullptr;
	Node* p1 = head;
	Node* p2 = other.head;

	while (p2 != nullptr)
	{
		p1 = new Node;
		p1->val = p2->val;
		p1->next = nullptr;
		p1 = p1->next;
		p2 = p2->next;
	}
}