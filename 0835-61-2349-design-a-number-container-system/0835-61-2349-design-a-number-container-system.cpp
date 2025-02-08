class NumberContainers {
public:
    unordered_map<int,int> idxNum;
    unordered_map<int,set<int>> numIdxs;
    NumberContainers() {}
    
    void change(int index, int number) {
        if(idxNum.find(index) != idxNum.end()){
            int prevNum = idxNum[index];
            numIdxs[prevNum].erase(index);
            // if all indices of the number are removed just remove the number
            if (numIdxs[prevNum].empty()) {
                numIdxs.erase(prevNum);
            }
        }
        idxNum[index] = number;
        numIdxs[number].insert(index);
        return;
    }
    
    int find(int number) {
        if(numIdxs.find(number) != numIdxs.end()){
            // return smallest index of occurence of number
            return *numIdxs[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */