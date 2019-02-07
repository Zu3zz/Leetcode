class Solution {
public:
	/*
	本solution执行时间为0ms
	1. 1
	2. 11 		上一行 1个1 所以11
	3. 21 		上一行 2个1 所以21
	4. 1211		上一行 1个2 1个1 所以1211
	5. 111221	上一行 1个1 1个2 2个1 所以111221
	6. 312211 上一行 3个1 2个2 1个1 所以312211
	7. 13112221 规则依旧
	*/
    string countAndSay(int n) {
    	// 先选择好是1的情况 字符串就是"1"
        string result = "1";
        // 如果大于等于2 在进入循环
        for ( int i = 2; i<= n ; i++){
            result = printNumber(result);
        }
        return result;
    }
    string printNumber(string lastStr) {
        string str;
        int num = 1;
        for ( int i = 1; i<lastStr.size();i++){
        	// 只要判断后一个字符串是否跟前一个字符相同
        	// 相同就计数器自加一 不同就按照A个B的格式 添加进字符串中
        	// 注意 这里最好用push_back方法 不要用to_string 会增加执行时间
        	// 直接用 num + '0' 变成字符串
            if(lastStr[i -1] != lastStr[i]){
                str.push_back(num + '0');
                str.push_back(lastStr[i-1]);
                num = 1;
            }
            else num++;
        }
        str.push_back(num + '0');
        str.append(1, lastStr[lastStr.length()-1]);
        return str;
    }
};