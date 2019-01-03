class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int pos = 0;
        for (auto a : nums)
        {
            if (a != 0)
                nums[pos++] = a;
        }

        while (pos < nums.size())
        {
            nums[pos++] = 0;
        }
    }
};
