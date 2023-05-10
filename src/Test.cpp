#include"GeneratePoint.h"
#include<iostream>
using namespace std ;

int main()
{
    cout<<"Enter Entity Name : ";
    string entityName;
    cin>>entityName;

    pair<long long ,long long> PublicKey = generateKey(entityName);
    cout<<"Puclic Key : "<<PublicKey.first<<" "<<PublicKey.second<<endl;
}