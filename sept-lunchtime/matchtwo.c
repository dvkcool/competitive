#include<stdio.h>
int main(){
        int cases;
        scanf("%d", &cases);
        int i =0; int j=0;
        for(i=0; i<cases; i++){
            int n, q;
            scanf("%d", &n);
            scanf("%d", &q);
            int a[n];
            int b[n];
            int result = 0;
            for(j=0; j<n; j++){
              scanf("%d", &a[j]);
            }
            for(j=0; j<n; j++){
              scanf("%d", &b[j]);
              if(a[j]==b[j]){
                result = result+1;
              }
              a[j] = result;
            }
            for(j=0; j<q; j++){
              int l, r, qw;
              scanf("%d", &l);
              scanf("%d", &r);
              scanf("%d", &qw);
              l = l ^ result;
              r = r ^ result;
              result = 0;
              if(l<1){
                l=1;
              }
              int k;
              for(k=l-1; (k<r && k>=0) && k<n; k++){
                if(b[k] == qw){
                  result++;
                }
              }
              if(l>1){
                result = result + a[l-1];
              }
              if(r<(n-1)){
                result = result + a[n-1] - a[r];
              }
              printf("%d\n", result);
            }
          }


  return 0;
}
