class Solution {
public:

    #define LSOne(b) (b &(-b))
    vector<int> ft;

    int query(int b){
        int max_space = 0;
        for( ; b; b-=LSOne(b)) max_space = max(max_space, ft[b]);
        return max_space;
    }

    void update(int b, int space){
        for( ; b < ft.size(); b+=LSOne(b)) ft[b] = max(ft[b], space);
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
         ft.assign(50001, 0);
         set<int> blocks = {0};

         for(auto&q: queries){
            if(q[0] == 1)
                blocks.insert(q[1]);  
        }

        for(auto it = next(blocks.begin()); it!= blocks.end(); it++) 
            update(*it, *it - *prev(it));
        
         vector<bool> ans;
         for(int i = queries.size() - 1; i >=0; i--){
            if(queries[i][0] == 1){
                int x = queries[i][1];
                auto it = blocks.lower_bound(x);
                if(next(it) != blocks.end()) update(*next(it), *next(it) - *prev(it));
                blocks.erase(it);
            }
            else{
                int x = queries[i][1];
                int sz = queries[i][2];
                ans.emplace_back((query(x) >= sz) || (x - *prev(blocks.lower_bound(x)) >= sz));
            }
         }

         reverse(ans.begin(), ans.end());
         return ans;
    }
};