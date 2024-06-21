class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int maxUnsatisfiedCust = 0;  //in any window (consecutive) of size mintues
        int currUnsatisfied = 0;

        for(int i = 0; i<minutes; i++){   //0,1,2,minutes-1
            currUnsatisfied += customers[i] * grumpy[i];
        }

        maxUnsatisfiedCust = currUnsatisfied;

        int i = 0;
        int j = minutes;
        while(j<n){
            currUnsatisfied += customers[j]* grumpy[j];  //new element in the window
            currUnsatisfied -= customers[i] * grumpy[i]; //removing elemet from the window
        
        maxUnsatisfiedCust = max(maxUnsatisfiedCust,currUnsatisfied);

        i++;
        j++;
        
        }

        int totalSatisfied = maxUnsatisfiedCust;  //using powewr
       for(int i = 0 ; i<n; i++){
        totalSatisfied += customers[i] * (1-grumpy[i]);
       }

     return totalSatisfied;

    }
};