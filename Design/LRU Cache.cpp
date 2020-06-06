list<int>lis;
unordered_map<int,int>mp;
unordered_map<int,list<int>::iterator>h_mp;
int lis_cap;
class LRUCache {
public:
    LRUCache(int capacity) {
        lis_cap=capacity;
        lis.clear();
        mp.clear();
        h_mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        lis.erase(h_mp[key]);
        lis.push_front(key);
        h_mp[key]=lis.begin();
        
        return mp[key];
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
            mp.erase(key),lis.erase(h_mp[key]);
        if(lis.size()==lis_cap)
            mp.erase(lis.back()),lis.pop_back();
        mp[key]=value;
        lis.push_front(key);
        h_mp[key]=lis.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
