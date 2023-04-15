//to perform selection of activities using greedy approach
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct 
{
    char task_id[5];
    int startTime,endTime;
}task;
//end of structure definition
void main()
{
    int n,i,j;
    task temp,*tasks;
    printf("Enter the number of tasks: ");
    scanf("%d",&n);
    tasks=(task*)malloc(n*sizeof(task));
    printf("\nEnter the task ID, starting time and ending time for each task:\n");
    for(i=0;i<n;i++)
    scanf("%s %d %d",tasks[i].task_id,&tasks[i].startTime,&tasks[i].endTime);
    //sorting the tasks in order of increasing ending times (bubble sort)
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    if(tasks[i].endTime>tasks[j].endTime){
        temp=tasks[i];
        tasks[i]=tasks[j];
        tasks[j]=temp;
    }//end of if block
    printf("\nThe tasks sorted in increasing order of ending times are as follows:\n");
    printf("\nTASK ID\t\tSTART TIME\t\tEND TIME");
    for(i=0;i<n;i++)
    printf("\n%s\t\t%d\t\t\t%d",tasks[i].task_id,tasks[i].startTime,tasks[i].endTime);
    printf("\n");
    printf("\nThe following activities are selected:");
    //the first task with minimium ending time is always selected
    i=0;
    printf("%s ",tasks[i].task_id);
    // the subsequent tasks will be selected iff their starting times are greater than
    // or equal to the ending time of the previously selected task
    for(j=1;j<n;j++)
    if(tasks[j].startTime>=tasks[i].endTime){
        printf("--> %s ",tasks[j].task_id);
        i=j;
    }//end of if block
    printf("(in Sequence)");
}//end of main