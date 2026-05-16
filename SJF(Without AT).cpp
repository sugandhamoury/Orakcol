
#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid, bt, ct, tat, wt;
};

// Compare Function for Sorting by Burst Time
bool compare(Process a, Process b)
{
    return a.bt < b.bt;
}

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
    }

    // Sorting according to Burst Time
    sort(p, p + n, compare);

    // Completion Time Calculation
    p[0].ct = p[0].bt;

    for(int i = 1; i < n; i++)
    {
        p[i].ct = p[i-1].ct + p[i].bt;
    }

    // TAT and WT Calculation
    float total_TAT = 0, total_WT = 0;

    for(int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct;

        p[i].wt = p[i].tat - p[i].bt;

        total_TAT += p[i].tat;
        total_WT += p[i].wt;
    }

    // Output
    cout << "\nP\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i].pid << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << endl;
    }

    cout << "\nTotal TAT = " << total_TAT << endl;
    cout << "Total WT = " << total_WT << endl;

    cout << "Average TAT = " << total_TAT / n << endl;
    cout << "Average WT = " << total_WT / n << endl;

    return 0;
}
