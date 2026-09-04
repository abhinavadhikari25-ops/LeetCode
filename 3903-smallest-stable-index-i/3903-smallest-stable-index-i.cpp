class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> premax(n);
        vector<int> sufmin(n);

        // Prefix maximum
        premax[0] = nums[0];

        for(int i = 1; i < n; i++) {
            premax[i] = max(premax[i - 1], nums[i]);
        }

        // Suffix minimum
        sufmin[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            sufmin[i] = min(sufmin[i + 1], nums[i]);
        }

        // Find first stable index
        for(int i = 0; i < n; i++) {
            int score = premax[i] - sufmin[i];

            if(score <= k) {
                return i;
            }
        }

        return -1;
    }
};