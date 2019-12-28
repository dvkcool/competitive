#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    
    int a[100000]= {0};
    int val = 1;
    for(int i=2; i<=n; i++){
        if(a[i]==0){
            for(int j=i; j<=n; j+= i){
                a[j] = val;
            }
            val++;
}
cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}
    

