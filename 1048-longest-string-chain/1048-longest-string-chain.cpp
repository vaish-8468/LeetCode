class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // Sort words by length in ascending order
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        unordered_map<string, int> dp;
        int maxLength = 0;

        for (const string& word : words) {
            int maxChainLength = 0;

            // Generate all possible predecessor words
            for (int i = 0; i < word.length(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);

                // Check if the predecessor exists in dp
                if (dp.count(predecessor)) {
                    maxChainLength = max(maxChainLength, dp[predecessor]);
                }
            }

            // Add the current word to the chain
            dp[word] = maxChainLength + 1;
            maxLength = max(maxLength, dp[word]);
        }

        return maxLength;}
};