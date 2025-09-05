#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    string infixToPostfix(string s)
    {
        string postfix;
        stack<char> st;
        unordered_map<char, int> prcd = {{'+', 1},
                                         {'-', 1},
                                         {'*', 2},
                                         {'/', 2},
                                         {'^', 3}};
        unordered_map<char, int> asso = {{'+', 1},
                                         {'-', 1},
                                         {'*', 1},
                                         {'/', 1},
                                         {'^', -1}}; // 1:l-r , -1:r-l

        for (char ch : s)
        {
            if (isOperand(ch))
                postfix += ch;
            else if (ch == '(')
                st.push(ch);
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if (st.empty())
                    st.push(ch);
                else
                {
                    while (prcd[ch] < prcd[st.top()])
                    {
                        postfix += st.top();
                        st.pop();
                    }
                    if (prcd[ch] > prcd[st.top()])
                    {
                        st.push(ch);
                    }
                    else
                    {
                        if (asso[ch] == 1)
                        {
                            postfix += st.top();
                            st.pop();
                        }
                        st.push(ch);
                    }
                }
            }
        }
        while (!st.empty())
        {
            postfix += st.top();
            st.pop();
        }
        return postfix;
    }

private:
    bool isOperand(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            return true;
        return false;
    }
};

int main()
{
    Solution sol;
    string infix = "a+b*c-(d/e^f)*g";
    string postfix = sol.infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl; // Output: "abc*def^/g*-+"
    return 0;
}

/*Infix to Postfix Conversion


You are given a string expression representing a valid infix mathematical
 expression. Your task is to convert this expression into its equivalent
 postfix notation, also known as Reverse Polish Notation (RPN).
The expression may include:

Operands: single lowercase English letters (a to z) or single-digit numbers (0 to 9)
Binary operators: +, -, *, /, ^
Parentheses: ( and ) to indicate grouping and precedence

Operator precedence (from highest to lowest):
^ (exponentiation)
*, / (multiplication and division)
+, - (addition and subtraction)

Associativity:
^ is right-associative
All other operators are left-associative
Parentheses override standard precedence


You must return the corresponding postfix expression as a string.
The result must not contain any spaces or separators between characters.


Examples:
Input: expression = "a+b*c"
Output: "abc*+"
Explanation: Multiplication has higher precedence than addition, so b * c is evaluated
first, then added to a.

Input: expression = "(a+b)*c"
Output: "ab+c*"
Explanation: The parentheses ensure that a + b is evaluated before multiplying with c.*/

/*
KEY-OBSERVATIONS & INSIGHTS:
. must have a way to check precedence and associativity
. must have a way to distinguish bet operand and operators
. order of operands are maintained, only operators change position
. visualise how there is a link between operators in stack and operands is ans as we store them.
  as long as the operators appear in correct order of precdence as left to right... precedence increasing... it is okay.. because
  the most recent operator is on top of stack and it will append first to the answer when popped all, and hence it will be evaluated first,
  and so on.. so the precendence is maintained. but, in case of violation of order of appearance of operators in terms of precedence,
  to make up for this, you go around by popping and appending the operators instantly to the final
  expression untill the order of precendence is maintained in stack, this ensures it will be evaluated first.

ALGO:
1.init ans string
2. for each char in infix string:
    if operand, push to ans
    if '(' : push
    if ')' : pop n store untill '(' is seen , pop but dont store '('
    if operator:
        if stack is empty, push to stack
        else:
            while prec(next)<prec(top): pop and store in ans
            if prec(next)>prec(top):
               push
            else:  //same
               if associatity +1: pop ans store in ans, push the curr now to stack
               else: push
3. while stack is not empty: pop and store in ans
4. finally, return ans
PROBLEMS:
1. how to associate precedence to operators--- use map
2. how to associate associativity to operators --- use map
*/