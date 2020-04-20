#include<stdio.h>

int main()
{
  int index,j,n,time,extra,flag=0,time_quantum=10;;
  int waiting_time=0,turn_around_time=0,arrival_time[10],burst_time[10],rt[10];
  printf("\nEnter the Total number of Process:\t ");
  scanf("%d",&n);
  extra=n;
  for(index=0;index<n;index++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",index+1);
    scanf("%d",&arrival_time[index]);
    scanf("%d",&burst_time[index]);
    rt[index]=burst_time[index];
  }
  printf("Enter Time Quantum:%d\t",time_quantum);
 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,index=0;extra!=0;)
  {
    if(rt[index]<=time_quantum && rt[index]>0)
    {
      time+=rt[index];
      rt[index]=0;
      flag=1;
    }
    else if(rt[index]>0)
    {
      rt[index]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[index]==0 && flag==1)
    {
      extra--;
      printf("P[%d]\t|\t%d\t|\t%d\n",index+1,time-arrival_time[index],time-arrival_time[index]-burst_time[index]);
      waiting_time+=time-arrival_time[index]-burst_time[index];
      turn_around_time+=time-arrival_time[index];
      flag=0;
    }
    if(index==n-1)
      index=0;
    else if(arrival_time[index+1]<=time)
      index++;
    else
      index=0;
  }
  printf("\nAverage Waiting Time= %f\n",waiting_time*1.0/n);
  printf("Avg Turnaround Time = %f",turn_around_time*1.0/n);
 
  return 0;
}

