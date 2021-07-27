#include<stdio.h>
int main(){
int n=6;
int arr[]={5,4,2,1,10,15};
int i,j;
for(i=0;i<6;i++){
for(j=i+1;j<n;j++){
if(arr[j]<arr[i]){
int temp=arr[j];
arr[j]=arr[i];
arr[i]=temp;
}
}
}
for(i=0;i<6;i++){
printf("%d ",arr[i]);
}
}
