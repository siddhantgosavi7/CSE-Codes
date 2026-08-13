#include<iostream>
#include<string>
#include <algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool checkZeroFree(int n) {
        int rem = 0;
        while(n > 0) {
            rem = n%10;
            n /= 10;
            if(rem == 0) return false;
        }

        return true;
    }

    int productOfDigit(int temp) {
        int p = 1;
        int rem = 0;
        while(temp > 0) {
            rem = temp%10;
            temp /= 10;

            p *= rem;
        }

        return p;
    }

    string smallestNumber(string num, long long t) {
        int N = stoi(num), n = num.size();
        int temp = N, rem = 0;
        long long T = t;
        unordered_map<int, int> m;
        string ans = "";

        while(T > 0) {
            if(T%2 == 0) {
                m[2]++;
                T /= 2;
            } else if(T%3 == 0) {
                m[3]++;
                T /= 3;
            } else if(T%5 == 0) {
                m[5]++;
                T /= 5;
            } else if(T%7 == 0) {
                m[7]++;
                T /= 7;
            } else {
                return "-1";
            }    
        }

        for(int i=0; i<n; i++) {
            rem = temp%10;
            temp /= 10;

            if(rem == 0) {
                return "-1";
            }

            if(rem == 1) {
                continue;
            } else if(rem == 2) {
                m[2]--;
            } else if(rem == 3) {
                m[3]--;
            } else if(rem == 4) {
                m[2] -= 2;
            } else if(rem == 5) {
                m[5]--;
            } else if(rem == 6) {
                m[2]--;
                m[3]--;
            } else if(rem == 7) {
                m[7]--;
            } else if(rem == 8) {
                m[2] -= 3;
            } else if(rem == 9) {
                m[3] -= 3;
            }
        }

        
        return ans;
    }
};

int main() {
    Solution s;

    string num;
    long long t;

    cout << "Enter num: ";
    //cin >> num;
    num = "123";

    cout << "Enter t: ";
    //cin >> t;
    t = 12;

    cout << "ans: " << s.smallestNumber(num, t) << endl; 
    return 0;
}