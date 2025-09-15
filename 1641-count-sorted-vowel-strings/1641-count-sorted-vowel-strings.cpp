class Solution {
public:
    int countVowelStrings(int n) {
        long long ans = 1;
        int r = 4;
        int num = n+4;

        for(int i=1; i<=r; i++){
            ans *= num;
            ans /= i;
            num--;
        }
        return ans;
    }
};