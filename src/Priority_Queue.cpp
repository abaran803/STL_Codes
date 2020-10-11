class PriorityQueue
{
	ll capacity;
	ll size;
	ll *arr;

public:

	PriorityQueue(ll cap)
	{
		capacity = cap;
		size = 0;
		arr = new ll[cap];
	}

	ll leftchild(ll i)
	{
		if(size > (2*i+1))
			return (2*i+1);
		else
			return -1;
	}

	ll rightchild(ll i)
	{
		if(size > (2*i+2))
			return (2*i+2);
		else
			return -1;
	}

	ll parent(ll i)
	{
		if(i > 0)
			return (i-1)/2;
		else
			return -1;
	}

	void correctup(ll i)
	{
		ll par = parent(i);
		if(par != -1)
		{
			if(arr[par]>arr[i])
				swap(arr[par],arr[i]);
			correctup(par);
		}
	}

	void correctdown(ll i)
	{
		ll max = i;
		if(leftchild(i) != -1)
			if(arr[leftchild(i)] < arr[max])
				max = leftchild(i);
		if(rightchild(i) != -1)
			if(arr[rightchild(i)] < arr[max])
				max = rightchild(i);
		swap(arr[i],arr[max]);
		if(i != max)
			correctdown(max);
	}

	void push(ll data)
	{
		if(size >= capacity)
		{
			cout << "Stack Overflow";
			return;
		}
		arr[size] = data;
		correctup(size);
		size++;
	}

	ll pop()
	{
		if(size <= 0)
		{
			cout << "Stack Underflow";
			return -1;
		}
		ll data = arr[0];
		swap(arr[0],arr[size-1]);
		size--;
		correctdown(0);
		return data;
	}

	void traverse()
	{
		for(ll i=0;i<size;i++)
			cout << arr[i] << " ";
		cout << endl;
	}

};