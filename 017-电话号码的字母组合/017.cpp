class Solution {
public:
		/*
		此solution执行时间可以达到0ms
		思路如下 对于字符串"23" 2对应"abc" 3对应"def"
		输入2 所以得到{"a","b","c"}
		输入3 
		对队首元素"a" 先删除"a" 在分别加入"d","e","f" 得到{"b","c","ad","ae","af"}
		对于排列中的首元素"b"，删除"b"，并分别加入'd','e','f'，得到{"c","ad","ae","af","bd","be","bf"}
		对于排列中的首元素"c"，删除"c"，并分别加入'd','e','f'，得到{"ad","ae","af","bd","be","bf","cd","ce","cf"}
		这就是最终结果了
		*/
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string s1;
        vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits == ""){
            return res;
        }
        res.push_back("");
        for(int i = 0 ; i<digits.size();i++){
        	  // 这里需要动态的获取res的大小 因为每一次都会改变
            int size = res.size();
            for(int j = 0; j<size;j++){
                string cur = res[0];
                //需要注意的是这里需要提前删除res的第一个
                res.erase(res.begin());
                for(int k = 0; k<dict[digits[i] - '0'].size();k++){
                    res.push_back(cur + dict[digits[i]-'0'][k]);
                }
            }
        }
        return res;
    }
};