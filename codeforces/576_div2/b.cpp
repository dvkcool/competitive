#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
#define lli long long int
int main(){
  lli l, h, ht;
  cin>>h>>l;
  l = l*l;
  ht = h;
  h = h* h;
  l = l -h;
  float x = l;
  //cout<<x<<endl;
  x =x /2;
  //cout<<x<<endl;
  x = x/ht;
  cout <<fixed<<setprecision(12)<< x << endl;
  return 0;
}
