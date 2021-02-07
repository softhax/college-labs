#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
#define q 23     //mod
#define alpha 5  //base

long int generateKey(long int base,long int exp)
{
    long int rem ;
    long int key = 1;
    while(exp>0)
    {
	rem = exp%2;
	if(rem == 1)
	    key = (key * base) % q;
	base = (base * base) % q;
	exp = exp / 2;
    }
    return key;
    
}

int main()
{
    long int a_private,a_public,b_private,b_public,shared_key_a,shared_key_b;
    cout<<" q - mod value  = "<<q<<endl;
    cout<<" alpha - base value = "<<alpha<<endl;
    srandom(time(0));

    a_private = random();

    b_private = random();
    
    cout<<"Private Keys are : "<<endl;
    cout<<" a_private = "<<a_private<<endl;
    cout<<" b_private = "<<b_private<<endl;

    a_public = generateKey(alpha,a_private);
    b_public = generateKey(alpha,b_private);
    cout<<"Public Keys : " <<endl;
    cout<<"a_public : "<<a_public<<endl;
    cout<<"b_public : "<<b_public<<endl;
    
    shared_key_a = generateKey(b_public,a_private);
    shared_key_b = generateKey(a_public,b_private);


    cout<<"Shared Key with :"<<endl;
    cout<<"A : "<<shared_key_a<<endl;
    cout<<"B : "<<shared_key_b<<endl;
    return 0;
}
