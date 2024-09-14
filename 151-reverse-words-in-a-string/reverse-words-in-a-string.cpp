class Solution {
public:
    string reverseWords(string s) {
        vector<string> words; // To store the individual words
        string word;
        stringstream ss(
            s); // Use stringstream to easily split the string by spaces

        // Extract words from the string
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the words and concatenate them with a single space
        string result;
        for (int i = words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i > 0) {
                result += " "; // Add a space between words
            }
        }

        return result;
    }
};