
class Trie {
public:
    // Structure for each Trie node
    struct TrieNode{
        bool isEndOfWord; // Indicates if the node represents the end of a valid word
        TrieNode* children[26]; // Array of pointers to child nodes, one for each letter in the alphabet (26 letters)

        // Constructor to initialize a TrieNode
        TrieNode(){
            isEndOfWord = false; // Initialize isEndOfWord as false

            // Initialize all child pointers to nullptr (no children initially)
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root; // Pointer to the root node of the Trie

    // Constructor to initialize the Trie with a root node
    Trie() {
        root = new TrieNode(); // Create a new TrieNode as the root
    }
    
    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root; // Start from the root node

        // Iterate through each character in the word
        for(const char &ch: word){
            int index = ch - 'a'; // Calculate the index (0-25) for the character

            // If the corresponding child node does not exist, create a new TrieNode
            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }
            node = node->children[index]; // Move to the next node
        }

        // After processing the entire word, mark the last node as the end of a word
        node->isEndOfWord = true;
    }
    
    // Function to search for a word in the Trie
    bool search(string word) {
        TrieNode* node = root; // Start from the root node

        // Iterate through each character in the word
        for(const char &ch: word){
            int index = ch - 'a'; // Calculate the index for the character

            // If the corresponding child node does not exist, the word is not found
            if(node->children[index] == nullptr){
                return false;
            }
            node = node->children[index]; // Move to the next node
        }

        // Check if the last node represents the end of the word
        if(node != nullptr && node->isEndOfWord == false) return false;
        return true;
    }
    
    // Function to check if any word in the Trie starts with a given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root; // Start from the root node

        // Iterate through each character in the prefix
        for(const char &ch: prefix){
            int index = ch - 'a'; // Calculate the index for the character

            // If the corresponding child node does not exist, no word starts with the prefix
            if(node->children[index] == nullptr){
                return false;
            }
            node = node->children[index]; // Move to the next node
        }

        // If all characters in the prefix are found, return true
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);       // Insert a word into the Trie
 * bool param_2 = obj->search(word); // Check if the word exists in the Trie
 * bool param_3 = obj->startsWith(prefix); // Check if any word starts with the given prefix
 */
