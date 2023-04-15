//to perform Job Sequencing (Greedy Approach) on a given set of tasks
// Given a set of ‘10’ jobs with their si and fi, find the optimal sequence of mutually compatible jobs using the greedy method: A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, si = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12} and fi = {5, 7, 8, 10, 11, 12, 13, 14, 15, 16}.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct{
    char job_id[5];
    int profit,deadline;
}job;//end of structure definition
void main(){
    int n,i,j,D=INT_MIN,*timeline,lastPossibleSlot,filledSlots=0,maximumProfit=0;
    job temp,*jobs;
    printf("Enter the number of tasks to be processed: ");
    scanf("%d",&n);
    jobs=(job*)malloc(n*sizeof(job));
    printf("For each task, mention the Job ID, deadline and profit separated by spaces:\n");
    for(i=0;i<n;i++)
    scanf("%s %d %d",jobs[i].job_id,&jobs[i].deadline,&jobs[i].profit);
    //sorting the jobs in descending order of profits
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    if(jobs[i].profit<jobs[j].profit){
        temp=jobs[i];
        jobs[i]=jobs[j];
        jobs[j]=temp;
    }//end of if block
    printf("\nThe jobs after sorting in descending order of profits are:\n");
    printf("\nJOB ID\t\tPROFITS\t\tDEADLINE");
    for(i=0;i<n;i++)
    printf("\n%s\t\t%d\t\t%d",jobs[i].job_id,jobs[i].profit,jobs[i].deadline);
    printf("\n");
    //finding the maximum deadline value
    for(i=0;i<n;i++)
    D=D>jobs[i].deadline-1?D:jobs[i].deadline-1;
    timeline=(int*)malloc(D*sizeof(int));
    for(i=0;i<=D;i++)
    timeline[i]=-1;//-1 implies free
    for(i=0;i<n;i++){
        lastPossibleSlot=D<jobs[i].deadline-1?D:jobs[i].deadline-1;
        while(lastPossibleSlot>=0){
            if(timeline[lastPossibleSlot]==-1){
                timeline[lastPossibleSlot]=i;
                filledSlots++;
                break;
            }//end of if block
            lastPossibleSlot--;
        }//end of while loop
        if(filledSlots-1==D)
        break;
    }//end of outer for loop
    printf("\nThe Jobs which can be performed are: ");
    for(i=0;i<=D;i++){
        i==D?printf("%s",jobs[timeline[i]].job_id):printf("%s -> ",jobs[timeline[i]].job_id);
        //calculating profits
        maximumProfit+=jobs[timeline[i]].profit;
    }//end of for loop
    printf(" (In Sequence)");
    printf("\nThe maximum profit that can be obtained = %d",maximumProfit);
}//end of main