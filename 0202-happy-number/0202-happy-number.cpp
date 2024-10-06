class Solution {
private:
    // ssd = SUM OF SQUARE DIGITS
    int ssd(int n){
        int sum = 0;
        while(n > 0){
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        // we need to check if its repeating in a loop or summing to 1
        unordered_set<int> m;
        while(n != 1){
            if(m.find(n) != m.end()){
                // triggers when we've seen a number more than once, aka in a circle
                return false;
            }
            m.insert(n);
            n = ssd(n);
        }
        // only ever reached if n == 1;
        return true;
    }
};