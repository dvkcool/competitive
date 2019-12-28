#include<iostream>
#include<vector>
using namespace std;
int main(){
    
    int n, x;
    cin>>n>>x;
    int visited[(1<<18) + 2] = {0};
    for(int i=1; i< 1<<n; i++){
        if(!visited[i])
            visited[i^x] = 1;
}
vector<int> result;
int start = 0;
for(int i=1; i< 1<<n; i++){
        if(!visited[i]){
            result.push_back(i^start);
            start = i;
        }
    }
cout<<result.size()<<endl;
for(int i=0; i<result.size(); i++){
    cout<<result[i]<<' ';
}
cout<<endl;
return 0;
}

