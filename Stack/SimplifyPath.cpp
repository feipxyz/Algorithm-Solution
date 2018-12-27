class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string str;
        string res;
        vector<string> vec;
        while (getline(ss, str, '/'))
        {
            if (str == "" || str == ".")
            {
                continue;
            }

            if (str == ".." && !vec.empty())
            {
                vec.pop_back();
            }
            else if (str != "..")
            {
                vec.push_back(str);
            }
        }

        for (auto s : vec)
        {
            res.append("/");
            res.append(s);
        }
        return res.empty() ? "/" : res;
    }
};
