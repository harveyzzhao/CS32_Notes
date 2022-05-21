
/* Node of a doubly linked list */
class Node
{
    public:
    int data;
    Node* next; // Pointer to next node in DLL
    Node* prev; // Pointer to previous node in DLL
};

1) Add a node at the front: (A 5 steps process) 
The new node is always added before the head of the given Linked List. 
And newly added node becomes the new head of DLL. 
For example if the given Linked List is 10152025 and we add an item 5 at the front, 
then the Linked List becomes 510152025. Let us call the function that adds at the 
front of the list is push(). The push() must receive a pointer to the head pointer, 
because push must change the head pointer to point to the new node (See this)