class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    bool has_carry = false;
    assert(!digits.empty());
    for (int i = digits.size() - 1; i >= 0; --i) {
      if (digits[i] == 9) {
        digits[i] = 0;
        has_carry = (i == 0);
      } else {
        digits[i] += 1;
        break;
      }
    }

    if (has_carry) {
      // all digits are 000...000 at this point.
      // Change the first slot to 1 and append 0.
      digits[0] = 1;
      digits.push_back(0);
    }
    return digits;
  }
};
