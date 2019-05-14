#include<stdio.h>
#include<stdbool.h>

int curravail[3],  n, m, avail[10], Max[10][10], alloc[10][10], need[10][10];

void Accept()
{
int i, sum[3];
sum[0]=sum[1]=sum[2]=0;
printf("\nEnter Available Resources: ");
for(i=0; i<m; i++)
	{
	printf("\nResource %d: ",i);
	scanf("%d",&avail[i]);
	}
printf("\nEnter Maximum Required Resources(A, B & C) for Processes: ");
for(i=0; i<n; i++)
	{
	printf("\nProcess %d: ",i);
	scanf("%d%d%d",&Max[i][0],&Max[i][1],&Max[i][2]);
	}
printf("\nEnter Allocated Resources(A, B & C) for Processes: ");
for(i=0; i<n; i++)
	{
	printf("\nProcess %d: ",i);
	scanf("%d%d%d",&alloc[i][0],&alloc[i][1],&alloc[i][2]);
	need[i][0]=Max[i][0]-alloc[i][0];
	need[i][1]=Max[i][1]-alloc[i][1];
	need[i][2]=Max[i][2]-alloc[i][2];
	}
for(i=0;i<n;i++)
	{
	sum[0]+=alloc[i][0];
	sum[1]+=alloc[i][1];
	sum[2]+=alloc[i][2];
	}
curravail[0]=avail[0]-sum[0];
curravail[1]=avail[1]-sum[1];
curravail[2]=avail[2]-sum[2];
}

void Display()
{
int i;
printf("\n Allocation\n");
for(int i=0;i<n;i++)
{	for(int j=0;j<m;j++)
	{
		printf("%d \t",alloc[i][j]);

	}
	printf("\n");
}
printf("\n Max Requirement\n");
for(int i=0;i<n;i++)
{	for(int j=0;j<m;j++)
	{
		printf("%d \t",Max[i][j]);

	}
	printf("\n");
}
printf("\n Need\n");
for(int i=0;i<n;i++)
{	for(int j=0;j<m;j++)
	{
		printf("%d \t",need[i][j]);

	}
	printf("\n");
}
printf("\nCurrent Available Resources are- %d %d %d \n",curravail[0],curravail[1],curravail[2]);
}

bool SafeState()
{

	int p,i,j,k,l,count;
	int finish[5]={0};
	int safeseq[n];
	int work[m];
	bool found=0;

	for(int i=0;i<m;i++)
	{
		work[i]=curravail[i];
	}
	count=0;
	while(count<n)
	{
		found=false;
		for(p=0;p<n;p++)
		{
			if(finish[p]==0)
			{
			for(j=0;j<m;j++)
			{
				if(need[p][j]>work[j])
					break;
			}
			if(j==m)
			{
			for(k=0;k<m;k++)
				work[k]=work[k]+alloc[p][k];
			safeseq[count++]=p;
			finish[p]=1;
			found=true;
			}
			}
		}
	if(found==false)
	{
		printf("system is not safe");
		return false;
	}
	}
	printf("system is safe\n");
	printf("safe sequence is:\n");
	for(i=0;i<n;i++)
	{
		printf("p%d \t",safeseq[i]);
	}
	return true;
}


void process_req()
{
bool is_safe;
int request[m];
int k,i,j;
printf("enter process no to req resources");
scanf("%d",&k);
printf("enter the no of required resource for the process");
for(j=0;j<m;j++)
{
scanf("%d",&request[j]);
if(request[i]>need[k][j])
{
printf("request not granted");
return;
}
if(request[i]>curravail[j])
{
printf("request not granted");
return;
}
}
for(j=0;j<m;j++)
{
curravail[j]=curravail[j]-request[j];
alloc[k][j]=alloc[k][j]+request[j];
need[k][j]=need[k][j]-request[j];
}
is_safe=SafeState();
if(is_safe==true)
{
printf("request granted");
Display(n,m,avail,Max,alloc,need);
}
else
{
printf("request granted");
for(j=0;j<m;j++)
{
curravail[j]=curravail[j]+request[j];
alloc[k][j]=alloc[k][j]-request[j];
need[k][j]=need[k][j]+request[j];
}

Display(n,m,avail,Max,alloc,need);
}
}








int main()
{
int ch;
printf("\nEnter no. of Processes: ");
scanf("%d",&n);
printf("\nEnter no. of Resources: ");
scanf("%d",&m);
Accept(n,m,avail,Max,alloc,need);
Display(n,m,avail,Max,alloc,need);

process_req();
printf("do you wnt to continue\n press 1 to continue 0 for exit\n");
scanf("%d",&ch);
do
{
process_req();
printf("do you wnt to continue\n press 1 to continue 0 for exit\n");
scanf("%d",&ch);
}while(ch==1);


return 0;
}

/*
Enter no. of Processes: 5

Enter no. of Resources: 3

Enter Available Resources: 
Resource 0: 10

Resource 1: 5

Resource 2: 7

Enter Maximum Required Resources(A, B & C) for Processes: 
Process 0: 7
5
3

Process 1: 3
2
2

Process 2: 9
0
2

Process 3: 2
2
2

Process 4: 4
3
3

Enter Allocated Resources(A, B & C) for Processes: 
Process 0: 0
1
0

Process 1: 2
0
0

Process 2: 3
0
2

Process 3: 2
1
1

Process 4: 0
0
2

 Allocation
0 	1 	0 	
2 	0 	0 	
3 	0 	2 	
2 	1 	1 	
0 	0 	2 	

 Max Requirement
7 	5 	3 	
3 	2 	2 	
9 	0 	2 	
2 	2 	2 	
4 	3 	3 	

 Need
7 	4 	3 	
1 	2 	2 	
6 	0 	0 	
0 	1 	1 	
4 	3 	1 	

Current Available Resources are- 3 3 2 
enter process no to req resources1
enter the no of required resource for the process1
0
2
system is safe
safe sequence is:
p1 	p3 	p4 	p0 	p2 	request granted
 Allocation
0 	1 	0 	
3 	0 	2 	
3 	0 	2 	
2 	1 	1 	
0 	0 	2 	

 Max Requirement
7 	5 	3 	
3 	2 	2 	
9 	0 	2 	
2 	2 	2 	
4 	3 	3 	

 Need
7 	4 	3 	
0 	2 	0 	
6 	0 	0 	
0 	1 	1 	
4 	3 	1 	

Current Available Resources are- 2 3 0 
do you wnt to continue
 press 1 to continue 0 for exit
1
enter process no to req resources4
enter the no of required resource for the process3
do you wnt to continue
 press 1 to continue 0 for exit
 0

*/
