class Solution {
public:

    int nextNum(int x){
        int s = 0;
        while(x>0){
            int d = x % 10;
            s += d*d;
            x /= 10;
        }
        return s;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1 && !seen.count(n)){
            seen.insert(n);
            n=nextNum(n);
        }
        return n==1;
    }
};