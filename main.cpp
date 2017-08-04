#include <iostream>
#include<bits/stdc++.h>

using namespace std;
class LRUCache {
private:
    unsigned int _capacity;
    //capacity of the cache
    unordered_map<int,pair<int,list<int>::iterator> > _cache;
    // < key < value , iterator of the key> >
    list<int> _lru;
    //list of the keys
    void update(unordered_map<int , pair<int, list<int>::iterator> >::iterator &temp){
        //first erase from the list
        _lru.erase(temp->second.second);
        //now add to the front of the list
        _lru.push_front(temp->first);
        //update the iterator in temp as _lru.begin()
        temp->second.second=_lru.begin();
    }
public:
    LRUCache(int capacity){
        _capacity=capacity;
    }
    int get(int key){
        auto temp=_cache.find(key);
        //if the key doesn't exists return -1
        if(temp==_cache.end())return -1;
        //if exists return the value & update the position of the key to the front of the list
        update(temp);
        return temp->second.first;
    }
    void put(int key, int value) {
        auto item = _cache.find(key);
        //if already present than just update the values
        if(item!=_cache.end()){
            //updating the linked list
            _lru.erase(item->second.second);
            _lru.push_front(key);
            //update the map
            _cache[key]={value,_lru.begin()};
            return;
        }
        //if space is left in the cache then push at front
        //else first remove the least recently used item ie. from the end of linked list
        if(_lru.size()>=_capacity){
            //first remove the lru value from map
            _cache.erase(_lru.back());
            //then from the linked list
            _lru.pop_back();
        }
        //insert at the beginning the key
        _lru.push_front(key);
        //insert into the map the given key-value pair
        _cache.insert({key,{value,_lru.begin()}});
        return;
    }
};
int main()
{
    LRUCache cache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cout<<cache.get(1)<<endl;       // returns 1
cache.put(3, 3);    // evicts key 2
cout<<cache.get(2)<<" ";       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cout<<cache.get(1)<<" ";       // returns -1 (not found)
cout<<cache.get(3);       // returns 3
cache.get(4);       // returns 4
    return 0;
}
