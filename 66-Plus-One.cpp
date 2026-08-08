class Solution {
public:
    // void help(vector<int>& digits,vector<int>& ans,int n ){
    //      if(digit[n]!=9){
    //             digits[n] += 1;

    //          }
    //          else{
    //             digits[n]=0;

    //          }
    // }
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        if (digits[n] != 9) {
            digits[n] += 1;
            // cout<<digits[n];
            return digits;
        }
        int sum = 0;
        for (int i = 0; i < digits.size(); i++) {
            sum += digits[i];
        }
        if (sum == digits.size() * 9) {
            vector<int> ans;
            ans.push_back(1);
            for (int i = 0; i < digits.size(); i++) {
                ans.push_back(0);
            }
            return ans;
        } else {
            cout<<"s";

            while (digits[n] == 9) {
                digits[n] = 0;
                n--;
            }
            digits[n] += 1;
        }
        return digits;
    }
};