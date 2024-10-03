class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){   return false;   }
        if(groupSize == 1){    return true;     }

        unordered_map<int, int> mp;
        for(int i=0; i<hand.size(); i++){
            mp[hand[i]]++;
        }
        priority_queue<int> pq;
        for(auto it : mp){
            pq.push(it.first);
        }

        while(!pq.empty()){
            int x = pq.top();
            for(int i=x; i>x-groupSize; i--){
                if(mp.find(i) == mp.end()){
                    return false;
                }
                mp[i]--;
                if(mp[i] == 0){
                    mp.erase(i);
                    pq.pop();
                }
            }
        }
        return true;
    }
};