// 1-pass
class Solution {
public:
    int longestMountain(vector<int>& A) {
        vector<int> up(A.size(), 0);
        vector<int> down(A.size(), 0);
        int nMax = 0;
        for (int i = A.size() - 2; i >= 0; i--)
        {
            if (A[i] > A[i + 1])
                down[i] = down[i + 1] + 1;
        }

        for (int i = 0; i < A.size(); i++)
        {
            if (i >= 1 && A[i] > A[i - 1])
                up[i] = up[i - 1] + 1;

            if (up[i] && down[i])
                nMax = max(nMax, up[i] + down[i] + 1);
        }

        return nMax;
    }
};
