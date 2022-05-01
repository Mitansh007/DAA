#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class job
{
	public:
    char id;
	int dl,p;
};

bool comparison(job a,job b)
{
return a.p>b.p;
}

int main()
{
		int n,i,j;
	cout<<"Enter no. of jobs\n";
	cin>>n;
	job a[n];
	for(i=0;i<n;i++)
    {
		cin>>a[i].id>>a[i].dl>>a[i].p;
	}
	
	cout<<"Job DL P"<<endl;
	for(i=0;i<n;i++)
    {
		cout<<a[i].id<<"   "<<a[i].dl<<"  "<<a[i].p<<endl;
	}

	sort(a,a+n,comparison);
	
	int result[n];
    bool slot[n];
    for (int i=0; i<n; i++)
        slot[i] = false;//unoccupied slots
 
 int profit=0;
    for (int i=0; i<n; i++)
    {
       for (int j=a[i].dl;j>0; j--)
       {
          if (slot[j]==false)
          {
          	profit +=a[i].p;
             result[j] = i;  
             slot[j] = true;
             break;
          }
       }
    }
    cout<<"Jobs are performed in order :"<<endl;
    for (int i=0; i<n; i++)
       if(slot[i])
         cout << a[result[i]].id << " ";
         cout<<"Total Profit is "<<profit<<endl;
         
}
