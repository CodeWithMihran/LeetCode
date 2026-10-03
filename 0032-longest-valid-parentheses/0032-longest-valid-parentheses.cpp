class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::vector<int> stack = {-1};
        int answer = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                stack.pop_back();
                if (stack.empty()) {
                    stack.push_back(i);
                }
            }
            answer = std::max(answer, i - stack.back());
        }
        
        return answer;
    }
};