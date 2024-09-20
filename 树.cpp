#include<stack>
#include<queue>
#include<string>
#include<unordered_map>
#include <iostream>
using namespace std;
class TreeNode_solution
{
private:
	struct TreeNode
	{
		int value;
		TreeNode* left;
		TreeNode* right;
	};
public:
	TreeNode_solution() {}
	~TreeNode_solution() {}
	//  前序遍历   这个遍历是按前序写的  中左右   递归写法. 
	//中左右的意思是 先处理根结点再处理左子树最后处理右子树  
	//                       当处理完根结点时，处理左子树，可以将左子树看成一个独立的树，再按照中左右的顺序处理结点
	//                       当处理完左子树时，处理右子树，也可以将右子树看成一个独立的树，再按照中左右的顺序处理结点
	void traversal(TreeNode* cur, vector<int>& vec)
	{
		if (cur == nullptr)
		{
			return;
		}
		vec.push_back(cur->value); //中
		traversal(cur->left, vec); //左
		traversal(cur->right, vec); //右
	}
	vector<int> preorder_traversal(TreeNode* root)
	{
		vector<int> ans;
		traversal(root, ans);
		return ans;
	}
	//前序的迭代写法
	// 因为是按照中左右的顺序
	//  当先一路往左处理左子树的时候 中结点没话说 直接将其值进入ans
	//  但由于都是左结点优先 右结点只能等左结点处理完后才轮到处理  
	//     那么当遇到多个分支的右节点需要处理 如何确定其处理顺序呢？
	// 不难想到栈！ 由于栈的特性 先进后出 从上面一路下来 将先遇到的右结点入栈 左节点后入栈 再先处理左节点 那么当左节点处理完成时 则将栈元素一一弹出处理  便可解决右结点的处理顺序问题 
	vector<int> preorder_traversal_Iterative(TreeNode* root)
	{
		stack<TreeNode*> stk;
		vector<int> ans;
		if (root == nullptr)
		{
			return ans;
		}
		stk.push(root);
		while (!stk.empty())
		{
			TreeNode* tn = stk.top();
			stk.pop();
			ans.push_back(tn->value);
			if (tn->right)
			{
				stk.push(tn->right);
			}
			if (tn->left)
			{
				stk.push(tn->left);
			}
		}
		return ans;
	}

	//给出中序的递归写法  左中右顺序
	void inorder_traversal(TreeNode* root, vector<int>& vec)
	{
		if (root == nullptr)
		{
			return;
		}
		inorder_traversal(root->left, vec);
		vec.push_back(root->value);
		inorder_traversal(root->right, vec);
	}
	vector<int> Inorder_traversal(TreeNode* root)
	{
		vector<int> ans;
		inorder_traversal(root, ans);
		return ans;
	}
	vector<int> Inorder_traversal_Iterative(TreeNode* root)
	{
		stack<TreeNode*> stk;
		vector<int> ans;
		TreeNode* cur = root;
		while (cur != nullptr || !stk.empty())
		{
			if (cur != nullptr)
			{
				stk.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = stk.top();
				stk.pop();
				ans.push_back(cur->value);
				cur = cur->right;
			}
		}
		return ans;
	}
	//后序遍历   左右中
	// 
	void postorder_traversal(TreeNode* root, vector<int>& vec)
	{
		if (root == nullptr)
		{
			return;
		}
		postorder_traversal(root->left, vec);
		postorder_traversal(root->right, vec);
		vec.push_back(root->value);
	}
	vector<int> Postorder_traversal(TreeNode* root)
	{
		vector<int> ans;
		postorder_traversal(root, ans);
		return ans;
	}
	vector<int> Postorder_traversal_Iterative(TreeNode* root)
	{
		stack<TreeNode*> stk;
		vector<int> ans;
		if (root == nullptr)
		{
			return ans;
		}
		TreeNode* cur = root;
		stk.push(cur);
		while (!stk.empty())
		{
			TreeNode* tn = stk.top();
			stk.pop();
			ans.push_back(tn->value);
			if (tn->left)
			{
				stk.push(tn->left);
			}
			if (tn->right)
			{
				stk.push(tn->right);
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
	//广度优先搜索二叉树
	// 因为是一层一层遍历 我们需要一个容器来按顺序保存一层中的每一个结点 同时这个容器还可以扩展与弹出结点
	//  不难想到可以用队列来模拟这一过程
	//   对第一层如果没有左右孩子则结束  如可以则存入首结点
	//   再对下一层进行处理 如果队列中的头元素可以有左右孩子的话则按左右顺序存入队列 并且将头元素的指向的值存入ans中 最后删除头 如果没有孩子的话则放弃存入
	//  这样循环遍历的最终结果是 当触底时 没有一个孩子存入队列 队列为空 则退出循环
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		queue<TreeNode*> que;
		vector<vector<int>> ans;
		if (root == nullptr)
		{
			return ans;
		}
		TreeNode* cur = root;
		que.push(cur);
		while (!que.empty())
		{
			int que_size = que.size();
			vector<int> vec;
			for (size_t i = 0; i < que_size; i++)
			{
				TreeNode* tr = que.front();
				vec.push_back(tr->value);
				que.pop();
				if (tr->left != nullptr)
				{
					que.push(tr->left);
				}
				if (tr->right != nullptr)
				{
					que.push(tr->right);
				}
			}
			ans.push_back(vec);
		}
		return ans;
	}
	//翻转二叉树
	TreeNode* invertTree_iterative(TreeNode* root)
	{
		stack<TreeNode*> stk;
		if (root != nullptr)
		{
			stk.push(root);
		}
		while (!stk.empty())
		{
			TreeNode* cur = stk.top();
			stk.pop();
			if (cur != nullptr)
			{
				if (cur->right != nullptr)
				{
					stk.push(cur->right);
				}
				if (cur->left != nullptr)
				{
					stk.push(cur->left);
				}
				swap(cur->left, cur->right);
			}
		}
	}
	//这里给出的是广度优先搜索
	TreeNode* invertTree_BFS(TreeNode* root)
	{
		queue<TreeNode*> que;
		if (root != nullptr)
		{
			que.push(root);
		}
		TreeNode* cur = root;
		int k = que.size();
		while (!que.empty())
		{
			for (size_t i = 0; i < k; i++)
			{
				TreeNode* node = que.front();
				que.pop();
				swap(node->left, node->right);
				if (node->left != nullptr)
				{
					que.push(node->left);
				}
				if (node->right != nullptr)
				{
					que.push(node->right);
				}
			}
			k = que.size();
		}
		return root;
	}

	//对称二叉树 
	//思路： 可能出现以下几种情况  
	//       1 左节点为空 右节点不为空 则必不然是对称
	//       2 左结点不为空 右结点为空 也不为对称
	//       3 左结点的值与右节点的值不同 则不对称
	//       4 只有左节点与右结点的值相同是 return true
	//    采用递归的思想  当上一对结点成功判定时 进入下一对结点的判定
	//       因为是对称二叉树  所以上一对结点判定完成是 上一对结点中的左节点要选取下一对的左结点  上一对结点中的右节点要选取下一对的右结点
	//       但一段话 只处理了可以往外扩展的结点 还需要处理可以往树中心缩的结点 
	//                                              因此上一对结点中的左节点要选取下一对的右结点 上一对结点中的右节点要选取下一对的左结点 
	//        只有两端都处理完成且结果都为true 时  才可以返回true；
	bool compare_is_symmetric(TreeNode* left, TreeNode* right)
	{
		if (left != nullptr && right == nullptr)
		{
			return false;
		}
		else if (left == nullptr && right != nullptr)
		{
			return false;
		}
		else if (left == nullptr && right == nullptr)
		{
			return true;
		}
		else if (left->value != right->value)
		{
			return false;
		}
		bool outside = compare_is_symmetric(left->left, right->right);
		bool inside = compare_is_symmetric(left->right, right->left);
		return outside && inside;
	}
	bool isSymmetric(TreeNode* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		return compare_is_symmetric(root->left, root->right);
	}

	//求二叉树的最大深度问题 深度是指从根结点到叶子结点的距离
	int getDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftdepth = getDepth(root->left);
		int rightdepth = getDepth(root->right);
		return 1 + max(leftdepth, rightdepth);
	}
	int maxDepth_DFS(TreeNode* root)
	{
		int count = 1;
		if (root == nullptr)
		{
			return 0;
		}
		return getDepth(root);
	}
	// 这里运用广度优先搜索
	int maxDepth_BFS(TreeNode* root)
	{
		int count = 1;
		if (root == nullptr)
		{
			return 0;
		}
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			bool flag = false;
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left != nullptr)
				{
					que.push(cur->left);
					flag = true;
				}
				if (cur->right != nullptr)
				{
					que.push(cur->right);
					flag = true;
				}
			}
			if (flag == true)
			{
				count += 1;
			}
		}
		return count;
	}
	//求二叉树的最小深度
	//给定一个二叉树，找出其最小深度。
	//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
	//说明：叶子节点是指没有子节点的节点
	int getDepth_DFS(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int LeftDepth = getDepth_DFS(root->left);
		int RightDepth = getDepth_DFS(root->right);
		if (root->left == nullptr && root->right != nullptr)
		{
			return 1 + RightDepth;
		}
		if (root->left != nullptr && root->right == nullptr)
		{
			return 1 + LeftDepth;
		}
		return min(LeftDepth, RightDepth) + 1;
	}
	int minDepth_DFS(TreeNode* root)
	{
		return getDepth_DFS(root);
	}
	int minDepth_BFS(TreeNode* root)
	{
		queue<TreeNode*> que;
		if (root == nullptr)
		{
			return 0;
		}
		que.push(root);
		int depth = 0;
		while (!que.empty())
		{
			depth += 1;
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left)
				{
					que.push(cur->left);
				}
				if (cur->right)
				{
					que.push(cur->right);
				}
				if (cur->left == nullptr && cur->right == nullptr)
				{
					return depth;
				}
			}
		}
		return depth;
	}
	//222. 完全二叉树的节点个数
	//给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
	//完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~2h 个节点
	int count_DFS(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left=count_DFS(root->left);
		int right=count_DFS(root->right);
		return left + right + 1;
	}
	int countNodes_DFS(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return count_DFS(root);
	}
	//这里给出了广搜的代码
	int countNodes_BFS(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		queue<TreeNode*> que;
		que.push(root);
		int count = 0;
		while (!que.empty())
		{
			int size = que.size();
			count += size;
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left)
				{
					que.push(cur->left);
				}
				if (cur->right)
				{
					que.push(cur->right);
				}
			}
		}
		return count;
	}
	//257.二叉树的所有路径  这里采用了前序遍历
	void binaryTreePaths_DFS(TreeNode* root,vector<string> &ans,vector<char> &path)
	{
		path.push_back(root->value);
		if (root->left==nullptr && root->right==nullptr)
		{
			string sPath;
			for (int i = 0; i < path.size(); i++)
			{
				sPath += to_string(path[i]);
				sPath += "->";
			}
			sPath += to_string(path[path.size() - 1]);
			ans.push_back(sPath);
			return;
		}
		if (root->left)
		{
			binaryTreePaths_DFS(root->left, ans, path);
			path.pop_back();
		}
		if (root->right)
		{
			binaryTreePaths_DFS(root->right, ans, path);
			path.pop_back();
		}
	}
	vector<string> binaryTreePaths(TreeNode* root)
	{
		vector<string> ans;
		vector<char> path;
		if (root==nullptr)
		{
			return ans;
		}
		binaryTreePaths_DFS(root, ans, path);
		return ans;
	}
};



/*105. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
示例 1:
输入: preorder = [3, 9, 20, 15, 7], inorder = [9, 3, 15, 20, 7]
输出 : [3, 9, 20, null, null, 15, 7]
示例 2 :
输入 : preorder = [-1], inorder = [-1]
输出 : [-1]
提示 :
1 <= preorder.length <= 3000
inorder.length == preorder.length
- 3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列*/
class Solution105
{
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
	unordered_map<int, int> hash;
	TreeNode ans;
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int n = preorder.size();
		for (int i = 0; i < n; i++)
		{
			hash[inorder[i]] = i;
		}
		return bulit(preorder, inorder, 0, n - 1, 0, n - 1);
	}
	TreeNode* bulit(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
	/* pl表示前序树的左边界 pr表示前序树的右边界 il表示中序树的左边界 ir表示中序树的右边界*/
	{
		if (pl > pr || il > ir)
		{
			return nullptr;
		}
		int k = hash[preorder[pl]]-il ;//获取中结点的左子树的个数
		TreeNode* root = new TreeNode(preorder[pl]);
		root->left = bulit(preorder, inorder, pl + 1, pl + k, il, il + k - 1);
		root->right = bulit(preorder, inorder, pl + k + 1, pr, il + k + 1, ir);
		return root;
	}
	void cengxubianli(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		queue<TreeNode*> que;
		que.push(root);
		vector<int> ans;
		while (!que.empty())
		{
			int n = que.size();
			for (int i = 0; i < n; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left)
				{
					que.push(cur->left);
				}
				if (cur->right)
				{
					que.push(cur->right);
				}
				ans.push_back(cur->val);
			}
		}
		for (auto i : ans)
		{
			cout << i << '\t';
		}
	}
};
/*int main()
{
	Solution105 ans;
	vector<int> preorder = { 1,2,4,5,3,6,7 };
	vector<int> inorder = { 4,2,5,1,6,3,7 };
	ans.cengxubianli(ans.buildTree(preorder, inorder));
}*/


/*使用后序和中序构造树*/
class Solution106
{
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
	TreeNode* root;
	unordered_map<int, int> hash;
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		int n = inorder.size();
		for (int i = 0; i < n; i++)
		{
			hash[inorder[i]] = i;
		}
		return built(inorder, postorder, 0, n - 1, 0, n - 1);
	}
	TreeNode* built(vector<int>inorder, vector<int>postorder, int il, int ir, int pl, int pr)
		/* pl表示后序树的左边界 pr表示前序树的右边界 il表示中序树的左边界 ir表示中序树的右边界*/
	{
		if (il > ir || pl > pr)
		{
			return nullptr;
		}
		int k = hash[postorder[pr]] - il;//获取中结点的左子树的个数
		TreeNode* root = new TreeNode(postorder[pr]);
		root->left = built(inorder, postorder, il, il + k - 1, pl, pl + k - 1);//重新规定左右边界
		root->right = built(inorder, postorder, il + k + 1, ir, pl + k, pr - 1);//重新规定左右边界
		return root;
	}
	void cengxubianli(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		queue<TreeNode*> que;
		que.push(root);
		vector<int> ans;
		while (!que.empty())
		{
			int n = que.size();
			for (int i = 0; i < n; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left)
				{
					que.push(cur->left);
				}
				if (cur->right)
				{
					que.push(cur->right);
				}
				ans.push_back(cur->val);
			}
		}
		for (auto i : ans)
		{
			cout << i << '\t';
		}
	}
};
/*int main()
{
	Solution106 ans;
	vector<int> inorder = { 4,2,5,1,6,3,7 };
	vector<int> postorde = { 4,5,2,6,7,3,1 };
	ans.cengxubianli(ans.buildTree(inorder, postorde));
}*/



/*700. 二叉搜索树中的搜索
已解答
简单
相关标签
相关企业
给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null
*/
class Solution700
{
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
public:
	TreeNode* searchBST(TreeNode* root, int val)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		while (root != nullptr)
		{
			if (root->val == val)
			{
				return root;
			}
			root = root->val > val ? root->left : root->right;
		}
		return nullptr;
	}
};


//验证是否二叉搜索树
class Solution98
{
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
public:
	bool inorder_traversal_isValidBST(TreeNode* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		stack<TreeNode*> stk;
		TreeNode* cur = root;
		TreeNode* pre_x = nullptr;
		while (cur != nullptr || !stk.empty())
		{
			if (cur != nullptr)
			{
				stk.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = stk.top();
				stk.pop();
				if (pre_x != nullptr && cur->val <= pre_x->val)
				{
					return false;
				}
				pre_x = cur;
				cur = cur->right;
			}
		}
		return true;
	}
};



//二叉搜索树中的插入操作
class Solution701
{
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
public:
	TreeNode* FindNode(TreeNode* root, int key,TreeNode* &pre_cur)
	{
		TreeNode* cur = root;
		while (cur!=nullptr)
		{
			if (cur->val<key)
			{
				pre_cur = cur;
				cur = cur->right;
			}
			else if (cur->val>key)
			{
				pre_cur = cur;
				cur = cur->left;
			}
			else
			{
				return cur;
			}
		}
		return cur;
	}
	TreeNode* get_new_one(TreeNode* cur)
	{
		while (cur->right != nullptr)
		{
			cur = cur->right;
		}
		return cur;
	}
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		TreeNode* pre_cur;
		TreeNode* cur = FindNode(root, key,pre_cur);
		if (cur->left==nullptr && cur->right==nullptr)
		{
			if (pre_cur->val < key)
			{
				pre_cur->right = nullptr;
			}
			else
			{
				pre_cur->left = nullptr;
			}
		}
		else if (cur->left!=nullptr && cur->right==nullptr)
		{
			if (pre_cur->val < key)
			{
				pre_cur->right = cur->left;
			}
			else
			{
				pre_cur->left = cur->left;
			}
		}
		else if (cur->right != nullptr && cur->left==nullptr)
		{
			if (pre_cur->val < key)
			{
				pre_cur->right = cur->left;
			}
			else
			{
				pre_cur->left = cur->left;
			}
		}
		else
		{
			if (pre_cur->val < key)
			{
				pre_cur->right = get_new_one(cur);
			}
			else
			{
				pre_cur->left = get_new_one(cur);	
			}
		}
	}
};
class Solution108
{
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
public:
	TreeNode* traversal(vector<int>nums, int left, int right)//递归版本
	{
		if (left > right)
		{
			return nullptr;
		}
		int middle = left + (right - left) / 2;
		TreeNode* root = new TreeNode(nums[middle]);
		root->left = traversal(nums, left, middle - 1);
		root->right = traversal(nums, middle + 1, right);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		TreeNode* root = traversal(nums, 0, nums.size() - 1);
		return root;
	}
	TreeNode* iterative(vector<int>& nums)//迭代法版本
	{
		if (nums.size() == 0)
		{
			return nullptr;
		}
		queue<int> leftque;
		queue<int> rightque;
		queue<TreeNode*> nodeque;
		TreeNode* root = new TreeNode(0);
		nodeque.push(root);
		leftque.push(0);
		rightque.push(nums.size() - 1);
		while (!nodeque.empty())
		{
			TreeNode* cur = nodeque.front();
			nodeque.pop();
			int left = leftque.front();
			leftque.pop();
			int right = rightque.front();
			rightque.pop();
			int middle = left + (right - left) / 2;
			cur->val = nums[middle];
			if (left < middle)
			{
				cur->left = new TreeNode(0);
				nodeque.push(cur->left);
				leftque.push(left);
				rightque.push(middle - 1);
			}
			if (right > middle)
			{
				cur->right = new TreeNode(0);
				nodeque.push(cur->right);
				leftque.push(middle + 1);
				rightque.push(right);
			}
		}
		return root;
	}
	void dispaly(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			int len = que.size();
			for (int i = 0; i < len; i++)
			{
				TreeNode* cur = que.front();
				cout << cur->val << '\t';
				que.pop();
				if (cur->left != nullptr)
				{
					que.push(cur->left);
				}
				if (cur->right != nullptr)
				{
					que.push(cur->right);
				}
			}
		}
	}
};
/*int main()
{
	Solution108 ans;
	vector<int> nums = { -10, -3 , -1 ,0 ,3 ,5 ,9 };
	ans.dispaly(ans.sortedArrayToBST(nums));
	cout << endl;
	ans.dispaly(ans.iterative(nums));
}*/






struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution_
{
public:
	TreeNode* traversal(vector<int>& nums, int left, int right)
	{
		if (left >= right)
		{
			return nullptr;
		}
		int maxInsert = left;
		for (int i = left + 1; i < right; i++)
		{
			if (nums[i] > nums[maxInsert])
			{
				maxInsert = i;
			}
		}
		TreeNode* root = new TreeNode(nums[maxInsert]);
		root->left = traversal(nums, left, maxInsert);
		root->right = traversal(nums, maxInsert + 1, right);
		return root;
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums)
	{
		return traversal(nums, 0, nums.size());
	}
};










class Solution_617
{
public:
	TreeNode* mergeTrees_traversal(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == nullptr)
		{
			return root2;
		}
		if (root2 == nullptr)
		{
			return root1;
		}
		TreeNode* root = new TreeNode;
		root->val = root1->val + root2->val;
		root->left = mergeTrees_traversal(root1->left, root2->left);
		root->right = mergeTrees_traversal(root1->right, root2->right);
		return root;
	}
	TreeNode* mergeTrees_iterative(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == nullptr)
		{
			return root2;
		}
		if (root2 == nullptr)
		{
			return root1;
		}
		queue<TreeNode*> que;
		que.push(root1);
		que.push(root2);
		while (!que.empty())
		{
			TreeNode* temp1 = que.front(); que.pop();
			TreeNode* temp2 = que.front(); que.pop();
			temp1->val += temp2->val;
			if (temp1->left && temp2->left)
			{
				que.push(temp1->left);
				que.push(temp2->left);
			}
			if (temp1->right && temp2->right)
			{
				que.push(temp1->right);
				que.push(temp2->right);
			}
			if (!temp1->left && temp2->left)
			{
				temp1->left = temp2->left;
			}
			if (!temp1->right && temp2->right)
			{
				temp1->right = temp2->right;
			}
		}
		return root1;
	}
};