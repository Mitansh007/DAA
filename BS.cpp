#include<iostream>
using namespace std;
void Display(int *Arr,int n)
{
    cout<<"Array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<Arr[i]<<" ";
    }
}

int RBinSearch(int *Arr,int l,int h,int k)
{
	int mid;
	if(l<=h)
	{
		mid=(l+h)/2;
		if(k==Arr[mid])
		{
			return mid;
		}else if(k<Arr[mid])
		{
		 return RBinSearch(Arr,l,mid-1,k);
		}else{
		 return RBinSearch(Arr,mid+1,h,k);
		}		
			}
   	return -1;				
}

int main()
{
    int size,key,r;
    cout<<"Enter size of array"<<endl;
    cin>>size;
    int A[size];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }
    Display(A,size);
    cout<<"\nEnter Key"<<endl;
    cin>>key;
//    r=BinSearch(A,size,key);
    r=RBinSearch(A,0,size-1,key);
    if(r==-1)
    cout<<"\nElement not found"<<endl;
    else
    cout<<"\nElement found at position "<<r<<endl;
    return 0;
}

/*int BinSearch(int *Arr,int n,int k)
{
	int l,h,mid;
	l=0;
	h=n-1;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(k==Arr[mid])
		{
			return mid;
			break;
		}else if(k<Arr[mid])
		{
		 h=mid-1; 
		}else{
			l=mid+1;
		}		
			}
 return -1;		
}*/
