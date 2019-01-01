class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int pos = strN.size();
        for (int i = strN.size() - 1; i > 0; i--)
        {
            if (strN[i] < strN[i - 1])
            {
                pos = i;
                strN[i - 1]--;
            }
        }

        for (int i = pos; i < strN.size(); i++)
        {
            strN[i] = '9';
        }
        return stoi(strN);
    }
};
