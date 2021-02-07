#include<iostream>
#include<string.h>
using namespace std;

long int gcd(long int a,long int b)
{
    if(a == 0 )
	return b;
    if(b == 0)
	return a;
    return gcd(b,a%b);
}


bool isPrime(long int x)
{

    for(long int i=2;i<x/2;i++)
    {
	if(x%i == 0)
	    return false;
    }
    return true;
}

long int encrypt(char ch,long int n,long int e)
{
    long int temp = ch;
    for(long int i = 1; i < e ;i++)
    {
	temp = (temp*ch) % n ;
	
    }
    return temp;
}


char decrypt(long int ch,long int n,long int d)
{   
    long int i ;
    long int temp = ch;
    for(i=1 ; i< d;i++)
    {
	temp = (temp * ch ) % n;
    }
    return temp;
}

int main()
{	
    long int p,q,n,e,d,phi;
    char message[50];
    long int cipher[50];
    cout<<"Enter the message to be encrypted:"<<endl;
    cin.getline(message,sizeof(message));
    
    long int len = strlen(message);

    do{
	p = rand() % 30 ;
    }while(!isPrime(p));


    do{
	q = rand() % 30;
    }while(!isPrime(q));


    n = p * q;
    phi = (p-1) * (q-1);

    do{
	e = rand() % phi;
    }while(gcd(phi,e)!=1);

    do{
	d = rand() % phi;
    }while( (d*e)%phi != 1 );


    cout<<"P : "<<p<<endl;
    cout<<"Q : "<<q<<endl;
    cout<<"N : "<<n<<endl;
    cout<<"PHI : "<<phi<<endl;
    cout<<"E : "<<e<<endl;
    cout<<"D : "<<d<<endl;

        
    for(int i=0;i<len;i++)
    {
	cipher[i] = encrypt(message[i],n,e);
    }
    
    cout<<"Encrypted Message : "<<endl;
    for(int i=0;i<len;i++)
	cout<<cipher[i]<<" ";
    for(int i= 0;i<len;i++)
	message[i] = decrypt(cipher[i],n,d);

    cout<<"\nDecrypted Message : "<<endl;
    for(int i=0;i<len;i++)
	cout<<message[i]<<" ";
    return 0;    
}
