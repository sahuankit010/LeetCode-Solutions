class WordDictionary {

    // A class representing a node in the Trie structure
    class TrieNode {
    public:
        bool isEndOfWord;       // Flag to indicate the end of a word
        TrieNode* children[26]; // Array of pointers to child nodes for each
                                // letter (26 letters of the alphabet)

        // Constructor to initialize a TrieNode
        TrieNode() {
            isEndOfWord =
                false; // Initially, this node is not the end of any word
            for (int i = 0; i < 26; i++) {
                children[i] =
                    nullptr; // Initialize all child pointers to nullptr
            }
        }
    };

public:
    TrieNode* root; // Root of the Trie

    // Constructor to initialize the WordDictionary
    WordDictionary() {
        root = new TrieNode(); // Create an empty TrieNode as the root
    }

    // Function to add a word to the dictionary
    void addWord(string word) {
        TrieNode* node = root; // Start at the root node

        // Traverse through each character in the word
        for (const char& ch : word) {
            int index =
                ch -
                'a'; // Get the index for the character (0 for 'a', 25 for 'z')
            if (node->children[index] == nullptr) {
                node->children[index] =
                    new TrieNode(); // Create a new TrieNode if it doesn't exist
            }

            node = node->children[index]; // Move to the next node
        }

        node->isEndOfWord = true; // Mark the last node as the end of the word
    }

    // Function to search for a word (supports '.' as a wildcard character)
    bool search(string word) {
        return searchUtility(word, root); // Start the search from the root node
    }

    // Helper function for searching the word (supports wildcard '.' for any
    // letter)
    bool searchUtility(string word, TrieNode* node) {

        // Traverse through each character in the word
        for (int i = 0; i < word.size() && node; i++) {
            int index = word[i] - 'a'; // Calculate index for the character

            // If the current character is not a wildcard '.'
            if (word[i] != '.') {
                node = node->children[index]; // Move to the next child node
            } else {
                // If wildcard '.' is found, try all possible child nodes
                TrieNode* temp = node;
                for (int j = 0; j < 26; j++) {
                    if (temp->children[j] != nullptr) {
                        // Recursively search for the remaining substring
                        if (searchUtility(word.substr(i + 1),
                                          temp->children[j]))
                            return true;
                    }
                }
                return false; // Return false if no match is found for the
                              // wildcard
            }
        }

        // Return true if the current node marks the end of a valid word, false
        // otherwise
        return node && node->isEndOfWord == true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
