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
            int minidx = i;
            for (int j = i + 1; j < A.size(); j++)
            {
                if (A[j] < A[minidx])
                {
                    minidx = j;
                }
            }
            swap(A[i], A[minidx]);
        }
    }
};
