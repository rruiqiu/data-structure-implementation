#include "HashTableLin.h"
#include <math.h>
#include <iostream>
using namespace std;

HashTableLin::HashTableLin(int maxNum, double load)
{
    int size = ceil(maxNum / load);
    setTableSize(size);
    setMaxLoadFactor(load);
    table.reserve(size);
}

void HashTableLin::insert(int n)
{
    int index = n % size;
    if (table[index] != 0) {
        while (table[index] != 0) {
            index++;
        }
        if (index >= size) {
            rehash();
        }
        table[index] = n;
    } else {
        table[index] = n;
    }
    keyNum++;
    if (keyNum >= size) {
        rehash();
    }
}

void HashTableLin::rehash()
{
    size = size * 2;
    while (isPrime(size) != true) {
        size++;
    }

    table.resize(size);
}

bool HashTableLin::isIn(int n)
{
    for (int i = 0 ; i < size; i++) {
        if (table[i] == n) {
            return true;
        }
    }
    return false;
}

void HashTableLin::printKeys()
{
    for(int i = 0; i < size; i++) {
        if (table[i] != 0) {
            cout << table[i] << " ";
        }
    }
    cout << endl;
}

void HashTableLin::printKeysAndIndexes()
{
    for(int i = 0; i < size; i++) {
        if (table[i] != 0) {
            cout << "index:" << i << " key:" << table[i] << " " << endl;
        }
    }
    cout << endl;
}

std::vector<double> HashTableLin::simProbeSuccess()
{
    vector<double> result(9);
    double res;
    for (double i = 0.1; i < 1.0; i = i + 0.1) {
        res = 0.5 * (1 + 1 / (1 - i));
        result.push_back(res);
    }
    return result;
}

// for bonus
std::vector<double> HashTableLin::simProbeUnsuccess()
{
    // TODO, change following code after completing this function
    vector<double> result(9);
    double res;
    for (double i = 0.1; i < 1.0; i = i + 0.1) {
        res = 0.5 * (1 + 1 / ((1 - i) * (1 - i)));
        result.push_back(res);
    }
    return result;
}
