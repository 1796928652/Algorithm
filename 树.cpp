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
	//  ǰ�����   ��������ǰ�ǰ��д��  ������   �ݹ�д��. 
	//�����ҵ���˼�� �ȴ��������ٴ��������������������  
	//                       ������������ʱ�����������������Խ�����������һ�������������ٰ��������ҵ�˳������
	//                       ��������������ʱ��������������Ҳ���Խ�����������һ�������������ٰ��������ҵ�˳������
	void traversal(TreeNode* cur, vector<int>& vec)
	{
		if (cur == nullptr)
		{
			return;
		}
		vec.push_back(cur->value); //��
		traversal(cur->left, vec); //��
		traversal(cur->right, vec); //��
	}
	vector<int> preorder_traversal(TreeNode* root)
	{
		vector<int> ans;
		traversal(root, ans);
		return ans;
	}
	//ǰ��ĵ���д��
	// ��Ϊ�ǰ��������ҵ�˳��
	//  ����һ·��������������ʱ�� �н��û��˵ ֱ�ӽ���ֵ����ans
	//  �����ڶ����������� �ҽ��ֻ�ܵ����㴦�������ֵ�����  
	//     ��ô�����������֧���ҽڵ���Ҫ���� ���ȷ���䴦��˳���أ�
	// �����뵽ջ�� ����ջ������ �Ƚ���� ������һ·���� �����������ҽ����ջ ��ڵ����ջ ���ȴ�����ڵ� ��ô����ڵ㴦�����ʱ ��ջԪ��һһ��������  ��ɽ���ҽ��Ĵ���˳������ 
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

	//��������ĵݹ�д��  ������˳��
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
	//�������   ������
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
	//�����������������
	// ��Ϊ��һ��һ����� ������Ҫһ����������˳�򱣴�һ���е�ÿһ����� ͬʱ���������������չ�뵯�����
	//  �����뵽�����ö�����ģ����һ����
	//   �Ե�һ�����û�����Һ��������  �����������׽��
	//   �ٶ���һ����д��� ��������е�ͷԪ�ؿ��������Һ��ӵĻ�������˳�������� ���ҽ�ͷԪ�ص�ָ���ֵ����ans�� ���ɾ��ͷ ���û�к��ӵĻ����������
	//  ����ѭ�����������ս���� ������ʱ û��һ�����Ӵ������ ����Ϊ�� ���˳�ѭ��
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
	//��ת������
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
	//����������ǹ����������
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

	//�Գƶ����� 
	//˼·�� ���ܳ������¼������  
	//       1 ��ڵ�Ϊ�� �ҽڵ㲻Ϊ�� ��ز�Ȼ�ǶԳ�
	//       2 ���㲻Ϊ�� �ҽ��Ϊ�� Ҳ��Ϊ�Գ�
	//       3 �����ֵ���ҽڵ��ֵ��ͬ �򲻶Գ�
	//       4 ֻ����ڵ����ҽ���ֵ��ͬ�� return true
	//    ���õݹ��˼��  ����һ�Խ��ɹ��ж�ʱ ������һ�Խ����ж�
	//       ��Ϊ�ǶԳƶ�����  ������һ�Խ���ж������ ��һ�Խ���е���ڵ�Ҫѡȡ��һ�Ե�����  ��һ�Խ���е��ҽڵ�Ҫѡȡ��һ�Ե��ҽ��
	//       ��һ�λ� ֻ�����˿���������չ�Ľ�� ����Ҫ������������������Ľ�� 
	//                                              �����һ�Խ���е���ڵ�Ҫѡȡ��һ�Ե��ҽ�� ��һ�Խ���е��ҽڵ�Ҫѡȡ��һ�Ե����� 
	//        ֻ�����˶���������ҽ����Ϊtrue ʱ  �ſ��Է���true��
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

	//������������������� �����ָ�Ӹ���㵽Ҷ�ӽ��ľ���
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
	// �������ù����������
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
	//�����������С���
	//����һ�����������ҳ�����С��ȡ�
	//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
	//˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ�
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
	//222. ��ȫ�������Ľڵ����
	//����һ�� ��ȫ������ �ĸ��ڵ� root ����������Ľڵ������
	//��ȫ������ �Ķ������£�����ȫ�������У�������ײ�ڵ����û�����⣬����ÿ��ڵ������ﵽ���ֵ������������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�����ײ�Ϊ�� h �㣬��ò���� 1~2h ���ڵ�
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
	//��������˹��ѵĴ���
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
	//257.������������·��  ���������ǰ�����
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



/*105. ��ǰ��������������й��������
���������������� preorder �� inorder ������ preorder �Ƕ���������������� inorder ��ͬһ����������������빹�����������������ڵ㡣
ʾ�� 1:
����: preorder = [3, 9, 20, 15, 7], inorder = [9, 3, 15, 20, 7]
��� : [3, 9, 20, null, null, 15, 7]
ʾ�� 2 :
���� : preorder = [-1], inorder = [-1]
��� : [-1]
��ʾ :
1 <= preorder.length <= 3000
inorder.length == preorder.length
- 3000 <= preorder[i], inorder[i] <= 3000
preorder �� inorder �� ���ظ� Ԫ��
inorder �������� preorder
preorder ��֤ Ϊ��������ǰ���������
inorder ��֤ Ϊ�������������������*/
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
	/* pl��ʾǰ��������߽� pr��ʾǰ�������ұ߽� il��ʾ����������߽� ir��ʾ���������ұ߽�*/
	{
		if (pl > pr || il > ir)
		{
			return nullptr;
		}
		int k = hash[preorder[pl]]-il ;//��ȡ�н����������ĸ���
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


/*ʹ�ú������������*/
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
		/* pl��ʾ����������߽� pr��ʾǰ�������ұ߽� il��ʾ����������߽� ir��ʾ���������ұ߽�*/
	{
		if (il > ir || pl > pr)
		{
			return nullptr;
		}
		int k = hash[postorder[pr]] - il;//��ȡ�н����������ĸ���
		TreeNode* root = new TreeNode(postorder[pr]);
		root->left = built(inorder, postorder, il, il + k - 1, pl, pl + k - 1);//���¹涨���ұ߽�
		root->right = built(inorder, postorder, il + k + 1, ir, pl + k, pr - 1);//���¹涨���ұ߽�
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



/*700. �����������е�����
�ѽ��
��
��ر�ǩ
�����ҵ
����������������BST���ĸ��ڵ� root ��һ������ֵ val��
����Ҫ�� BST ���ҵ��ڵ�ֵ���� val �Ľڵ㡣 �����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻� null
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


//��֤�Ƿ����������
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



//�����������еĲ������
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
	TreeNode* traversal(vector<int>nums, int left, int right)//�ݹ�汾
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
	TreeNode* iterative(vector<int>& nums)//�������汾
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