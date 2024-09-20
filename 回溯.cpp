#include<vector>
#include<set>
#include<string>
#include <algorithm>
#include<map>
#include <unordered_set>
#include<unordered_map>
using namespace std;

//����������ʵ�����ϻ���һ������ö��
//ֻ�����ܶ������õ�����forѭ�����ѽ�� ���Ի���Ӧ�˶���

/*
* ����Ӽ������������⡢�ָ�����ĵ������Ӽ����ռ����νṹ���������нڵ�Ľ����
��                                          ������⡢�ָ��������ռ����νṹ��Ҷ�ӽڵ�Ľ����
*/



//�������
/*
*	���˾����������������Բο���״ͼ
*	�õݹ��������ȵ����� ��for����ɹ�ȵ�����
*/
class Solution_77
{
public:
	vector<vector<int>> ans;
	vector<int> path;
	void backtracking(int m, int n, int k)
	{
		if (path.size() == k)
		{
			ans.push_back(path);
		}
		for (int i = m; i <= n; i++)//���������һ����֦�Ż� ���Բο���ͼ  i<= n - ( k - path.size() ) + 1
		{

			path.push_back(i);
			backtracking(i + 1, n, k);
			path.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k)
	{
		backtracking(1, n, k);
		return ans;
	}
};
/*
int main()
{
	Solution_77 sol;
	int n = 4;
	int k = 2;
	for (auto i : sol.combine(4, 4))
	{
		for (auto j : i)
		{
			cout << j << '\t';
		}
		cout << endl;
	}
}
*/





class Solution_216
{
public:
	vector<vector<int>> ans;
	vector<int> path;
	int get_sum(vector<int> path)
	{
		int sum = 0;
		for (auto i : path)
		{
			sum += i;
		}
		return sum;
	}
	void backtracking(int m, int n, int k, vector<bool>& used)//���������һ����֦�Ż� ���Բο���ͼ  i<= n - ( k - path.size() ) + 1
	{
		if (get_sum(path) == n && path.size() == k)
		{
			ans.push_back(path);
			return;
		}
		for (int i = m; i < 10; i++)
		{
			if (used[i] == true)
			{
				continue;
			}
			used[i] = true;
			path.push_back(i);
			backtracking(i + 1, n, k, used);
			path.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<bool> used(10, false);
		backtracking(1, n, k, used);
		return ans;
	}
};
/*
int main()
{
	int k = 3;
	int n = 9;
	Solution_216 sol;
	for (auto i : sol.combinationSum3(k, n))
	{
		for (auto j : i)
		{
			cout << j << '\t';
		}
		cout << endl;
	}
}
*/

class Solution_17
{
public:
	vector<string> ans;
	map<char, string> hash = {
		{'2',"abc"},
		{'3',"def"},
		{'4',"ghi"},
		{'5',"jkl"},
		{'6',"mno"},
		{'7',"pqrs"},
		{'8',"tuv"},
		{'9',"wxyz"}
	};
	string path;
	void backtracking(int m, string digits)
	{
		int len = digits.size();
		if (m == len)
		{
			ans.push_back(path);
			return;
		}
		char temp = digits[m];
		string str = hash[temp];
		for (int i = 0; i < str.size(); i++)
		{
			path.push_back(str[i]);
			backtracking(m + 1, digits);
			path.pop_back();
		}
	}
	vector<string> letterCombinations(string digits)
	{
		backtracking(0, digits);
		return ans;
	}
};
/*
int main()
{
	string digits = "2";
	Solution_17 sol;
	for (auto i : sol.letterCombinations(digits))
	{
		cout << i << endl;
	}
}
*/




class Solution_39
{
public:
	vector<vector<int>> ans;
	vector<int> path;
	int get_sum(vector<int> path)
	{
		int sum = 0;
		for (auto i : path)
		{
			sum += i;
		}
		return sum;
	}
	void backtracking(vector<int>& candidates, int target, int m)
	{
		if (get_sum(path) == target)
		{
			ans.push_back(path);
			return;
		}
		else if (get_sum(path) > target)
		{
			return;
		}
		for (int i = m; i < candidates.size(); i++)
		{
			path.push_back(candidates[i]);
			backtracking(candidates, target, i);//���ﲻ�ü�1 ��Ϊ�����ظ�ѡ
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		backtracking(candidates, target, 0);
		return ans;
	}
};
/*
int main()
{
	vector<int> candidates = { 2,3,6,7 };
	int target = 7;
	Solution_39 sol;
	for (auto i : sol.combinationSum(candidates, target))
	{
		for (auto j : i)
		{
			cout << j << '\t';
		}
		cout << endl;
	}
}
*/




class Solution_40
{
public:
	vector<vector<int>> ans;
	vector<int> path;
	int get_sum(vector<int>path)
	{
		int sum = 0;
		for (auto i : path)
		{
			sum += i;
		}
		return sum;
	}
	void backtracking(int m, vector<int>& candidates, int target, vector<bool>& used)
	{
		if (get_sum(path) == target)
		{
			ans.push_back(path);
			return;
		}
		else if (get_sum(path) > target)
		{
			return;
		}
		for (int i = m; i < candidates.size(); i++)
		{
			if (i > 0 && used[i - 1] == false && candidates[i] == candidates[i - 1])
			{
				continue;
			}
			used[i] = true;
			path.push_back(candidates[i]);
			backtracking(i + 1, candidates, target, used);
			path.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		vector<bool> used(candidates.size(), false);
		sort(candidates.begin(), candidates.end());
		backtracking(0, candidates, target, used);
		return ans;
	}
};
/*
int main()
{
	vector<int> candidates = { 10,1,2,7,6,1,5 };
	Solution_40 sol;
	for (auto& i : sol.combinationSum2(candidates, 8))
	{
		for (auto j : i)
		{
			cout << j << '\t';
		}
		cout << endl;
	}
}
*/



class Solution__131
{
public:
	vector<vector<string>> ans;
	vector<string> path;
	bool IsHuiWen(const string& str, int start, int end)
	{
		for (int i = start, j = end; i < j; i++, j--)
		{
			if (str[i] != str[j])
			{
				return false;
			}
		}
		return true;
	}
	void backtracking(string s, int index)
	{
		int len = s.size();
		if (index >= s.size())
		{
			ans.push_back(path);
			return;
		}
		for (int i = index; i < len; i++)
		{
			if (IsHuiWen(s, index, i))
			{
				path.push_back(s.substr(index, i - index + 1));
			}
			else
			{
				continue;
			}
			backtracking(s, i + 1);
			path.pop_back();
		}
	}
	vector<vector<string>> partition(string s)
	{
		backtracking(s, 0);
		return ans;
	}
};

/*
int main()
{
	Solution__131 sol;
	for (auto& i : sol.partition("aaab"))
	{
		for (auto& j : i)
		{
			cout << j << '\t';
		}
		cout << endl;
	}
}
*/





class Solution_93
{
public:
	vector<string> ans;
	bool IsValid(const string& s, int start, int end)//�ж�����ӵ������Ƿ�Ϸ�
	{
		if (start > end)
		{
			return false;
		}
		if (s[start] == '0' && start != end)
		{
			return false;
		}
		int num = 0;
		for (int i = start; i <= end; i++)
		{
			if (s[i] > '9' || s[i] < '0')
			{
				return false;
			}
			num = num * 10 + s[i] - '0';
			if (num >= 256)
			{
				return false;
			}
		}
		return true;
	}
	void backtracking(string& s, int index, int pointNum)
	{
		int len = s.size();
		if (pointNum == 3)//ֻҪ�����3��'.'��ô������־ͷֳ����ĸ�����
		{
			if (IsValid(s, index, len - 1))//�ж����һ�������Ƿ�Ϸ�
			{
				ans.push_back(s);
			}
			return;
		}
		for (int i = index; i < s.size(); i++)
		{
			if (IsValid(s, index, i))//�жϵ�ǰ�����Ƿ�Ϸ�
			{
				pointNum++;
				s.insert(s.begin() + i + 1, '.');
				backtracking(s, i + 2, pointNum);//ע�������'.'��
				pointNum--;
				s.erase(s.begin() + i + 1);
			}
			else
			{
				break;
			}
		}
	}
	vector<string> restoreIpAddresses(string s)
	{
		backtracking(s, 0, 0);
		return ans;
	}
};
/*
int main()
{
	Solution sol;
	for (auto &i : sol.restoreIpAddresses("25525511135"))
	{
		cout << i << endl;
	}
}
*/



//�Ӽ����ռ����νṹ���������нڵ�Ľ��
class Solution__78//�õ�һ�����ϵ������Ӽ�
{
public:
	vector<vector<int>> ans;
	vector<int> path;
	void backtracking(vector<int>& nums, int index)
	{
		ans.push_back(path);
		if (index >= nums.size())
		{
			return;
		}
		for (int i = index; i < nums.size(); i++)
		{
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}

	}
	vector<vector<int>> subsets(vector<int>& nums)
	{
		backtracking(nums, 0);
		return ans;
	}
};

class Solution__78__1 //������ö��
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> ans;
		int length = nums.size();
		vector<int> s;
		for (int i = 0; i < (1 << length); i++)
		{
			int j = i;
			int k = 0;
			while (j != 0)
			{
				if ((j & 1) == 1)
				{
					s.push_back(nums[k]);
				}
				j = (j >> 1);
				k += 1;
			}
			ans.push_back(s);
			s.clear();
		}
		return ans;
	}
};
/*
int main()
{
	vector<int> nums = { 1,2,3 };
	Solution__78 sol;
	for (auto i : sol.subsets(nums))
	{
		for (auto j : i)
		{
			cout << j <<'\t';
		}
		cout << endl;
	}
}
*/




class Solution_90
{
private:
	vector<vector<int>> ans;
	vector<int> path;
	void backtracking(vector<int>& nums, int start, vector<bool>& used)
	{
		ans.push_back(path);
		for (int i = start; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
			{
				continue;
			}
			path.push_back(nums[i]);
			used[i] = true;
			backtracking(nums, i + 1, used);
			used[i] = false;
			path.pop_back();
		}
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		vector<bool> used(nums.size(), false);
		sort(nums.begin(), nums.end());
		backtracking(nums, 0, used);
		return ans;
	}
};
/*
int main()
{
	vector<int> nums = { 1,2,2 };
	Solution_90 sol;
	for (auto i : sol.subsetsWithDup(nums))
	{
		for (auto j : i)
		{
			cout << j << '\t';
		}
		cout << endl;
	}
}
*/


/*
491. �ǵݼ�������
����һ���������� nums ���ҳ����������и������в�ͬ�ĵ��������У������������� ����������Ԫ�� ������԰� ����˳�� ���ش𰸡�
�����п��ܺ����ظ�Ԫ�أ����������������ȣ�Ҳ���������������е�һ���������
*/
class Solution_491
{
public:
	vector<vector<int>> ans;
	vector<int> path;
	void backtracking(int start, vector<int>& nums)
	{
		if (path.size() >= 2)
		{
			ans.push_back(path);
		}
		unordered_set<int> set;
		for (int i = start; i < nums.size(); i++)
		{
			if (set.find(nums[i]) != set.end())
			{
				continue;
			}
			if (!path.empty() && nums[i] < path.back())
			{
				continue;
			}
			set.insert(nums[i]);
			path.push_back(nums[i]);
			backtracking(i + 1, nums);
			path.pop_back();
		}
	}
	vector<vector<int>> findSubsequences(vector<int>& nums)
	{
		backtracking(0, nums);
		return ans;
	}
};
/*
int main()
{
	vector<int> nums = { 4,7,6,7 };
	Solution_491 sol;
	for (auto i : sol.findSubsequences(nums))
	{
		for (auto j : i)
		{
			cout << j << '\t';
		}
		cout << endl;
	}
}
*/


//ȫ��������
class Solution_47
{
public:
	vector<vector<int>> ans;
	vector<int> path;
	void backtracking(vector<int>& nums, vector<bool>& used)
	{
		int len = nums.size();
		if (path.size() == len)
		{
			ans.push_back(path);
			return;
		}
		for (int i = 0; i < len; i++)
		{
			if (used[i] == true)
			{
				continue;
			}
			used[i] = true;
			path.push_back(nums[i]);
			backtracking(nums, used);
			path.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return ans;
	}
};



class Solution_47_1// ͨ��set��ȥ�� 
{
public:
	vector<vector<int>> ans;
	vector<int> path;
	set<vector<int>>  res;//����ͨ��set������ 
	void backtracking(vector<int>& nums, vector<bool>& used)
	{
		int len = nums.size();
		if (path.size() == len)
		{
			res.insert(path);
			return;
		}
		for (int i = 0; i < len; i++)
		{
			if (used[i] == true)
			{
				continue;
			}
			used[i] = true;
			path.push_back(nums[i]);
			backtracking(nums, used);
			used[i] = false;
			path.pop_back();
		}
	}
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		for (auto& i : res)
		{
			ans.push_back(i);
		}
		return ans;
	}
private:
};
class Solution_47_2
{
public:
	vector<vector<int>> ans;
	vector<int> path;
	void backtracking(vector<int>& nums, vector<bool>& used)
	{
		if (path.size() == nums.size())
		{
			ans.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == true)//used[i-1]==true ����ɾȥ ��������{1��1��1}
			{
				continue;
			}
			if (used[i] == false)
			{
				used[i] = true;
				path.push_back(nums[i]);
				backtracking(nums, used);
				used[i] = false;
				path.pop_back();
			}
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());//����һ��Ҫ���� ��ΪΪ������ȥ�ش��� nums[i]=nums[i-1]����
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return ans;
	}
};
/*
int main()
{
	Solution_47_2 sol;
	vector<int> nums = { 1,1,1 };
	for (auto i : sol.permuteUnique(nums))
	{
		for (auto j : i)
		{
			cout << j << '\t';
		}
		cout << endl;
	}
}
*/





/*
332. ���°����г�
����һ�ݺ����б� tickets ������ tickets[i] = [fromi, toi] ��ʾ�ɻ������ͽ���Ļ����ص㡣����Ը��г̽������¹滮����
������Щ��Ʊ������һ���� JFK������Ϲ��ʻ��������������������Ը��г̱���� JFK ��ʼ��������ڶ�����Ч���г̣����㰴�ֵ����򷵻���С���г���ϡ�
���磬�г�["JFK", "LGA"] ��["JFK", "LGB"] ��Ⱦ͸�С���������ǰ��
�ٶ����л�Ʊ���ٴ���һ�ֺ�����г̡������еĻ�Ʊ ���붼��һ�� �� ֻ����һ��
*/
class Solution_332
{
public:
	vector<string> ans;
	unordered_map<string, map<string, int>> hash;//��һ��string������ɵ� map<Ŀ�ĵأ����Է���Ŀ�ĵ�ʣ�ຽ�����> 
	bool backtracking(vector<vector<string>>& tickets)
	{
		if (ans.size() == tickets.size() + 1)
		{
			return true;
		}
		string temp = ans.back();
		if (hash.find(temp) != hash.end())
		{
			for (pair<const string, int>& i : hash[temp])
			{
				if (i.second == 0)
				{
					continue;
				}
				i.second--;
				ans.push_back(i.first);
				if (backtracking(tickets))
				{
					return true;
				}
				ans.pop_back();
				i.second++;
			}
		}
		return false;
	}
	vector<string> findItinerary(vector<vector<string>>& tickets)
	{
		ans.push_back("JFK");
		for (auto& i : tickets)
		{
			hash[i[0]][i[1]]++;
		}
		backtracking(tickets);
		return ans;
	}
};
/*
int main()
{
	vector<vector<string>> tickets = { {"MUC","LHR" }, {"JFK", "MUC"},{"SFO", "SJC"},{"LHR", "SFO"} };
	Solution_332 sol;
	for (auto& i : sol.findItinerary(tickets))
	{
		cout << i << endl;
	}
}
*/




/*
51. N �ʺ�
���չ�������Ĺ��򣬻ʺ���Թ�����֮����ͬһ�л�ͬһ�л�ͬһб���ϵ����ӡ�
n �ʺ����� �о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
����һ������ n ���������в�ͬ�� n �ʺ����� �Ľ��������
ÿһ�ֽⷨ����һ����ͬ�� n �ʺ����� �����ӷ��÷������÷����� 'Q' �� '.' �ֱ�����˻ʺ�Ϳ�λ
*/
class Solution_51
{
public:
	vector<vector<string>> ans;
	bool IsVaild(int row, int column, vector<string>& vec, int n)//�޸��� �� б Ϊtrue
	{
		for (int i = 0; i < row; i++)
		{
			if (vec[i][column] == 'Q')
			{
				return false;
			}
		}
		for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
		{
			if (vec[i][j] == 'Q')
			{
				return false;
			}
		}
		for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
		{
			if (vec[i][j] == 'Q')
			{
				return false;
			}
		}
		return true;
	}
	void backtracking(int n, int row, vector<string>& vec)
	{
		if (row == n)
		{
			ans.push_back(vec);
			return;
		}
		for (int col = 0; col < n; col++)
		{
			if (IsVaild(row, col, vec, n))
			{
				vec[row][col] = 'Q';
				backtracking(n, row + 1, vec);
				vec[row][col] = '.';
			}
		}
	}
	vector<vector<string>> solveNQueens(int n)
	{
		vector<string> vec(n, string(n, '.'));
		backtracking(n, 0, vec);
		return ans;
	}
};
/*
int main()
{
	Solution_51 sol;
	for (auto& i : sol.solveNQueens(4))
	{
		for (auto &j : i)
		{
			cout << j << '\t';
		}
		cout << endl;
	}
}
*/