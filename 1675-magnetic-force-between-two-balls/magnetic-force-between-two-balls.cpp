class Solution {
public:

   bool possibleTOplace(vector<int>& position, int m, int midforce){

    int prevBalls = position[0];
    int CountBalls = 1;
    for(int i = 1; i<position.size(); i++){
        int curr = position[i];
        if(curr-prevBalls >= midforce){
          CountBalls++;
          prevBalls = curr;
        }

        if(CountBalls == m)
        break;
    
    }  
    return CountBalls == m; 

   }
    int maxDistance(vector<int>& position, int m) {

        int n = position.size();
        sort(begin(position),end(position));
           
        int min = 1;
        int max = position[n-1] - position[0];
        int result = 0;
        while(min<=max){
            int midforce = min + (max-min)/2;
           
           if(possibleTOplace(position,m,midforce)){

            result = midforce;

            min = midforce+1;
           }
           else {
            max = midforce-1;
           }
        }
        
        return result;
    }
};  