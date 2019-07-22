class Solution {
  // 去除给定字符中的元音 水题
public:
    string removeVowels(string S) {
        string ans = "";
        int n = S.length();
        for(int i=0;i<n;i++){
            char c = S[i];
            if(c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u') continue;
            ans+=c;
        }
        return ans;
    }
};