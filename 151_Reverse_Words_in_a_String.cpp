class Solution {
public:
    string reverseWords(string s) {
        string ret = ""; // initialized empty
        int start = 0; // the current word
        int new_word = false;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ' '){
                if (new_word)
                    ret = " " + s.substr(start, i - start) + ret; // add the word to the existent one
                start = i + 1; // the next word will be start at i + 1
                new_word = false;
            }
            else
                new_word = true;
        }
        if (new_word)
            ret = s.substr(start, s.length() - start) + ret; // the final word
        else 
            ret = ret.substr(1); // from 1 onwards
        return ret;
    }
};
