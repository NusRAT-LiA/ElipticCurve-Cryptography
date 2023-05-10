#include <iostream>
#include "Point.h"
#include "ElipticCurve.h"
#include "Entity.h"

using namespace std;

ElipticCurve EC;
//Entity newEntity;

bool Is_Prime(int n)
{
    for (int i=2;i<=n;i++) 
    {
	
        if (n % i == 0)
            return 0;
     
    }
    return 1;
 }

 Point GeneratePointG(Entity E,ElipticCurve EC)
 {
 	srand(time(0));
	long long int x = rand()%EC.GetRangeC()+1;
	long long int y=E.FindY(EC.CalcYsqrt(x));	
	while(y==0 && x<EC.GetRangeC())
	{
		y=E.FindY(EC.CalcYsqrt(++x));	
	}
 	Point G(x,y);
 	return G;
 }

 ElipticCurve CreateCurve()
 {
    long long int  a=1009 , b = 20056;

    // srand(time(NULL));

    
    // long long int RangeConst =rand() ;

    // while(!Is_Prime(RangeConst))
    // {
    //     RangeConst++;
    // }
    long long int RangeConst = 559799 ;
    ElipticCurve EC= ElipticCurve(a , b , RangeConst);
   return EC;
 }

pair<long long int , long long int > generateKey(string Name)
{  
   EC=CreateCurve();
   Entity newEntity(Name,EC);
   Point G = GeneratePointG(newEntity,EC);
   srand(time(NULL));
   newEntity.PrivateKeyGeneration();
   newEntity.PublicKeyGeneration(G);
   
   
   return {newEntity.PublicKey.getX(),newEntity.PublicKey.getY()};
   
}

// int main()
// {
//    pair<long long int , long long int > result ;
//    cout<<"Executing"<<endl;
//    result=generateKey("Alice");
//    cout<<"PublicKey :  "<<result.first<<"\t"<<result.second<<endl;
// }