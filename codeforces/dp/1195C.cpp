/*
 * BasketBall team choice problem 1195C
 * Happy Coding
 * Divyanshu Kumar
 */
#include<bits/stdc++.h>

using namespace std;

int main()
{
   // cout<<"Hello World";
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    long long int maxSum[2][n];
    maxSum[0][n-1] = a[n-1];
    maxSum[1][n-1] = b[n-1];
    for(int i =n-2; i>=0; i--){
        maxSum[0][i] = max((a[i]+maxSum[1][i+1]), maxSum[0][i+1]);
        maxSum[1][i] = max((b[i]+maxSum[0][i+1]), maxSum[1][i+1]);
    }
    cout << max(maxSum[0][0], maxSum[1][0])<<endl;
    return 0;
}
