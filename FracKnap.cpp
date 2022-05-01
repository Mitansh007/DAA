//fractional knapsack
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class item
{
	public:
	int p,w;
	double r;
};

bool comparison(item a,item b)
{
return a.r>b.r;
}

int main()
{
	int n,C_of_K,i;
	cout<<"Enter no. of items:"<<endl;
	cin>>n;
    cout<<"Enter weight of knapsack:"<<endl;
	cin>>C_of_K;
	item a[n];
	for(i=0;i<n;i++)
    {
		cin>>a[i].p>>a[i].w;
		a[i].r=a[i].p/a[i].w;
	}
	
	cout<<"Profit Weight"<<endl;
	for(i=0;i<n;i++)
    {
		cout<<a[i].p<<"        "<<a[i].w<<"\n";
		a[i].r=a[i].p/a[i].w;
	}
	
	sort(a,a+n,comparison);
	
	int c=0;
    double max_profit=0;
	
	for(i=0;i<n;i++)
	{
		if(c+a[i].w<=C_of_K)
        {
			c+=a[i].w;
			max_profit+=a[i].p;
		}
		else
        {
			double r=C_of_K-c;
			max_profit+=(r/a[i].w*double(a[i].p));
			break;
		}
		
		
	}
	cout<<"\nMaximum profit earned: "<<max_profit;
}
