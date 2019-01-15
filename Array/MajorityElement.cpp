class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        // write your code here
        int result = 0;
        int times = 0;

        for (auto n : nums)
        {
            if (times == 0)
            {
                result = n;
                times++;
            }
            else if (n == result)
            {
                times++;
            }
            else
            {
                times--;
            }
        }
        return result;
    }

};
