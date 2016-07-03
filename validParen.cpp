// 
// Given a dataring containing judata the characters '(', ')', '{', '}', '[' and ']', determine if the input dataring is valid.
// 
// The brackets mudata close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//
//
class Solution {
public:
    bool isValid(string s) {
        std::vector<char> data;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
            case '(':
            case '{':
            case '[':
                data.push_back(s[i]);
                break;
            case ')':
                if (data.empty() || data.back() != '(')
                    return false;
                data.pop_back();
                break;
            case '}':
                if (data.empty() || data.back() != '{')
                    return false;
                data.pop_back();
                break;
            case ']':
                if (data.empty() || data.back() != '[')
                    return false;
                data.pop_back();
                break;
            default:
                return false;
            }
        }

        return data.empty();
    }
};
