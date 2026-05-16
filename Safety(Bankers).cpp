#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[n][m];
    int maxi[n][m];
    int need[n][m];
    int avail[m];

    cout << "\nEnter Allocation Matrix:\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    cout << "\nEnter Maximum Matrix:\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> maxi[i][j];
        }
    }

    cout << "\nEnter Available Resources:\n";
    for(int i=0; i<m; i++)
    {
        cin >> avail[i];
    }

    // Need Matrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            need[i][j] = maxi[i][j] - alloc[i][j];
        }
    }

    bool finish[n] = {false};

    vector<int> safeSequence;

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            if(finish[i] == false)
            {
                bool possible = true;

                for(int j=0; j<m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        possible = false;
                        break;
                    }
                }

                if(possible == true)
                {
                    for(int j=0; j<m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    finish[i] = true;

                    safeSequence.push_back(i);
                }
            }
        }
    }

    bool safe = true;

    for(int i=0; i<n; i++)
    {
        if(finish[i] == false)
        {
            safe = false;
        }
    }

    if(safe == true)
    {
        cout << "\nSystem is in SAFE state\n";

        cout << "Safe Sequence: ";

        for(int i=0; i<safeSequence.size(); i++)
        {
            cout << "P" << safeSequence[i];

            if(i != safeSequence.size()-1)
            {
                cout << " -> ";
            }
        }
    }
    else
    {
        cout << "\nSystem is NOT SAFE\n";
    }

    return 0;
}

