
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<< "enter the number of processes and number of storage spaces: ";
    cin>> n;


    int capa[n];
    cout<< "enter size of each memory partition: ";
    for(int i=0; i<n; i++)
    {
        cin>> capa[i];
    }

    cout<< " enter the size of each process: " ;
    int pro[n];
    for(int i=0; i<n; i++)
    {
        cin>> pro[i];
    }

    int alloc[n];
    for(int i=0; i<n ; i++)
    {
        alloc[i]=-1;
    }


    for(int i=0; i<n; i++)
    {
        int min_frag=9999;
        int in_frag=0;
        int index=-1;
        for(int j=0; j<n; j++)
        {
            if(capa[j] >= pro[i] && alloc[j]== -1)
            {
                in_frag= capa[j]-pro[i];
                if(in_frag < min_frag)
                {
                    min_frag = in_frag;
                    index= j;
                }
            }
        }
        if(index!=-1)
          alloc[index]= pro[i];
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
