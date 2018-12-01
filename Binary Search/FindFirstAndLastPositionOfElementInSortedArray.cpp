class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            int m = (l + r) / 2;
            if (target == nums[m])
            {
                int i = m;
                int j = m;
                while (i - 1 >= 0 && nums[i - 1] == nums[m]) i--;
                while (j + 1 < nums.size() && nums[j + 1] == nums[m]) j++;
                res[0] = i;
                res[1] = j;
                break;
            }
            else if (target > nums[m])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        if (l == r && nums[l] == target)
        {
            res[0] = l;
            res[1] = l;
        }


        return res;
    }
};

class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> res{-1, -1};
        if (nums.empty()) return res;

        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        if (nums[l] != target)
            return res;

        res[0] = l;
        r = nums.size() - 1;
        cout << l << " " << r << endl;
        while (l < r)
        {
            int m = (l + r) / 2 + 1;
            if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m;
            }
        }

        res[1] = r;
        return res;

    }
};
