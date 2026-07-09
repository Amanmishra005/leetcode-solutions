class Solution {
public:
    void dfs(Node* node , Node* cNode){
        for(Node* n : node->neighbors){
            if(mp.find(n)==mp.end()){
                Node* clone = new Node(n->val);
                mp[n] = clone;
                cNode->neighbors.push_back(clone);
                dfs(n , clone);
            }else{
                cNode->neighbors.push_back(mp[n]);
            }
        }
    }
    unordered_map<Node* , Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* cNode = new Node(node->val);
    mp[node] = cNode;
    dfs(node , cNode);
    return cNode;
    }
};