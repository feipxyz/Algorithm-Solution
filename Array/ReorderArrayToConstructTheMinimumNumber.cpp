class Solution {
public:
    /**
     * @param nums: n non-negative integer array
     * @return: A string
     */
    string minNumber(vector<int> &nums) {
        // write your code here
        stringstream stream;
        vector<string> strNums;
        for (auto n : nums)
        {
            string tmp;
            stream << n;
            stream >> tmp;
            stream.clear();
            strNums.push_back(tmp);
        }

        sort(strNums.begin(), strNums.end(), cmp);

        // cout << "ff" << endl;
        string connect;
        for (auto s : strNums)
            connect += s;

        bool Flag = false;
        string res;
        for (int i = 0; i < connect.size(); i++)
        {
            if (connect[i] != '0')
            {
                res.append(1, connect[i]);
                Flag = true;
            }
            else if (Flag)
            {
                res.append(1, connect[i]);
            }
        }

        return res.empty() ? "0" : res;
    }

    static bool cmp(string s1, string s2)
    {
        return s1 + s2 < s2 + s1;
    }
};
