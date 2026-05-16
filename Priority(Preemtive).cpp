
#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid, at, bt, rt, priority;
    int ct, tat, wt;
};

int main()
{
    int n;

    cout << "Enter number of Processes: ";
    cin >> n;

    Process p[n];

    // Input
    for(int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        cout << "\nProcess " << p[i].pid << endl;

        cout << "Arrival Time: ";
        cin >> p[i].at;

        cout << "Burst Time: ";
        cin >> p[i].bt;

        cout << "Priority: ";
        cin >> p[i].priority;

        // Remaining Time
        p[i].rt = p[i].bt;
    }

    int completed = 0;
    int current_time = 0;

    while(completed != n)
    {
        int highest = -1;
        int highest_priority = INT_MAX;

        // Find highest priority process
        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= current_time &&
               p[i].rt > 0 &&
               p[i].priority < highest_priority)
            {
                highest_priority =
                    p[i].priority;

                highest = i;
            }
        }

        // No process available
        if(highest == -1)
        {
            current_time++;
            continue;
        }

        // Execute for 1 unit
        p[highest].rt--;

        current_time++;

        // Process completed
        if(p[highest].rt == 0)
        {
            completed++;

            p[highest].ct = current_time;

            p[highest].tat =
                p[highest].ct - p[highest].at;

            p[highest].wt =
                p[highest].tat - p[highest].bt;
        }
    }

    float total_TAT = 0;
    float total_WT = 0;

    // Output
    cout << "\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].priority << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << endl;

        total_TAT += p[i].tat;
        total_WT += p[i].wt;
    }

    cout << "\nTotal TAT = " << total_TAT << endl;

    cout << "Total WT = " << total_WT << endl;

    cout << "Average TAT = "
         << total_TAT / n << endl;

    cout << "Average WT = "
         << total_WT / n << endl;

    return 0;
}
