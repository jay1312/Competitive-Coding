#include<bits/stdc++.h>
using namespace std;
struct node
{
int v;
int w;	
};
vector<struct node>road[50005];
int d[50005];
int n;
int v[50005];
int bfs(int s)
{
	int i;
	for(i=0;i<=n;i++)
	d[i]=0,v[i]=0;
	
	v[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(i=0;i<road[p].size();i++)
		{
			if(v[road[p][i].v]==0)
			{
			v[road[p][i].v]=1;
			d[road[p][i].v] = d[p] + road[p][i].w;
			q.push(road[p][i].v);
		    }
		}
	}
	int maxi = 1;
	for(i=2;i<=n;i++)
	if(d[maxi]<d[i])
	maxi=i;
	return maxi;
}
int main()
{
	int t,i,u,v,w;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<n;i++)
		{
			cin>>u>>v>>w;
			road[u].push_back((node) {v,w});
			road[v].push_back((node) {u,w});
		}
	//	cout<<"jay";
		int start = bfs(1);
		int ans = bfs(start);
		cout<<d[ans]<<endl;
	}
}
