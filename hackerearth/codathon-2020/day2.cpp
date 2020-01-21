    /* Jai Mata Di */
    #include <bits/stdc++.h>
    #define lli long long int
    using namespace std;
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);  cout.tie(0);
      int n, t;
      cin>>n;
      int a[n];
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          cin>>t;
          if(i==j){
            a[i] = t;
          }
        }
      }
      int b[n+1];
      b[0] = a[0]; b[n] = 0;
      for (int i = 1; i < n; i++)
            b[i] = a[i] ^ a[i - 1];
      int q, g, h, k;
      cin>>q;
      for(int i=0; i<q; i++){
        cin>>t>>g>>h>>k;
        g--;
        b[g] = b[g]^k;
        b[h] = b[h] ^k;
        /*
        for(; g<=h; g++){
          a[g] = a[g] ^ k;
        }
        */
      }
      lli sum = 0;
      /*
      for(int i=0; i<n; i++){
        sum += a[i];
      }
      */
      for (int i = 0; i < n; i++) {
              if (i == 0)
                  a[i] = b[i];
              else
                  a[i] = b[i] ^ a[i - 1];
     
              sum += a[i];
      }
      cout<<sum<<endl;
      return 0;
    }
