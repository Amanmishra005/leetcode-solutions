class Solution {
public:
vector<string> ans;
int m , n;
    struct trieNode{
        bool isEnd;
        trieNode* children[26];
        string word;
    };
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        newNode->word = "";

        for(int  i =0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    void insert(trieNode* root, string &word){
        trieNode* crawler = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            int idx = ch - 'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
        crawler->word = word; 
    }
    void findWordstrie(vector<vector<char>>& board , int i , int j ,trieNode* root){
        if(i<0 || j< 0 || i>=m || j>=n) return;
        char ch = board[i][j];
        int idx = ch - 'a';
        if(board[i][j]=='$' || root->children[idx] == NULL) return;
        root = root->children[idx];
         if(root->isEnd == true){
            ans.push_back(root->word);
            root->isEnd = false;
         }
         char temp = board[i][j];
         board[i][j] = '$';
         int delrow[] = {1,0,-1,0};
         int delcol[] = {0,1,0,-1};
         for(int k = 0;k<4;k++){
            int nrow = i + delrow[k];
            int ncol = j  + delcol[k];
            findWordstrie(board , nrow , ncol , root);
         }
         board[i][j] = temp;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        trieNode* root = getNode();
        for(auto &word : words){
            insert(root,word);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               
                    findWordstrie(board, i , j , root);
                

            }
        }
        return ans;
    }
};