class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        vector<int> dArr;
        for(int i=0; i<n; i++){
            dArr.push_back(arr[i]);
        }
        sort(dArr.begin(), dArr.end());
        
        int rank = 1;

        for(int i=0; i<n; i++){
            if(mp.find(dArr[i]) == mp.end()){
                mp[dArr[i]] = rank;
                rank++;
            }
        }
        for(int i=0; i<n; i++){
            dArr[i] = mp[arr[i]];
        }
        return dArr;
    }
};