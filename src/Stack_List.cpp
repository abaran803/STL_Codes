class Node
{
public:
	ll data;
	Node* next;
};

class StackList
{
	Node* head = NULL;
	ll count = 0;

public:

	void push(ll data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->next = head;
		head = temp;
		count++;
	}

	ll pop()
	{
		if(head == NULL)
		{
			cout << "Stack underflow" << endl;
			return -1;
		}
		Node* temp = head;
		ll data = temp->data;
		head = temp->next;
		delete(temp);
		count--;
		return data;
	}

	ll size()
	{
		return count;
	}

	void traverse()
	{
		Node* temp = head;
		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp =  temp->next;
		}
		cout << endl;
	}

	bool empty()
	{
		if(head == NULL)
			return true;
		return false;
	}

	ll top()
	{
		if(head == NULL)
		{
			cout << "Stack is Empty" << endl;
			return -1;
		}
		return head->data;
	}

	~StackList()
	{
		if(head != NULL)
		{
			while(head->next != NULL)
			{
				Node* temp = head;
				head = head->next;
				delete(temp);
			}
			delete(head);
		}
	}

};