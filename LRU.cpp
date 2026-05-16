
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter number of pages: ";
    cin >> n;

    int page[n];

    cout << "enter pages: ";
    for(int i=0; i<n; i++)
    {
        cin >> page[i];
    }

    int frame;
    cout << "enter frame capacity: ";
    cin >> frame;

    vector<int> v;
    int fault = 0;

    for(int i=0; i<n; i++)
    {
        bool found = false;

        // page already ache kina check
        for(int j=0; j<v.size(); j++)
        {
            if(v[j] == page[i])
            {
                found = true;

                // recent use er jonno age delete
                v.erase(v.begin() + j);

                // last e add
                v.push_back(page[i]);

                break;
            }
        }

        // page na thakle
        if(found == false)
        {
            fault++;

            // frame full na hole
            if(v.size() < frame)
            {
                v.push_back(page[i]);
            }

            else
            {
                // least recently used delete
                v.erase(v.begin());

                // new page add
                v.push_back(page[i]);
            }
        }

        // current frame print
        cout << "frame : ";
        for(auto value : v)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    cout << "page fault : " << fault << endl;

    return 0;
}
