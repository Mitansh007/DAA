//Quick sort - recursive
#include <bits/stdc++.h>
using namespace std;
  
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSort(int A[], int l, int h)
{
    if (l < h) {
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}
 
int main()
{
    int size;
	cout<<"Enter size"<<endl;
	cin>>size;
	int A[size];
	cout<<"Enter array elements"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>A[i];
	}
    quickSort(A, 0, size - 1);
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
