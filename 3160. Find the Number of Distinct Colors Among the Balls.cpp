class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
         unordered_map<int, int> color;
         unordered_map<int, int> balls;
         int m = queries.size();
         vector<int> ans;

         for(auto&q: queries){
            int b = q[0];
            int new_color = q[1];

            if(balls.find(b) != balls.end()){
              color[balls[b]]--;
              if(color[balls[b]] == 0) color.erase(balls[b]);
            }
            balls[b] = new_color;
            color[new_color]++;
            ans.push_back(color.size());
         }

         return ans;
    }
};