class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int cur = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
                result[i + j + 1] = (cur % 10) + '0';
                carry = cur / 10;
            }
            result[i] += carry;
        }

        size_t startpos = result.find_first_not_of("0");
        if (string::npos != startpos) {
            return result.substr(startpos);
        }
        return "0";
    }
};
