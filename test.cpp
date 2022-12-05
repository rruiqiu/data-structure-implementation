/*************************************************************************
* File Name: test.cpp
* Author: TyrantLucifer
* E-mail: TyrantLucifer@gmail.com
* Blog: https://tyrantlucifer.com
* Created Time: 2022年04月19日 星期二 10时14分21秒
 ************************************************************************/
#include "HashTableLin.h"
#include "HashTableQuad.h"
using namespace std;

int main()
{
    /*
    HashTableLin* table = new HashTableLin(5, 0.4);
    table -> insert(2);
    table -> insert(4);
    table -> insert(15);
    table -> printKeys();
    table -> printKeysAndIndexes();
    */
    HashTableQuad* table1 = new HashTableQuad(5, 0.4);
    table1 -> insert(2);
    table1 -> insert(4);
    table1 -> insert(15);
    table1 -> printKeys();
    table1 -> printKeysAndIndexes();
    return 0;
}

