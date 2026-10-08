#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string lexicographically_larger(int num) {
        int i = log2(num)+1;
        string str = "";

        while(i > 26) {
            str += static_cast<char>('z');
            num -= pow(2, 26);
            i--;
        }
        
        while(num > 0 && i >= 0) {
            
            if(i >= 0 && pow(2, i) <= num) {
                num -= pow(2, i);
                str += static_cast<char>(97 + i);
            }
            cout << str << " " << i << endl;
            i--;
        }

        return str;
    }

    
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        
        for(int i=0; i<n; i++) {
            ans.push_back(lexicographically_larger(nums[i]));
            //cout << "#" << ans[i] << endl;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {33554433,33554433,33554433};
    vector<string> result = sol.largestString(nums);
    
    for(const string& str : result) {
        cout << str << endl;
    }
    
    return 0;
}