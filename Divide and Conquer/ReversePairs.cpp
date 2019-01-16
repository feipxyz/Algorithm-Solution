class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        // write your code here
        vector<int> copy(A);
        if (A.empty())
            return 0;
        return ReversePairsCore(A, copy, 0, A.size() - 1);
    }

    int ReversePairsCore(vector<int>& A, vector<int>& copy, int start, int end)
    {
        if (start == end)
        {
            copy[start] = A[start];
            return 0;
        }

        int mid = (start + end) / 2;
        int leftCount = ReversePairsCore(copy, A, start, mid);
        int rightCount = ReversePairsCore(copy, A, mid + 1, end);
        int i = mid;
        int j = end;
        int count = leftCount + rightCount;
        int indexCopy = end;
        while (i >= start && j >= mid + 1)
        {
            if (A[i] > A[j])
            {
                count += (j - mid);
                copy[indexCopy--] = A[i--];
            }
            else
            {
                copy[indexCopy--] = A[j--];
            }
        }

        while (i >= start)
            copy[indexCopy--] = A[i--];
        while (j >= mid + 1)
            copy[indexCopy--] = A[j--];

        return count;
    }
};
