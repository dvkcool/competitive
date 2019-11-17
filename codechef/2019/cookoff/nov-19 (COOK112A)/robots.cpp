#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstring>
#define lli long long int
using namespace std;
double calcRad(char c){
  switch(c){
    case '0':
      return 0;
    case '1':
      return 1.0472;
    case '2':
      return 2.0944;
    case '3':
      return 3.14159;
    case '4':
      return 4.18879;
    case '5':
      return 5.23599;
  }
  return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  int t, i, j;
  cin>>t;
  string s;
  int n, q, l, r;
  double xans, yans;
  int count[200000][6];
  while(t>0){
    t--;
    cin>>n>>q;
    cin>>s;
    i =0;
    memset(count, 0, 200000*6*sizeof(count[0][0]));
    int m = s[0] - '0';
    count[0][m]++;
    for(j=1; j<n; j++){
      for(i=0; i<6; i++){
        count[j][i] = count[j-1][i];
      }
      m = s[j] - '0';
      count[j][m]++;
    }
    i =0;
    while(i<q){
      i++;
      cin>>l>>r;
      xans = 0;
      yans = 0;
      m = s[l-1] - '0';
      for(j=0; j<6; j++){
        double p =count[r-1][j] - count[l-1][j];
        if(j==m){
          p++;
        }
        if(p !=0){
          xans += (p * cos(calcRad('0'+j)));
          yans += (p * sin(calcRad('0'+j)));
        }
      }
      cout<<xans<<" "<<yans<<endl;
    }
  }

	return 0;
}
