class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // leading digit is not zero
        // resulting number is a power of two --> TRUE 
        vector<int> arr;
        for(int i=0; i<30; i++){
            int num = pow(2,i);
            arr.push_back(num);
        }
        int idx = 0;
        while(idx < 30 ){
            int powerTwo = arr[idx];
            string str = to_string(powerTwo);
            sort(str.begin(),str.end());
            string compStr = to_string(n);
            sort(compStr.begin(),compStr.end());

            cout<<"str : "<<str<<" compStr : "<<compStr<<endl;
            if(str == compStr) return true;
            idx++;
        }
        return false;
    }
};