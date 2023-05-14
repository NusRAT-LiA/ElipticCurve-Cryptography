#include"GeneratePoint.h"
#include<iostream>
using namespace std ;

int main()
{
    string entityName ;
    cout<<"Enter the name of Entity  : "<<endl;
    cin>>entityName;

    pair<long long , long long > publicKey = generateKey(entityName);
    cout<<"Public key pair : "<<publicKey.first<<" "<<publicKey.second<<endl;
    
}