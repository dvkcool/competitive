#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  int n, m;
  cin>>n>>m;
  int a[n][m];
  int b[n][m];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>a[i][j];
      b[i][j] = 0;
    }
  }
  int r = 0;
  vector<int> g;
  vector<int> h;
  for(int i=0; i<n-1; i++){
    for(int j=0; j<m-1; j++){
      if(a[i][j]!=b[i][j]){
        if(b[i][j]==0){
          b[i][j] = 1;
          b[i+1][j] = 1;
          b[i][j+1] = 1;
          b[i+1][j+1]=1;
          g.push_back(i+1);
          h.push_back(j+1);
          r++;
        }
        else{
          cout<<-1<<endl;
          return 0;
        }
      }
      else if(a[i][j]==1 && (a[i+1][j]!=0 && (a[i][j+1]!=0 && a[i+1][j+1]!=0))){
        b[i][j] = 1;
        b[i+1][j] = 1;
        b[i][j+1] = 1;
        b[i+1][j+1]=1;
        g.push_back(i+1);
        h.push_back(j+1);
        r++;
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(a[i][j] != b[i][j]){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  cout<<r<<endl;
  vector<int>::iterator gt;
  vector<int>::iterator ht;
  ht = h.begin();
  for(gt=g.begin(); gt<g.end(); gt++, ht++){
    cout<<*gt<<" "<<*ht<<endl;
  }


	return 0;
}
