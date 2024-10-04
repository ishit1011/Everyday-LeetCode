class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());
        int l = 0, r = n-1, sum = skill[l] + skill[r];
        long long ans = 0;
        while(l < r){
            if(skill[l] + skill[r] != sum){
                return -1;
            }
            ans += (skill[l] * skill[r]);
            l++;
            r--;
        }
        return ans;
    }
};