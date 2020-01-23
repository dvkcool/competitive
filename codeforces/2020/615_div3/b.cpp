    /* Jai Mata Di */
    #include <bits/stdc++.h>
    using namespace std;
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);  cout.tie(0);
      int t, n, x, y, j, k, could;
      cin>>t;
      while(t>0){
        t--;
        vector<pair<int, int> > points;
        cin>>n;
        while(n>0){
          n--;
          cin>>x>>y;
          points.push_back(make_pair(y, x));
        }
        sort(points.begin(), points.end());
        vector<char> result;
        x =0, y=0, could = 1;
        for(int i=0; i<points.size(); i++){
          k = points[i].first;
          j = points[i].second;
          if(j<x){
            could = 0;
            break;
          }
          k = k - y;
          j = j - x;
          y = points[i].first;
          x = points[i].second;
          while(j>0){
            j--;
            result.push_back('R');
          }
          while(k>0){
            k--;
            result.push_back('U');
          }
        }
        if(could ==0){
          cout<<"NO\n";
          continue;
        }
        else{
          cout<<"YES\n";
        }
        for(auto x: result){
          cout<<x;
        }
        cout<<'\n';
      }
      return 0;
    }
