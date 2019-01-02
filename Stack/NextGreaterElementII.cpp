class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        vector<int> res(nums.size(), -1);

        for (int i = 0; i < nums.size() * 2; i++)
        {
            int k = i % nums.size();
            while (!stk.empty() && nums[stk.top()] < nums[k])
            {
                res[stk.top()] = nums[k];
                stk.pop();
            }

            if (k < nums.size())
                stk.push(k);
        }

        return res;
    }
};
