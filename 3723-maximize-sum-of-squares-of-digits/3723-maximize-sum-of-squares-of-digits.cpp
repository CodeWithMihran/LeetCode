#include <string>

class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        std::string result = "";
        result += std::string(sum / 9, '9');
        if (sum % 9 > 0) {
            result += std::to_string(sum % 9);
        }
        result += std::string(num - (sum + 8) / 9, '0');
        return result;
    }
};
