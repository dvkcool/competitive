#include<stdio.h>
int main(){
  int n;
  int diff = 0;
  int quesa = 0;
  int quesb = 0;
  int achar[26];
  int bchar[26];
  int ans = 0;
  char a[150000];
  char b[150000];
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  int i;
  for(i=0; i<n; i++){
    if(a[i]=='?'){
      quesa++;
    }
    else{
      int e = a[i] - 'a';
      achar[e]++;
    }
  }
  for(i=0; i<n; i++){
    if(b[i]=='?'){
      quesb++;
    }
    else{
      int e = b[i] - 'a';
      bchar[e]++;
    }
  }
  for(i=0; i<26; i++){
    if(achar[i]==bchar[i]){
      ans+=achar[i];
    }
    else if(achar[i]>bchar[i]){
      diff += ( achar[i] - bchar[i]);
    }
    else if(bchar[i]>achar[i]){
        diff += (bchar[i] - achar[i]);
    }
  }

  return 0;
}
