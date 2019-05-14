#include<stdio.h>
#include<pthread.h>

pthread_t thread1,thread2;					//declaration of thread

int add(int a[3])							//add function
{
	a[2]=a[1]+a[0];
	printf("result of thread 1 is : %d\n",a[2]);

}

int sub(int b[3])							//subtract function
{
	b[2]=b[1]-b[0];
	printf("result f thread 2 is : %d\n ",b[2]);
}

int main()									//main function
{
	int arr[4],a[3],b[3],i,ans=0;
	pthread_t thread1,thread2;
	printf("enter 4 numbers\n");
	for(i=0;i<4;i++){
		scanf("%d",&arr[i]);
		}
	a[0]=arr[0];	
	a[1]=arr[1];	
	b[0]=arr[2];	
	b[1]=arr[3];	
	
	pthread_create(&thread1,NULL,(void*)add,a);
	pthread_create(&thread2,NULL,(void*)sub,b);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	ans=a[2]*b[2];
	
	printf("the result = %d\n",ans);
	return 0;
	


}


/*
RESULT:-
ibm@IBM:~$ gcc thrd.c -lpthread
ibm@IBM:~$ ./a.out
enter 4 numbers
4
1
6
5
result of thread 1 is : 5
result f thread 2 is : -1
 the result = -5



*/

