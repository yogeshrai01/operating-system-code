// #include <stdio.h>

// struct process{
//         int pid;
//         int at;
//         int bt;
//         int ct;
//         int tat;
//         int wt;
// };

// int main(){
//     int n, it = 0, tt, sumTAT = 0, sumWT = 0;
//     float atat, awt, cpuUtil, cpuIdle;
//     struct process temp;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     struct process p[n];
//     for(int i=0; i<n; ++i){
//         printf("For Process %d Enter:-\n",i+1);
//         p[i].pid = i+1;
//         p[i].at = 0;
//         printf("Burst Time: ");
//         scanf("%d",&p[i].bt);
//     }

//     for(int i=0; i<n-1; ++i){
//         for(int j=0; j<n-i-1; ++j){
//             if(p[j].bt > p[j+1].bt){
//                 temp = p[j];
//                 p[j] = p[j+1];
//                 p[j+1] = temp;
//             }
//         }
//     }

//     p[0].ct = p[0].bt - p[0].at;
//     for(int i=1; i<n; ++i){
//         if(p[i].at > p[i-1].ct){
//             p[i].ct = p[i].at + p[i].bt;
//             it += p[i].at - p[i-1].ct;
//         }
//         else{
//             p[i].ct = p[i-1].ct + p[i].bt;
//         }
//     }

//     tt = p[n-1].ct;

//     for(int i=0; i<n; ++i){
//         p[i].tat = p[i].ct - p[i].at;
//         p[i].wt = p[i].tat - p[i].bt;
//         sumTAT += p[i].tat;
//         sumWT += p[i].wt;
//     }

//     atat = sumTAT/(float)n;
//     awt = sumWT/(float)n;

//     cpuUtil = (tt - it)/(float)tt * 100;
//     cpuIdle = (it)/(float)tt * 100;

//     printf("PID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
//     for(int i=0; i<n; ++i){
//         printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
//     }
//     printf("ATAT = %f\n", atat);
//     printf("AWT = %f\n", awt);
//     printf("CPU Util = %f\n", cpuUtil);
//     printf("CPU Idle = %f\n", cpuIdle);

//     return 0;
// }








#include<stdio.h>
#include<stdlib.h>
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void sortat(int p[], int at[], int bt[], int n)
{
  int i, j;
  for(i=0;i<n;i++)
  {
      for(j=i+1;j<n;j++)
      {   /* sort the process having less arrival*/
	  if(at[i]>at[j])
	  { 
	        swap(&p[i], &p[j]);
		swap(&at[i], &at[j]);
		swap(&bt[i], &bt[j]);
	   }
           /* if two processes have the same arrival time than sort them having less burst time */
	   else if(at[i]==at[j])
	   {
	      if(bt[i]>bt[j])
                 swap(&p[i], &p[j]);
                 swap(&at[i], &at[j]);
                 swap(&bt[i], &bt[j]);
	   }
       }
  }
}
/* calculate turnaround time and waiting time */
void tatwt( int ct[], int at[], int bt[], int tat[], int wt[], int n)
{
   int i;
   for(i=0;i<n;i++)
   {
	tat[i]=ct[i]-at[i];
	wt[i]=tat[i]-bt[i];
   }
}
int main()
{
  int *p, *at, *bt, *tat, *wt, *ct, pos, i, j, min=1000, n;
  float awt=0, atat=0;
  printf("\nenter the number of process:");
  scanf("%d", &n);
  p=(int*)malloc(n*sizeof(int));
  at=(int*)malloc(n*sizeof(int));
  bt=(int*)malloc(n*sizeof(int));
  ct=(int*)malloc(n*sizeof(int));
  wt=(int*)malloc(n*sizeof(int));
  tat=(int*)malloc(n*sizeof(int));
  printf("enter the process: ");
  for(i=0;i<n;i++)
  {
	scanf("%d",&p[i]); 
  }
  printf("enter the arrival time: ");
  for(i=0;i<n;i++)
  {
	scanf("%d",&at[i]);
  }
  printf("enter the burst time: ");
  for(i=0;i<n;i++)
  {
	scanf("%d",&bt[i]);
  }
  sortat(p, at, bt, n);
  ct[0]=at[0] + bt[0];
  for(i=1; i<n; i++)
  {
	for(j=i; j<n; j++)
	{
	    if(at[j]<=ct[i-1])
	   {
              if(bt[j]<min)
              {
                 min=bt[j];
                 pos=j;
              }
	   }
	}
   /*  when you get less burst time process, swap p, at, bt at position 2,
    and when getting 2nd less burst time swap at position 3rd and so on.  */
    swap(&p[i], &p[pos]);
    swap(&at[i], &at[pos]);
    swap(&bt[i], &bt[pos]);
    min=1000;
    ct[i]=ct[i-1]+bt[i];
  }
  tatwt(ct, at, bt, tat, wt, n);
  printf("\np\t at\t bt\t ct\t tat\t wt"); 
  for(i=0;i<n;i++)
  {
    printf("\n%d\t %d\t %d\t %d\t %d\t %d",p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
  }
  for(i=0;i<n;i++)
  { 
    atat+=tat[i];
    awt+=wt[i];
  }
  // average turnaround time and average waiting time
  atat=atat/n;
  awt=awt/n;
  printf("\n avg tat=%.2f and avg wt=%.2f",atat, awt); 
  return 0;
}