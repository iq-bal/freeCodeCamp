#include<iostream>

using namespace std;

const int N=1e5+10;
int fact[N];

void factorial(){
    fact[0]=1;
    fact[1]=1;
    for (int i = 2; i < N; i++)
    {
        fact[i]= fact[i-1]*i;
    }
}

int main(){
    // this is the concept of precomputation
    factorial();
    int t;  cin>>t;
    while (t--)
    {
        
    }
    return 0;
}

/*
hashing is a precomputation techniques 
hashing is a searching technique 
*/