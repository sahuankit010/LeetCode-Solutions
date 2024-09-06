class Solution {
public:
    /*
    Algo:
    1. Declare a stack for numbers and strings: numStack and stringStack respectively.
    2. Iterate over the string `s` from index 0 to n-1 (i++).
       Initialize currString to store the currently forming string.
    3. If the current character is a digit, build the number (to handle multi-digit numbers).
    4. If the current character is '[':
        - Push the current number onto the numStack.
        - Push the current string onto the stringStack.
        - Reset currString to start capturing a new string within the brackets.
        - Reset the number to 0.
    5. If the current character is ']':
        - Retrieve the number of repetitions (repeatTimes) from numStack.
        - Save the current string in tempStr.
        - Restore the previous string from stringStack.
        - Append tempStr repeatTimes to the restored string.
    6. If the current character is a letter, append it to currString.
    */
    string decodeString(string s) {
        int n = s.size(); // Length of the input string

        stack<string> stringStack; // Stack to hold strings when encountering '['
        stack<int> numStack; // Stack to hold numbers for repetition

        string currString = ""; // Current string being processed
        int num = 0; // Current number being built (to handle cases like "12[abc]")

        for(int i = 0; i < n; ++i) {
            char ch = s[i]; // Current character in the string

            // If the character is a digit, build the number
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0'); // Handle multi-digit numbers
            }
            // If '[' is encountered, push the current number and string onto their respective stacks
            else if (ch == '[') {
                numStack.push(num); // Store the number of repetitions
                stringStack.push(currString); // Store the current string
                currString = ""; // Reset current string for new content inside brackets
                num = 0; // Reset num for the next potential number
            }
            // If ']' is encountered, it's time to repeat the string
            else if (ch == ']') {
                int repeatTimes = numStack.top(); // Get the repetition count
                numStack.pop(); // Remove the number from the stack

                string tempStr = currString; // Temporary storage of the current string

                currString = stringStack.top(); // Get the previous string from the stack
                stringStack.pop(); // Remove it from the stack

                // Append the repeated string to the previous string
                while (repeatTimes-- > 0) {
                    currString += tempStr;
                }

            } 
            // If it's just a letter, add it to the current string
            else {
                currString += ch;
            }
        }

        return currString; // Return the fully decoded string
    }
};
