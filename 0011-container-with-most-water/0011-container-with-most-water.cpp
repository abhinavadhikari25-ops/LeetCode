class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0 ,rp =height.size()-1;
        while(lp < rp){
        int w = rp-lp;
        int ht = min(height[lp],height[rp]);
        int cur_wt = w * ht;
        maxWater = max(maxWater,cur_wt);
        height[lp] < height[rp] ? lp++ : rp--;
      }

      return maxWater;
    }
};