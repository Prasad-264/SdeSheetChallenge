/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

//* Brute force
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        for (int i = 0; i < n; i++) {
            ans = ans * x;
        }
        return ans;
    }
};

//* TC = O(N)
//* SC = O(1)

//* Binary Expo (Efficient solution)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long n2 = n;
        if(n2 < 0) n2 = -1 * n2;
        while(n2) {
            if(n2 % 2 == 0) {
                x = x * x;
                n2 /= 2;
            }
            else {
                ans = ans * x;
                n2 = n2 - 1;
            }
        }
        if(n < 0) ans = (double) (1.0) / (double) (ans);
        return ans;
    }
};

//* TC = O(log N)
//* SC = O(1)