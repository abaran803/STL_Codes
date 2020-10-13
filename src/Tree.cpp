class Node
{
public:
	ll data;
	Node* left;
	Node* right;
};

class Tree
{
public:

	Node* root;
	ll n;
	
	Tree()
	{
		root = NULL;
		n = 0;
	}

	ll size()
	{
		return n;
	}

	ll empty()
	{
		return (n == 0);
	}

	void insert(ll data)
	{
		root = push(data,root);
		n++;
	}

	Node* push(ll data, Node* head)
	{
		if(head == NULL)
		{
			Node* temp = new Node();
			temp->data = data;
			temp->right = NULL;
			temp->left = NULL;
			return temp;
		}
		Node* temp1 = head;
		if(temp1->data > data)
			temp1->left = push(data,temp1->left);
		else if(temp1->data <= data)
			temp1->right = push(data,temp1->right);
		return head;
	}

	ll top()
	{
		if(root == NULL)
		{
			cout << "Tree nave no node";
			return -1;
		}
		return root->data;
	}

	void preorder()
	{
		traverPre(root);
		cout << endl;
	}

	void traverPre(Node* head)
	{
		if(head)
		{
			cout << head->data << " ";
			traverPre(head->left);
			traverPre(head->right);
		}
	}

	void inorder()
	{
		traverin(root);
		cout << endl;
	}

	void traverin(Node* head)
	{
		if(head)
		{
			traverin(head->left);
			cout << head->data << " ";
			traverin(head->right);
		}
	}

	void postorder()
	{
		traverpost(root);
		cout << endl;
	}

	void traverpost(Node* head)
	{
		if(head)
		{
			traverpost(head->left);
			traverpost(head->right);
			cout << head->data << " ";
		}
	}

	bool find(ll data)
	{
		if(search(data,root) == NULL)
			return false;
		return true;
	}

	Node* search(ll data,Node* temp)
	{
		if(temp == NULL)
			return NULL;
		if(temp->data == data)
			return temp;
		if(data < temp->data)
			return search(data,temp->left);
		else
			return search(data,temp->right);
	}

	ll getMin()
	{
		Node* temp = root;
		if(temp == NULL)
		{
			cout << "No element in tree ";
			return -1;
		}
		while(temp->left != NULL)
			temp = temp->left;
		return temp->data;
	}

	ll getMax()
	{
		Node* temp = root;
		if(temp == NULL)
		{
			cout << "No element in tree ";
			return -1;
		}
		while(temp->right != NULL)
			temp = temp->right;
		return temp->data;
	}

	ll Maximum(Node* temp1)
	{
		Node* temp = temp1;
		if(temp == NULL)
		{
			cout << "No element in tree ";
			return -1;
		}
		while(temp->right != NULL)
			temp = temp->right;
		return temp->data;
	}

	ll Minimum(Node* temp1)
	{
		Node* temp = temp1;
		if(temp == NULL)
		{
			cout << "No element in tree ";
			return -1;
		}
		while(temp->left != NULL)
			temp = temp->left;
		return temp->data;
	}

	Node* par(ll data,Node* temp,Node* ParentOfTemp)
	{
		if(temp != NULL)
		{
			if(temp->data == data)
				return ParentOfTemp;
			else
			{
				Node* left = par(data,temp->left,temp);
				Node* right = par(data,temp->right,temp);
				if(left != NULL)
					return left;
				else if(right != NULL)
					return right;
			}
		}
		return NULL;
	}

	ll parent(ll data)
	{
		Node* temp = new Node();
		temp->data = -1;
		temp->left = NULL;
		temp->right = NULL;
		Node* temp1 = par(data,root,temp);
		if(temp1 == NULL)
			return -1;
		return temp1->data;
	}

	ll successor(ll data)
	{
		Node* temp = search(data,root);
		if(temp == NULL)
			return -1;
		if(temp->right != NULL)
			return Minimum(temp->right);
		Node* temp1 = par(temp->data,root,NULL);
		while(temp1 != NULL && temp == temp1->right)
		{
			temp = temp1;
			temp1 = par(temp1->data,root,NULL);
		}
		if(temp1 == NULL || temp1->data < data)
			return -1;
		return temp1->data;
	}

	ll predecessor(ll data)
	{
		Node* temp = search(data,root);
		if(temp == NULL)
			return -1;
		if(temp->left != NULL)
			return Maximum(temp->left);
		Node* temp1 = par(temp->data,root,NULL);
		while(temp1 != NULL && temp == temp1->left)
		{
			temp = temp1;
			temp1 = par(temp1->data,root,NULL);
		}
		if(temp1 == NULL || temp1->data > data)
			return -1;
		return temp1->data;
	}

};