#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
	TreeNode(int value):value_(value){
        cout << "Construct a TreeNode!" << endl;
	}
	~TreeNode(){}
private:
	int value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* ConstructBinaryTree(vector<int> pre,vector<int> middle){
	//获取数组元素长度
	int len = middlen.size();
    //错误检验，判空
    if(len <= 0){
    	return nullptr;
    }
    //需要重新构建整棵树，因此需要动态分配内存
    TreeNode* root = new TreeNode(pre[0]); //前序数组第一个节点一定是树根节点
    //循环遍历中序遍历序列，找到根节点位置
    int head = 0;
    for(int i = 0;i < len;i++) //这里可以做一个改进，遍历时间复杂度为O(n)
    {
    	if(middle[i] == pre[0]){
    		head = i; //需要用一个中间变量来记录根节点的下标
    		break;
    	}
    	
    }
    //区分左右子树
    for(int i = 0;i < index;i++){
    	left_pre.push(pre[i+1]); //注意左子树的根节点是整棵树的根节点，因此根节点不用添加
    	left_in.push(middle[i]);
    }
    //index指向根节点，可以不用添加
    for(int j = index+1;j < len;j++){
        right_pre.push(pre[j]) //前序遍历序列的右子树，直接添加
        right_in.push(middle[j]);//中序遍历数组，右半部分，直接添加
    }
   
   //分组之后继续递归，在第一层函数处完成设置指针
    root->left = ConstructBinaryTree(left_pre,left_in);
    root->right = ConstructBinaryTree(right_pre,right_in);

    //最后返回当前树的根节点
    return root;
};

int main(){
	
}