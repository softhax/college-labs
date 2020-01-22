#include<bits/stdc++.h>
using namespace std;
#define size 1000
int count=0;

void swap(int *a,int *b)
{   
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high)
{
    int i,j,pivot;
    pivot=arr[low];
    i=low+1;	j=high;
    while(1)
    {
	while(pivot>=arr[i] && i<=high)
	    {i++;   ::count++;}
	while(pivot<arr[j])
	    {j--;   ::count++;}
	if(i<j)
	    {swap(&arr[i],&arr[j]);}
	else
	    {swap(&arr[low],&arr[j]);}
	return j;
   }
}

void quick_sort(int arr[],int low,int high)
{
   int i;
   if(low<high)
   {
       i=partition(arr,low,high);
       quick_sort(arr,low,i-1);
       quick_sort(arr,i+1,high);
   }
}


int main()
{
    int i,n,j,k,c1,c2,c3,a[size],b[size],c[size];    
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    cout<<"Enter the array:"<<endl;
    for(i=0;i<n;i++)	cin>>a[i];
    quick_sort(a,0,n-1);
    cout<<"The sorted array is :"<<endl;
    for(i=0;i<n;i++)
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

	::count=0;  quick_sort(a,1,i);	c1=::count;
	::count=0;  quick_sort(b,1,i);	c2=::count;
	::count=0;  quick_sort(c,1,i);	c3=::count;
	cout<<i<<"\t"<<c1<<"\t"<<c2<<"\t"<<c3<<"\n";
    }
    return 0;
}
