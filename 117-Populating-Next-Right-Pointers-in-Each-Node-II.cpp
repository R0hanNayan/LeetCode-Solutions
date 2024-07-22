class Solution {
public:
    Node* connect(Node* root) {
        if(!root){  return NULL;  }
        queue<Node*> q;

        q.push(root);
        while(!q.empty()){
            int k = q.size();
            Node* prev = NULL;

            while(k--){
                Node* top=q.front();
                q.pop();
                top->next=prev;
                prev=top;

                if(top->right)  q.push(top->right);
                if(top->left)   q.push(top->left);
            }
        }
        return root;
    }
};