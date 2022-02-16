#include <iostream>
#include <vector>
#include <algorithm>

typedef struct TreeNode {
	int label; 
	TreeNode *left = nullptr, *right = nullptr;
} TreeNode; 

using namespace std;

// a > b 
int dist (unsigned int root, int it, vector<int>& preorder){
    auto iter = find(preorder.begin() + root, preorder.end(), it);
    return distance(preorder.begin(), iter);
}

int minIdx (unsigned int root, unsigned int l, unsigned int r, vector<int>& preorder, vector<int>& inorder){

    if(l == r)
        return -1;
    
    if(l + 1 == r)
        return l;


    int rootlocation = find(preorder.begin(), preorder.end(), inorder[root]) - preorder.begin();

    int min = dist(rootlocation, inorder[l], preorder);

    int minI = l;

    for(l += 1; l < r; l++){
        int distance = dist(rootlocation, inorder[l], preorder);
        if(distance < min){
            min = distance;
            minI = l;
        }
    }

    return minI;    
}

TreeNode* filltree (vector<int>& inorder, vector<int>& preorder, int i, int l, int r){

    TreeNode* node = new TreeNode;

    node->label = inorder[i];

    int leftIdx = minIdx(i, l, i, preorder, inorder);
    int rightIdx = minIdx(i, i + 1, r, preorder, inorder);

    if(leftIdx != -1){
        node->left = filltree(inorder, preorder, leftIdx, l, i);
    }
    if(rightIdx != -1){
        node->right = filltree(inorder, preorder, rightIdx, i + 1, r);
    }

    return node;
}

void clearTree(TreeNode* root){
    if(root != nullptr){
        clearTree(root->left);
        clearTree(root->right);
        delete root;
    }
}

void printPostOrder(TreeNode* root){
    if(root != nullptr){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->label << " ";        
    }
}

void fillPostorder(vector<int>& preorder, vector<int>& inorder){

    int rootInd = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[0]));

    TreeNode* root = filltree(inorder, preorder, rootInd, 0, preorder.size());


    printPostOrder(root);
    cout << endl;
    clearTree(root);
    
}


int main() {
	int n; 
	cin >> n;

    if(n < 1){
        return 0;
    }

	vector<int> preorder(n); 
	for(int i=0; i<n; i++) cin >> preorder[i];

	vector<int> inorder(n); 
	for(int i=0; i<n; i++) cin >> inorder[i];

	// compute your post order traversal in postorder!

    fillPostorder(preorder, inorder);   
    
    


	

	// output the post order traversal

    //for(int i=0; i<n; i++) cout << postorder[i] << " "; 
	//cout << endl; 
}

// 3 5 6 4 2 8 9 7 1