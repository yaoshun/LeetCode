typedef long long ll;
class Solution {
private:
    int helper(long long n) {
        ll digit = 1;
        ll cur = 1;
        while (n > cur * 9 * digit) {
            n -= cur * 9 * digit;
            cur *= 10;
            digit++;
        }
        
        ll number = cur + (n - 1) / digit;
        for (int i = 0; i < digit - (n - 1) % digit - 1; i++) {
            number /= 10;
        }
        return number % 10;
    }
public:
    int findNthDigit(int n) {
        return helper((ll)n);
    }
};
