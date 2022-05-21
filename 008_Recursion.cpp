Recursion mindset: if a problem is too big to solve at once, break it down into subparts and solve the subparts; if the subparts are tooo big apply the same operation... until the subproblem can be solved immediately/

//recursion illustrated through merge sort algorithm
sort a pile of N items
if (N >= 2)
{
	split the pile into two unsorted piles of N/2 items
	have someone sort the left subpile
	have someone sort the right subpile
	merge the two sorted subpiles into one sorted pile
}

	//since the merge algorithm disregard the size of each pile, we can 
	//also we didn't account for the base case here. When we only have one pile the program will keep spliting it down into 1 and 0 piles and it will not help

//how do you make sure the function doesn't terminate?
	//base case: paths through the function that do not make a recursive call
	//recursive cases: path through the function that make a recursive call
	//ALWAYS DO SOMETHING TO BREAK THE PROBLEM DOWN FURTHER SO IT IS CLOSER TO ITS BASE CASE

//every recursive call is to solve a strictly "smaller" problem (closer to base case)
//recursion is similar to the proof by induction (base case and inductive case)

void sort(int a[], int b, int e)
{
	if (e - b >= 2)
	{
		int mid = (b + e) / 2;
		sort(a, b, mid);
		sort(a, mid, e);
		merge(a, b, mid, e);
	}
}

//three strategies for recursion
	//1. divide and conquer - split the problem into roughly equal sizes
	//2. first and then the rest
	//3. the last and then the rest approach


//some wrong recursive functions
bool has(int a[], int n, int target)
{
	if (n <= 0)	return false;
	if (a[0] == target)
		return true;
	return has(a+1, n-1, target);s]
}

//the function's base case must holds true no matter what and 
bool solve(start, end)
{
	if (start == end)
		return true;
	mark the start as visited
	for each direction:
		if (moving in that direction is possible, and this spot has not been visited)
			if(solve(position reached by moving that step, end))
				return true;
	return false;
}

//check if the recursive function is valid: check if there are return paths that cover true AND false
//check if the recursion is actually reducing the problem.