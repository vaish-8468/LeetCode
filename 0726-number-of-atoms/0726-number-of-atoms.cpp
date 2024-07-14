class Solution {
public:
     typedef unordered_map<string, int> MAP;

    string countOfAtoms(string formula) {
        int n = formula.length();
        
        stack<MAP> st;
        st.push(MAP());

        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                //opening bracket
                st.push(MAP());
                i++;
            } else if (formula[i] == ')') {
                //closing bracket
                MAP currMap = st.top();
                st.pop();
                i++;
                //determine the frequency of elements inside the brackets
                string multiplier;
                while (i < formula.length() && isdigit(formula[i])) {
                    multiplier += formula[i];
                    i++;
                }
                if (!multiplier.empty()) {
                    //convert the multiplier from string to integer
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }
                //after incrementing the count of the prev top, merge it with the curr top
                for (auto& [atom, count] : currMap) {
                    st.top()[atom] += count;
                }
            } else {
                string currAtom;
                currAtom += formula[i];
                i++;
                while (i < formula.length() && islower(formula[i])) {
                    currAtom += formula[i];
                    i++;
                }

                string currCount;
                while (i < formula.length() && isdigit(formula[i])) {
                    currCount += formula[i];
                    i++;
                }

                int count = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currAtom] += count;
            }
 
        }
        
        //at last, store the last map from the stack into ordered map to print the result in the required format
        map<string, int> sortedMap(begin(st.top()), end(st.top()));

        string result;
        for (auto& [atom, count] : sortedMap) {
            result += atom;
            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
    }
};