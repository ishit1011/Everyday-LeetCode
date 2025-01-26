class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [] (auto e1, auto e2) { 
            if(stoi(e1[1]) == stoi(e2[1]))
            return e1[0][0] > e2[0][0];   //if same timeStamp then put offline event first i.e. return true if e1[0][0]=='o' (offline)
            
            return stoi(e1[1]) < stoi(e2[1]);   // else put less timeStamp first
             
        }); 
        vector<int> cntMentions(numberOfUsers,0);
        
        vector<int> offlineStartTime(numberOfUsers,-1);
        int n = events.size();
        for(int i=0; i<n; i++){
            string eType = events[i][0];
            int timeStamp = stoi(events[i][1]);
            string allIds = events[i][2];
            
            if(eType == "MESSAGE"){
                if(allIds == "ALL"){
                    for(int id=0; id<numberOfUsers; id++){
                        cntMentions[id]++; 
                    }
                }
                else if(allIds == "HERE"){
                    for(int id=0; id<numberOfUsers; id++){
                        if(offlineStartTime[id] == -1 || offlineStartTime[id]+59 < timeStamp){
                            cntMentions[id]++;
                        }    
                    }
                }
                else{
                    unordered_map<int, int> freqMap;
                    stringstream ss(allIds); // Create a stringstream to parse the string
                    string id;
                    while (ss >> id) { // Extract each ID from the string
                        // Extract the numeric part of the ID
                        int idNumber = stoi(id.substr(2));
                        freqMap[idNumber]++; // Increment the frequency in the map
                    }
                    for(auto [id,cnt] : freqMap){
                        // Check online
                        cntMentions[id] += cnt;
                        
                    }
                }
                
            }
            if(eType == "OFFLINE"){
                stringstream ss(allIds);
                int num;
                while (ss >> num) {
                    offlineStartTime[num] = timeStamp;
                }
            }
        }
        return cntMentions;
    }
};