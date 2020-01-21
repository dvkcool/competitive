    /* Jai Mata Di */
    #include <bits/stdc++.h>
    #define lli long long int
    using namespace std;
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);  cout.tie(0);
      int n = 100000;
      bool prime[n+1];
      memset(prime, true, sizeof(prime));
      prime[1] = false;
      for (int p=2; p*p<=n; p++)
      {
          if (prime[p] == true)
          {
              for (int i=p*p; i<=n; i += p)
                  prime[i] = false;
          }
      }
      int b_size = sqrt(n);
      int tot_size = ceil(sqrt(n));
      tot_size++;
      int sq_count[tot_size];
      int count[n+1]; int q;
      memset(count, 0, sizeof(count));
      memset(sq_count, 0, sizeof(sq_count));
      cin>>q;
      int a, l, r, x, rootx, bnum;
      for(int i=0; i<q; i++){
        cin>>a;
        if(a==1){
          cin>>x;
          rootx = sqrt(x);
          for(int i=1; i<=rootx; i++){
            if(x%i==0){
              if(prime[i]){
                count[i]++;
                bnum = i / b_size;
                sq_count[bnum]++;
              }
              if(x/i != i && prime[x/i]){
                count[x/i]++;
                bnum = (x/i) / b_size;
                sq_count[bnum]++;
              }
            }
          }
        }
        else{
          cin>>l>>r;
          lli sum = 0;
          while (l<r and l%b_size!=0 and l!=0){
            sum += count[l];
            l++;
          }
          while (l+b_size <= r)
          {
            sum += sq_count[l/b_size];
            l += b_size;
          }
          while (l<=r)
          {
              sum += count[l];
              l++;
          }
    			cout<<sum<<'\n';
        }
      }
    	/*
    	for(int i=0; i<n; i++){
    		if(count[i]){
    			cout<<" i: "<<i<<" "<<count[i]<<'\n';
    		}
    	}
    	*/
     
      return 0;
    }
