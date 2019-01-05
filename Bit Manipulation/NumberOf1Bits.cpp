class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n)
        {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        long long num = n;
        while (num)
        {
            long long p = 1;
            while (p <= num)
            {
                p = p << 1;
            }
            res++;
            p = p >> 1;
            num -= p;
        }
        return res;
    }
};
