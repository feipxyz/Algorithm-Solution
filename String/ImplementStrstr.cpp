class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int j = 0;
        int k = 0;
        while (j < haystack.size() && k < needle.size())
        {
            if (haystack[j] == needle[k])
            {
                j++;
                k++;
            }
            else
            {
                j = j - k + 1;
                k = 0;
            }
        }

        if (k == needle.size())
            return j - k;
        else
            return -1;
    }
};
