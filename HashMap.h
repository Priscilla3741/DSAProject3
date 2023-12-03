#ifndef DSAPROJECT3_MAP_H
#define DSAPROJECT3_MAP_H

#include <vector>
#include <list>
#include "Stocks.h"
using namespace std;

class HashMap {
private:
    static const int hashGroups = 11;
    list<pair<string, vector<struct StockInfo>>> table[hashGroups];
public:
    HashMap() : table(hashGroups) {}
    bool isEmpty() const;
    int hashFunction(string key);
    void insert(string key, vector<struct StockInfo> info);

};

#endif //DSAPROJECT3_MAP_H
