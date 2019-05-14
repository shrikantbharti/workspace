#include<stdio.h>
struct term
{
  int f_no;
  char bit;
  int count;
};
typedef struct term pterm;
void display_buffer(int buffer[10],int no_of_frames)
{
  int k;
       for(k=0;k<no_of_frames;k++)
	  {
	    if(buffer[k]!=-1)
	       printf("%4d",buffer[k]);
	     else
		   printf("   -");
	  }
}
void init( int buffer[10], pterm pg_table[10], int no_of_frames)
{
   int i;
   for(i=0;i<no_of_frames;i++)
      buffer[i] = -1;
   for(i=0;i<10;i++)
     pg_table[i].bit = 'I'; // set invalid for all pages
}
void fifo(int refstr[20],int n,int no_of_frames)
{
   pterm pg_table[10];

   int i,j,k,p,pg_no,front,buffer[10];
   int page_faults = 0;
   j=0; front = 0;

   init(buffer,pg_table,no_of_frames);
   printf("\n Page Replacement Using FIFO\n");
   printf("\n");
   for(i=0;i<n;i++)
   {
      pg_no = refstr[i];
      printf("\n%4d",pg_no);
      if(pg_table[pg_no].bit == 'I') // page fault
	{
	  if(j<no_of_frames)  // page fault but free frame available
	      {
		buffer[j] = pg_no;
		j++;
	       }
	  else // page replacement
	  {
	     p = buffer[front];
	     pg_table[p].bit = 'I';
	     buffer[front] = pg_no;
	     front = (front +1)%no_of_frames;
	   }
	     pg_table[pg_no].bit = 'V';
	     page_faults++;
	     display_buffer(buffer,no_of_frames);
	     printf("   F");
	    

       }// end of page fault
     } // end of for
     printf("\n total page faults =%d",page_faults);
     
 }
 
 void lru(int refstr[20],int n,int no_of_frames)
 {
   pterm pg_table[10];
   int i,j,k,p,pg_no,front,buffer[10];
   int page_faults = 0;
   int r,m,found,min;
   j=0;
   init(buffer,pg_table,no_of_frames);
      printf("\n Page Replacement Using LRU\n");
      printf("\n");
   for(i=0;i<n;i++)
   {
      pg_no = refstr[i];
      pg_table[pg_no].count = i;
      printf("\n%4d",pg_no);
      if(pg_table[pg_no].bit == 'I') // page fault
	{
	  if(j<no_of_frames)  // page fault but free frame available
		 {
		  buffer[j] = pg_no;
		  j++;
	       }
	  else // page replacement
	  {
	    // r will be index into buffer & buffer[r] will be page replaced
	      min = 99;
	      for(k=0;k<no_of_frames;k++)
		{
		    p = buffer[k];
		    if(pg_table[p].count < min)
		       {
			  min = pg_table[p].count;
			  r=k;
		       }
	       }
	       p=buffer[r];
	       buffer[r] = pg_no;
	       pg_table[p].bit = 'I';
	   } // end of page replacement
	     pg_table[pg_no].bit = 'V';
	     page_faults++;
	     display_buffer(buffer,no_of_frames);
	     printf("   F");
	     
       }// end of page fault
     } // end of for
     printf("\n total page faults =%d",page_faults);
     
 }
 int main()
 {
 int refstr[25],i, n, no_of_frames;
 
 printf("enter length of ref string ");
 scanf("%d",&n);
 printf("enter nof of frames ");
 scanf("%d",&no_of_frames);
 printf("enter refrence string\n");
 for(i=0;i<n;i++)
   {
     printf("refstr[%d] ",i);
     scanf("%d",&refstr[i]);
    }
  fifo(refstr, n, no_of_frames);
  
  lru(refstr, n, no_of_frames);
 return 0;
 }

/*
OUTPUT:

ibm@IBM:~$ cd Desktop
ibm@IBM:~/Desktop$ gcc ass6.c
ibm@IBM:~/Desktop$ ./a.out
enter length of ref string 11
enter nof of frames 3
enter refrence string
refstr[0] 2
refstr[1] 3
refstr[2] 0
refstr[3] 4
refstr[4] 2
refstr[5] 1
refstr[6] 0
refstr[7] 2
refstr[8] 3
refstr[9] 0
refstr[10] 2

 Page Replacement Using FIFO


   2   2   -   -   F
   3   2   3   -   F
   0   2   3   0   F
   4   4   3   0   F
   2   4   2   0   F
   1   4   2   1   F
   0   0   2   1   F
   2
   3   0   3   1   F
   0
   2   0   3   2   F
 total page faults =9
 Page Replacement Using LRU


   2   2   -   -   F
   3   2   3   -   F
   0   2   3   0   F
   4   4   3   0   F
   2   4   2   0   F
   1   4   2   1   F
   0   0   2   1   F
   2
   3   0   2   3   F
   0
   2
 total page faults =8


*/






