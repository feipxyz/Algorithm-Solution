class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpSrc;
        unordered_map<char, int> mpCur;
        int nFindLen = 0;
        queue<int> qIndex;
        for (auto ch : t)
        {
            mpSrc[ch]++;
        }

        int nWinLeft = -1;
        int nWinRight = s.size();

        for (int i = 0; i < s.size(); i++)
        {
            if (mpSrc.count(s[i]) == 0)
                continue;

            mpCur[s[i]]++;
            qIndex.push(i);

            if (mpCur[s[i]] <= mpSrc[s[i]]) nFindLen++;

            if (nFindLen == t.size())
            {
                int k = 0;
                do
                {
                    k = qIndex.front();
                    qIndex.pop();
                    mpCur[s[k]]--;
                } while (mpCur[s[k]] >= mpSrc[s[k]]);

                if (i - k < nWinRight - nWinLeft)
                {
                    nWinRight = i;
                    nWinLeft = k;
                }
                nFindLen--;
            }
        }

        return nWinLeft == -1 ? "" : s.substr(nWinLeft, nWinRight - nWinLeft + 1);
    }
};
