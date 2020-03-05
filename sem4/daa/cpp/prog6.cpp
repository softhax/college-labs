#include<bits/stdc++.h>
using namespace std;
#define size 256
int table[size];

void ShiftTable(char pattern[10])
{
    int i,j,m;
    m = strlen(pattern);
    for(i = 0;i<size;i++)   table[i] = m; 
    for(j=0;j<m-1;j++)	table[pattern[j]] = m-1-j;
}

int Horspool(char text[50],char pattern[10])
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i=m-1,j;
    while(i<n)
    {
	int k = 0;  //Matching index
	while(k<m && pattern[m-1-k]==text[i-k])	k++;	//Check matching
	if(k==m)    return i-m+1;	    // Will execute when match found
	else i += table[text[i]];
    }
    return -1;
}
int main()
{
    char pattern[10],text[50];
    cout<<"Enter the string :"<<endl;
    cin>>text;
    cout<<"Enter the pattern :"<<endl;
    cin>>pattern;
    ShiftTable(pattern);
  //  cout<<"It reaches here"<<endl;
//    for(int i = 0 ; i <size;i++)
//	    cout<<table[i]<<" ";
    //cout<<"It also reachers here"<<endl;
    fflush(stdout);
    int pos = Horspool(text,pattern);
    if(pos == -1)   cout<<"Patten not found !!"<<endl;
    else    cout<<"Pattern found at position "<<pos<<endl;
    
    return 0;
}
