    /* Jai Mata Di */
    #include <bits/stdc++.h>
    #define mod 1000000007
    #define lli long long int
    using namespace std;
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);  cout.tie(0);
      lli r = 0;
      int n; string s;
      vector<int> a, b;
      cin>>n>>s;
      lli pow2mod[n];
      pow2mod[0] = 1;
      for(int i=1; i<n; i++){
        pow2mod[i] = (pow2mod[i-1] * 2)%mod;
      }
      char x, y;
      cin>>x>>y;
      for(int i=0; i<n; i++){
        if(s[i]==x){
          a.push_back(i);
        }
        else if(s[i]==y){
          b.push_back(i);
        }
      }
      if(x==y){
          for(int i=0; i<a.size(); i++){
              b.push_back(a[i]);
          }
      }
      if(a.size()==0 || b.size()==0){
          cout<<0<<endl;
          return 0;
      }
      int i = a.size() -1;
      int j;
      for(j=b.size() -1; j>=0; j--){
        if(b[j]<=a[i])
        break;
        //cout<<b[j] - a[i]<<endl;
        r = r + pow2mod[b[j] - a[i]-1];
       // cout<<r<<endl;
      }
      int p;
      lli prev, cur;
      prev = r;
      for(i=i-1; i>=0; i--){
        p = a[i+1] - a[i];
        //r = (r + (((r* pow2mod[p])%mod)* 2)%mod)%mod;
        cur = (prev* pow2mod[p])%mod;
        for(; j>=0; j--){
          if(b[j]<=a[i])
          break;
          //cout<<b[j] - a[i]<<endl;
          cur = cur + pow2mod[b[j] - a[i]-1];
        }
        prev= cur;
        r = (r+cur)%mod;
        //cout<<r<<endl;
      }
      if(x==y){
          r = r + a.size();
          r = r % mod;
      }
      cout<<r<<endl;
      return 0;
    }
