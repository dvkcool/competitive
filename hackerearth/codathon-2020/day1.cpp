    /* Jai Mata Di */
    #include <bits/stdc++.h>
    using namespace std;
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);  cout.tie(0);
      int n, k;
      cin>>n>>k;
      int a[n];
      for(int i=0; i<n; i++) cin>>a[i];
     
      int l =0, r = n-1;
      int count =0;
      while(l<n){
        if(a[l]<= k) count++;
        else break;
        l++;
      }
      if(count<n){
        while(r>=l){
          if(a[r]<= k) count++;
          else break;
          r--;
        }
      }
      cout<<(n-count)<<endl;
      return 0;
    }
