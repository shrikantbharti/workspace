	#include<stdio.h>
	#include<stdlib.h>
	struct process
	{
		int name;
		int at;
		int bt;
		int wt;
		int tat;
	}p[10];
	void accept(struct process p[10],int n)
	{
		int i;
		printf("\nAccepting Process Information :");
		for(i=0;i<n;i++)
		{
			p[i].wt=0;
			p[i].tat=0;
			printf("\nProcess Information %d :", i+1);
			printf("\nProcess ID: ");
			scanf("%d",&p[i].name);
			printf("\nArrival Time: ");
			scanf("%d",&p[i].at);
			printf("\nBurst Time: ");
			scanf("%d",&p[i].bt);
		}
	
	}
	void display(struct process p[10],int n)
	{
		int i;
		printf("\nDisplaying Process Information :");
		printf("\nID \t AT \t BT \t WT \t TAT ");
		for(i=0;i<n;i++)
		{
		printf("\n%d \t %d \t %d \t %d \t %d  ",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tat);	
		}
		
	}
	void sort(struct process p[10],int n)
	{
		struct process temp;
		int i,j;
		for(i=0;i<n-1;i++)
			{
					for(j=0;j<n-i-1;j++)
				{
					
					if(p[j].at>p[j+1].at)
             			{
                			temp=p[j];
               				p[j]=p[j+1];
                			p[j+1]=temp;        
             			}
			
				}	
			}	
	}
	void dischart(struct process p[10],int n)
	{
		int ft,i;
		ft=p[0].at;
		printf("\nProcess Chart : %d",ft);
		for(i=0;i<n;i++)
		{
			ft=ft+p[i].bt;
			printf("<--P%d--> %d",p[i].name,ft);
		}
	}
	void fcfs(struct process p[10],int n)
	{
		int i;
		int tot_wt=0,tot_tat=0;
		int ft;
		float avg_wt,avg_tat;
		ft=p[0].at;
		for(i=0;i<n;i++)
		{
			ft=ft+p[i].bt;
			p[i].tat=ft-p[i].at;
			p[i].wt=p[i].tat-p[i].bt;
			tot_wt=tot_wt+p[i].wt;
			tot_tat=tot_tat+p[i].tat;
		}
		display(p,n);
		avg_wt=tot_wt/n;
		avg_tat=tot_tat/n;
		printf("\nAverage Waiting Time: %f",avg_wt);
		printf("\nAverage Turn Around Time: %f",avg_tat);
	}
	void main()
	{
		int ch,n;
		printf("\nProgram for Process Information!!");
		do
		{
			printf("\nMenu \n1)Accept Information \n2)Display Information \n3)Sort \n4)Display Chart \n5)FCFS  \n6)Exit \nChoice: ");
			scanf("%d",&ch);
			switch(ch)
			{
			case 1:
			printf("\nEnter No of Process: ");
			scanf("%d",&n);
			accept(p,n);
			break;
			case 2:
			display(p,n);
			break;
			case 3:
			printf("\nBefore Sorting: ");
			display(p,n);
			sort(p,n);
			printf("\nAfter Sorting: ");
			display(p,n);
			break;
			case 4:
			dischart(p,n);
			break;
			case 5:
			fcfs(p,n);
			break;
			case 6:
			exit(0);
			break;
			}
		}
		while(1);
	}
