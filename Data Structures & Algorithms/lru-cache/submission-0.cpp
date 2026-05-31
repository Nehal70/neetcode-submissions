class LRUCache {
private:
    unordered_map<int, list<pair<int,int>>::iterator> backMap;
    list<pair<int, int>> lruCache;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!backMap.count(key)) return -1;
        //in map, splice to front
        lruCache.splice(lruCache.begin(), lruCache, backMap[key]);
        return backMap[key]->second;
    }
    
    void put(int key, int value) {
        if (backMap.count(key)) {
            //edit existing value
            backMap[key]->second = value;
            //splice
            lruCache.splice(lruCache.begin(), lruCache, backMap[key]);
            return;
        } 
        if (lruCache.size() == this->capacity) {
            backMap.erase(lruCache.back().first);
            lruCache.pop_back();
        }
        lruCache.push_front({key, value});
        backMap[key] = lruCache.begin();
    }
};
