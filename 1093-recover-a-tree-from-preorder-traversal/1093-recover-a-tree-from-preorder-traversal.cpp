/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* f(int &i,int cnt,string &s){
    if(i==s.length())return NULL;
    int c=0,j=i;
    while(j<s.length()&&s[j]!='-'){
        j++;
    }
    string str=s.substr(i,j-i);
    int val=stoi(str);
    TreeNode*node=new TreeNode(val);
    while(j<s.length()&&s[j]=='-'){
        c++;
        j++;
    }
    if(c==cnt+1){
        i=j;
        node->left=f(i,c,s);
        int c1=0,k=i;
    while(k<s.length()&&s[k]!='-'){
        k++;
    }
    while(k<s.length()&&s[k]=='-'){
        c1++;
        k++;
    }
    if(c1==cnt+1){
        i=k;
        node->right=f(i,c1,s);
    }
    }
    return node;
}
    TreeNode* recoverFromPreorder(string s) {
        int i=0;
        return f(i,0,s);
    }
};