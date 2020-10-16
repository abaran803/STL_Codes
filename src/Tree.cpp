class Node
{
public:

	ll data;
	ll height;
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
	ll size();
	ll empty();
	void insert(ll data);
	ll NodeHeight(Node* head);
	Node* push(ll data, Node* head);
	ll top();
	void preorder();
	void traverPre(Node* head);
	void inorder();
	void traverin(Node* head);
	void postorder();
	void traverpost(Node* head);
	void rightNodeLeftorder();
	void traverrightNodeLeft(Node* head);
	bool find(ll data);
	Node* search(ll data,Node* temp);
	ll getMin();
	ll getMax();
	ll Maximum(Node* temp1);
	ll Minimum(Node* temp1);
	Node* par(ll data,Node* temp,Node* ParentOfTemp);
	ll parent(ll data);
	ll successor(ll data);
	ll predecessor(ll data);
	void remove(ll data);
	Node* pop(ll data,Node* head);
	ll Height(ll data);
	ll BalanceFactor(Node* temp);
	Node* LL(Node* head);
	Node* RR(Node* head);
	Node* LR(Node* head);
	Node* RL(Node* head);
};







/*-----------------------------------Insert/Delete------------------------------*/

void Tree::insert(ll data)
{
	root = push(data,root);
	n++;
}

Node* Tree::push(ll data, Node* head)
{
	if(head == NULL)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->height = 0;
		temp->right = NULL;
		temp->left = NULL;
		return temp;
	}
	if(head->data > data)
		head->left = push(data,head->left);
	else if(head->data < data)
		head->right = push(data,head->right);
	else
		return head;
	head->height = NodeHeight(head);
	if(BalanceFactor(head) == 2 && BalanceFactor(head->left) == 1)
		head = LL(head);
	else if(BalanceFactor(head) == 2 && BalanceFactor(head->left) == -1)
		head = LR(head);
	else if(BalanceFactor(head) == -2 && BalanceFactor(head->right) == -1)
		head = RR(head);
	else if(BalanceFactor(head) == -2 && BalanceFactor(head->right) == 1)
		head = RL(head);
	return head;
}

void Tree::remove(ll data)
{
	root = pop(data,root);
	n--;
}


Node* Tree::pop(ll data,Node* head)
{
	Node* temp = search(data,head);
	if(temp == NULL)
	{
		cout << data << " doesn't exist\n";
		return head;
	}
	Node* temp1 = par(data,root,NULL);
	if(temp->right == NULL && temp->left == NULL)
	{
		if(temp1 == NULL)
			root = NULL;
		else
		{
			if(temp1->right == temp)
				temp1->right = NULL;
			else
				temp1->left = NULL;
		}
	}
	else if(temp->right != NULL && temp->left == NULL)
	{
		if(temp1 == NULL)
			root = root->right;
		else
		{
			if(temp1->right == temp)
				temp1->right = temp->right;
			else
				temp1->left = temp->right;
		}
	}
	else if(temp->right == NULL && temp->left != NULL)
	{
		if(temp1 == NULL)
			root = root->left;
		else
		{
			if(temp1->right == temp)
				temp1->right = temp->left;
			else
				temp1->left = temp->left;
		}
	}
	else
	{
		
		head = pop(successor(data),head);
	}
	return head;
}

/*------------------x----------------Insert/Delete---------------x--------------*/








/*-----------------------------------Travesal-----------------------------------*/
void Tree::preorder()
{
	traverPre(root);
	cout << endl;
}

void Tree::traverPre(Node* head)
{
	if(head)
	{
		cout << head->data << " ";
		traverPre(head->left);
		traverPre(head->right);
	}
}

// Ascending Order
void Tree::inorder()
{
	traverin(root);
	cout << endl;
}

void Tree::traverin(Node* head)
{
	if(head)
	{
		traverin(head->left);
		cout << head->data << " ";
		traverin(head->right);
	}
}

void Tree::postorder()
{
	traverpost(root);
	cout << endl;
}

void Tree::traverpost(Node* head)
{
	if(head)
	{
		traverpost(head->left);
		traverpost(head->right);
		cout << head->data << " ";
	}
}

// Inverse of Inorder or Descending Order
void Tree::rightNodeLeftorder()
{
	traverrightNodeLeft(root);
	cout << endl;
}

void Tree::traverrightNodeLeft(Node* head)
{
	if(head)
	{
		traverrightNodeLeft(head->right);
		cout << head->data << " ";
		traverrightNodeLeft(head->left);
	}
}

/*--------------------x--------------Traversal------------------x----------------*/








/*------------------------------------Size/Top/Empty-------------------------------*/

ll Tree::size()
{
	return n;
}

ll Tree::empty()
{
	return (n == 0);
}

ll Tree::top()
{
	if(root == NULL)
	{
		cout << "Tree nave no node";
		return -1;
	}
	return root->data;
}

/*------------------x-----------------Size/Top/Empty-----------------x------------*/







/*------------------------------------Search_Element------------------------------*/

bool Tree::find(ll data)
{
	if(search(data,root) == NULL)
		return false;
	return true;
}

Node* Tree::search(ll data,Node* temp)
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

/*------------------x-----------------Search_Element--------------------x---------*/







/*--------------------------------Minimum/Maximum_Element-------------------------*/

ll Tree::getMin()
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

ll Tree::getMax()
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

ll Tree::Maximum(Node* temp1)
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

ll Tree::Minimum(Node* temp1)
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

/*----------------x---------------Minimum/Maximum_Element--------------x----------*/







/*-----------------------------Successor/Preceeder/Parent---------------------------*/

Node* Tree::par(ll data,Node* temp,Node* ParentOfTemp)
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

ll Tree::parent(ll data)
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

ll Tree::successor(ll data)
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

ll Tree::predecessor(ll data)
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

/*--------------x--------------Successor/Preceeder/Parent-------------x-------------*/







/*-----------------------------------Convert_To_AVL---------------------------------*/

ll Tree::NodeHeight(Node* head)
{
	ll hl,hr;
	hl = (head && head->left)? head->left->height : -1;
	hr = (head && head->right)? head->right->height : -1;
	return max(hr,hl)+1;
}

ll Tree::BalanceFactor(Node* temp)
{
	if(temp == NULL)
	{
		cout << "Element not found ";
		return 0;
	}
	ll hl,hr;
	hl = (temp->left)? temp->left->height : -1;
	hr = (temp->right)? temp->right->height : -1;
	return hl-hr;
}

ll Tree::Height(ll data)
{
	Node* temp = search(data,root);
	if(temp == NULL)
		return -1;
	return temp->height;
}

Node* Tree::LL(Node* head)
{
	Node* temp = par(head->data,root,NULL);
	if(temp == NULL)
	{
		root = head->left;
		temp = root;
	}
	else
		temp = head->left;
	Node* ptr = temp->right;
	temp->right = head;
	temp->right->left = ptr;
	return temp;
}

Node* Tree::RR(Node* head)
{
	Node* temp = par(head->data,root,NULL);
	if(temp == NULL)
	{
		root = head->right;
		temp = root;
	}
	else
		temp = head->right;
	Node* ptr = temp->left;
	temp->left = head;
	temp->left->right = ptr;
	return temp;
}

Node* Tree::LR(Node* head)
{
	Node* temp = par(head->data,root,NULL);
	if(temp == NULL)
	{
		root = head->left->right;
		temp = root;
	}
	else
		temp = head->left->right;
	Node* ptr = head->left;
	head->left->right = temp->left;
	head->left = temp->right;
	temp->right = head;
	temp->left = ptr;
	return temp;
}

Node* Tree::RL(Node* head)
{
	Node* temp = par(head->data,root,NULL);
	if(temp == NULL)
	{
		root = head->right->left;
		temp = root;
	}
	else
		temp = head->right->left;
	Node* ptr = head->right;
	head->right->left = temp->right;
	head->right = temp->left;
	temp->left = head;
	temp->right = ptr;
	return temp;
}

/*-----------------x-----------------Convert_To_AVL-----------------------x---------*/
