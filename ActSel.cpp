//activity selection
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class activity
{
	public:
	int s,f;
};

bool comparison(activity a,activity b)
{
return a.f<b.f;
}

int main()
{
	int n,i,j;
    cout<<"No of activities:"<<endl;
	cin>>n;
	activity a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i].s>>a[i].f;
	}
	
	sort(a,a+n,comparison);
	
	i=0;
    cout<<"Following activities are selected:"<<endl;
	cout<<"("<<a[i].s<<","<<a[i].f<<")"<<endl;
	
	for (j=1;j<n;j++)
    {
		if(a[j].s>=a[i].f){
			cout<<"("<<a[j].s<<","<<a[j].f<<")"<<endl;
			i=j;
		}
	}
}
