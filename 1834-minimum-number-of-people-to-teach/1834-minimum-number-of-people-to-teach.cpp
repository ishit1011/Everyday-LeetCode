class Solution {
public:
    int countIntersections(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq1;
        for (int x : arr1) {
            freq1[x]++;
        }

        int count = 0;
        for (int x : arr2) {
            if (freq1[x] > 0) {
                count++;
                freq1[x]--; // Decrement count to account for duplicates
            }
        }
        return count;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int,int> friendCommonLang;
        int f = friendships.size();

        vector<vector<int>> userNoCommonLangs;
        for(int i=0; i<f; i++){
            int p1 = friendships[i][0], p2 = friendships[i][1]; 
            vector<int> langs1 = languages[p1-1];
            vector<int> langs2 = languages[p2-1];
            int commonLangs = countIntersections(langs1,langs2);
            if(commonLangs == 0){
                userNoCommonLangs.push_back({p1,p2});
            }
        }

        sort(userNoCommonLangs.begin(),userNoCommonLangs.end());
        cout<<"No common langs : ";
        for(int i=0; i<userNoCommonLangs.size(); i++){
            cout<<"["<<userNoCommonLangs[i][0]<<","<<userNoCommonLangs[i][1]<<"]";
        }

        // Step 2: For each language, count unique people to teach
        cout<<endl;
        int minTeach = INT_MAX;
        for (int lang = 1; lang <= n; ++lang) {
            unordered_set<int> toTeach;
            for (auto& pair : userNoCommonLangs) {
                int p1 = pair[0] - 1, p2 = pair[1] - 1;
                bool p1Knows = false;
                for (int l : languages[p1]) {
                    if (l == lang) {
                        p1Knows = true;
                        break;
                    }
                }
                bool p2Knows = false;
                for (int l : languages[p2]) {
                    if (l == lang) {
                        p2Knows = true;
                        break;
                    }
                }
                if (!p1Knows) toTeach.insert(pair[0]);
                if (!p2Knows) toTeach.insert(pair[1]);
            }
            // Debug: Print users to teach for this language
            cout << "Language " << lang << " needs teaching to: ";
            for (int user : toTeach) {
                cout << user << " ";
            }
            cout << "(total: " << toTeach.size() << ")" << endl;
            minTeach = min(minTeach, (int)toTeach.size());
        }

        return minTeach;
    }
};