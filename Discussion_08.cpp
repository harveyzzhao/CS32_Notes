SORTING ALGORITHMS:
INSERTION SORT

for (element in the array)
{
	while (element is less than the previous one)
		swap it with the privious element
}

void insertionSort(int arr[], int n)
{
	int curr = 0;
	while (curr < n)
	{
		int target = curr;
		//find the index that is smaller than arr[curr]
		for (int i = curr - 1; i >= 0; i--)
		{
			if (arr[i] < arr[curr])
				arr
		}
	}
}

//FIXME: understand intuitively how insertionsort works
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{

	}
}


BUBBLE SORT


MERGE SORTING(nlogn time efficiency)
QUICK SORT O(nlogn)

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now at right place*/
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//tree
	//binary	tree

struct BNode {
	string val;
	BNode *left, *right;
};
BNode* root = nullptr;

struct Node
{
	string pval;
	vector<Node> m_child;
};

Node* root = nullptr;

//p has to be passed by reference because we don't want to 
//copy the original address of p over to another address
void Insert(Node*& p, string pval)	
{
	//if the tree is empty
	if (p == nullptr)
	{
		p = new Node;
		p->val = pval;
		return;
	}
	Node* newnode = new Node;
	newnode->val = pval;
	(p->child).push_back(newnode);
	return;
}

//Traversal methods
	//Preorder Traversal
	//parent node first, then children

void Preorder(Node* p) {
	if (p == nullptr)
		return;
	cout << p->val << endl;
	for (auto it: p->child)
	{
		Preorder(it);
	}
}

void Postorder(Node* p){
	//left, right, root
	if (p == nullptr)	return;
	for (auto it: p->child)
		Preorder(it);
	cout << p->val;
}

//binary search tree
//every child node to the right is greater than the parent node and vice versa
val(left_child) < val(parent) < val(right_child)

			6
		3		9
	 1  5	 7  11

inserting in BST
void BInsert(BNode*& p, const string& pval){
	if (p == nullptr)	//empty node
	{
		p = new BNode;
		p->val = pval;
		p->left = p->right = nullptr;
		return;
	}
	if (pval < p->val)	//insert left
		BInsert(p->left, pval);
	else if (pval == p->val)	//already exists
		return;
	else	//insert right
		BInsert(p->right, pval);
}

BNode* largest(BNode* p)
{
	return (p->right == nullptr) ? p : largest(p->right);
}

//assume each value occurs once
//TODO: Copy and paste the code for tree node deletion

//The Time complexity for a list to insert a node at a random position 
//in the middle is also O(N) BECAUSE YOU HAVE TO TRAVERSE THROUGH THE ARRAY FIRST

//The time complexity for a list to delete a REFERENCE TO A node is O(1)