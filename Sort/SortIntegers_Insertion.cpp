class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers(vector<int> &A) {
        // write your code here
        for (int i = 1; i < A.size(); i++)
        {
            int tmp = A[i];
            int p = i;
            for (p = i; p > 0 && A[p - 1] > tmp; p--)
            {
                A[p] = A[p - 1];
            }
            A[p] = tmp;
        }
    }
};
