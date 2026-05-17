#include <iostream>
#include <iomanip>

using namespace std;

struct Process {
    int pid, at, bt, ct, tat, wt;
    bool done;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p;

    // --- Input Section ---
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "P" << p[i].pid << " Arrival Time: ";
        cin >> p[i].at;
        cout << "P" << p[i].pid << " Burst Time: ";
        cin >> p[i].bt;
        p[i].done = false;
    }

    // --- SJF Logic Section ---
    int completed = 0, curr_time = 0;
    float total_tat = 0, total_wt = 0;

    while (completed != n) {
        int idx = -1;
        int min_bt = 1e9; // Initialize with a large value

        // Find process with minimum burst time among arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].at <= curr_time && !p[i].done) {
                if (p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
                }
                // Tie-breaker: process with earlier arrival time
                if (p[i].bt == min_bt) {
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            p[idx].ct = curr_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            
            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
            
            curr_time = p[idx].ct;
            p[idx].done = true;
            completed++;
        } else {
            // If no process has arrived, increment time
            curr_time++;
        }
    }

    // --- Output Section ---
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" 
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << total_tat / n;
    cout << "\nAverage Waiting Time: " << total_wt / n << endl;

    return 0;
}