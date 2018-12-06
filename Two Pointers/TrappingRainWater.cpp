class Solution {
public:
    int trap(vector<int>& height) {
        int rmax = 0;
        int lmax = 0;
        int r = height.size() - 1;
        int l = 0;
        int result = 0;

        while (l < r)
        {
            rmax = max(rmax, height[r]);
            lmax = max(lmax, height[l]);
            if (lmax < rmax)
                result += (lmax - height[l++]);
            else
                result += (rmax - height[r--]);
        }
        return result;
    }
};
