#define ll long long
#include"./src/imports.cpp"

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("inp.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif


	PriorityQueue pq = PriorityQueue(100);
	pq.push(26);
	pq.push(4);
	pq.push(23);
	pq.push(2);
	pq.push(53);
	cout << pq.pop() << endl;
	cout << pq.pop() << endl;
	return 0;
}