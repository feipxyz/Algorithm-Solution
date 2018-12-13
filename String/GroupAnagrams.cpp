// solution 1
class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> word_map;
        vector<vector<string>> result;

        for (auto s : strs)
        {
            map<char, int> cur;
            for (auto c : s)
            {
                cur[c] += 1;
            }

            if (word_map.find(cur) != word_map.end())
            {
                word_map[cur].push_back(s);
            }
            else
            {
                word_map[cur] = {s};
            }
        }

        for (auto iter = word_map.begin(); iter != word_map.end(); iter++)
        {
            result.push_back(iter->second);
        }

        return result;
    }
};

// solution 2
class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> word_map;
        vector<vector<string>> result;
        for (auto s : strs)
        {
            auto t = s;
            sort(s.begin(), s.end());
            word_map[s].push_back(t);
        }

        for (auto iter = word_map.begin(); iter != word_map.end(); iter++)
        {
            result.push_back(iter->second);
        }

        return result;
    }
};
