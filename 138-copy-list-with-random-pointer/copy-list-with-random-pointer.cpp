/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random; 
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //creaating deep copy without reandom pointer 
        Node* dummy= new Node(0);   //helper to build the new list
        Node* tempC = dummy;    //traverse the duplicate list 
        Node* temp = head;      //pointer to traverse the original list
        while(temp){
            tempC->next  = new  Node(temp->val);
            tempC = tempC->next;  
            temp = temp->next;     
        }
        Node* b = dummy->next;  //head of deep copied list (without randoms)
        Node* a= head;
        //create map of <original,duplicate>
        unordered_map<Node*,Node*> m;
        Node* tempa = a;    //head of the original linked list.
        Node* tempb = b;    //head of the copied list
        while(tempa!=NULL){
            m[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        }
        //now collect from map m 
        for(auto x: m){
            Node* o = x.first;  //original node
            Node* d = x.second; //duplicate node
            if(o->random!=NULL){        
                Node* oRandom = o->random;
                Node* dRandom = m[o->random];  //duplicate node’s random target (found via the map).
                //after finding just attach the random 
                d->random = dRandom; 
            }
        }
        return b;
    }
};