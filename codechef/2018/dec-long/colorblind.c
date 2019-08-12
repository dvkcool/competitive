#include <stdio.h>
#include<stdlib.h>
struct dish{
    int c;
    int d;
    struct dish *next;
 };
typedef struct dish *Dish;

Dish head;
Dish last;
void addFrontNode(int cl, int ds){
  Dish temp;
  temp = (Dish)malloc(sizeof(struct dish));
  if(head ==NULL){
    last = temp;
  }
  temp->next = head;
  temp->c = cl;
  temp->d = ds;
  head =temp;
}
void addBackNode(int cl, int ds){
    Dish temp, p;
    temp = (Dish)malloc(sizeof(struct dish));
    temp->c = cl;
    temp->d = ds;
    temp->next = NULL;
    if(head == NULL && last== NULL){
      head = temp;
      last = temp;
    }
    else{
      last->next = temp;
      last = temp;
    }
}

int checkdish(int cm, int k){
  int max = 0;
  Dish p;
  p = head;
  int ct=0;
  while(p!=NULL){
    if(p->c >=(cm-k) && p->c <=(cm+k)){
      ct = ct + p->d;
    }
    else{
      if(ct>max){
        max = ct;
      }
      ct = 0;
    }
  }
  return max;
}
int main(){
  head = NULL;
  int n, k;
  scanf("%d%d", &n, &k);
  int i=0;
  int r = 0;
  for(i=0; i<n; i++){
    int p;
    scanf("%d", &p);
    if(p==1){
      int cm, dm;
      scanf("%d%d",&cm, &dm);
      cm = cm^r;
      addFrontNode(cm, dm);
    }
    else if(p==2){
      int cm, dm;
      scanf("%d%d",&cm, &dm);
      cm = cm^r;
      addBackNode(cm, dm);
    }
    else{
      int cm;
      scanf("%d", &cm);
      cm = cm ^r;
      r = checkdish(cm, k);
      printf("%d\n", r);
    }
  }
  return 0;
}
