class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> s1, s2;

        for(int i=0; i<arr1.size(); i++){
            int num = arr1[i];
            s1.insert(num);
            while(num > 0){
                num /= 10;
                s1.insert(num);
            }
        }

        for(int i=0; i<arr2.size(); i++){
            int num = arr2[i];
            s2.insert(num);
            while(num > 0){
                num /= 10;
                s2.insert(num);
            }
        } 
        int len = 0;
        for(auto it:s1){
            if(s2.find(it) != s2.end()){
                int t = it;
                int tempLen = 0;
                while(t > 0){
                    tempLen++;
                    t /= 10;
                }
                len = max(tempLen,len);   
            }       
        }

        // for(auto it:s1){
        //     cout<<it<<" ";          
        // }
        // cout<<endl;
        // for(auto it:s2){
        //     cout<<it<<" ";          
        // }
        return len;
    }
};