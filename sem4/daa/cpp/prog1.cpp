#include<bits/stdc++.h>
using namespace std;
#define size 1000

int count=0;

void merge(int arr[],int low,int high,int mid)
{
    int i,j,k,b[size];
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high)
    {
	if(arr[i]<arr[j])
	{ 
	    b[k++]=arr[i++];
	    ::count++;
	}

	else
	{
	    b[k++]=arr[j++];
	    ::count++;
	}
    
    }

    while(i<=mid)
    {
	b[k++]=arr[i++];
	::count++;
    }

    while(j<=high)
    {
	b[k++]=arr[j++];
	::count++;
    }

    for(i=low;i<=high;i++)
	arr[i]=b[i];
    
}


void merge_sort(int arr[],int low,int high)
{
    int mid;
    if(low<high)
    {
	mid=(low+high)/2;
	merge_sort(arr,low,mid);
	merge_sort(arr,mid+1,high);
	merge(arr,low,high,mid);
    }

}
int main()
{
    int i,n,j,k,c1,c2,c3,a[size],b[size],c[size];    
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    cout<<"Enter the array:"<<endl;
    for(i=0;i<n;i++)	cin>>a[i];
    merge_sort(a,0,n-1);
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

	::count=0;  merge_sort(a,1,i);	c1=::count;
	::count=0;  merge_sort(b,1,i);	c2=::count;
	::count=0;  merge_sort(c,1,i);	c3=::count;
	cout<<i<<"\t"<<c1<<"\t"<<c2<<"\t"<<c3<<"\n";
    }
    return 0;
}
