class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 0)
            return 0;

        int nMax = 0;

        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] < prices[i+1])
            {
                nMax = nMax + prices[i+1] - prices[i];
            }
        }
        return nMax;

    }
};
