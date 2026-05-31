class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;

        // Using 32 bits to match the standard size of a signed int
        for (int i = 0; i < 32; i++) {
            // Extract the i-th bit of a and b
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;

            // Full Adder Logic:
            // Sum bit = A XOR B XOR Carry
            int currentSumBit = bitA ^ bitB ^ carry;
            
            // Carry out = (A AND B) OR (Carry AND (A XOR B))
            carry = (bitA & bitB) | (carry & (bitA ^ bitB));

            // Place the sum bit into the result at position i
            sum |= (currentSumBit << i);
        }
        return sum;
    }
};