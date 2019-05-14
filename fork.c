#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        pid_t pid, p;
        int n, *num, i, j, temp;
        printf("Enter the length of the array: ");
        scanf("%d",&n);
        num = (int*)malloc(sizeof(int)*n);
        printf("Enter the Array element:\n");
        for(i = 0 ; i < n ; i++)
                scanf("%d",&num[i]);
        p = fork();
        if(p == 0 )
        {
                printf("\nChild process exucuting :->\n");
                for(i = 0 ; i < n ; i++ )
                {
                        for(j = 0 ; j < n-i-1 ; j++)
                        {
                                if(num[j] < num[j+1])
                                {
                                        temp = num[j];
                                        num[j] = num[j+1];
                                        num[j+1] = temp;
                                }
                        }
                }
                printf("The sorted array is:\n");
                for(i = 0 ; i < n ; i++)
                {
                        printf("%d ",num[i]);
                }
                printf("\n");
                printf("\nReturn by Child process:%d\n",p);
               // printf("\nReturn by Child process:%d",pid);
        }
        else if(p>0)
        {
                         waitpid(p,NULL,WUNTRACED);
                        printf("Parent process executing :->\n");
                       
                        for(i = 0 ; i < n ; i++ )
                        {
                                for(j = 0 ; j < n-i-1 ; j++)
                                {
                                        if(num[j] > num[j+1])
                                        {
                                                temp = num[j];
                                                num[j] = num[j+1];
                                                num[j+1] = temp;
                                        }
                                }
                        }
                        printf("The sorted array is:\n");
                        for(i = 0 ; i < n ; i++)
                        {
                                printf("%d ",num[i]);
                        }
                        printf("\n");

                        printf("\nID of Child process Returned to Parent process :%d\n",p);
                       // printf("\nID of Child process OR Return by Parent process :%d\n",pid);
         }

        else if (p<0)
        {
            printf("Unsuccessful Execution");
        }

return 0;
}
/*
Output:
ibm@IBM:~$ gcc fork.c
ibm@IBM:~$ ./a.out
Enter the length of the array: 4
Enter the Array element:
4
3
12 
8

Child process exucuting :->
The sorted array is:
12 8 4 3 

Return by Child process:0
Parent process executing :->
The sorted array is:
3 4 8 12 

ID of Child process Returned to Parent process :2618*
*/

