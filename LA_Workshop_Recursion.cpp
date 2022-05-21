Clean code:
	less lines doesn not necessarily better
	no premature optimization
inheritance:
	the subclass IS A type of base class

did I use the virtual keyword for a base class function that is being overriden as a derived class?

Recursion:
	base case: every recursive function must have "stopping condition" or "base case" that stops the pitfall.
	Two rules of recursion:
		1. reducing the problem	- everytime the function calls itself you have to pass in a more simplified version of the code.
		2. base case

		//know if ax + by = c
		bool isSolvable()
		{
			if (c == 0)
				return true;
			if (c < 0)
				return false;
			return isSolvable(x, y, c - x) || isSolvable(x, y, c - y);
		}

		//reduce: slowly take out x to check (a-1)x + by = c -x;
		//or slowly take out y to check ax + (b-1)y = c - y;

		//think about base case first
		//stop point
		//test out the easiest cases for example "", size 1... and figure out how to simplify to the easiest cases


		bool isPalindrome(string foo)
		{
			int len = foo.length();
			if (len <= 1)
				return true;
			if (foo[0] != foo[len - 1])
				return false;
			return isPalindrome(foo.substr(1, len-2));
		}


	Debugger:
		break points,
		call stack (stack trace)
		step into - move into the code for a function call
		step over - execute the current line and move to the next one 
		step out - finish the current function

//Pascal's triangle
