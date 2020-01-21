    /* Jai Mata Di */
    #include <bits/stdc++.h>
    #define mod 1000000007
    #define lli long long int
    using namespace std;
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);  cout.tie(0);
      int n, m, l, temp;
      cin>>n>>m>>l;
      int count[m];
      for(int i=0; i<m; i++) count[i] = 0;
      for(int i=0; i<l; i++){
        cin>>temp;
        count[temp%m]++;
      }
      lli dp[2][m];
      int prev = 0;
      int cur = 1;
      for(int i=0; i<m; i++){
        dp[0][i] = count[i];
      }
      for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
          dp[cur][j] = 0;
        }
        for(int j=0; j<m; j++){
          for(int k=0; k<m; k++){
            dp[cur][(j+k)%m] = (dp[cur][(j+k)%m] + ((dp[prev][j] % mod) * (count[k]%mod))%mod)%mod;
          }
        }
        cur = cur==1 ? 0: 1;
        prev = prev==1? 0 : 1;
      }
      // To get cur
      cur = cur==1 ? 0: 1;
      prev = prev==1? 0 : 1;
      cout<<dp[cur][0]<<endl;
      return 0;
    }
