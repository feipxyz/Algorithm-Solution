class Solution {
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        for (int num = 0; num <= n; num++)
        {
            if (k == 0 && num == 0)
            {
                count++;
                continue;
            }

            int tmp = num;
            while (tmp)
            {
                if (tmp % 10 == k)
                    count++;
                tmp = tmp / 10;
            }
        }
        return count;
    }
};
