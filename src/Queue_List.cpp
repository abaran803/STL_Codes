class Node
{
public:
	ll data;
	Node* next;
};

class QueueList
{
	Node* front = NULL;
	Node* rear = NULL;
	ll count = 0;

public:

	bool empty()
	{
		return (front == NULL);
	}

	void push(ll data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->next = NULL;
		count++;
		if(empty())
		{
			front = temp;
			rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}

	ll pop()
	{
		if(empty())
		{
			cout << "Stack underflow" << endl;
			return -1;
		}
		Node* temp = front;
		ll data = temp->data;
		front = temp->next;
		delete(temp);
		if(front == NULL)
			rear = NULL;
		count--;
		return data;
	}

	ll size()
	{
		return count;
	}

	void traverse()
	{
		Node* temp = front;
		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp =  temp->next;
		}
		cout << endl;
	}

	ll top()
	{
		if(rear == NULL)
		{
			cout << "Stack is Empty" << endl;
			return -1;
		}
		return rear->data;
	}

	~QueueList()
	{
		if(front != NULL)
		{
			while(front->next != NULL)
			{
				Node* temp = front;
				front = front->next;
				delete(temp);
			}
			delete(front);
		}
	}

};