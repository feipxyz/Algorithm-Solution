class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vt(256, -1);
        int nLeft = -1;
        int nMax = 0;
        for (int i = 0; i < s.size(); i++)
        {
            nLeft = max(nLeft, vt[s[i]]);
            nMax = max(nMax, i - nLeft);
            vt[s[i]] = i;
        }

        return nMax;
    }
};
