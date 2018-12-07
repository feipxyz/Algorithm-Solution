class Solution {
public:
    int jump(vector<int>& nums) {
        int nJumpNum = 0;
        int nCanReach = 0;
        int start = 0;
        while (nCanReach < nums.size() - 1)
        {
            nJumpNum++;
            // 上一次能到达的位置
            int nLastReach = nCanReach;
            for (int j = start; j <= nLastReach; j++)
            {
                nCanReach = max(nCanReach, j + nums[j]);
            }
            //将i变为上一次能到达的位置的下一个
            start = nLastReach + 1;
        }
        return nJumpNum;
    }
};
