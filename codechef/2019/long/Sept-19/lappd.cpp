#include "bits/stdc++.h"
#define MOD 1000000007
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;
int f(int x,int y){return int((x*1.0*x)/y);}
int mod(long long x){return (x%MOD);}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
	    int a,b,c,ans=0;
	    scanf("%d%d%d",&a,&b,&c);
	    //(a-1)(c-1)>b*b and a>1
		for(int i=1;i<=b;i++){
			ans=mod(max(0,c-i-1)*1LL*max(0,a-i-1)+ans);
			for(int j=2;j<=min(a,i+1);j++)
				ans=mod(ans+max(0,c-f(i,j-1)-1));
			for(int j=2;j<=min(c,i+1);j++)
				ans=mod(ans+max(0,a-f(i,j-1)-1));
		}
		printf("%d\n",ans);
	}
	return 0;
}
