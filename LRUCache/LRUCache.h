#include<bits/stdc++.h>
#ifndef LRUCACHE_H
#define LRUCACHE_H

class LRUCache {
    unsigned int _capacity;
    //capacity of the cache
    std::unordered_map<int,std::pair<int,std::list<int>::iterator> > _cache;
    // < key < value , iterator of the key> >
    std::list<int> _lru;
    //list of the keys
    void update(std::unordered_map<int , std::pair<int, std::list<int>::iterator> >::iterator &temp);
    //helper function
public:
    //constructor : initiates a cache of size capacity
    LRUCache(int capacity);
    // returns the value associated with key
    int get(int key);
    //sets the key-value pair
    void put(int key, int value);
};
#endif // LRUCACHE_H
