class Solution {
public:
    bool isValid(string s) {
        // 运行时间0ms 很神奇 我也不知道leetcode怎么判出来的
        // 主要用到了栈的数据结构 所有的符号按照规则 有入必有对应的出
        // 形如 1.(({})) 2.([()]){}都是合法的输入 而[(])就是一个不合法的
        // 可以观察看到 对于(){}[] 只要按照stack的数据结构存储
        // 当遇到左括号的时候 先入栈，遇到右括号时 检查栈顶元素是否与其匹配
        // 直接拿出比较 不匹配则直接返回失败
        // 等到所有元素全部进行完之后 stack应该是一个空的 此时最后检查一下 
        // 如果无误就是一个合法的括号规则
        stack<char> s1;
        for(int i=0;i<s.size();i++){
            // 遇到左括号入栈
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                s1.push(s[i]);
            }
            else{
                if(s1.size() == 0){
                    return false;
                }
                char match;
                // 遇到右括号检查栈顶是否匹配
                if(s[i]==')'){
                    match = '(';
                }else if(s[i]==']'){
                    match = '[';
                }else if(s[i]=='}'){
                    match = '{';
                }
                // 拿到栈顶元素
                // 并且弹出
                char c = s1.top();
                s1.pop();
                if(c != match){
                    return false;
                }
            }
        }
        if(s1.size() != 0){
            return false;
        }
        return true;
    }
};