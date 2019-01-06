class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int nCurMin = nums[0];
        int nCurMax = nums[0];
        int nMaxProduct = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int nTmpMin = nCurMin;
            int nTmpMax = nCurMax;
            nCurMin = min(min(nTmpMin * nums[i], nTmpMax * nums[i]), nums[i]);
            nCurMax = max(max(nTmpMin * nums[i], nTmpMax * nums[i]), nums[i]);
            nMaxProduct = max(nMaxProduct, nCurMax);
        }

        return nMaxProduct;
    }
};
