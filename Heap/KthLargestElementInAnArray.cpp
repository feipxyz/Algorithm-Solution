class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (i >= k)
                pq.pop();
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            pq.pop();
        return pq.top();
    }
};
