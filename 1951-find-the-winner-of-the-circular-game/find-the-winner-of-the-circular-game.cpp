class Solution {
public:


     int Winneridx(int n, int k){
        if(n==1){
            return 0;

        }

        int idx = Winneridx(n-1,k);

        idx = (idx + k) % n;
        return idx;
        
     }

    int findTheWinner(int n, int k) {
        int result_idx = Winneridx(n,k);

        return result_idx+1;
    }
};