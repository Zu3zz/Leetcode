class Solution {
public:
    // 本题有三种做法
    // 1. 使用内置的sorted函数对两个字符串进行排序 然后比较 时间复杂度为n*logn
    // 2. 使用map进行统计 然后进行比较 由于c++没有内置map的比较函数 所以需要手动统计
    // 3. 由于给定的字符串中只存在小写 所以可以创建一个长度为26的数组进行存储统计，比较数组是否相同
    // 第一种是最慢的
    // 本解法时间使用第二种解法 执行时间为16ms 如果将第三遍循环中的条件放在第二次循环中执行 那么执行时间可以缩减至12ms
    // 使用第三种解法可以达到4ms的执行时间 但是具有局限性 只能在本题内使用 可以自行尝试
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<char,int> map1;
        // 第一遍循环 统计s字符串中出现的字符频率
        for(int i=0;i<s.size();i++){
            map1[s[i]]+=1;
        }
        // 第二次循环 统计t字符串中出现的字符频率 减去
        for(int i=0;i<t.size();i++){
            map1[t[i]]-=1;
        }
        // 第三次循环 检查是否有非零的 如果存在 则说明两个字符串不是字母异位词
        for(int i=0;i<t.size();i++){
            if(map1[t[i]] != 0){
                return false;
            }
        }
        return true;
    }
};