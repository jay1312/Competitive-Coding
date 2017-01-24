// before going forward do study "how does bitwise sieve works".
// http://code.cloudkaksha.org/algorithm/bit-magic/bitwise-sieve-of-eratosthenes
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000
#define LIM 10000

int flagArr[MAX>>6];
#define ifComp(x) (flagArr[x>>6]&(1<<((x>>1)&31)))
#define isComp(x) (flagArr[x>>6]|=(1<<((x>>1)&31)))
int arr[8000010];
void BitSeive()
{
       register int i,j,k;
       for(i=3;i<LIM;i+=2)
       {
              if(!ifComp(i))
              {
                     for(j=i*i,k=i<<1;j<MAX;j+=k)
                            isComp(j);
              }	
       }
       arr[0]=2;
       for(i=3,j=1; j<=8000010;i+=2)
       {
              if(!ifComp(i))
              {
                     arr[j]=i;	
                     j++;	
              }	
       }
}

int main() {
       BitSeive();
       int t,i;
    //   cout<<arr[8000010];
       for(i=0;arr[i]<=100000000;i=i+100)
       cout<<arr[i]<<endl;
       return 0;
}
