/* Q-7. Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'. */

#include <cstring>
#include <iostream>
using namespace std;

int countDecode(char *digits, int n)
{
    // base cases
    if (n == 0 || n == 1)
        return 1;
    if (digits[0] == '0')
        return 0;
    // for base condition "01123" should return 0
    int count = 0;
    if (digits[n - 1] > '0')
        count = countDecode(digits, n - 1);
    if (digits[n - 2] == '1' || (digits[n - 2] == '2' && digits[n - 1] < '7'))
        count += countDecode(digits, n - 2);

    return count;
}
int countWays(char *digits, int n)
{
    if (n == 0 || (n == 1 && digits[0] == '0'))
        return 0;
    return countDecode(digits, n);
}
int main()
{
    char d[] = "111";
    int n = strlen(d);
    cout << "Count is " << countWays(d, n);
    return 0;
}
