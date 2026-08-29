class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> answer(n);

        for (int i = 0; i < n; i++) {
            
            int left = 0;
            int right = 0;

            for (int j = 0; j < i; j++) {
                left += nums[j];
            }

            for (int j = i + 1; j < n; j++) {
                right += nums[j];
            }

            answer[i] = abs(left - right);
        }

        return answer;
    }
};