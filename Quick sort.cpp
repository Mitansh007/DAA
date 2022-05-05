#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i=l;
    int j=h;
    do
    {
        do
        {
            i++;
        }while(arr[i]<=pivot);
        do
        {
            j--;
        }while(arr[j]>pivot);
        if(i<j)
        {
            swap(&arr[i], &arr[j]);
        }
    }while(i<j);
    
    swap(&arr[l], &arr[j]);
    return j;
}

void Rquicksort(int arr[], int l, int h)
{
    int j;
    if(l<h)
    {
        j=partition(arr, l, h);
        Rquicksort(arr, l, j);
        Rquicksort(arr, j+1, h);
    }
}

void Iquicksort(int arr[], int l, int h)
{
    int stack[h-l+1];
    int top=-1;
    stack[++top]=l;
    stack[++top]=h;
    while(top>=0)
    {
        h=stack[top--];
        l=stack[top--];
        
        int p=partition(arr,l,h);
        
        if(p-1>l)
        {
            stack[++top]=l;
            stack[++top]=p-1;
        }
        if(p+1<h)
        {
            stack[++top]=p+1;
            stack[++top]=h;
        }
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
    Iquicksort(arr, 0, n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
