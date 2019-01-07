#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,x,y;
		cin>>n>>x>>y;
		ll A[n];
		for(int i = 0;i < n;i++){
			cin>>A[i];
		}
		sort(A, A+n);
		ll sum[n];
		sum[0] = A[0];
		for(int i = 1;i < n;i++){
			sum[i] = A[i]+sum[i-1];
		}
//		for(int i = 0;i < n;i++){
//			cout<<sum[i]<<" ";
//		}
//		cout<<endl;
		//initially
		ll valless = sum[0];
		ll valmore = sum[n-1]-sum[0];
		ll cntl = 1;
		ll cntm = n-1;
        ll in = 1;

		ll profit;
		for(ll z = A[0]; z <= A[n-1] ; z++){
            	if(z == A[in]){
            		cntm--;
            		valmore = sum[n-1]-sum[in];
            		valless = sum[in];
            		cntl++;
            		in++;
				}
//				cout<<"z: "<<z<<" valless "<<valless<<" valmore "<<valmore<<" cntless "<<cntl<<" cntmore "<<cntm<<endl;

				ll val = y*(z*cntl-valless)-x*(valmore-z*cntm);
//				cout<<"val: "<<val<<endl;
				if(val > 0){
					profit = val;
					break;
				}
		}
		cout<<profit<<endl;
	}
	return 0;
}
