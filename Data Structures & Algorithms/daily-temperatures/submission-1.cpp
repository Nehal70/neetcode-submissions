class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> backingStack;
        vector<int> result(temperatures.size());
        result[temperatures.size() - 1] = 0;
    

        for (int i = 0; i < temperatures.size(); i++) {
            if (i == 0) {
                //just add the first one
                backingStack.push(i);
            } else {
                //not the first one, regular logic. 
                while (!backingStack.empty() && temperatures[i] > temperatures[backingStack.top()]) {
                    int prevIndex = backingStack.top();
                    backingStack.pop();
                    result[prevIndex] = i - prevIndex;
                }
                //result[backingStack.top()] = count;
                backingStack.push(i);
            }

        }
        return result;
    }
};
