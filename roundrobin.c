#include <stdio.h>
#include <limits.h>

struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

struct remaining{
	int inqueue;
    int bt;
};

int main(){
    int i, n, it = 0, tt, sumTAT = 0, sumWT = 0;
    float atat, awt, cpuUtil, cpuIdle;
    struct process temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    struct remaining rem[n];
    int totalCompleted = 0;

    for(int i=0; i<n; ++i){
        printf("For Process %d Enter:-\n",i+1);
        p[i].pid = i+1;
        printf("Arrival Time: ");
        scanf("%d",&p[i].at);
        printf("Burst Time: ");
        scanf("%d",&p[i].bt);
        rem[i].inqueue = 0;
        rem[i].bt = p[i].bt;
    }
        
    int executing = 0;
    int turn = 1;
    int minTurn;
    int time;
    int noExec;
    rem[0].inqueue = turn;
    time = p[0].at;
    it = time;
    int te, qt;
    printf("Enter the quantum time: ");
    scanf("%d", &qt);

    while(totalCompleted < n){
        noExec = 1;
        minTurn = INT_MAX; 
        for(int i=0; i<n; ++i){
            if(rem[i].inqueue > 0 && rem[i].inqueue < minTurn){
                minTurn = rem[i].inqueue;
                executing = i;
                noExec = 0;
            }
        }
        if(noExec){
            ++it;
            ++time;
        }
        else{
            if(rem[executing].bt > qt){
                rem[executing].bt -= qt;
                time += qt;
                for(int i=0; i<n; ++i){
                    if(rem[i].inqueue == 0 && p[i].at <= time){
                        rem[i].inqueue = ++turn;
                    }
                }
                rem[executing].inqueue = ++turn;
            }
            else{
                time += rem[executing].bt;
                rem[executing].bt = 0;
                p[executing].ct = time;
                for(int i=0; i<n; ++i){
                    if(rem[i].inqueue == 0 && p[i].at <= time){
                        rem[i].inqueue = ++turn;
                    }
                }
                rem[executing].inqueue = -1;
                ++totalCompleted;
            }
        }
    }

    tt = time;

    for(int i=0; i<n; ++i){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        sumTAT += p[i].tat;
        sumWT += p[i].wt;
    }

    atat = sumTAT/(float)n;
    awt = sumWT/(float)n;

    cpuUtil = (tt - it)/(float)tt * 100;
    cpuIdle = (it)/(float)tt * 100;

    printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for(int i=0; i<n; ++i){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("ATAT = %f\n", atat);
    printf("AWT = %f\n", awt);
    printf("Throughput = %f\n", n/(float)tt);
    printf("CPU Util = %f\n", cpuUtil);
    printf("CPU Idle = %f\n", cpuIdle);

    return 0;
}
