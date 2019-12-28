    #include<iostream>
    #define lli long long int
    using namespace std;
    int main(){
      lli n, five=0, two=0;
      cin>>n;
      if(n%2 !=0){
        cout<<0<<endl;
      }
      else{
        lli p = 10;
        while(n / p != 0){
        	five += n/p;
          	p = p * 10;
        }
        cout<<five<<endl;
      }
      return 0;
    }
