class Solution
{
public:
    string postToPre(string postfix)
    {
        stack<string> st;

        for (char c : postfix)
        {
            if (isOperator(c))
            {
                string operand1 = st.top();
                st.pop();
                string operand2 = st.top();
                st.pop();
                string res = c + operand2 + operand1;
                st.push(res);
            }
            else
            {
                st.push(string(1, c));
            }
        }

        return st.top();
    }

private:
    bool isOperator(char c)
    {
        set<char> operators = {'+', '-', '*', '/', '^'};
        if (operators.count(c))
            return true;
        return false;
    }
};