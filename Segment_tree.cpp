// Implementation of segment tree //
#include<bits/stdc++.h>
using namespace std;
int tree[50005];
int a[50005];
void build(int node, int start, int end)
{
	if (start==end)
	{
		tree[node]=a[start];
	} 
	else
	{
		int mid=(start+end)/2; // to find mid value		
		build(2*node+1,start,mid); // to make left child
		build((2*node)+2,mid+1,end); // to make right child 
		tree[node]=tree[2*node+1]+tree[(2*node)+2];
	}
}

void update(int node,int start,int end,int id, int val)
{
	if (start==end)
	{
		a[id]+=val;
		tree[node]+=val;
	}
	else
	{
		int mid=(start+end)/2;
		if (start<=id && id<=mid)   // if id lies between start and mid
			update(2*node+1,start,mid,id,val);
		else
		{
			update(2*node+2,mid+1,end,id,val);
		}
		tree[node]=tree[2*node+1]+tree[2*node+2];
	}
}

int query(int node, int start,int end, int l, int r)
{
	if (r<start || end<l)
		return 0; // out of range if r is less that start or l is bigger than end
	if (l<=start && end<=r)	
		return tree[node];
	int mid=(start+end)/2;
	int p1=query(2*node+1,start,mid,l,r);
	int p2=query((2*node)+2,mid+1,end,l,r);
	return p1+p2;	
}

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	build(0,0,n-1);
	cout<<endl;
	int x=query(0,0,n-1,0,n-1);
	cout<<x<<endl;
	update(0,0,n-1,3,5);
	x=query(0,0,n-1,1,3);
	cout<<x<<endl;
}
