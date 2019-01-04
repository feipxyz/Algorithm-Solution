class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
           int low = 0;
           int high = A.size()-1;
           quicksort(A, low ,high);
    }

    void quicksort(vector<int>& A, int low, int high){
        if (low >= high)
            return;

        int i = low;
        int j = high;
        int pivot = A[low];
        while (i < j)
        {
            while (i < j && A[j] > pivot)
                j--;
            if (i < j)
                A[i++] = A[j];

            while (i < j && A[i] < pivot)
                i++;
            if (i < j)
                A[j--] = A[i];
        }

        A[i] = pivot;
        quicksort(A, low, i - 1);
        quicksort(A, i + 1, high);
    }
};
