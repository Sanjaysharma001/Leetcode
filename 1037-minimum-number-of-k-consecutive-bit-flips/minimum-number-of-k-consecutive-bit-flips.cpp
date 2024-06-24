class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flip = 0;
        int flipcountfromPasti = 0;
        vector<bool> isflipped(n, false);

        for(int i = 0; i<n; i++){
            if(i>=k && isflipped[i-k] == true){
                flipcountfromPasti--;
            }
            if(flipcountfromPasti % 2 == nums[i]) {
                if(i + k > n)
                return -1;

                flipcountfromPasti++;
                flip++;
                isflipped[i] = true;

            }
        }

        return flip;
        
    }
};