#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid, bt, rt, ct, tat, wt;
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

        cout << "Burst Time: ";
        cin >> p[i].bt;

        // Remaining Time
        p[i].rt = p[i].bt;
    }

    int tq;

    cout << "\nEnter Time Quantum: ";
    cin >> tq;

    int current_time = 0;
    int completed = 0;

    while(completed != n)
    {
        bool executed = false;

        for(int i = 0; i < n; i++)
        {
            // Process still remaining
            if(p[i].rt > 0)
            {
                executed = true;

                // If remaining time > time quantum
                if(p[i].rt > tq)
                {
                    current_time += tq;

                    p[i].rt -= tq;
                }

                else
                {
                    // Process completes
                    current_time += p[i].rt;

                    p[i].ct = current_time;

                    p[i].rt = 0;

                    completed++;

                    p[i].tat = p[i].ct;

                    p[i].wt =
                        p[i].tat - p[i].bt;
                }
            }
        }

        // Safety check
        if(executed == false)
        {
            break;
        }
    }

    float total_TAT = 0;
    float total_WT = 0;

    // Output
    cout << "\nP\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i].pid << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << endl;

        total_TAT += p[i].tat;
        total_WT += p[i].wt;
    }

    cout << "\nTotal TAT = "
         << total_TAT << endl;

    cout << "Total WT = "
         << total_WT << endl;

    cout << "Average TAT = "
         << total_TAT / n << endl;

    cout << "Average WT = "
         << total_WT / n << endl;

    return 0;
}
