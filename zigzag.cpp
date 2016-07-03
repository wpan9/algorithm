
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;

        // A string for each row
        vector<string> substrings(numRows);

        int rowIndex = 0;
        int delta = 1;
        for (int i = 0, n = s.size(); i < n; ++i) {
            substrings[rowIndex].push_back(s[i]);

            // flip delta if hitting the boundary.
            if (rowIndex == numRows - 1) {
                delta = -1;
            } else if (rowIndex == 0) {
                delta = 1;
            }
            rowIndex += delta;
        }
        string result;
        for (auto &ss : substrings) {
            result.append(ss);
        }
        return result;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        if (s.size() <= numRows) return s;

        int n = (int)s.size();
        int pred = 2 * numRows - 2;

        string result;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < n; j += pred) {
                // Each iteration appends 1 node for boundary rows
                // and may append an extra node for internal rows.
                //
                // The gap in between is (2 * numRows - i - 1).
                //
                // row 0 (boundary)
                // row 1
                // row 2
                // ...
                // row i, s[j] ----> s[j + (2 * nRows - i - 1)]
                // ...
                // row numRows - 1 (boundary)
                result.push_back(s[j]);
                if (i != 0 && i != numRows - 1 && (j + 2 * (numRows - i - 1) < n)) {
                    // has a single internal node.
                    result.push_back(s[j + 2 * (numRows - i - 1)]);
                }
            }
        }
        return result;
    }
};
