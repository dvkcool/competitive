#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c[n],b[n];
    for(int i=0;i<n;i++)
    {
      cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
      cin>>b[i];
    }
    long long ans=0;
    vector<int> bus,car;
    for(int i=0;i<n;i++)
    {
      if(b[i]<c[i])
      {
        ans+=b[i];
        bus.push_back(c[i]-b[i]);
      }
      else
      {
        ans+=c[i];
        car.push_back(b[i]-c[i]);
      }
    }
    int bus_sz=bus.size(),car_sz=car.size();
    if(abs(bus_sz-car_sz)<=1)
    {
      cout<<ans<<endl;
    }
    else
    {
      int r=abs(bus_sz-car_sz)/2;
      if(bus_sz>car_sz)
      {
        sort(bus.begin(),bus.end());
        for(int i=0;i<r;i++)
        {
          ans+=bus[i];
        }
      }
      else
      {
        sort(car.begin(),car.end());
        for(int i=0;i<r;i++)
        {
          ans+=car[i];
        }
      }
      cout<<ans<<endl;
    }
}
