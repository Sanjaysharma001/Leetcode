class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> first = edges[0];  //(a,b)
        vector<int> Second = edges[1];  //(c,a)

        if(first[0]==Second[0] || first[0]==Second[1]){
            return first[0];
        }
         return first[1];
    }
};