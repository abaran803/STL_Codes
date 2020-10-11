class StackVector
{
	ll *arr;
	ll n;
	ll length;

	void Doublen()
	{
		length *= 2;
		ll *arr1 = new ll[length];
		for(ll i=0;i<n;i++)
			arr1[i] = arr[i];
		arr = arr1;
	}

public:

	StackVector()
	{
		length = 1;
		arr = new ll[length];
		n = 0;
	}

	void push(ll data)
	{
		if(n == length)
			Doublen();
		arr[n++] = data;
	}

	ll pop()
	{
		if(n < 1)
		{
			cout << "Stack Underflow" << endl;
			return -1;
		}
		n--;
		return arr[n];
	}

	void traverse()
	{
		for(ll i=0;i<n;i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	ll size()
	{
		return n;
	}

	bool empty()
	{
		if(n <= 0)
			return true;
		return false;
	}

	ll top()
	{
		if(empty())
		{
			cout << "Stack is Empty" << endl;
			return -1;
		}
		return arr[n-1];
	}
};