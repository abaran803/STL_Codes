class Vector
{
	ll *arr = new ll[1];
	ll n = 0;
	ll length = 1;

	void Doublen()
	{
		length *= 2;
		ll *arr1 = new ll[length];
		for(ll i=0;i<n;i++)
			arr1[i] = arr[i];
		arr = arr1;
	}

	public:

		void push_back(ll data)
		{
			if(n >= length)
				Doublen();
			arr[n++] = data;
		}

		void push_front(ll data)
		{
			if(n >= length)
				Doublen();
			n++;
			for(ll i=n;i>0;i--)
				arr[i] = arr[i-1];
			arr[0] = data;
		}

		void pop_back()
		{
			if(n < 1)
			{
				cout << "Stack Underflow" << endl;
				return;
			}
			n--;
		}

		void pop_front()
		{
			if(n < 1)
			{
				cout << "Stack Underflow" << endl;
				return;
			}
			for(ll i=0;i<n-1;i++)
				arr[i] = arr[i+1];
			n--;
		}

		void insert(ll data,ll pos)
		{
			if(n >= length)
				Doublen();
			if(pos > n+1 || pos < 1)
			{
				cout << "An error occurred" << endl;
				return;
			}
			ll i;
			for(i=n;i>=pos;i--)
				arr[i] = arr[i-1];
			n++;
			arr[i] = data;
		}

		void traverse()
		{
			for(ll i=0;i<n;i++)
				cout << arr[i] << " ";
		}

		bool empty()
		{
			if(n == 0)
				return true;
			return false;
		}

		ll front()
		{
			if(empty())
			{
				cout << "Vector is Empty" << endl;
				return -1;
			}
			return arr[0];
		}

		ll back()
		{
			if(empty())
			{
				cout << "Vector is Empty" << endl;
				return -1;
			}
			return arr[n-1];
		}

		ll size()
		{
			return n;
		}

		void reverse()
		{
			ll temp;
			for(ll i=0,j=n-1;i<j;i++,j--)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		ll at(ll pos)
		{
			if(pos < 1 || pos > n)
			{
				cout << "An error occurred" << endl;
				return -1;
			}
			return arr[pos-1];
		}
};