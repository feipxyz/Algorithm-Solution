class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> mpRes;
        vector<int> res;
        stack<int> stk;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!stk.empty() && stk.top() < nums[i])
            {
                mpRes[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(nums[i]);
        }

        for (auto num : findNums)
        {
            if (mpRes.find(num) != mpRes.end())
                res.push_back(mpRes[num]);
            else
                res.push_back(-1);
        }

        return res;
    }
};
