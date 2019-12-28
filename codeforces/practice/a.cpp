#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0; i<2*n; i++){
        cin>>a[i];
    }
    int count  = 0 ;
    for(int i=1; i<2*n; i++){
        if(a[i] == a[0]){
            count++;
        }
    }
    if(count == (2*n -1)){
        cout<<-1<<endl;
        return 0;
    }
    int leftSum = 0, rightSum = 0;
    for(int i=0; i<n; i++) leftSum += a[i];
    for(int i=n; i<2*n; i++) rightSum += a[i];
    if(leftSum != rightSum){
        for(int i=0; i<2*n; i++) cout<<a[i]<<' ';
        cout <<endl; return 0;
    }
    for(int i=0; i<n; i++){
        count =0;
        for(int j=n; j<2*n; j++){
            if(a[i] != a[j]){
                int t = a[j];
                a[j] = a[i];
                a[i] = t;
                count =1;
                break;
            }
        }
        if(count) break;
    }
    for(int i=0; i<2*n; i++) cout<<a[i]<<' ';
        cout <<endl; return 0;


    return 0;
}

