class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here
        int sum;
        int carry;

        do
        {
            sum = a ^ b;
            carry = (a & b) << 1;
            a = sum;
            b = carry;
        } while(b != 0);

        return a;
    }
};
