class Solution {
public:
    int reverse(int x) {
        if (x < 0 && x != -2147483648)
            return -1 * reverse_recursive((-1) * x, 0);
        else if (x < 0)
            return 0;
        else
            return reverse_recursive(x, 0);
    }
private:
    int reverse_recursive(int num, int carry){
        if (carry < 214748364 || (carry == 214748364 && num%10 < 7)) {
            if (num < 10)
                return carry*10 + num;
            else
                return reverse_recursive(num/10, carry*10 + num%10);
        }
        else
            return 0;
    }
};
