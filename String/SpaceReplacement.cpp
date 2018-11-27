#include <string>
using namespace std;

class Solution {
public:
    /*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // write your code here
        int nSpaceNum = 0;
        for (int i = 0; i < length; i++)
        {
            if (string[i] == ' ')
            {
                nSpaceNum++;
            }
        }

        int left = length;
        int right = length + 2 * nSpaceNum;
        while (left != right)
        {
            if (string[left] == ' ')
            {
                string[right--] = '0';
                string[right--] = '2';
                string[right--] = '%';
                left--;
            }
            else
            {
                string[right--] = string[left--];
            }
        }

        return length + 2 * nSpaceNum;
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
