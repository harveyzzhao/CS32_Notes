//dynamic binding: when we declare a pointer
Polymorphisms (pure virtual functions)
class Characters {
public:
	virtual void MoveOrAttack(int dx, int dy) = 0;

}

//inheritance order of construction and destruction
1. construct the base class (initialization list)
2. member variable's default constructors
3. 

Finding factorial
Recursion
finding factorials
f(int n)
{
	if (n == 1 || n == 0)	return 1;
	int result = n * f(n - 1)	return result;
}

