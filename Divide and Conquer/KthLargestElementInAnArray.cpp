class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> array = nums;
        int low = 0;
        int high = array.size() - 1;
        while (1)
        {
            int pos = QuickSort(array, low, high);
            if (pos == k - 1)
            {
                return array[pos];
            }
            else if (pos < k - 1)
            {
                low = pos + 1;
            }
            else
            {
                high = pos - 1;
            }

        }
        return -1;
    }

    int QuickSort(vector<int>& nums, int low, int high)
    {
        int i = low;
        int j = high;
        int pivot = nums[low];

        while (i < j)
        {
            while (i < j && nums[j] < pivot)
                j--;
            if (i < j)
                nums[i++] = nums[j];
            while (i < j && nums[i] > pivot)
                i++;
            if (i < j)
                nums[j--] = nums[i];
        }
        nums[i] = pivot;
        return i;
    }
};
