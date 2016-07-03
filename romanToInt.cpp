class Solution {
public:
    int romanToInt(std::string s) {
      if (s.empty())
        return 0;

      map<char, int> vm;
      vm['I'] =	1;
      vm['V'] =	5;
      vm['X'] =	10;
      vm['L'] =	50;
      vm['C'] =	100;
      vm['D'] =	500;
      vm['M'] =	1000;

      int len = s.size();
      int result = vm[s[len - 1]];
      for (int i = len - 2; i >= 0; --i) {
        if (vm[s[i]] < vm[s[i + 1]])
          result -= vm[s[i]];
        else
          result += vm[s[i]];
      }

      return result;
    }
};
