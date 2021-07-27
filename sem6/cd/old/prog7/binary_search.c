#include<stdio.h>
int binary(int arr[], int x, int n){
int l=0;
int r=n-1;
int mid;
while(l<=r){
mid=(l+r)/2;
if(arr[mid]==x) return mid;
else if(arr[mid]<x){
l=mid+1;
}
else{
r=mid-1;
}
}
return -1;
}
int main(){
int arr[]={1,2,3,4,5,6,7,8,9,10};
int n=5;
int x=3;
int res=binary(arr,x,n);
if(res==-1) printf("Not found\n");
else printf("element found at %d\n",res);
return 0;
}
