class FindSumPairs {
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& _nums1, vector<int>& _nums2) {
        nums1 = _nums1;
        nums2 = _nums2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }

    void add(int index, int val) {
        // Decrease old value frequency
        freq2[nums2[index]]--;
        if (freq2[nums2[index]] == 0) freq2.erase(nums2[index]);

        // Update value in nums2
        nums2[index] += val;

        // Increase new value frequency
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        int countPairs = 0;
        for (int num : nums1) {
            int complement = tot - num;
            if (freq2.count(complement)) {
                countPairs += freq2[complement];
            }
        }
        return countPairs;
    }
};


/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */