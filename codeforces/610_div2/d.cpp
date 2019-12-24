#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  lli m, n, t, a, b, x, maxQ, easyTotal, hardTotal;
  lli q[200001];
  cin>>m;
  while(m>0){
    m--;
    maxQ = 0;
    easyTotal=0; hardTotal=0;
    cin>>n>>t>>a>>b;
    for(lli i=0; i<n; i++){
      cin>>q[i];
      if(q[i]){
        hardTotal++;
      }
      else{
        easyTotal++;
      }
    }
    map<lli, int[2]> Qcount;
    for(lli i=0; i<n; i++){
      cin>>x;
      if(q[i]){
        Qcount[x][1]++;
      }
      else{
        Qcount[x][0]++;
      }
    }
    map<lli, int[2]>::iterator itr;
    itr = Qcount.begin();
    lli tr = itr->first;
    tr--;
    lli easyDone = 0;
    lli hardDone = 0;
    lli easyCount = 0;
    lli hardCount = 0;
    if(tr>0){
      easyDone = tr/a;
      easyDone = min(easyDone, easyTotal);
      maxQ = easyDone;
      tr -= ((easyDone)*a );
      if(tr>0){
        hardDone = tr/b;
        hardDone = min(hardDone, hardTotal);
        maxQ += hardDone;
      }
    }
    //cout<<maxQ<<endl;
    for(; itr != Qcount.end(); ++itr){
        if(easyCount*a + hardCount*b < itr->first){
            maxQ = max(maxQ, easyCount + hardCount);
            tr = itr->first;
            tr--;
            tr -= easyCount*a + hardCount*b;
            if(tr>0){
              easyDone = 0; hardDone = 0;
              easyDone = tr/a;
              easyDone = min(easyDone, easyTotal-easyCount);
              tr -= ((easyDone)*a );
              if(tr>0){
                hardDone = tr/b;
                hardDone = min(hardDone, hardTotal-hardCount);
              }
                maxQ = max(maxQ, easyCount + hardCount + hardDone+ easyDone);
            }
        }

      easyCount += itr->second[0];
      hardCount += itr->second[1];
      tr = itr->first;
      tr -= ((easyCount)*a );
      tr -= ((hardCount)*b );
      //cout<<easyDone<<" "<<hardDone<<" "<<itr->first<<endl;
      if(tr >=0){
        maxQ = max(easyCount+ hardCount, maxQ);
        if(tr>0){
            easyDone = 0; hardDone = 0;
            easyDone = tr/a;
            easyDone = min(easyDone, easyTotal- easyCount);
            tr -= ((easyDone)*a );
            if(tr>0){
                hardDone = tr/b;
                hardDone = min(hardDone, hardTotal-hardCount);
            }
            maxQ = max(easyCount+ hardCount+easyDone+hardDone, maxQ);
        }
        //cout<<maxQ<<endl;
      }
    }
      tr = t;
      tr -= ((easyCount)*a );
      tr -= ((hardCount)*b );
      //cout<<easyDone<<" "<<hardDone<<" "<<itr->first<<endl;
      if(tr >=0){
        maxQ = max(easyCount+ hardCount, maxQ);
        //cout<<maxQ<<endl;
      }
    cout<<maxQ<<endl;




  }

  return 0;
}
