#ifndef DSAPROJECT3_MAP_H
#define DSAPROJECT3_MAP_H
#include <vector>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename Key, typename Value>
struct keyValue {
    Key key;
    Value value;
    keyValue(const Key& k, const Value& v) : key(k), value(v) {};
};
template <typename Key, typename Value>
class HashMap {
private:
    std::vector<std::list<std::pair<Key, Value>>> map;
    int capacity;
    int size;
public:
    int hashFunction(struct HashMap* map, Key* key);
    void Insert(struct HashMap* map, const Key* k, const Value* v);
    void reHash(int capacity);
};


#endif //DSAPROJECT3_MAP_H
