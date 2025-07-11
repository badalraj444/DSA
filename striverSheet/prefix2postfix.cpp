class Solution
{
public:
    string prefixToPostfix(const string &s)
    {
        stack<string> st;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (isOperator(c))
            {
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = x + y + c;
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
. when you get an operator, pop last two operands, bind togeter as op1  op2 oper and push back


ALGO:
1. init  stack
2. reverse prefix given
3. for all char in prefix:
      if operand, push into stack
      else if operator:
         pop last two complete operands, bind together and push back
4. return st.top();


PROBLEMS:

*/