class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k)
            return "0";

        int i = 0;
        stack<char> stk;

        while (i < num.size())
        {
            while (k && !stk.empty() && stk.top() > num[i])
            {
                stk.pop();
                k--;
            }
            stk.push(num[i++]);
        }

        while (k--)
        {
            stk.pop();
        }

        string res(stk.size(), '0');
        i = stk.size();
        while (i)
        {
            res[i-1] = stk.top();
            stk.pop();
            i--;
        }

        i = 0;
        while (i < res.size() && res[i] == '0')
        {
            res.erase(i, 1);
        }

        return res.size() == 0 ? "0" : res;
    }
};
