class Node
{
	public:
		ll data;
		Node* prev = NULL;
		Node* next = NULL;
};

class List
{
	Node* head = NULL;

	public:

		List()
		{
			head = NULL;
		}

		Node* begin()
		{
			return head;
		}

		Node* end()
		{
			Node* temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			return temp;
		}

		ll front()
		{
			return head->data;
		}

		ll back()
		{
			return end()->data;
		}

		void push_back(ll data)
		{
			Node *newNode = new Node();
			newNode->data = data;
			newNode->next = NULL;
			newNode->prev = NULL;
			Node* temp = head;
			if(head == NULL)
			{
				head = newNode;
				return;
			}
			Node* temp1 = head;
			while(temp != NULL)
			{
				temp1 = temp;
				temp = temp->next;
			}
			temp1->next = newNode;
			newNode->prev = temp1;
		}

		void push_front(ll data)
		{
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = NULL;
			newNode->prev = NULL;
			newNode->next = head;
			if(head)
				head->prev = newNode;
			head = newNode;	
		}

		void pop_back()
		{
			if(head == NULL)
			{
				cout << "Stack Underflow" << endl;
				return;
			}
			Node* LasNode = end();
			if(LasNode->prev == NULL)
			{
				head = NULL;
				delete(LasNode);
				return;
			}
			Node* temp1 = LasNode->prev;
			temp1->next = NULL;
			delete(LasNode);
		}

		void pop_front()
		{
			if(head == NULL)
			{
				cout << "Stack underflow" << endl;
				return;
			}
			Node* temp = head;
			head = head->next;
			if(head)
				head->prev = NULL;
			delete(temp);
		}

		bool empty()
		{
			if(head == NULL)
				return true;
			return false;
		}

		void erase(ll data)
		{
			if(head == NULL)
			{
				cout << "Stack underflow" << endl;
				return;
			}
			if(head->data == data)
			{
				pop_front();
				return;
			}
			Node* temp = head;
			Node* temp1 = head;
			while(temp != NULL && temp->data != data)
			{
				temp1 = temp;
				temp = temp->next;
			}
			temp1->next = temp->next;
			if(temp1->next)
				temp1->next->prev = temp1;
			delete(temp);
		}

		void traverse()
		{
			Node* temp = head;
			while(temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
};