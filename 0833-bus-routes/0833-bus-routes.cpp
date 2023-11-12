class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        // Graph --->(STOP, Routes its part of)
        unordered_map<int,vector<int>> adjList;
        for(int i=0; i<routes.size(); i++){
            for(auto stops : routes[i]){
                adjList[stops].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> vis;
        int busCount = 1;
        for(auto routes : adjList[source]){
            q.push(routes);
            vis.insert(routes);
        }

        while(q.size()){
            int size = q.size();

            for(int i=0; i<size; i++){
                int route = q.front();
                q.pop();

                for(auto stop : routes[route]){
                    if(stop == target){
                        return busCount;
                    }

                    for(auto nextRoute : adjList[stop]){
                        if(!vis.count(nextRoute)){
                            vis.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};