class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        FindCombination(candidates, 0, target, cur, res);
        return res;
    }

    void FindCombination(vector<int> candidates, int start, int target, vector<int> cur, vector<vector<int>> &res)
    {
        if (target == 0)
        {
            res.push_back(cur);
        }
        else if (target < 0 || start >= candidates.size())
        {
            return;
        }


        for (int i = start; i < candidates.size(); i++)
        {
            if (target - candidates[i] < 0)
                break;
            cur.push_back(candidates[i]);
            FindCombination(candidates, i, target - candidates[i], cur, res);
            cur.pop_back();
        }
    }
};
