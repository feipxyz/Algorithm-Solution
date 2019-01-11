class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[right])
            {
                // 这里可以是 left++，但考虑到二分的话还是写成下面的形式
                left = max(left, mid) + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};
