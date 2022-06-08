/* Ques-48:Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]*/

// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
    cout<<root->data<<" ";
	printPostOrder(root->left);
	printPostOrder(root->right);
	
}

class Solution{
    public:
    Node* buildTree(char in[],char pre[], int n)
    {
    map<int, Node*> M;
    Node* p = NULL;
    int i = 0;
    for (int j = 0; j < n; j++) {
        auto it = M.find(in[i]);
        Node* n = new Node(pre[j]);
        if (it == M.end()) {
            if (in[i] == pre[j]) i++;
            if (p) p->left = n;
        } else {
            do {
                p = it->second;
                it = M.find(in[++i]);
            } while  (it != M.end());
            p->right = n;
        }
        M[pre[j]] = p = n;
    }
    return M[pre[0]];
}
    
};

int main()
{
		int n=7;
		// 
        char inorder[]={'a','b','d','e','c','f','g'};
         char preorder[]={'d', 'b', 'e', 'a', 'f', 'c', 'g'};
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	
}
  