#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "HashMap.h"
using namespace std;

bool HashMap::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashMap::hashFunction(string key) {
    return key.size() % hashGroups;
}

void HashMap::insert(string key, vector<struct StockInfo> info) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto iterateBegin = begin(cell);
    bool keyExists = false;
    for (; iterateBegin != end(cell); iterateBegin++) {
        if (iterateBegin->first == key) {
            keyExists = true;
            iterateBegin->second = info;
        }
    }
    if (!keyExists) {
        cell.emplace_back(key, info);
    }
}
