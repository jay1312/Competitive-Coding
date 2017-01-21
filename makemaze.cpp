#include<bits/stdc++.h>
using namespace std;
char a[25][25];
int n,m;
int visit[25][25];
int x[]={0,0,-1,1};
int y[]={-1,1,0,0};
bool bfs(int sx,int sy,int dx,int dy)
{
	if(sx==dx&&sy==dy)
	return true;
	if(visit[sx][sy]==0)
	{
	visit[sx][sy]=1;
	for(int i=0;i<4;i++)
	{
		int snx = sx + x[i];
		int sny = sy + y[i];
		if(snx>=0 && snx<n &&sny>=0&&sny<m&&a[snx][sny]=='.')
		if(bfs(snx,sny,dx,dy))
		return true;
	}
    }
    return false;
}
int main()
{
	int t,i,j,sx,sy,dx,dy;
	cin>>t;
	while(t--)
	{
		bool invalid = false;
		cin>>n>>m;
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		cin>>a[i][j];
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		visit[i][j]=false;
		int str=0;
		for(j=0;j<m;j++)
		{
			if(a[0][j]=='.')
			{
				if(str==0)
				{
					sx = 0;
					sy = j;
				}
				else if(str==1)
				{
					dx = 0;
					dy = j;  
				}
				else
				{
					invalid = true;
					break;
				}
				
				str++;
			}
			if(n!=1 && a[n-1][j]=='.')
			{
				if(str==0)
				{
					sx = n-1;
					sy = j;
				}
				else if(str==1)
				{
					dx = n-1;
					dy = j;  
				}
				else
			{
					invalid = true;
					break;
				}
				str++;
			}
		}
		for(i=1;i<n-1;i++)
		{
			if(a[i][0]=='.')
			{
				if(str==0)
				{
					sx = i;
					sy = 0;
				}
				else if(str==1)
				{
					dx = i;
					dy = 0;  
				}
				else
				{
					invalid = true;
					break;
				}
				
				str++;
			}
			if(m!=1 && a[i][m-1]=='.')
			{
				if(str==0)
				{
					sx = i;
					sy = m-1;
				}
				else if(str==1)
				{
					dx = i;
					dy = m-1;  
				}
				else
				{
					invalid = true;
					break;
				}
				str++;
			}
		}
	//	cout<<"str "<<str<<endl<<endl;
		if(str==0||str==1||invalid)
		cout<<"invalid\n";
		else if(bfs(sx,sy,dx,dy))
		cout<<"valid\n";
		else cout<<"invalid\n";
	}
}
