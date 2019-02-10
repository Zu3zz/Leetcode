const int size_1 = 26; // 字母表一共26个字母 这是只有大写或者小写的情况

// 加速输入输出
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
// 本solution执行时间为40ms 可以击败百分之99的代码
// 首先根据前缀树 即字典树的定义 有一个空的根节点 下面有26个子树 分别对应26个字母
// 所以要想定义前缀树 必须首先定义每个节点 每个节点有一个自己的值num 以及对应的26个子树
// 将所有的子节点分别置为空

class Node {
public:
    Node* next[size_1];
    int num;
    Node(){
        num = 0;
        for(int i = 0;i<size_1;i++)
            next[i] = NULL;
    }
};

// 对一个字典树 先定义一个根节点 在利用刚才的Node直接新建
class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    /*
    插入单词 还是先新建一个root节点 然后根据所给单词的长度
    如果没有前缀的单词 那么就新建一个 然后将p指向下一个对应的节点
    同时num节点的值自加一
    */
    void insert(string word) {
        Node* p = root;
        for(int i = 0;i<word.length();i++){
            if(p->next[word[i]-'a'] == NULL){
                p->next[word[i]-'a'] = new Node();
            }
            p = p->next[word[i]-'a'];
        }
        p->num++;
    }
    
    /** Returns if the word is in the trie. */
    /*
    搜索单词 还是先新建一个root节点 然后根据所给单词的长度
    逐个查找 如果没有就返回false
    如果全部查找完之后 num的值不为零 那么说明该单词存在
    返回true
    */
    bool search(string word) {
        Node* p = root;
        for(int i = 0;i<word.length();i++){
            if(p->next[word[i]-'a'] == NULL){
                return false;
            }
            p = p->next[word[i]-'a'];
        }
        if(p->num!=0) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    /** Returns if the word is in the trie. */
    /*
    看单词开头 跟搜索单词思路大题相同
    不用判断最后num是否为0 因为只需要搜索前缀
    */
    bool startsWith(string prefix) {
        Node *p = root;
        for(int i = 0;i<prefix.length();i++){
            if(p->next[prefix[i]-'a'] == NULL) return false;
            p = p->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */