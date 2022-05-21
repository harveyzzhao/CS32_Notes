//vector STL - 
//master the list of commands and use it
vector<int> vi;
vi.push_back(10);
vi.push_back(20);
front()	//behaves like std::queue
back()
push_back()
pop_back()
[], at(), iterator (allowed to use ++, --, +=, -=)
vector<double>	vd(10);	//construct 10 doubles in the vectors, default value for default types are 0(false)
vector<string> vs(10, "Hello")	//construct 10 strings with value "hello"
int arr[] = {0, 1, 2, 3, 4};
vector<int> vx(a, a+5);	//construct a vector of ints [a, a + 5)
//unitialized spaces in the vector have "garbage values"

//each vector has three values:
	//content
	//size
	//capacity

//since when we expand the vector by copying the old content into a new vector, the iterator will be invalidated when we insert or delete an element.

//list - doubly linked list
list<int> li;
li.push_back(20);
push_front(30);	//unique to list
pop_front();	//unique
front()
back()

//NO [] access operator - list store values in random memory addresses.
	//instead, use ITERATOR
	//ITERATOR points 
	//*it, it++, it--; (NO it -= 2)
	list<int>::iterator p = li.begin();	//.begin() points to the first element of the list, .end() points to the element just after the end of the list

	for (p; p != li.end(); p++);

	//ways to initialize a list
	list<double> ld(10);
		//ld.size() is 10, each element is 0.0
	list<string> ls(10, "Hello");
	//ls.size() is 10, each element is "Hello"
	vector<string> vs(ls.begin(), ls.end());
	//vs.size() is 10, vs[0] is "Hello", vs[1]

	//INSERTION: li.insert(p, 40);
	insertion ALWAYS insert before the pointer you give. It returns the iterator that points to the newly inserted item.
	//DELETION
	deletion ALWAYS return an iterator following the target.
	It is illegal to use iterator after deletion. use it = li.end();
	iterator = li.erase(iterator);