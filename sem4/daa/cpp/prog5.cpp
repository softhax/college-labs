#include<bits/stdc++.h>
using namespace std;
int count = 0;
#define SIZE 2000
void Heapify(int arr[2000],int n)
{
    int i,j;
    for(i=floor(n/2);i>=1;i--)
    {
	int k = i;
	int v = arr[k];
	bool heap = false;
	while(!heap && 2*k<=n)
	{
	    j = 2*k;
	    if(j<n)
		if(arr[j]<arr[j+1])
		    j++;
	    if(v>=arr[j])
		heap = true;
	    else
	    {
		arr[k] = arr[j];
		k = j;
	    }

	    ::count++;
	    arr[k] = v;
	}
    }
}

void swap(int *a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heap_sort(int arr[2000],int size)
{
    int i;
    Heapify(arr,size);
    for(i=size;i>=1;i--)
    {
	swap(&arr[1],&arr[i]);
	Heapify(arr,i-1);
    }
}


int main()
{
    int i,n,j,k,c1,c2,c3,a[SIZE],b[SIZE],c[SIZE];    
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    cout<<"Enter the array:"<<endl;
    for(i=1;i<=n;i++)	cin>>a[i];
    heap_sort(a,n);
    cout<<"The sorted array is :"<<endl;
    for(i=1;i<=n;i++)
	cout<<a[i]<<"\t";
    cout<<"\nThe basic operation was executed "<<::count<<" times."<<endl;
    cout<<"\nSIZE\tASC\tDESC\tRAN\n";
    for(i=16;i<1000;i*=2)
    {
	for(j=1;j<=i;j++)
	{
	    a[j]=j;
	    b[j]=i-j+1;
	    c[j]=(rand()%i)+1;    
	}

	::count=0;  heap_sort(a,i);	c1=::count;
	::count=0;  heap_sort(b,i);	c2=::count;
	::count=0;  heap_sort(c,i);	c3=::count;
	cout<<i<<"\t"<<c1<<"\t"<<c2<<"\t"<<c3<<"\n";
    }
    return 0;
}
