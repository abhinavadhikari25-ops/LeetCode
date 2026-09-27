class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, vector<int>& current, vector<bool>& used) {
        
        // Base case
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }
        
        // Try every number
        for (int i = 0; i < nums.size(); i++) {
            
            // Already used
            if (used[i])
                continue;
            
            // Choose
            current.push_back(nums[i]);
            used[i] = true;
            
            // Explore
            solve(nums, current, used);
            
            // Undo (Backtrack)
            current.pop_back();
            used[i] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        solve(nums, current, used);
        
        return ans;
    }
};