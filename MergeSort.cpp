#include<iostream>
using namespace std;
void Display(int Arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<Arr[i]<<" ";
	}
	cout<<"\n";	
}

void Merge(int A[], int l, int mid, int h)
{
	int B[100];
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=h)
	{
		if(A[i]<A[j])
		{
			B[k++]=A[i++];
		}
		else
		{
			B[k++]=A[j++];
		}
	}
	for(;i<=mid;i++)
        B[k++]=A[i];
	for(;j<=h;j++)
        B[k++]=A[j];
	 for(i=l;i<=h;i++)
        A[i]=B[i];
}

void MergeSort(int arr[], int l, int h)
{
    int m;
    if (l < h)
    {
        m = (l + h) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, h);
        Merge(arr, l, m, h);
    }
}


int main(){
	int size;
	cout<<"Enter size"<<endl;
	cin>>size;
	int A[size];
	cout<<"Enter array elements"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>A[i];
	}

	MergeSort(A,0,size-1);
    cout<<"After Merging"<<endl;
	Display(A,size);
	
	return 0;
}
