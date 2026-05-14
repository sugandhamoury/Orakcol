#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<< "enter the number of processes and memory partition: ";
    cin>> n;


    cout<< "enter the size of the memory partitions: " ;
    int capa[n];
    for(int i=0; i<n; i++)
    {
        cin>> capa[i];

    }

    cout<< "enter the size of the processes: " ;

    int pro[n];
    for(int i=0; i<n; i++)
    {
        cin>> pro[i];

    }

    int alloc[n];
    for(int i=0; i<n; i++)
    {
        alloc[i]= -1;

    }

    for(int i=0; i<n; i++)
    {
        int max_frag=0;
        int index=0;
        int frag=0;

        for(int j=0; j<n; j++)
        {

            if(capa[j] >= pro[i] && alloc[j] == -1)
            {
                frag= capa[j]-pro[i];
                if(frag >=max_frag)
                {
                    max_frag=frag;
                    index=j;
                }
            }
        }
        alloc[index]=pro[i];
    }
    cout<< "\n";

    for(int i=0 ; i<n; i++)
    {
        if(alloc[i] != -1)
            cout<< " at memory partition " << i+1 << ": " << alloc[i] <<" (process size) "<< endl;

        else if(alloc[i]== -1)
            cout<< " at memory partition " << i+1 << ": " << "not allocated " <<endl;

    }

    return 0;




}
