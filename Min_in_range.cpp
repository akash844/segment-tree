#include<bits/stdc++.h>
using namespace std;
int a[100005];
int tree[500005];
void build(int node,int start,int end)
{
	if (start==end)
		tree[node]=a[start];
	else
	{
		int mid=(start+end)/2;
		build(2*node+1,start,mid);
		build(2*node+2,mid+1,end);
		tree[node]=min(tree[2*node+1],tree[2*node+2]);
	}
}

void update(int node, int start, int end, int id, int val)
{
	if (start==end)
	{
		a[id]=val;
		tree[node]=val;
	}
	else
	{
		int mid=(start+end)/2;
		if (start<=id && id<=mid)
			update(2*node+1,start,mid,id,val);
		else
			update(2*node+2,mid+1,end,id,val);
		tree[node]=min(tree[2*node+1],tree[2*node+2]);
	}
}

int query(int node,int start,int end,int l,int r)
{
	if (r<start || end<l)
		return 0;
	if (l<=start && end<=r)
		return tree[node];
	int mid=(start+end)/2;
	int p1=query(2*node+1,start,mid,l,r);
	int p2=query(2*node+2,mid+1,end,l,r);
	if (p2==0)
		return p1;
	else if (p1==0)
		return p2;
	return min(p1,p2);
}

int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	build(0,0,n-1);
	while(q--)
	{
		char t;// t=type
		int x,y;
		cin>>t>>x>>y;
		if(t=='q')
		{
			int ans=query(0,0,n-1,x-1,y-1);
			cout<<ans<<endl;
		}
		else
			update(0,0,n-1,x-1,y);
	}
}
