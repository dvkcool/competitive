    /* Jai Mata Di */
    #include <bits/stdc++.h>
    #define lli long long int
    using namespace std;
     
    int minPoint = 0;
     
    int findNext(int count[], int m, int l){
      int r = l;
      for(int i=m; i<l; i++){
        if(count[i]==0){
          r = i;
          minPoint = i;
          break;
        }
      }
      return r;
    }
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);  cout.tie(0);
      int t, x, modx;
      lli j, result, maxc;
      cin>>t>>x;
      maxc = 0;
      int count[x];
      memset(count, 0, sizeof(count));
      int minIndex = 0;
      int minCount = 0;
      int start = 0;
      while(t>0){
        t--;
        cin>>j;
        modx = j%x;
        count[modx]++;
        if(modx==minIndex){
          minIndex = findNext(count, minIndex, x);
          if(minIndex < x){
            result = start + minIndex;
            cout<<result<<'\n';
          }
          else{
            start += x;
            for(int i=0; i<x; i++) count[i]--;
            minIndex = findNext(count, 0, x);
            result = start + minIndex;
            cout<<result<<'\n';
          }
        }
        else if(minIndex<x){
          result = start + minIndex;
          cout<<result<<'\n';
        }
        else{
          //Will never happen
        }
      }
      return 0;
    }
