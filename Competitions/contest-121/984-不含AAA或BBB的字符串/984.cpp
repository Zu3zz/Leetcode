class Solution {
public:
    bool endsWith(string s, string sub){
        return s.rfind(sub) == (s.length()-sub.length())&&(s.length()>=sub.length())?true:false;
    }
    string strWithout3a3b(int A, int B) {
        string res;
        while(A>0 || B>0){
            if (A >= B) {
                if(endsWith(res,"aa")){
                    res+="b";
                    B-=1;
                }
                else{
                    res+="a";
                    A-=1;
                }
            } else {
                if(endsWith(res,"bb")){
                    res+="a";
                    A-=1;
                }
                else{
                    res+="b";
                    B-=1;
                }
            }
        }
        return res;
    }
};