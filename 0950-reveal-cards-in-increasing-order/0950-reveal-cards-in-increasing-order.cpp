class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        bool skip = false;
        int idxInDeck = 0, idxInAns = 0;
        int N = deck.size();
        vector<int> ans(N);

        sort(deck.begin(),deck.end());

        while(idxInDeck < N){
            if(ans[idxInAns] == 0){
                if(skip == false){
                    ans[idxInAns] = deck[idxInDeck];
                    idxInDeck++;
                }
                skip = !skip;
            }
            idxInAns = (idxInAns + 1) % N;
        }
        return ans;
    }
};