class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string cur;
        vector<string> res;
        if (s.size() < 4)
            return res;
        BackTracking(s, 0, 1, cur, res);
        return res;
    }

    void BackTracking(string s, int idx, int place, string cur, vector<string>& res)
    {
        if (place > 4)
        {
            if (idx >= s.length())
            {
                cur.pop_back();
                res.push_back(cur);
            }
            return;
        }
        else if (idx >= s.length())
        {
            return;
        }

        for (int i = 1; i <= 3; i++)
        {
            if (idx + i - 1 >= s.size())
                break;

            string sub = s.substr(idx, i);
            if (sub.size() > 1 && sub[0] == '0')
                break;

            if (sub.length() < 3 || sub < "256")
            {
                cur.append(sub);
                cur.append(1, '.');
                BackTracking(s, idx + i, place + 1, cur, res);
                cur.erase(cur.end() - i - 1, cur.end());
            }
        }
    }
};
