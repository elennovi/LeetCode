class Solution {
public:
    bool isValid(string str) {
        stack<char> s; // to store the state of the parentheses
        
        for(char c: str){ // every char in the string
            if (!s.empty()){ 
                if (c == ')' && s.top() == '(')
                    s.pop();
                else if (c == ']' && s.top() == '[')
                    s.pop();
                else if (c == '}' && s.top() == '{')
                    s.pop();
                else if (c == ')' || c == ']' || c == '}')
                    return false;
                else if (c == '(' || c == '[' || c == '{')
                    s.push(c);
            }
            else { // empty stck
                if (c == ')' || c == ']' || c == '}')
                    return false;
                else if (c == '(' || c == '[' || c == '{')
                    s.push(c);
            }
        } 

        if (!s.empty()) 
            return false; // not valid parentheses
        return true;       
    }
};
