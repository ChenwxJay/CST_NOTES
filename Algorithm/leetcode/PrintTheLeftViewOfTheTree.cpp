#include <iostream>
#include <queue>
using namespace std;
struct TreeNode{
	int value;//节点存储的数据
	TreeNode* left;
	TreeNode* right;
};

void solve(TreeNode* root){
	if(root == nullptr)
		return;
	queue<TreeNode*> temp;
    temp.push_back(root);//将根节点加入队列
    //循环，按层打印
    while(!temp.empty()){
        TreeNode* node = temp.peek();
        cout << node->value << " ";
        //判断左右节点是否为空，不为空则加入队列
        if(node->left != nullptr)
        	temp.push_back(node->left);
        if(node->right != nullptr)
        	temp.push_back(node->right);
    }
}
void solve2(TreeNode* root){
	if(root == nullptr)
		return;
     
}
int main(){
	solve1();
	solve2();
}