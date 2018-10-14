using namespace std;
#include<iostream>
#include<string.h>
#define MAX 100
#include<stack>
stack<char> s;
bool balanced(char *exp)
{
    int p;
    for (int i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            {
                s.push(exp[i]);
                continue;
            }
        if(s.empty())
        {
            return false;
        }
        switch(exp[i])
        {
        case ')':
            {
                p=s.top();
                s.pop();
                if(p=='{' || p=='[')
                {
                    return false;
                }
                break;
            }
             case '}':
            {
                p=s.top();
                s.pop();
                if(p=='(' || p=='[')
                {
                    return false;
                }
                break;
            }
             case ']':
            {
                p=s.top();
                s.pop();
                if(p=='{' || p=='(')
                {
                    return false;
                }
                break;
            }
        }
    }
    return s.empty();
}
void balancedparenthesis(char *exp)
{
    if(balanced(exp))
        cout<<"Valid Expression"<<endl;
    else
        cout<<"Invalid Expression"<<endl;
}
int main()
{
    char exp[MAX];
    cin>>exp;
    balancedparenthesis(exp);
    return 0;
}
