class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
          vector<int> occur(51, 0);
          int ans = 0;
          for(auto&v: nums){
            occur[v]++;
            if(occur[v] == 2) ans^= v;
          }

          return ans;
    }
};