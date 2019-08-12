#include<iostream>
#include <cstring>
#include<algorithm>
#define lli long long int
using namespace std;
lli n;
struct PosXOR
{
public:
    lli val;
    lli pos;
    //PosXOR(lli k, lli s) : val(k), pos(s) {}
    /*
    bool operator < (const PosXOR& str) const
    {
        return (val < str.val);
    }
    */
};
PosXOR posxor[100001];
void merge(lli l, lli m, lli r)
{
    lli i, j, k;
    lli n1 = m - l + 1;
    lli n2 =  r - m;
    PosXOR L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = posxor[l + i];
    for (j = 0; j < n2; j++)
        R[j] = posxor[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].val <= R[j].val)
        {
            posxor[k] = L[i];
            i++;
        }
        else
        {
            posxor[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        posxor[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        posxor[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(lli l, lli r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        lli m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(l, m);
        mergeSort(m+1, r);

        merge(l, m, r);
    }
}
void solve(){
  n=0;
  cin>>n;
  cin>>posxor[0].val;
  posxor[0].pos = 0;
  lli t = 0;
  for(lli i=1; i<n; i++){
    cin>>posxor[i].val;
    posxor[i].pos = i;
    posxor[i].val = posxor[i-1].val ^ posxor[i].val;
  }
  mergeSort(0, n-1);
  lli r = 0;
  for(lli i=0; i<n; i++){
    //cout<<posxor[i].val<<endl;
    if(posxor[i].val==0){
      r = r + posxor[i].pos;
    }
    else{
      break;
    }
  }
  for(lli i=0; i<(n-1);i++){
    lli x= 0;
    lli m  = 0;
    for(lli j=i+1; j<n; j++){
      if(posxor[j].val==posxor[i].val){
        x++;
        m = m+ x;
        //r = r + posxor[j].pos -  posxor[i].pos - 1;
      }
      else{
        break;
      }
    }
    lli e = x;
    lli u = e;
    //cout<<x<<" "<<m<<endl;
    //cout<<" before calc"<<r<<endl;
    while(x>=0){
      //cout << r<<endl;
      //cout<<e*posxor[i+x].pos<<endl;
      r = r + (e*posxor[i+x].pos);
      e = e-2;
      x--;
    }
    r = r - m;
    i = i +u;
  }
  cout<<r<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(0);
  int cases;
  cin>>cases;
  while(cases){
    cases--;
    solve();
  }
  return 0;
}
