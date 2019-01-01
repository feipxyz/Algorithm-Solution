class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> res(T.size(), 0);
        int i = 0;
        while (i < T.size())
        {
            if (stk.empty() || T[stk.top()] >= T[i])
            {
                stk.push(i);
                i++;
            }
            else
            {
                int top = stk.top();
                stk.pop();
                res[top] = i - top;
            }
        }
        return res;
    }
};
