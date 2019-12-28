#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int t[n], a, oddCount=0, evenCount=0, oddA[n], evenA[n];
    
    for(int i=0; i<n; i++){
        cin>>a;
        if(a%2 ==0){
            evenA[evenCount++] = a;
}
else{
    oddA[oddCount++] = a;
}
t[i] = a;
}
if(oddCount==0 || evenCount==0){
    for(int i=0; i<n; i++) cout<<t[i]<<' ';
cout<<endl;
return 0;
}
sort(evenA, evenA+evenCount);
sort(oddA, oddA+oddCount);
int i =0, j =0;
while(i<evenCount && j<oddCount){
    a= min(evenA[i], oddA[j]);
    if(a==evenA[i]){
        i++;
    }
    else{
        j++;
    }
    cout<<a<<' ';
}
while(i<evenCount){
    cout<<evenA[i]<<' ';
    i++;
}
while(j<oddCount){
    cout<<oddA[j]<<' ';
    j++;
}
cout<<endl;
return 0;
}

