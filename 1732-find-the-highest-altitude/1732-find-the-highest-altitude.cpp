class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans(gain.size() + 1);
        
        int l = gain[0];
        int r = gain.size();
        
        ans[0] = 0;
        
        for(int i = 0; i < gain.size(); i++) {
            ans[i + 1] = ans[i] + gain[i];
        }
        
        int x = *max_element(ans.begin(), ans.end());
        
        return x;
    }
};