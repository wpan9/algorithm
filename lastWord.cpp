// Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
// return the length of last word in the string.
// 
// If the last word does not exist, return 0.
// 
// Note: A word is defined as a character sequence consists of non-space characters only.
// 
// For example, 
// Given s = "Hello World",
// return 5.
//
class Solution {
public:
    int lengthOfLastWord(string s) {
        int N = (int)s.length();
        if (N == 0)
            return 0;

        int i = N - 1;
        // skip trailing whitespaces.
        while (true) {
            if (i < 0)
                return 0;
            if (s[i] != ' ')
                break;
            --i;
        }

        int length = 0;
        while (i >= 0) {
            if (s[i] == ' ')
                return length;
            length++, i--;
        }
        return length;
    }
};

int lengthOfLastWord(string s) {
    int len = 0;
    for (int i = s.length() - 1; i >=0; i--){
        if (s[i] != ' ')
            len++;
        if (s[i] == ' ' && len != 0)
            return len;
    }
    return len;
}

