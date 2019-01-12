class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            while (low < high && nums[low] % 2 == 1)
                low++;
            while (low < high && nums[high] % 2 == 0)
                high--;
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }
};
