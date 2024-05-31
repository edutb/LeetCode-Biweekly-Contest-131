class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
         
          vector<int> index;
          vector<int> ans;

          for(int i = 0; i < nums.size(); i++){
            if(nums[i] == x) index.push_back(i);  
          }

          for(auto&q: queries){
             if(q <= index.size()) ans.push_back(index[q-1]);
             else ans.push_back(-1);
          }

          return ans;
    }
};