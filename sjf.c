#include<stdio.h>
#include<stdlib.h>

struct s{
int name;
int at;
int bt;
int wt;
int tat;
int rt;

};
typedef struct s node;

node p[10];
  int n;


void accept()

{
  int i;
  for(i=0; i<n; i++)
  {
    printf("enter details for process P%d \n",i);
    p[i].name = i;
    printf("enter arrival time ");
    scanf("%d",&p[i].at);
    printf("enter burst time ");
    scanf("%d",&p[i].bt);
    p[i].rt=p[i].bt;
    p[i].wt = 0;
    p[i].tat = 0;
  }
}


void display()
{
  int i;
  printf("\n\n\n\tPname     at     bt     wt      tat\n");
  for(i=0;i<n;i++)
  {
    printf("\n\tP%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tat);
  }
}


void sort()
{
  int i,j;
  node t;
  for(i=0;i<n-1;i++)
   {
      for(j=i+1;j<n;j++)
	{
	   if(p[i].at > p[j].at)
	      {
		t= p[i];
		p[i] = p[j];
		p[j] = t;
	      }
	}
   }
}

void  sjfpremt(int n)
{
   int i,time=0,count=0,smallest=0,end=0,total_wt=0, total_tat=0,temp=555,temp2=555;
    float avg_wt=0,avg_tat=0;
   p[9].rt = 9999;

   for(time = 0;count != n; time++)
      {
            smallest = 9;
            for(i = 0; i < n; i++)
            {
                  if(p[i].at <= time && p[i].rt < p[smallest].rt && p[i].rt > 0)
                  {
                        smallest = i;

                  }



            }
            temp=smallest;

            p[smallest].rt--;
        if (temp!=temp2)
        {
         printf("%d<--P%d-->",time,p[smallest].name);
         }
         temp2=temp;
            if(p[smallest].rt == 0)
            {

                  count++;
                  end = time + 1;
                  p[smallest].wt= end - p[smallest].at - p[smallest].bt;
                  p[smallest].tat= end - p[smallest].at;
                  total_wt = total_wt+ p[smallest].wt;
                  total_tat = total_tat + p[smallest].tat;
            }

      }
	printf("%d",time);
      display();
      avg_wt = total_wt/ n;
      avg_tat = total_tat / n;
      printf("\n\nAverage Waiting Time:\t%f\n", avg_wt);
      printf("Average Turnaround Time:\t%f\n", avg_tat);


}


int main()
{

  printf("enter no of processes\n");
  scanf("%d",&n);


  accept();
  sort();


  printf(" \nbefore processing sorted on arrival time\n");
  display();


   sjfpremt(n);

  return 0;
}

/*
Result:-
student@student:~$ gcc shan.c
student@student:~$ ./a.out
enter no of processes
3
enter details for process P0 
enter arrival time 0
enter burst time 5
enter details for process P1 
enter arrival time 3
enter burst time 2
enter details for process P2 
enter arrival time 4
enter burst time 6
 
before processing sorted on arrival time



	Pname     at     bt     wt      tat

	P0	0	5	0	0

	P1	3	2	0	0

	P2	4	6	0	0
0<--P0-->5<--P1-->7<--P2-->13


	Pname     at     bt     wt      tat

	P0	0	5	0	5

	P1	3	2	2	4

	P2	4	6	3	9


Average Waiting Time:	1.000000
Average Turnaround Time:	6.000000


*/
