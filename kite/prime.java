
class prime
{
public static void main(String[] args)
{
int p;
int c = 0;
for(int i=2;i<100000;i++)
{
p=0;
for(int j=2;j<i;j++)
{
if(i%j==0)
p=1;
}
if(p==0){
System.out.print(i+",");
c++;
if((c%20)==0){
  System.out.println("");
}
}
}
}
}
