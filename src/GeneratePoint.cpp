#include <iostream>
#include "Point.h"
#include "ElipticCurve.h"
#include "Entity.h"

using namespace std;

ElipticCurve EC; // Object to store the elliptic curve parameters

// bool Is_Prime(int n)
// {
//     for (int i = 2; i <= n; i++)
//     {
//         if (n % i == 0)
//             return 0;
//     }
//     return 1;
// }

// Function to generate a point G on the elliptic curve
Point GeneratePointG(Entity E, ElipticCurve EC)
{
    srand(time(0));
    long long int x = rand() % EC.GetRangeC() + 1;
    long long int y = E.FindY(EC.CalcYsqrt(x));
    while (y == 0 && x < EC.GetRangeC())
    {
        y = E.FindY(EC.CalcYsqrt(++x));
    }
    Point G(x, y);
    return G;
}

// Function to create an elliptic curve
ElipticCurve CreateCurve()
{
    long long int a = 1009, b = 20056;

    // srand(time(NULL));

    // long long int RangeConst =rand() ;

    // while(!Is_Prime(RangeConst))
    // {
    //     RangeConst++;
    // }
    long long int RangeConst = 559799;
    ElipticCurve EC = ElipticCurve(a, b, RangeConst);
    return EC;
}

// Function to generate the key pair
pair<long long int, long long int> generateKey(string Name)
{
    EC = CreateCurve(); // Create the elliptic curve
    Entity newEntity(Name, EC); // Create an entity with a name and the elliptic curve

    Point G = GeneratePointG(newEntity, EC); // Generate point G on the elliptic curve
    srand(time(NULL));
    newEntity.PrivateKeyGeneration(); // Generate private key for the entity
    newEntity.PublicKeyGeneration(G); // Generate public key for the entity

    return {newEntity.PublicKey.getX(), newEntity.PublicKey.getY()};
}
