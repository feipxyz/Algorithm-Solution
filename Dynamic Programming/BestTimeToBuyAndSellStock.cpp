class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int nMinEle = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            nMinEle = min(nMinEle, prices[i]);
            res = max(res, prices[i] - nMinEle);
        }
        return res;
    }
};
