class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        FindCombinationSum(candidates, target, 0, cur, res);
        return res;
    }

    void FindCombinationSum(vector<int> candidates, int target, int start, vector<int> cur, vector<vector<int>>& res)
    {
        if (target == 0)
        {
            res.push_back(cur);
        }
        else if (target < 0 || start >= candidates.size())
        {
            return;
        }

        int i = start;
        while (i < candidates.size())
        {
            if (target - candidates[i] < 0)
                break;
            cur.push_back(candidates[i]);
            FindCombinationSum(candidates, target - candidates[i], i + 1, cur, res);
            cur.pop_back();
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) i++;
            //if (i > 0 && cnadidates[i] == candidates[i - 1]) i++;
            i++;
        }
    }
};
