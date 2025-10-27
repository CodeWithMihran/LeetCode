class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int word_len = words[0].size();
        int total_len = word_len * words.size();
        unordered_map<string, int> word_count;
        for (auto &w : words) word_count[w]++;

        for (int i = 0; i < word_len; ++i) {
            unordered_map<string, int> seen;
            int left = i;

            for (int j = i; j + word_len <= s.size(); j += word_len) {
                string word = s.substr(j, word_len);
                if (word_count.count(word)) {
                    seen[word]++;
                    while (seen[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        left += word_len;
                    }

                    if (j + word_len - left == total_len)
                        res.push_back(left);
                } else {
                    seen.clear();
                    left = j + word_len;
                }
            }
        }

        return res;
    }
};