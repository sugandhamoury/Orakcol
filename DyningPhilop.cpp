
#include<bits/stdc++.h>
using namespace std;

int forks[5] = {1,1,1,1,1};

void dine(int p)
{
    cout << "\nPhilosopher "
         << p
         << " is Hungry\n";

    // Check left and right fork
    if(forks[p] == 1 &&
       forks[(p+1)%5] == 1)
    {
        // Take forks
        forks[p] = 0;
        forks[(p+1)%5] = 0;

        cout << "Philosopher "
             << p
             << " takes Fork "
             << p
             << " and Fork "
             << (p+1)%5 << "\n";

        cout << "Philosopher "
             << p
             << " is Eating\n";

        // Release forks
        forks[p] = 1;
        forks[(p+1)%5] = 1;

        cout << "Philosopher "
             << p
             << " finished Eating\n";

        cout << "Forks Released\n";
    }
    else
    {
        cout << "Philosopher "
             << p
             << " must Wait\n";
    }
}

int main()
{
    int n;

    cout << "Enter number of philosophers: ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        dine(i);
    }

    return 0;
}
