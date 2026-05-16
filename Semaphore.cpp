
#include<bits/stdc++.h>
using namespace std;

int semaphore = 3;

void wait()
{
    if(semaphore > 0)
    {
        semaphore--;

        cout << "Resource Allocated\n";
        cout << "Remaining Resource: "
             << semaphore << "\n";
    }
    else
    {
        cout << "No Resource Available\n";
        cout << "Process is Waiting...\n";
    }
}

void signal()
{
    semaphore++;

    cout << "Resource Released\n";
    cout << "Available Resource: "
         << semaphore << "\n";
}

int main()
{
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    // Processes requesting resource
    for(int i=1; i<=n; i++)
    {
        cout << "\nProcess "
             << i
             << " requests resource\n";

        wait();
    }

    // Releasing one resource
    cout << "\nA process releases resource\n";

    signal();

    // Last process tries again
    cout << "\nLast process tries again\n";

    wait();

    return 0;
}
