class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> actual_index(n);
        iota(begin(actual_index), end(actual_index), 0);

        auto lambda = [&](int &i, int &j) {
            return positions[i] < positions[j];
        };

        sort(actual_index.begin(), actual_index.end(), lambda);

        vector<int> result;

        stack<int> st;
        for (int &currIndx : actual_index) {
            if (directions[currIndx] == 'R') {
                st.push(currIndx);
            } else {
                while (!st.empty() && healths[currIndx] > 0) {
                    int top_idx = st.top();
                    st.pop();

                    if (healths[top_idx] > healths[currIndx]) {
                        healths[top_idx] -= 1;
                        healths[currIndx] = 0;
                        st.push(top_idx);
                    } else if (healths[top_idx] < healths[currIndx]) {
                        healths[currIndx] -= 1;
                        healths[top_idx] = 0;
                    } else {
                        healths[currIndx] = 0;
                        healths[top_idx] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};
