class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<int> hists;
        hists.resize(matrix[0].size());
        int max_area = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                hists[j] = matrix[i][j] == '0' ? 0 : (1 + hists[j]);
            }

            max_area = max(max_area, largestRectangleArea(hists));
        }
        return max_area;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int max_area = 0;
        int i = 0;
        vector<int> h = heights;
        h.push_back(0);
        while (i < h.size())
        {
            if (stk.empty() || h[stk.top()] <= h[i])
            {
                stk.push(i++);
            }
            else
            {
                int j = stk.top();
                stk.pop();
                max_area = max(max_area, h[j] * (stk.empty() ? i : i - stk.top() - 1));
            }

        }
        return max_area;
    }
};
