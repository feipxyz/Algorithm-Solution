class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stkIndex;
        int maxArea = 0;
        vector<int> histogram = heights;
        histogram.push_back(0);

        int i = 0;
        while (i < histogram.size())
        {
            if (stkIndex.empty() || histogram[stkIndex.top()] <= histogram[i])
            {
                stkIndex.push(i++);
            }
            else
            {
                int idx = stkIndex.top();
                stkIndex.pop();
                maxArea = max(maxArea, histogram[idx] * (stkIndex.empty() ? i : (i - stkIndex.top() - 1)));
            }
        }
        return maxArea;
    }
};
