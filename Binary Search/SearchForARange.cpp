class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int i = 0;
        int j = A.size() - 1;
        vector<int> res{-1, -1};
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (A[mid] == target)
            {
                int k = 0;
                while (mid - k >= 0 && A[mid - k] == target)
                    k++;
                res[0] = mid - k + 1;
                k = 0;
                while (mid + k <= A.size() - 1 && A[mid + k] == target)
                    k++;
                res[1] = mid + k - 1;
                break;
            }
            else if (A[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid -1;
            }
        }
        return res;
    }
};
