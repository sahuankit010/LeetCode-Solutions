
/*
Intuition Behind the Approach:
Trie Data Structure:

The Trie (prefix tree) is perfect for problems involving prefixes. 
Each node in the Trie represents a prefix of one or more words. 
As we insert words, we update how many words pass through each prefix.
Insertion of Words:

When a word is inserted into the Trie, every node (representing a character in the word) 
updates its count to reflect how many words share that prefix.

Calculating Prefix Scores:

For each word, we traverse the Trie, summing up the count at each node corresponding 
to the characters of the word. This count gives us how many words have passed through 
each prefix, and the sum gives the "prefix score" for the word.
Example Walkthrough:
Let's say we have the words: ["abc", "ab", "bc"].

Insert the words:
abc -> Each node for 'a', 'b', 'c' gets incremented.
ab -> Nodes for 'a', 'b' are incremented again.
bc -> Nodes for 'b', 'c' are incremented.
Prefix Scores:
For the word abc, the score is the sum of counts for nodes corresponding to 'a', 'b', and 'c'.
For the word ab, the score is the sum of counts for nodes corresponding to 'a' and 'b'.
For the word bc, the score is the sum of counts for nodes corresponding to 'b' and 'c'.
*/
class Solution {
    // TrieNode represents a node in the Trie data structure.
    // Each node has a count and an array of children representing the 26 lowercase letters.
    class TrieNode {
    public:
        TrieNode* children[26]; // Each index represents a letter 'a' to 'z'.
        int count;              // Count of how many times this node has been visited when inserting words.

        // Constructor to initialize a new Trie node.
        TrieNode() {
            count = 0;
            // Initialize all children pointers to nullptr.
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

public:
    TrieNode* root; // Root of the Trie.

    // Constructor initializes the root node of the Trie.
    Solution() {
        root = new TrieNode(); // Create an empty root TrieNode.
    }

    // Function to insert a word into the Trie.
    // As we insert characters, we increment the count at each node.
    void insert(const string& str) {
        TrieNode* node = root; // Start from the root.

        // For each character in the word:
        for (const char& ch : str) {
            int index = ch - 'a'; // Calculate the index corresponding to the character.
            
            // If no node exists for the current character, create one.
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            
            // Increment the count for the current node, as this prefix is part of another word.
            node->children[index]->count++;
            
            // Move to the next node in the Trie.
            node = node->children[index];
        }
    }

    // Function to calculate the sum of prefix scores for a given word.
    // The prefix score is the sum of counts of all the nodes along the path of the word's prefix.
    int prefixCount(const string& str) {
        TrieNode* node = root; // Start from the root.
        int ans = 0;           // This will store the sum of counts for all prefixes of the word.

        // For each character in the word:
        for (const char& ch : str) {
            int index = ch - 'a'; // Calculate the index corresponding to the character.

            // If there's no Trie node for the current character, stop since no further prefix exists.
            if (node->children[index] == nullptr) {
                break; // No more prefixes to consider, so break early.
            }

            // Add the count of the current node to the answer (this count reflects how many words share this prefix).
            ans += node->children[index]->count;

            // Move to the next node in the Trie.
            node = node->children[index];
        }

        // Return the sum of the counts for all prefixes.
        return ans;
    }

    // Main function to calculate the sum of prefix scores for each word in the input list.
    // It first inserts all the words into the Trie and then calculates the prefix score for each word.
    vector<int> sumPrefixScores(vector<string>& words) {
        
        // Insert each word into the Trie.
        for (const string& curr : words) {
            insert(curr);
        }

        // Prepare an answer vector to store the prefix scores.
        vector<int> ans(words.size());
        int i = 0;

        // For each word, calculate its prefix score by traversing the Trie.
        for (const string& curr : words) {
            ans[i++] = prefixCount(curr);
        }

        // Return the prefix scores for all the words.
        return ans;
    }
};
