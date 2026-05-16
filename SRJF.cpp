#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid, at, bt, rt, ct, tat, wt;
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

        // Remaining Time initially = Burst Time
        p[i].rt = p[i].bt;
    }

    int completed = 0;
    int current_time = 0;

    while(completed != n)
    {
        int shortest = -1;
        int min_bt = INT_MAX;

        // Find shortest remaining time process
        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= current_time &&
               p[i].rt > 0 &&
               p[i].rt < min_bt)
            {
                min_bt = p[i].rt;
                shortest = i;
            }
        }

        // No process available
        if(shortest == -1)
        {
            current_time++;
            continue;
        }

        // Execute process for 1 unit
        p[shortest].rt--;

        current_time++;

        // Process completed
        if(p[shortest].rt == 0)
        {
            completed++;

            p[shortest].ct = current_time;

            p[shortest].tat =
                p[shortest].ct - p[shortest].at;

            p[shortest].wt =
                p[shortest].tat - p[shortest].bt;
        }
    }

    float total_TAT = 0;
    float total_WT = 0;

    // Output
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
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
