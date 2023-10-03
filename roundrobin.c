
// #include<stdio.h>

// int main()
// {
//       int i, limit, total = 0, x, counter = 0, time_quantum;
//       int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
//       float average_wait_time, average_turnaround_time;
//       printf("\nEnter Total Number of Processes:\t");
//       scanf("%d", &limit);
//       x = limit;
//       for(i = 0; i < limit; i++)
//       {
//             printf("\nEnter Details of Process[%d]n", i + 1);

//             printf("Arrival Time:\t");

//             scanf("%d", &arrival_time[i]);

//             printf("Burst Time:\t");

//             scanf("%d", &burst_time[i]);

//             temp[i] = burst_time[i];
//       }

//       printf("\nEnter Time Quantum:\t");
//       scanf("%d", &time_quantum);
//       printf("\nProcess IDttBurst Timet Turnaround Timet Waiting Timen");
//       for(total = 0, i = 0; x != 0;)
//       {
//             if(temp[i] <= time_quantum && temp[i] > 0)
//             {
//                   total = total + temp[i];
//                   temp[i] = 0;
//                   counter = 1;
//             }
//             else if(temp[i] > 0)
//             {
//                   temp[i] = temp[i] - time_quantum;
//                   total = total + time_quantum;
//             }
//             if(temp[i] == 0 && counter == 1)
//             {
//                   x--;
//                   printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
//                   wait_time = wait_time + total - arrival_time[i] - burst_time[i];
//                   turnaround_time = turnaround_time + total - arrival_time[i];
//                   counter = 0;
//             }
//             if(i == limit - 1)
//             {
//                   i = 0;
//             }
//             else if(arrival_time[i + 1] <= total)
//             {
//                   i++;
//             }
//             else
//             {
//                   i = 0;
//             }
//       }

//       average_wait_time = wait_time * 1.0 / limit;
//       average_turnaround_time = turnaround_time * 1.0 / limit;
//       printf("\nnAverage Waiting Time:\t%f", average_wait_time);
//       printf("\nAvg Turnaround Time:\t%fn", average_turnaround_time);
//       return 0;
// }

// #include<stdio.h>

// void main()
// {
//     int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];
//     float avg_wt, avg_tat;
//     printf(" Total number of process in the system: ");
//     scanf("%d", &NOP);
//     y = NOP;

//     for(i=0; i<NOP; i++)
//     {
//         printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);
//         printf(" Enter Arrival time: \t");
//         scanf("%d", &at[i]);
//         printf(" \nEnter Burst time: \t");
//         scanf("%d", &bt[i]);
//         temp[i] = bt[i];
//     }

//     printf("Enter the Time Quantum for the process: \t");
//     scanf("%d", &quant);
//     printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
//     for(sum=0, i = 0; y!=0; )
//     {
//          if(temp[i] <= quant && temp[i] > 0)
//        {
//            sum = sum + temp[i];
//             temp[i] = 0;
//             count=1;
//          }
//         else if(temp[i] > 0)
//         {
//             temp[i] = temp[i] - quant;
//             sum = sum + quant;
//         }
//         if(temp[i]==0 && count==1)
//         {
//             y--;
//             printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);
//             wt = wt+sum-at[i]-bt[i];
//             tat = tat+sum-at[i];
//             count =0;
//         }
//         if(i==NOP-1)
//         {
//             i=0;
//         }
//         else if(at[i+1]<=sum)
//         {
//             i++;
//         }
//         else
//         {
//             i=0;
//         }
//     }
// }

// #include <stdio.h>
// #include<stdlib.h>

// // Function to calculate turn around time
// int turnarroundtime(int processes[], int n,
//                     int bt[], int wt[], int tat[])
// {
//     // calculating turnaround time by adding
//     // bt[i] + wt[i]
//     for (int i = 0; i < n; i++)
//         tat[i] = bt[i] + wt[i];
//     return 1;
// }
// // Function to find the waiting time for all
// // processes
// int waitingtime(int processes[], int n,
//                 int bt[], int wt[], int quantum)
// {
//     // Make a copy of burst times bt[] to store remaining
//     // burst times.
//     int rem_bt[n];
//     for (int i = 0; i < n; i++)
//         rem_bt[i] = bt[i];
//     int t = 0; // Current time
//     // Keep traversing processes in round robin manner
//     // until all of them are not done.
//     while (1)
//     {
//         bool done = true;
//         // Traverse all processes one by one repeatedly
//         for (int i = 0; i < n; i++)
//         {
//             // If burst time of a process is greater than 0
//             // then only need to process further
//             if (rem_bt[i] > 0)
//             {
//                 done = false; // There is a pending process
//                 if (rem_bt[i] > quantum)
//                 {
//                     // Increase the value of t i.e. shows
//                     // how much time a process has been processed
//                     t += quantum;
//                     // Decrease the burst_time of current process
//                     // by quantum
//                     rem_bt[i] -= quantum;
//                 }
//                 // If burst time is smaller than or equal to
//                 // quantum. Last cycle for this process
//                 else
//                 {
//                     // Increase the value of t i.e. shows
//                     // how much time a process has been processed
//                     t = t + rem_bt[i];
//                     // Waiting time is current time minus time
//                     // used by this process
//                     wt[i] = t - bt[i];
//                     // As the process gets fully executed
//                     // make its remaining burst time = 0
//                     rem_bt[i] = 0;
//                 }
//             }
//         }
//         // If all processes are done
//         if (done == true)
//             break;
//     }
//     return 1;
// }
// // Function to calculate average time
// int findavgTime(int processes[], int n, int bt[],
//                 int quantum)
// {
//     int wt[n], tat[n], total_wt = 0, total_tat = 0;
//     // Function to find waiting time of all processes
//     waitingtime(processes, n, bt, wt, quantum);
//     // Function to find turn around time for all processes
//     turnarroundtime(processes, n, bt, wt, tat);
//     // Display processes along with all details
//    printf("Processes Burst Time Waiting Time turnaround time");
//    // Calculate total waiting time and total turn
//    // around time
//    for (int i=0; i<n; i++) {
//         total_wt = total_wt + wt[i];
//         total_tat = total_tat + tat[i];
//       printf("\t%d\t\t\t%d\t\t\t%d\t\t\t%d",i+1, bt[i], wt[i], tat[i]);
//    }
//    printf("Average waiting time = %f", (float)total_wt / (float)n);
//    printf("Average turnaround time = %f", (float)total_tat / (float)n);
//    return 1;
// }
// // main function
// int main()
// {
//    // process id's
//    int processes[] = {1, 2, 3};
//    int n = sizeof processes / sizeof processes[0];
//    // Burst time of all processes
//    int burst_time[] = {8, 6, 12};
//    // Time quantum
//    int quantum = 2;
//    findavgTime(processes, n, burst_time, quantum);
//    return 0;
// }

// #include <stdio.h>

// #define MAX_PROCESSES 100

// typedef struct Process {
//     int id;
//     int arrival_time;
//     int burst_time;
//     int remaining_time;
// } Process;

// int main() {
//     int n, time_quantum;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     if (n <= 0 || n > MAX_PROCESSES) {
//         printf("Invalid number of processes.\n");
//         return 1;
//     }

//     printf("Enter the time quantum: ");
//     scanf("%d", &time_quantum);

//     Process processes[MAX_PROCESSES];
//     int completion_time[MAX_PROCESSES];
//     int turnaround_time[MAX_PROCESSES];

//     for (int i = 0; i < n; i++) {
//         processes[i].id = i + 1;
//         printf("Enter arrival time and burst time for process P%d: ", i + 1);
//         scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
//         processes[i].remaining_time = processes[i].burst_time;
//     }

//     int current_time = 0;
//     int remaining_processes = n;

//     while (remaining_processes > 0) {
//         for (int i = 0; i < n; i++) {
//             if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
//                 int execution_time = (processes[i].remaining_time <= time_quantum) ? processes[i].remaining_time : time_quantum;
//                 processes[i].remaining_time -= execution_time;
//                 current_time += execution_time;

//                 if (processes[i].remaining_time == 0) {
//                     completion_time[i] = current_time;
//                     turnaround_time[i] = completion_time[i] - processes[i].arrival_time;
//                     remaining_processes--;
//                 }
//             }
//         }
//     }

//     printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\n");
//     for (int i = 0; i < n; i++) {
//         printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
//                processes[i].burst_time, completion_time[i], turnaround_time[i]);
//     }

//     float average_turnaround_time = 0;
//     for (int i = 0; i < n; i++) {
//         average_turnaround_time += turnaround_time[i];
//     }
//     average_turnaround_time /= n;

//     printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

//     return 0;
// }



#include<stdio.h> 
int main() 
{ 
      int i,j,t, n, total = 0, x, counter = 0, tquant; 
      int wait_time = 0, turnaround_time = 0, at[10], bt[10], temp[10],p[10]; 
      float average_wait_time, average_turnaround_time;
      printf("Name: Simran Solanki_Section: L_Student id: 21012654\n\n");
      printf("\nEnter Number of Processes: "); 
      scanf("%d", &n); 
      x = n; 
      printf("Enter arrival time and burst time for each process:\n\n");
      for (int i = 0; i < n; i++)
      {
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        p[i]=i+1;
        temp[i] = bt[i];
      }
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &tquant); 
     for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - i); j++)
        {
            if (at[j] > at[j + 1])
            {
                t = p[j + 1];
                p[j + 1] = p[j];
                p[j] = t;
                t = at[j + 1];
                at[j + 1] = at[j];
                at[j] = t;
                t = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = t;
            }
        }
    }
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= tquant && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - tquant; 
                  total = total + tquant; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", p[i], bt[i], total - at[i], total - at[i] - bt[i]);
                  wait_time = wait_time + total - at[i] - bt[i]; 
                  turnaround_time = turnaround_time + total - at[i]; 
                  counter = 0; 
            } 
            if(i == n - 1) 
            {
                  i = 0; 
            }
            else if(at[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / n;
      average_turnaround_time = turnaround_time * 1.0 / n;
      printf("\n\nAverage Waiting Time: %f", average_wait_time); 
      printf("\nAvg Turnaround Time: %f\n", average_turnaround_time); 
      return 0; 
}