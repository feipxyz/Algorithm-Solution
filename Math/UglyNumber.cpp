class Solution {
public:
    bool isUgly(int num) {
        vector<int> divisor{2, 3, 5};

        for (auto a : divisor)
        {
            if (num == 0)
                break;
            while (num % a == 0)
            {
                num /= a;
            }
        }
        return num == 1;
    }
};
