class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int slow = 1;
        int fast = 2;
        while (fast < nums.size())
        {
            if (nums[fast] != nums[slow] || nums[fast] != nums[slow - 1])
            {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};
