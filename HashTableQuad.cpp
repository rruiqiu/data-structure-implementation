#include "HashTableQuad.h"
#include <math.h>
#include <iostream>
using namespace std;

HashTableQuad::HashTableQuad(int maxNum, double load)
{
    int size = ceil(maxNum / load);
    setTableSize(size);
    setMaxLoadFactor(load);
    table.reserve(size);
}

void HashTableQuad::insert(int n)
{
    int index = n % size;
    int count = 1;
    if (table[index] != 0) {
        while (table[index]!= 0) {
            cout << index;
            if (count % 2 == 0) {
                index = (index - ceil(count / 2.0) * ceil(count / 2.0));
            } else {
                index = (index + ceil(count / 2.0) * ceil(count / 2.0));
            }
            count++;
        }
        if (index >= size) {
            rehash();
        }
    } else {
        table[index] = n;
    }
    keyNum++;
    if (keyNum >= size) {
        rehash();
    }
}

void HashTableQuad::rehash()
{
    size = size * 2;
    table.resize(size);
}

bool HashTableQuad::isIn(int n)
{
    for (int i = 0 ; i < size; i++) {
        if (table[i] == n) {
            return true;
        }
    }
    return false;
}

void HashTableQuad::printKeys()
{
    for(int i = 0; i < size; i++) {
        if (table[i] != 0) {
            cout << table[i] << " ";
        }
    }
    cout << endl;
}

void HashTableQuad::printKeysAndIndexes()
{
    for(int i = 0; i < size; i++) {
        if (table[i] != 0) {
            cout << "index:" << i << " key:" << table[i] << " " << endl;
        }
    }
    cout << endl;
}

std::vector<double> HashTableQuad::simProbeSuccess()
{
    vector<double> result(9);
    double res;
    for (double i = 0.1; i < 1.0; i = i + 0.1) {
        res = 1 / i * log(1 / (1 - i));
        result.push_back(res);
    }
    return result;
}
