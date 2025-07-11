class Solution
{
public:
    string prefixToInfix(string s)
    {
        string infix;
        stack<string> st;

        reverse(s.begin(), s.end());

        for (char c : s)
        {
            if (isOperator(c))
            {
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = '(' + x + c + y + ')';
                st.push(z);
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
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
            return true;
        return false;
    }
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. read right to left , because you will always be sure to have two operands
  before you get a operator
. when you get an operator, pop last two operands, bind togeter, pack in () and push back


ALGO:
1. init  stack
2. reverse prefix given
3. for all char in prefix:
      if operand, push into stack
      else if operator:
         pop last two complete operands, bind together, pack in parenthesis and push back
4. return st.top();


PROBLEMS:

*/