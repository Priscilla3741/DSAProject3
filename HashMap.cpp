#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "HashMap.h"
using namespace std;

template<typename Key, typename Value>
int HashMap<Key, Value>::hashFunction(struct HashMap *map, Key *key) {
    int bucketIndex;
    int sum = 0;
    int factor = 31;

    for (int i = 0; i < strlen(key); i++) {
        sum = ((sum % map->capacity) + (((int)key[i]) * factor) % map->capacity) % map->capacity;
    }
}

template<typename Key, typename Value>
void HashMap<Key, Value>::Insert(struct HashMap* map, const Key* k, const Value* v) {
    if (size >= capacity * 0.75) {
        // rehash(capacity * 2)
    }
}

template<typename Key, typename Value>
void HashMap<Key, Value>::reHash(int capacity) {
    new HashMap = vector<
}
