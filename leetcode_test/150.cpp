#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }

    int strToint(string str){
        int sign = 0, total = 0;
        if(str[0] == '-') sign = 1;
        int pow = 1;
        for(int i = 0;i<str.size();i++){
            if(str[i] == '-') continue;
            total *= pow;
            total += (str[i] - '0');
            pow *= 10;
        }
        if (sign) return -1 * total;
        return total;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for(int i = 0;i<tokens.size();i++){
            string& token = tokens[i];
            if(isNumber(tokens[i]))
                stk.push(strToint(tokens[i]));
            else{
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                
                switch (token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> vs = {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
    // for(int i = 0;i<vs.size();i++){
    //     if(sol.isNumber(vs[i]))
    //         cout << vs[i] << " : " << sol.strToint(vs[i]) << endl;
    // }
     sol.strToint("196");
    auto r = sol.evalRPN(vs);
    cout << r << endl;
    return 0;
}
