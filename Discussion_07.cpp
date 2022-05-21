//sort by predicate
//std::sort by value

void sort(iterator begin, iterator end, bool predicate function f);

bool f(const string& s1, const string& s2)
{
	return s1.size() > s2.size();
}
sort(s+1, s+11, f);

//interpretation the predicate
//changes the order of s1 and s2 if and only if 1 returns true.

void sort(iterator begin, iterator end, bool f());

bool f(const Pair<int, char>& s1, const Pair<int, char>& s2)
{
	return s1.Get_Second() > s2.Get_Second();
}

sort(sp, p+10, f);

//big O notation
	//simplified analysis of an Algorithm

//rules: ignore Constants O(5n) -> O(n);
//2. certain terms dominate others
	//O(1) < O(logn) < O(n) < O(nlogn) < O(n*n) < O(2^n) < O(n!)

//Calculating time complexity
for (int i = 0; i < n; i++)
	stmt;	//-----n/2

for (int i = 0; i < n; i + 2)	stmt;	//this has a Time Complexity of O(n), because this for loop executes the stmt one half of the times as the first for loop, but we ignore the coefficient.

for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		stmt;

for (int i = 0; i < n; i++)
	for (int j = 0; j < i; j++)
		stmt;
	