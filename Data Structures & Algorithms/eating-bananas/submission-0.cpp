class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // piles --> 2 4 5 7 9 3 5 6 
        // h --> num hours to eat all bananas.              
        auto it = max_element(piles.begin(), piles.end());
        int right = *it;
        int left = 1;
        int result = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            int temp = h;
            for(int i = 0; i < piles.size(); i++) {
                temp -= ((piles[i] + middle - 1) / middle);
                if (temp < 0) break;
            }
            if (temp < 0) {
                //took too long
                left  = middle + 1;
            } else {
                //solved comfortably
                result = middle;
                right = middle - 1;
            }
        }
        return result;
    }
};
