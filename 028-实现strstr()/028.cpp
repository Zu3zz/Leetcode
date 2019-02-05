static const auto _ = []() {
	std::ios::sync_with_stdio( false );
	std::cin.tie( nullptr );
	return nullptr;
}( );
class Solution {
public:
	/*
	可以直接使用c++内置的find函数 返回haystack字符串中needle字符串中的位置
	或者使用kmp算法 比较两个字符串
	*/
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
        // if(needle.size() == 0 || haystack == needle){
        //     return 0;
        // }
        // if(needle.size() > haystack.size()){
        //     return -1;
        // }
        // int j = 0;
        // int i = 0;
        // for(int i =0 ; i < haystack.size();i++){
        //     if(j == needle.size()){
        //         return i - needle.size();
        //     }
        //     if(haystack[i] == needle[j]){
        //         j++;
        //     } else {
        //         i -=j;
        //         j = 0;
        //     }
        // }
        // if(j == needle.size()){
        //     return i - needle.size();
        // }
        // return -1;
    }
};