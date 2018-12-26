class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int nCanReach = 0;

        while (i <= nCanReach && i < nums.size())
        {
            nCanReach = max(nCanReach, nums[i] + i);
            i++;
        }

        return i == nums.size();
    }
};
