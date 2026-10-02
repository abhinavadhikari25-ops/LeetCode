class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        vector<int> sq(nums.size());
        int pos = nums.size() - 1;

        while (left <= right) {
            
            if (abs(nums[left]) > abs(nums[right])) {
                sq[pos] = nums[left] * nums[left];
                left++;
            }
            else {
                sq[pos] = nums[right] * nums[right];
                right--;
            }
            
            pos--;
        }

        return sq;
    }
};