class Solution {
public:
    double myPow(double x, int n) {
        if (n > 0)
        {
            return Pow(x, n);
        }
        else
        {
            return 1 / Pow(x, -n);
        }
    }

    double Pow(double x, int n)
    {
        if (n == 0)
            return 1;

        double half = Pow(x, n / 2);

        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};
