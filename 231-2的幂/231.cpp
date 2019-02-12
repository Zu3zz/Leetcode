static const auto _=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && (!(n&(n-1)));
    }
};