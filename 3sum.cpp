
vector<vector<int>> solve(vector<int> num> {
  vector<vector<int>> result;
  if (num.size() < 3)
    return result;
  std::sort(num.begin(), num.end());

  for (int p = 0; p < num.size() - 2; ++p) {
    // Skip this number if we have checked the same number in the previous
    // iteration.
    if (p > 0 && num[p] == num[p - 1])
      continue;

    for (int i = p + 1, j = num.size() - 1; i < j;) {
      if (num[p] + num[i] + num[j] == 0) {
        bool exist = false;
        // Insert only if there is no duplicate. Removing duplicate inside the
        // loop is a tradeoff between space and time. Keeping duplicates may use
        // more space.
        for (int k = result.size() - 1; k >= 0; --k) {
          // The first number already differs.
          if (result[k][0] != num[p])
            break;

          // Both the first number and the second number match.
          if (result[k][1] == num[i]) {
            exist = true;
            break;
          }
        }
        if (!exist) {
          vector<int> t;
          t.push_back(num[p]);
          t.push_back(num[i]);
          t.push_back(num[j]);
          result.push_back(t);
        }
        ++i, --j;
      } else if (num[p] + num[i] + num[j] > 0) {
        --j;
      } else {
        ++i;
      }
    }
  }
  return result;
}