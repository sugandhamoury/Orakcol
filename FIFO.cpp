#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<< "enter the number of pages: ";
    cin>> n;

    int page[n];

    cout<< "enter the pages: ";
    for(int i=0; i<n; i++)
    {
        cin>> page[i] ;
    }

    int frame;
    cout<< "enter frame capacity: ";
    cin>> frame;

    unordered_set<int> s;
    queue<int> que;

    int fault = 0;

    for(int i=0; i<n; i++)
    {
        if(s.size() < frame)
        {
            if(s.find(page[i]) == s.end())
            {
                s.insert(page[i]);
                fault++;

                que.push(page[i]);
            }
        }

        else
        {
            if(s.find(page[i]) == s.end())
            {
                int temp = que.front();
                que.pop();

                s.erase(temp);

                s.insert(page[i]);
                que.push(page[i]);

                fault++;
            }
        }
    }

    cout<< "page fault : " << fault << endl;

    cout<< "pages in queue: ";

    queue<int> temp = que;

    while(!temp.empty())
    {
        cout<< temp.front() << " ";
        temp.pop();
    }

    return 0;
}
