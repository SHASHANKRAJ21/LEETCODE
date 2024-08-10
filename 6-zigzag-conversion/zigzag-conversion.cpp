class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // If there is only one row, then the zigzag pattern is the same as the original string.
        if (numRows == 1) return s;
      
        std::string ans;  // The final answer string in zigzag order.
        int cycleLength = 2 * numRows - 2;  // The length of the repeating zigzag cycle.
      
        // Loop through each row.
        for (int currentRow = 1; currentRow <= numRows; ++currentRow) {
            // The interval depends on the current row and alternates within each zigzag cycle.
            int interval = (currentRow == numRows) ? cycleLength : 2 * numRows - 2 * currentRow;
            int currentIndex = currentRow - 1;  // The starting index in the original string for this row.
          
            // Loop through characters in the row.
            while (currentIndex < s.length()) {
                ans.push_back(s[currentIndex]); // Append character to the answer string.
                currentIndex += interval; // Move to the next character in the zigzag pattern.
                interval = cycleLength - interval; // Alternate the interval for the zigzag pattern.
              
                // The interval should not be zero; if it is, reset it to the cycle length.
                if (interval == 0) {
                    interval = cycleLength;
                }
            }
        }
      
        return ans;  // Return the zigzag pattern string.
    }
};