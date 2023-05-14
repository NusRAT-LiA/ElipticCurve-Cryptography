# ElipticCurve-Cryptography
A comprehensive C++ implementation of Elliptic Curve Cryptography (ECC) for PublicKey and PrivateKey generation .


## Introduction

Elliptic curve cryptography is a modern cryptographic technique that utilizes the properties of elliptic curves to provide secure communication. This program demonstrates the generation of public key pairs using elliptic curves along with providing learning materials for anyone intrested in the world of cryptography.

## Prerequisites

- C++ compiler
- Standard Template Library (STL)

## Getting Started

1. Clone the repository:

```bash
git clone https://github.com/NusRAT-LiA/ElipticCurve-Cryptography.git
```
2.    Include the "GeneratePoint.h" header file in your code to use the elliptic curve point generation functionality.

```cpp
#include "GeneratePoint.h"
```

3.    Implement your code using the generateKey() function from "GeneratePoint.h" to generate public key pairs. Here's an example:

```cpp
#include <iostream>
#include "GeneratePoint.h"

using namespace std;

int main()
{
    string entityName;
    cout << "Enter the name of the Entity: " << endl;
    cin >> entityName;

    pair<long long, long long> publicKey = generateKey(entityName);
    cout << "Public key pair: " << publicKey.first << " " << publicKey.second << endl;

    return 0;
}

```

## Usage

1.   Enter the name of the entity when prompted:
```bash
Enter the name of the Entity:
Alice

```
2.    The program will generate a pair of public keys:
```bash
 
Rremember Alice's  Private Key , You cant invoke it again !!  : 409224
Public key pair: 123456789 987654321

```

## Contributing

Contributions to the SHA256-Hashing project are welcome! If you have any improvements, bug fixes, or new features to add, please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature`
3. Commit your changes: `git commit -m 'Add your feature'`
4. Push to the branch: `git push origin feature/your-feature`
5. Submit a pull request.

## License

This project is licensed under the MIT License.