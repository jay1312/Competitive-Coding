#include<bits/stdc++.h>
using namespace std;
int mmove[110][110];
int cmove[110][110];
int r;
int col;
struct field
{
int x;
int y;	
};
void cbfs(field c)
{
	bool visit[110][110];
	for(int i=1;i<=r;i++)
	for(int j=1;j<=col;j++)
	visit[i][j]=false;
	queue<field>q;
	q.push(c);
	cmove[c.x][c.y]=0;
	while(!q.empty())
	{
		field p = q.front();
		q.pop();
		if(visit[p.x][p.y]==false)
		{
		visit[p.x][p.y]=true;
		if(p.x+1<=r && cmove[p.x+1][p.y]>cmove[p.x][p.y]+1)
		{
			cmove[p.x+1][p.y]=cmove[p.x][p.y]+1;
			q.push( (field){	p.x+1,p.y		} );
		}
        if(p.x-1>=1 && cmove[p.x-1][p.y]>cmove[p.x][p.y]+1)
		{
			cmove[p.x-1][p.y]=cmove[p.x][p.y]+1;
			q.push( (field){	p.x-1,p.y		} );
		}
		if(p.y+1 <= col && cmove[p.x][p.y+1]>cmove[p.x][p.y]+1)
		{
			cmove[p.x][p.y+1]=cmove[p.x][p.y]+1;
			q.push( (field){	p.x,p.y+1		} );
		}
		if(p.y-1>=1 && cmove[p.x][p.y-1]>cmove[p.x][p.y]+1)
		{
			cmove[p.x][p.y-1]=cmove[p.x][p.y]+1;
			q.push( (field){	p.x,p.y	-1	} );
		}
	    }
	}
	
}
void mbfs(field m)
{
	bool visit[110][110];
	for(int i=1;i<=r;i++)
	for(int j=1;j<=col;j++)
	visit[i][j]=false;
	queue<field>q;
	q.push(m);
	mmove[m.x][m.y]=0;
	while(!q.empty())
	{
		field p = q.front();
		q.pop();
		if(visit[p.x][p.y]==false)
		{
		visit[p.x][p.y]=true;
		if(p.x+1<=r && mmove[p.x+1][p.y]>mmove[p.x][p.y]+1)
		{
			mmove[p.x+1][p.y]=mmove[p.x][p.y]+1;
			q.push( (field){	p.x+1,p.y		} );
		}
        if(p.x-1>=1 && mmove[p.x-1][p.y]>mmove[p.x][p.y]+1)
		{
			mmove[p.x-1][p.y]=mmove[p.x][p.y]+1;
			q.push( (field){	p.x-1,p.y		} );
		}
		if(p.y+1<=col && mmove[p.x][p.y+1]>mmove[p.x][p.y]+1)
		{
			mmove[p.x][p.y+1]=mmove[p.x][p.y]+1;
			q.push( (field){	p.x,p.y+1		} );
		}
		if(p.y-1>=1 && mmove[p.x][p.y-1]>mmove[p.x][p.y]+1)
		{
			mmove[p.x][p.y-1]=mmove[p.x][p.y]+1;
			q.push( (field){	p.x,p.y-1	} );
		}
	    }
	}
	
}
int main()
{
	int t,i,j;
 	field c1,c2,m;
	cin>>r>>col;
	cin>>t;
	while(t--)
	{
		cin>>m.x>>m.y>>c1.x>>c1.y>>c2.x>>c2.y;
		for ( int i = 1; i <=r; ++i ) {
			for ( int j = 1; j <=col; ++j ) {
				mmove[ i ][ j ] = cmove[ i ][ j ] = 1000000;
			}
		}
		cbfs(c1);
		cbfs(c2);
		mbfs(m);
		
		//	for(i=1;i<=r;i++)
	//	{
	//		cout<<mmove[i][1]<<' '<<cmove[i][1]<<endl;
	//	}
		
		
		
		bool kill = true;
		
		for(i=1;i<=r;i++)
		{
			if(mmove[i][1]<cmove[i][1] || mmove[i][col]<cmove[i][col])
			{
				kill=false;
				break;
			}
		}
		
		if(!kill)
		{
		for(i=1;i<=col;i++)
		{
			if(mmove[1][i]<cmove[1][i] || mmove[r][i]<cmove[r][i])
			{
				kill=false;
				break;
			}	
		}
	    }
	    if(kill==false)
	    cout<<"YES\n";
	    else cout<<"NO\n";
	}
}
