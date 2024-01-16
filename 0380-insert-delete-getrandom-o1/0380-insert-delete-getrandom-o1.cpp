class RandomizedSet {
public:
    vector<int> set;
    RandomizedSet() {}
    
    bool insert(int val) {
        auto c = find(set.begin(), set.end(), val);
        if(c != set.end()){
            return false;
        }
        else{
            set.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        auto c = find(set.begin(), set.end(), val);
        if(c != set.end()){
            int index = distance(set.begin(), c);
            set.erase(set.begin() + index);
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        return set[rand()%set.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */