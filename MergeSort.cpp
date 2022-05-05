#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int mid, int h)
{
    int i=l, j=mid+1, k=l;
    int B[100];
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void Rmergesort(int arr[], int l, int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        Rmergesort(arr,l,mid);
        Rmergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

void Imergesort(int arr[], int n)
{
    int p, l, mid, h, i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(arr,l,mid,h);
        }
    }
    if(p/2<n)
    {
        merge(arr,0,p/2-1,n-1);
    }
}

int main()
{
    int n;
    cout<<"Enter the length of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter all the elements of array"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    Imergesort(arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
