class LRUCache {
private:
    // pointer to list to add and update nodes
    unordered_map<int, list<pair<int, int>>::iterator> _hash;
    // stores the values at keys to remove them quickly
    list<pair<int, int>> _list;
    // current size
    int _size;
    // maximum capacity
    int _capacity;
    
public:
    LRUCache(int capacity) {
        // intialise current size as 0
        _size = 0;
        // initialise maximum capacity
        _capacity = capacity;
    }
    
    int get(int key) {
        if(_hash.find(key) == _hash.end())
            // key not found, return -1
            return -1;
        auto p = _hash[key];
        // get the value from the key
        int value = p->first;
        // recently accessed, so
        // remove from list
        _list.erase(p);
        // and push in the front
        _list.push_front({value, key});
        _hash[key] = _list.begin();
        return value;
    }
    
    void put(int key, int value) {
        // check if key is previously there
        if(_hash.find(key) != _hash.end()){
            _list.erase(_hash[key]);
            _size--;
        }
        // insert new key into LRU cache
        _list.push_front({value, key});
        auto p = _list.begin();
        _hash[key] = p;
        _size++;
        // if size overflows than capacity, remove recently used key
        if(_size > _capacity){
            key = _list.back().second;
            _hash.erase(key);
            _list.pop_back();
            _size--;
        }
    }
};