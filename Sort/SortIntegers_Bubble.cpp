class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers(vector<int> &A) {
        // write your code here
        for (int i = 0; i < A.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < A.size() - i - 1; j++)
            {
                if (A[j] > A[j + 1])
                {
                    swap(A[j], A[j + 1]);
                    flag = false;
                }
            }
            if (flag) break;
        }
    }
};
