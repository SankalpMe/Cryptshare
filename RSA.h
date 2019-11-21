//
// Created by Sankalp Bhamare on 20/11/19.
//
#include "math.h"
#include "fstream"

#ifndef HELLO_RSA_H
#define HELLO_RSA_H

long int gcd(long int a, long int b);

bool isPrime(long int x);

long int generatePrime(long int x);


class RSAGenerator {

private:
    long int p;
    long int q;
    long int phi;
    long int salt;

    void useSalt();

    void createPublicKey();

    void createPrivateKey();

    int p1;
    int p2;
public:
    long int d;
    long int e;
    long int n;

    RSAGenerator();

    RSAGenerator(long int salt);

    bool checkSalt();

    void createKey();

};

class RSAKey {
public:
    long int n;
    long int e;
    long int d;
    bool isPrivate;

    RSAKey();

    RSAKey(RSAGenerator rgen);

    long int encrypt(long int data);

    long int decrypt(long int data);

    void saveToFile(char *fileName);
    void savePublicKey(char *fileName);
    int loadFromFile(char *fileName);
};

class RSABlockKey {
    RSAKey key;
    public:
    RSABlockKey(RSAKey key);
    RSABlockKey();
    void changeKey(RSAKey key);
    void encrypt(char *blob,long int size,long int *res);
    void decrypt(long int *blob,long int size,char *res);
    void writeBlockData(char* blob, long int size, std::ostream &fout);
    void readBlockData(char* blob, long int size, std::istream &fin);
};




#endif //HELLO_RSA_H
