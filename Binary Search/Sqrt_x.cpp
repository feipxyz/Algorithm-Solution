class Solution {
public:
    int mySqrt(int x) {
        long int l = 1;
        long int r = x;
        while (l < r)
        {
            long int m = (l + r) / 2;
            if (m * m  == x)
            {
                return m;
            }
            else if (m * m > x)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        if (l * l > x)
            return l - 1;
        else
            return l;
    }
};
