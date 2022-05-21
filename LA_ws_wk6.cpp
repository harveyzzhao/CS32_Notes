class Potato {
public:
	Potato(int in_size) : size(in_size){}
	int getSize() const
	{
		return size;
	}
private:
	int size;
};

int main(){
	vector<Potato> potatoes;
	potatoes.push_back(p1);
	potatoes.push_back(Potato(4));
	potatoes.push_back(Potato(5));
	vector<Potato>::iterator it = potatoes.begin();
	while (it != potatoes.end())
	{
		//reassign it because potatoes.erase(it) returns the position AFTER the erased value.

		it = potatoes.erase(it);	//why would you assign it to potatoes.erase(it)?
		// Since potatoes.erase(it) already points the iterator to one index after, no need to increment it. it++;
	}

	for (it = potatoes.begin(); it != potatoes.end(); it++)
		cout << it->getSize() << endl;
};

int sumOfDigits(int num)
{
	if (num <= 0)
		return 0;
	return sumOfDigits(num / 10) + 
}

int sumOfDigits(int num) {
	if (num < 10)
		return num;
	return num % 10 + sumOfDigits(num / 10);
}

int getMax(int a[], int n)
{
	if (n == 1) return a[0];
	int maxofRest = getMax(a + 1, n - 1);
	return (a[0] > maxofRest) ? a[0] : maxofRest;
}