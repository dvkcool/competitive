#include<stdio.h>
void check(int h){
  int i =1;
  while(i<=h){
    printf("1 %d", i);
    int r;
    scanf("%d", &r);
    if(r==1 && i==1){
      printf("2\n3 1\n");
    }
    else if(r==1){
      int j = i-250;
      printf("1 %d\n", j);
      int rt;
      scanf("%d", &rt);
      if(rt==1){
        printf("2\n");
        i = j;
        j = j-250 +1;
      }
      else if(rt==-1){
        return;
      }
      else if(rt == 0){
        j++;
      }
      for(;j<i; j++){
        printf("1 %d\n",j);
        int ry;
        scanf("%d", &ry);
        if(ry==1){
          printf("2\n3 %d\n", j);
          return;
        }
      }
      printf("3 %d\n", i);
      return;
    }
    i+=500;
  }
  int j = i-250;
  printf("1 %d\n", j);
  int rt;
  scanf("%d", &rt);
  if(rt==1){
    printf("2\n");
    i = j;
    j = j-250+1;
  }
  else if(rt==-1){
    return;
  }
  else if(rt == 0){
    j++;
  }
  for(;j<n; j++){
    printf("1 %d\n",j);
    int ry;
    scanf("%d", &ry);
    if(ry==1){
      printf("2\n3 %d\n", j);
      return;
    }
  }
  printf("3 %d\n", n);
  return;

}
int main(){
  int n, c;
  scanf("%d %d", &n, &c);
  check(n);
  return 0;
}
