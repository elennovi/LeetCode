class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        int length = s.length(); // the common length
        
        // processing the strings
        unordered_map<char, char> match; 
        // key: chars from s
        // value: char from t
        unordered_map<char, char> reverse_match; 
        // key: chars from t
        // value: char from s
        
        for(int i = 0; i < length; ++i){
            char c_s = s[i], c_t = t[i]; // current chars
            auto it = match.find(c_s);
            auto it_r = reverse_match.find(c_t);
            if (it == match.end() && it_r == reverse_match.end())
                match.insert({c_s, c_t}), reverse_match.insert({c_t, c_s});
            else if (it != match.end() && it_r != reverse_match.end() && it->first == it_r->second && it_r->first == it->second){}
            else 
                return false;
        }
        return true;
    }
};
