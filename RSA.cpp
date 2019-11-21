//
// Created by Sankalp Bhamare on 20/11/19.
//

#include "RSA.h"

using namespace std;
const int saltLen = 3;

long int gcd(long int a, long int b) {
    long int t;
    while (true) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

long int newPrime(long int x) {
    long int n = 0;
    long int prime = 0;
    long int i = 0;
    while (n < x) {
        if (isPrime(i)) {
            n++;
            prime = i;
        }
        i++;
    }
    return prime;
}

bool isPrime(long int x) {
    for (long int i = 2; i < sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


RSAGenerator::RSAGenerator() {

}

RSAGenerator::RSAGenerator(long int salt) {
    this->salt = salt;
}

bool RSAGenerator::checkSalt() {
    if (salt > ((long int) pow(10, saltLen * 2 - 1)) && salt < ((long int) pow(10, saltLen * 2))) {
        if (p1 == p2) {
            return false;
        } else if (p1 < 10 || p2 < 10) {
            return false;
        } else
            return true;

    } else {
        return false;
    }
}

void RSAGenerator::useSalt() {
    if (salt > ((long int) pow(10, saltLen * 2 - 1)) && salt < ((long int) pow(10, saltLen * 2))) {
        p1 = salt % ((int) pow(10, saltLen));
        p2 = (salt - p1) / ((int) pow(10, saltLen));
    }
}

void RSAGenerator::createKey() {
    useSalt();
    if (checkSalt()) {
        p = newPrime(p1);
        q = newPrime(p2);
        n = p * q;
        phi = (p - 1) * (q - 1);
        createPublicKey();
        createPrivateKey();
    }

}

void RSAGenerator::createPublicKey() {
    e = 7;
    long int ea[100];
    long int er = 7;
    long int track;
    long int ind = 0;
    while (er < phi) {
        if (ind >= 100)
            break;
        track = gcd(er, phi);
        if (track == 1 && er != p && er != q) {

            ea[ind++] = er;
        }
        er++;
    }

    e = ea[ind / 2];
}

void RSAGenerator::createPrivateKey() {
    long int i = 1;
    while (true) {

        if ((1 + i * phi) % e == 0) {
            break;
        }
        i++;
    }
    d = (1 + i * phi) / e;
}


RSAKey::RSAKey() {
    n = 0;
    e = 0;
    d = 0;
    isPrivate = false;
}

RSAKey::RSAKey(RSAGenerator rgen) {
    n = rgen.n;
    e = rgen.e;
    d = rgen.d;
    isPrivate = true;
}

long int RSAKey::encrypt(long int data) {
    long int res = 1;
    for (long int i = 0; i < e; i++) {
        res = res * data;
        res = res % n;
    }
    return res;
}


long int RSAKey::decrypt(long int data) {
    if (isPrivate) {
        long int res = 1;
        for (long int i = 0; i < d; i++) {
            res = res * data;
            res = res % n;
        }
        return res;
    } else {
        return -1;
    }
}

void RSAKey::saveToFile(char *fileName) {
    ofstream fout(fileName, ios::binary | ios::out);
    fout.write((char *) this, sizeof(RSAKey));
    fout.close();
}
void RSAKey::savePublicKey(char *fileName) {
    ofstream fout(fileName, ios::binary | ios::out);
    long int temp = this->d;
    this->d = 0;
    this->isPrivate = false;
    fout.write((char *) this, sizeof(RSAKey));
    this->d = temp;
    this->isPrivate = true;
    fout.close();
}

int RSAKey::loadFromFile(char *fileName) {
    ifstream fin(fileName, ios::binary | ios::in);
    if(!fin){
        return 0;
    }
    fin.read((char *) this, sizeof(RSAKey));
    fin.close();
    return 1;
}

RSABlockKey::RSABlockKey(RSAKey key) {
    this->key = key;
}

void RSABlockKey::encrypt(char *blob, long int size, long int *res) {


    for (long int i = 0; i < size; i++) {
        res[i] = key.encrypt(blob[i]);
    }

}

void RSABlockKey::decrypt(long int *blob, long int size, char *res) {

    for (long int i = 0; i < size; i++) {
        res[i] = (char) key.decrypt(blob[i]);
    }

}

RSABlockKey::RSABlockKey() {

}

void RSABlockKey::changeKey(RSAKey key) {
    this->key = key;
}




void RSABlockKey::writeBlockData(char *blob, long int size, std::ostream &fout) {
    long int res[size];
    encrypt(blob, size, res);
    fout.write((char*)&res,sizeof(res));
}




void RSABlockKey::readBlockData(char *blob, long int size, std::istream &fin) {
    long int res[size];
    fin.read((char*)&res,sizeof(res));
    decrypt(res, size, blob);
}
