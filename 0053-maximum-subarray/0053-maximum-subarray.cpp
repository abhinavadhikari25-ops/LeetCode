class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MaxSum = INT_MIN;
        int CurSum = 0;
        for(int val : nums){
            CurSum += val;
            MaxSum = max(CurSum,MaxSum);
            if(CurSum < 0){
                CurSum = 0;
            }
        }
        return MaxSum;
    }
};