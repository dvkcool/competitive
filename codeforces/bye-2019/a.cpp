#include <iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin>>t;
  while(t>0){
    t--;
    int n, k1, k2, p;
    cin>>n>>k1>>k2;
    int max1 = 0, max2 = 0;
    for(int i=0; i<k1; i++){
      cin>>p;
      max1 = max(max1, p);
    }
    for(int i=0; i<k2; i++){
      cin>>p;
      max2 = max(max2, p);
    }
    if(max1 < max2){
      cout<<"NO"<<endl;
    }
    else{
      cout<<"YES"<<endl;
    }
  }

  return 0;
}
