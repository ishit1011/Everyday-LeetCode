class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        map<int,int> count;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        
        while(n--){
            for(auto [x,y] : count){
                for(int i=x; i<x+k; i++){
                    cout<<"subset starts";
                    if(count[i] == 0){return false;}
                    count[i]--;
                    if(count[i] == 0){count.erase(i);}
                    cout<<"\n";
                }
                cout<<"------map element ends----\n";
                break;
                
            }
        }
        return true;
    }
};