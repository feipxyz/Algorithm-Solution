class Solution {
public:
    string countAndSay(int n) {
        string res("1");
        if (n == 1)
            return res;

        while (--n)
        {
            string cur;
            for (int i = 0; i < res.size(); i++)
            {
                int count = 1;
                while ((i + 1 < res.size()) && (res[i] == res[i + 1]))
                {
                    count++;
                    i++;
                }
                cur.append(to_string(count));
                cur.append(1, res[i]);
            }
            res = cur;
        }
        return res;
    }
};
