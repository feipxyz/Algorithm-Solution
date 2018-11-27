# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        BackTrack(n, n, "", result);
        return result;
    }

    void BackTrack(int left, int right, string s, vector<string>& result)
    {
        if (left == 0 && right == 0)
            result.push_back(s);

        if (left > 0)
        {
            BackTrack(left - 1, right, s + '(', result);
        }

        if (right > 0 && left < right)
        {
            BackTrack(left, right - 1, s + ')', result);
        }
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
