#include <stdio.h>
#include<stdlib.h>
struct numt{
    int val;
    int r;
    struct numt *next;
 };
typedef struct numt *Numt;
int qa = -1;
int qb = -1;

Numt head;
Numt Last;
void addN(int v, int vr){
  Numt temp;
  temp = (Numt)malloc(sizeof(struct numt));
  temp->val = v;
  temp->r = vr;
  temp->next =NULL;
  if(head==NULL){
    head = temp;
    Last = temp;
  }
  else{
    Last->next = temp;
    Last = temp;
  }
}

void peekt(){
  Numt temp = head;
  if(temp->r >0){
    temp->r = temp->r -1;
    qa = temp->val;
    if(temp->r == 0){
      head = temp->next;
      free(temp);
      temp = head;
      temp->r = temp->r -1;
      qb = temp->val;
      if(temp->r == 0){
        head = temp->next;
        free(temp);
        temp = head;
      }
    }
    else{
      temp = temp->next;
      temp->r = temp->r -1;
      qb = temp->val;
      if(temp->r == 0){
        head = temp->next;
        free(temp);
        temp = head;
      }
    }
  }

}
int main(){
  head = NULL;
  int cases;
  scanf("%d", &cases);
  int i =0;
  for(i=0; i<cases; i++){
    int n;
    scanf("%d", &n);
    int result[n];
    int a, b, c, dr, e, f;
    printf("\n1 1 2 3");
    scanf("%d", &a);
    printf("\n1 2 3 4");
    scanf("%d", &b);
    printf("\n1 1 2 4");
    scanf("%d", &c);
    // 1 3 4
    dr = a^b;// 1 4
    e = b^c;// 1 3
    f = c^a;// 3 4
    int big = a > b ? (a > c ? a : c) : (b > c ? b : c) ;
    int smal = a < b ? (a < c ? a : c) : (b < c ? b : c) ;
    int m, l, p, t;
    int stopme = 0;
    for(m=smal; m<=big; m++){
      for(l=smal; l<=big; l++){
        if(m==l){
          continue;
        }
        if((m^l) == e){
            for(p =smal; p<=big; p++){
                if(l==p || m==p){
                    continue;
                }
                if(((m^p )== dr) && ((l^p) ==f)){
                    t = ((a ^ m)^l);
                    if(t==m || t==l ||t==p){
                        continue;
                    }
                    if(((m^t)^l)==a){
                        if(((t^l)^p)==b){
                            if(((m^t)^p)==c){
                                stopme = 1;
                                break;
                            }
                        }
                    }

                }
            }
        }
        if(stopme){
          break;
        }
      }
      if(stopme){
        break;
      }
    }
    result[0] = m;
    result[2] = l;
    result[3] = p;
    result[1] = ((a ^ m)^l);
    head = NULL;
    addN(1, 1);
    addN(3, 1);
    addN(4, 1);
    int y = 5;
    while(y<=n){
      peekt();
      printf("\n1 %d %d %d", qa, qb, y);
      int mr;
      scanf("%d", &mr);
      result[y-1] = ((mr ^ result[qa-1])^result[qb-1]);
      addN(y, 2);
      y++;
    }
    y=0;
    printf("\n2");
    while(y<n){
      printf(" %d", result[y]);
      y++;
    }
    int yt = 0;
    scanf("%d", &yt);
    if(yt==-1){
      break;
    }

  }
  return 0;
}
