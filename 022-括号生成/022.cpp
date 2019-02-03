class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        gen("",vec,n,n);
        return vec;
    }
    void gen(string sublist, vector<string> &vec,int left,int right){
        if (left == 0 && right == 0){
            vec.push_back(sublist);
            return;
        }
        if (left > 0) {
            gen(sublist+ "(", vec, left-1, right);
        }
        if (right > left) {
            gen(sublist+ ")", vec, left, right-1);
        }
    }
};