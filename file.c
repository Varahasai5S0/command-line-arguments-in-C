#include<stdio.h>
#include<stdlib.h> 
int max=-1;
double avg;
void printfile(FILE *fptr)
{
   int c,i,num;
   double sum=0;
   rewind(fptr);
   c=getc(fptr);
   for(i=0;i<c;i++)
   {
      num=getc(fptr); 
      if(max<num)
         max=num;
      sum+=num;
   }
   avg=sum/c; 
   printf("Max is:%d",max);
   printf("Average is:%lf",avg);
} 
void doublespace(FILE *ofp)
{
   putc(avg,ofp);
   putc(max,ofp);
} 
int main(int argc,char *argv[])
{
   FILE *ifp,*ofp;
   ifp=fopen(argv[1],"r+");
   ofp=fopen("answer-hw3","w+");  
   printf("reading from file");
   printfile(ifp); 
   printf("Writing into file");
   doublespace(ofp);
   ifp.close();
   ofp.close();
   return 0;  
}
