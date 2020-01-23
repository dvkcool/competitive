    /* Jai Mata Di */
    #include <bits/stdc++.h>
    using namespace std;
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);  cout.tie(0);
      int t, a, b, c, n, s, maxt;
      cin>>t;
      while(t>0){
        t--;
        cin>>a>>b>>c>>n;
        maxt = max(a, max(b, c));
        s = a+ b+ c+ n;
        if(s%3==0 && s/3 >= maxt) cout<<"YES\n";
        else cout<<"NO\n";
      }
      return 0;
    }
