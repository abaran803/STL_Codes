#define ll long long
#include"./src/imports.cpp"

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("inp.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif


	Tree t = Tree();
	t.insert(9);
	t.insert(11);
	t.insert(15);
	t.insert(2);
	t.insert(51);
	t.insert(81);
	t.insert(15);
	t.insert(13);
	t.insert(3);
	t.insert(16);
	t.inorder();
	// t.remove(9);
	// t.preorder();
	// t.inorder();
	// t.postorder();
	// t.rightNodeLeftorder();
	// cout << t.parent(16) << endl;
	// cout << t.successor(16) << endl;
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin >> arr[i];
	for(ll i=0;i<n;i++)
	{
		// cout << t.predecessor(arr[i]) << " " << arr[i] << " ~~~" << endl;
		// cout << t.Height(arr[i]) << " ";
	}
	cout << t.root->right->data;
	return 0;
}