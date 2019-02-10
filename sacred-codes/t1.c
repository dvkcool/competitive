#include<stdio.h>
#include<math.h>

int main(){

  int cases, n, q, i, j;
  char m;
  scanf("%d", &cases);
  char teams[100000][3][20];
  int d[100000];
  while(cases>0){
    cases--;
    scanf("%d %d", &n, &q);
    memset(d, 0, n*sizeof(d[0]));
    for(i=0; i<n; i++){
      scanf("%d %s %c",&j, &t, &m);
      if(m=='Y'){
        teams[j-1][1] = temp;
      }
      else{
        teams[j-1][]
      }
    }


  }
  return 0;
}
