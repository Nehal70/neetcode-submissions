class MinStack {
public:

    vector<pair<int, int>> minStack; //stores the actual values 
    int minimum;

    MinStack() { 
        //first is the value, second is the min seen so far
        minimum = INT_MAX;
    }
    
    void push(int val) {
        if (minStack.empty()) {
            minStack.push_back({val, val});
        } else {
            // Get the previous minimum from the current top
            int currentMin = minStack.back().second;
            minStack.push_back({val, std::min(val, currentMin)});
        }
    }
    
    void pop() {
        minStack.pop_back();
    }
    
    int top() {
        return minStack.back().first;
    }
    
    int getMin() {
        return minStack.back().second;
    }
};
