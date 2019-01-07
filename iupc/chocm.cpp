#include<bits/stdc++.h>
using namespace std;

 int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low-1); // index of smaller element
  for (int j=low; j<high; j++)
  {
      // If current element is smaller than or
      // equal to pivot
      if (arr[j] <= pivot)
      {
          i++;

          // swap arr[i] and arr[j]
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
      }
  }

  // swap arr[i+1] and arr[high] (or pivot)
  int temp = arr[i+1];
  arr[i+1] = arr[high];
  arr[high] = temp;

  return i+1;
}


/* The main function that implements QuickSort()
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
 void sort(int arr[], int low, int high)
{
  if (low < high)
  {
      /* pi is partitioning index, arr[pi] is
        now at right place */
      int pi = partition(arr, low, high);

      // Recursively sort elements before
      // partition and after partition
      sort(arr, low, pi-1);
      sort(arr, pi+1, high);
  }
}


 int piece( int m, int n, int l){
  int d = n-m;
  if(d>=l){
    return 0;
  }
  if(m>=l){
    return 0;
  }
  return a[d][m];
}

int main(){
	int n,k;
	cin>>n>>k;
  int a[300001][300001];
  int q[k];
	for(int i = 0;i < n;i++){
		cin>>a[0][i];
	}
	for(int i = 0;i < k;i++){
		cin>>q[i];
	}
  for(int i=1; i<n; i++){
    for(int j=0; j<(n-i); j++){
      a[i][j] = a[i-1][j] + a[0][i+j];
    }
  }


  for(int i=0; i<k; i++){
    sort(q, 0, i);
    int st = 0;
    int max = 0;
    for(int j=0; j<=i; j++){
      int d = q[j]-1-st;
      int kr =  a[d][st];
      st = q[j];
      if(kr>max){
        max = kr;
      }
    }
    int d = n-1-st;
    int kr =  a[d][st];
    if(kr>max){
      max = kr;
    }
    cout<<max<<endl;
  }


	return 0;
}
