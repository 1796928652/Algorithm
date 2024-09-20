#include<iostream>
#include<string>
#include<unordered_map>
#include<math.h>
#include<vector>
#include<algorithm>
#include<limits>
#include<limits.h>
#include<set>
#include<map>
#include<queue>
#include<list>
#include <unordered_set>
using namespace std;
// Prim �㷨
/*
int main()
{
	int v, e;
	int x, y, k;
	cin >> v >> e;
	vector<vector<int>> grid(v + 1, vector<int>(v + 1, INT_MAX));
	while (e--)
	{
		cin >> x >> y >> k;
		grid[x][y] = k;
		grid[y][x] = k;
	}
	/*
	* ���Ĳ�������
	* 1.�ҵ�������������С�Ľڵ�
	* 2.���ýڵ���뵽��������
	* 3.����ʣ��ڵ㵽�������ľ���
	*/
/*
	vector<int> minDist(v + 1, INT_MAX); //���нڵ㵽��С����������С����
	vector<bool> IsInTree(v + 1, false); //�ж��Ƿ�����������
	vector<int> path;//����·��
	for (int i = 1; i < v; i++)
	{
		int cur = -1;
		for (int j = 1; j <= v; j++)
		{
			if (!IsInTree[j]&& (cur==-1 || minDist[j]<minDist[cur]))//����cur==-1 ��Ĭ�������ĵ�һ���ڵ������Ҫѡȡ�ĵ������ıȽϴ�С�������õ���Ҫѡȡ�ĵ�
			{
				cur = j;
			}
		}
		IsInTree[cur] = true;
		path.push_back(cur);
		for (int j = 1; j <= v; j++)
		{
			if (!IsInTree[j] && minDist[j]>grid[cur][j])
			{
				minDist[j] = grid[cur][j];
			}
		}
	}
	for (auto i : path)
	{
		cout << i << '\t';
	}
	int result = 0;
	for (auto i : minDist)
	{
		result += i;
	}
	cout << result<<endl;
}
*/





/*
* kruskal�ĺ���
* 1.ÿ���ҵ�Ȩֵ��С�Ҳ���ʹ��С���������ֻ��ı�
* 2.����ñ�
*/
/*ps���ҵ�Ȩֵ��С�ı�ͨ������������
	  �ҵ�����ʹԭ�����ֻ��ı� �����Ͽ���ͨ�����������ж� �������������Ӵ�
	  �������ʹ�ò��鼯
	  ʹ�ò��鼯��˼·��
			����������ʱ����ʹһ��Ϊ���ڵ�һ��ΪҶ�ڵ� ���ڵ�ָ��Ҷ�ڵ�
			��ô�����һ���ڵ�����Ȼԭ���ڵ�ָ��Ҷ�ڵ�
			������һ�����ǿ���ԭ���ڵ�ָ����
	  ����ʵ�ֿ�����һλ����ʵ��
*/
struct edge
{
	int p1, p2, val;//p1��p2�ֱ��ʾ������val��ʾȨֵ
};
class Kruskal_solution
{
public:
	static bool cmp(edge x, edge y)
	{
		return x.val < y.val;
	}
	int FindFather(int v);
	void getedge();//����ߵ�����
	void get_n();//�����м�����
	void get_m();//�����м�����
	int kruskal();
	Kruskal_solution();
	~Kruskal_solution();

private:
	vector<edge> e;
	vector<int> father;
	int n = 0, m = 0;//n��ʾ�㣬m��ʾ��
};

void Kruskal_solution::getedge()
{
	for (int i = 0; i < m; i++)
	{
		edge temp;
		cin >> temp.p1 >> temp.p2 >> temp.val;
		e.push_back(temp);
	}
}
void Kruskal_solution::get_n()
{
	cin >> n;
}
void Kruskal_solution::get_m()
{
	cin >> m;
}
int Kruskal_solution::FindFather(int v)
{
	if (father[v] == v)
	{
		return v;
	}
	else
	{
		int F = FindFather(father[v]);
		father[v] = F;
		return F;
	}
}
int Kruskal_solution::kruskal()
{
	int result = 0;
	int nums_edge = 0;
	for (int i = 0; i < n; i++)
	{
		father.push_back(i);
	}
	sort(e.begin(), e.end(), cmp);
	for (int i = 0; i < m; i++)
	{
		int a = FindFather(e[i].p1);
		int b = FindFather(e[i].p2);
		if (a != b)
		{
			result += e[i].val;
			nums_edge++;
			father[a] = b;
			if (nums_edge == n - 1)
			{
				break;
			}
		}
	}
	return result;
}
Kruskal_solution::Kruskal_solution() {}
Kruskal_solution::~Kruskal_solution() {}
/*
int main()
{
	Kruskal_solution dij;
	kru.get_n();
	kru.get_m();
	kru.getedge();
	cout << kru.kruskal();
}
*/










/*dijkstra�㷨
* ȡ��ԭ�����δ���ʽڵ� �γ�һ��С·����ͼ��  //�������ʹ�ö�������ȡ�����δ���ʽڵ�
* ������ڵ���Ϊ���ʹ�
* ����δ���ʽڵ㵽Դ��ľ��� 
/*int main()
{
	int n, m, p1, p2, val;
	cin >> n >> m;
	vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
	for (int i = 0; i < m; i++)
	{
		cin >> p1 >> p2 >> val;
		grid[p1][p2] = val;
	}
	vector<int> minDist(n + 1, INT_MAX);//����ڵ㵽Դ�����̾���
	vector<bool> visited(n + 1, false);//�Ƿ���ʹ��ڵ�
	minDist[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int minval = INT_MAX;
		int cur = 1;
		for (int v = 1; v <= n; v++)
		{
			if (!visited[v] && minDist[v] < minval)
			{
				minval = minDist[v];
				cur = v;
			}
		}
		visited[cur] = true;
		for (int v = 1; v <= n; v++)
		{
			if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v])
			{
				minDist[v] = minDist[cur] + grid[cur][v];
			}
		}
	}
	if (minDist.back() == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << minDist.back() << endl;
	}
}*/






//���ö������dijkstra
class mycomparison_dijk
{
public:
	bool operator()(const pair<int, int>& lhs, const pair<int, int>rhs)
	{
		return lhs.second > rhs.second;
	}
};

struct dij_edge
{
	int to;//toĳ�ڵ�
	int val;//�ߵ�Ȩ��
	dij_edge(int t,int w):to(t),val(w){}
};
//int main()
//{
//	int n, m,p1, p2, val;
//	cin >> n >> m;
//
//	vector<list<dij_edge>> grid(n + 1);
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> p1 >> p2 >> val;
//		grid[p1].push_back(dij_edge(p2, val));
//	}
//
//	int start = 1;
//	int end = n;
//
//	vector<int> minDist(n + 1, INT_MAX);
//	vector<bool> visited(n + 1, false);
//	priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison_dijk> que;
//	que.push(pair<int, int>(start, 0));
//	minDist[start] = 0;
//
//	while (!que.empty())
//	{
//		//��һ�� ѡһ����Դ�������δ�����ʹ��Ľڵ�
//		pair<int, int> cur = que.top();
//		que.pop();
//		if (visited[cur.first])
//		{
//			continue;
//		}
//
//		//�ڶ��� ��Ǹýڵ�Ϊ���ʹ�
//		visited[cur.first] = true;
//
//		//����δ���ʽӴ��㵽Դ��ľ���
//		for (dij_edge edge:grid[cur.first])
//		{
//			if (!visited[edge.to] && minDist[cur.first]+edge.val<minDist[edge.to])
//			{
//				minDist[edge.to] = minDist[cur.first] + edge.val;
//				que.push(pair<int, int>(edge.to, minDist[edge.to]));
//			}
//		}
//	}
//
//	if (minDist[end]==INT_MAX)
//	{
//		cout << -1 << endl;
//	}
//	else
//	{
//		cout << minDist[end] << endl;
//	}
//
//}






/*200. ��������
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ����� / ����ֱ���������ڵ�½�������γɡ�
���⣬����Լ��������������߾���ˮ��Χ*/
class Solution_200
{
public:
	void dfs(vector<vector<char>>& grid, int r, int c)
	{
		int nr = grid.size();
		int nc = grid[0].size();
		grid[r][c] = '0';
		if (r - 1 >= 0 && grid[r - 1][c] == '1') { dfs(grid, r - 1, c); }
		if (r + 1 < nr && grid[r + 1][c] == '1') { dfs(grid, r + 1, c); }
		if (c + 1 < nc && grid[r][c + 1] == '1') { dfs(grid, r, c + 1); }
		if (c - 1 >= 0 && grid[r][c - 1] == '1') { dfs(grid, r, c - 1); }
	}
	int numIslands(vector<vector<char>>& grid)
	{
		int nr = grid.size();
		int nc = grid[0].size();
		if (!nr)
		{
			return 0;
		}
		int nums_land = 0;
		for (int i = 0; i < nr; i++)
		{
			for (int j = 0; j < nc; j++)
			{
				if (grid[i][j] == '1')
				{
					++nums_land;
					dfs(grid, i, j);
				}
			}
		}
		return nums_land;
	}
};



/*463. ������ܳ�
����һ�� row x col �Ķ�ά�����ͼ grid �����У�grid[i][j] = 1 ��ʾ½�أ� grid[i][j] = 0 ��ʾˮ��
�����еĸ��� ˮƽ�ʹ�ֱ �����������Խ��߷�������������������ˮ��ȫ��Χ��������ǡ����һ�����죨����˵��һ��������ʾ½�صĸ���������ɵĵ��죩��
������û�С������������� ָˮ���ڵ����ڲ��Ҳ��͵�����Χ��ˮ�������������Ǳ߳�Ϊ 1 �������Ρ�����Ϊ�����Σ��ҿ�Ⱥ͸߶Ⱦ������� 100 ���������������ܳ�
*/
class Solution_463 {
public:
	int fun(vector<vector<int>>& grid, int r, int c)
	{
		int count = 0;
		int nr = grid.size();
		int nc = grid[0].size();
		if (c == 0 || grid[r][c - 1] == 0) { count++; }
		if (c == nc - 1 || grid[r][c + 1] == 0) { count++; }
		if (r == 0 || grid[r - 1][c] == 0) { count++; }
		if (r == nr - 1 || grid[r + 1][c] == 0) { count++; }
		return count;
	}
	int islandPerimeter(vector<vector<int>>& grid)
	{
		int nr = grid.size();
		int nc = grid[0].size();
		int ans = 0;
		for (int i = 0; i < nr; i++)
		{
			for (int j = 0; j < nc; j++)
			{
				if (grid[i][j] == 1)
				{
					ans += fun(grid, i, j);
				}
			}
			cout << endl;
		}
		return ans;
	}
};
/*int main()
{
	vector<vector<int>> grid = {
		{0,1,0,0},
		{1,1,1,0},
		{0,1,0,0},
		{1,1,0,0}
	};
	Solution_463 sol;
	cout << sol.islandPerimeter(grid);
}*/



/*695. �����������
����һ����СΪ m x n �Ķ����ƾ��� grid ��
���� ����һЩ���ڵ� 1 (��������)���ɵ���ϣ�����ġ����ڡ�Ҫ������ 1 ������ ˮƽ������ֱ���ĸ������� ���ڡ�����Լ��� grid ���ĸ���Ե���� 0������ˮ����Χ�š�
���������ǵ���ֵΪ 1 �ĵ�Ԫ�����Ŀ��
���㲢���� grid �����ĵ�����������û�е��죬�򷵻����Ϊ 0
*/
class Solution_695
{
public:
	int dfs(vector<vector<int>>& grid, int r, int c)
	{
		int count = 1;
		int nr = grid.size();
		int nc = grid[0].size();
		grid[r][c] = 0;
		if (r - 1 >= 0 && grid[r - 1][c] == 1) { count += dfs(grid, r - 1, c); }
		if (r + 1 < nr && grid[r + 1][c] == 1) { count += dfs(grid, r + 1, c); }
		if (c - 1 >= 0 && grid[r][c - 1] == 1) { count += dfs(grid, r, c - 1); }
		if (c + 1 < nc && grid[r][c + 1] == 1) { count += dfs(grid, r, c + 1); }
		return count;
	}
	int maxAreaOfIsland(vector<vector<int>>& grid)
	{
		int nr = grid.size();
		int nc = grid[0].size();
		int ans = 0;
		for (int i = 0; i < nr; i++)
		{
			for (int j = 0; j < nc; j++)
			{
				int temp = 0;
				if (grid[i][j] == 1)
				{
					temp = dfs(grid, i, j);
				}
				ans = max(ans, temp);
			}
		}
		return ans;
	}
};
/*
int main()
{
	vector<vector<int>> grid = {
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}
	};
	Solution_695 sol;
	cout << sol.dfs(grid, 1, 7) << endl;
	cout << sol.maxAreaOfIsland(grid);
}
*/



/*
827. ����˹���
����һ����СΪ n x n �����ƾ��� grid ����� ֻ�ܽ�һ�� 0 ��� 1 ��
����ִ�д˲�����grid �����ĵ�������Ƕ��٣�
���� ��һ���ϡ��¡������ĸ����������� 1 �γɡ�
*/
class Solution_827
{
public:
	int dfs(vector<vector<int>>& grid, int r, int c, int k)
	{
		int count = 1;
		int nr = grid.size();
		int nc = grid[0].size();
		grid[r][c] = k;
		if (r - 1 >= 0 && grid[r - 1][c] == 1) { count += dfs(grid, r - 1, c, k); }
		if (r + 1 < nr && grid[r + 1][c] == 1) { count += dfs(grid, r + 1, c, k); }
		if (c - 1 >= 0 && grid[r][c - 1] == 1) { count += dfs(grid, r, c - 1, k); }
		if (c + 1 < nc && grid[r][c + 1] == 1) { count += dfs(grid, r, c + 1, k); }
		return count;
	}
	set<int> connect_land(vector<vector<int>>& grid, int r, int c)
	{
		set<int> land;
		int nr = grid.size();
		int nc = grid[0].size();
		if (r - 1 >= 0 && grid[r - 1][c] != 0) { land.insert(grid[r - 1][c]); }
		if (r + 1 < nr && grid[r + 1][c] != 0) { land.insert(grid[r + 1][c]); }
		if (c - 1 >= 0 && grid[r][c - 1] != 0) { land.insert(grid[r][c - 1]); }
		if (c + 1 < nc && grid[r][c + 1] != 0) { land.insert(grid[r][c + 1]); }
		return land;
	}
	int largestIsland(vector<vector<int>>& grid)
	{
		int ans = 0;
		int nr = grid.size();
		int nc = grid[0].size();
		map<int, int> land;
		int k = -1;
		for (int i = 0; i < nr; i++)
		{
			for (int j = 0; j < nc; j++)
			{
				if (grid[i][j] == 1)
				{
					int temp = dfs(grid, i, j, k);
					land[k] = temp;
					k--;
					ans = max(temp, ans);
				}
			}
		}
		cout << "ans=" << ans << endl;
		for (int i = 0; i < nr; i++)
		{
			for (int j = 0; j < nc; j++)
			{
				if (grid[i][j] == 0)
				{
					set<int>temp_land = connect_land(grid, i, j);
					int temp_sum = 0;
					if (temp_land.size() != 0)
					{
						for (auto l : temp_land)
						{
							cout << l << '\t';
							cout << "land[l]:" << land[l] << '\t';
							temp_sum += land[l];
							cout << "temp_sum=" << temp_sum << '\t';
						}
					}
					cout << endl;
					cout << "temp_sum=" << temp_sum << '\t';
					ans = max(ans, temp_sum + 1);
				}
			}
			cout << endl;
		}
		return ans;
	}
};
/*int main()
{
	vector<vector<int>> grid = {
		{1,0},
		{0,1}
	};
	Solution_827 sol;
	cout << sol.largestIsland(grid);
}*/




//������
class HeapSort
{
public:
	HeapSort();
	~HeapSort();
	void percdom(vector<int>& nums, int i, int n);
	void create_Heapsort(vector<int>& nums);
	void Heapsort(vector<int>& nums);
private:

};

HeapSort::HeapSort() {}

HeapSort::~HeapSort() {}

void HeapSort::percdom(vector<int>& nums, int i, int n)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && nums[left] > nums[largest])
		largest = left;
	if (right < n && nums[right] > nums[largest])
		largest = right;
	if (largest != i)
	{
		swap(nums[i], nums[largest]);
		percdom(nums, largest, n);
	}
}

void HeapSort::create_Heapsort(vector<int>& nums)
{
	int n = nums.size();
	int root_index = ((n & 1) == 1 ? (n - 1) / 2 : n / 2 - 1);
	for (int i = root_index; i >= 0; i--)
	{
		percdom(nums, i, n);
	}
}

void HeapSort::Heapsort(vector<int>& nums)
{
	int n = nums.size();
	create_Heapsort(nums);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(nums[0], nums[i]);
		percdom(nums, 0, i);
	}
}

/*
int main()
{
	vector<int> nums = { 12,2,16,30,28,10,16,20,6,18 };
	HeapSort hs;
	hs.Heapsort(nums);
	for (auto i : nums)
	{
		cout << i << '\t';
	}
}
*/





class Solution_994
{
public:
	bool in_area(vector<vector<int>>& grid, int r, int c)//�ж�����Խ��
	{
		return (0 <= r && r < grid.size()) &&
			(0 <= c && c < grid[0].size());
	}
	void dfs(int depth, vector<vector<int>>& grid, int r, int c)//depth�Ǽ�¼��� ��������ٶȸ�������ȵĻ���ֻ���¼�����ٶ�
	{
		int nr = grid.size();
		int nc = grid[0].size();
		if (!in_area(grid, r, c))
		{
			return;
		}
		if (grid[r][c] == 0)
		{
			return;
		}
		if (depth >= dp[r][c])
		{
			return;
		}
		dp[r][c] = min(depth, dp[r][c]);
		dfs(depth + 1, grid, r - 1, c);
		dfs(depth + 1, grid, r + 1, c);
		dfs(depth + 1, grid, r, c - 1);
		dfs(depth + 1, grid, r, c + 1);
	}

	int orangesRotting(vector<vector<int>>& grid)
	{
		int nr = grid.size();
		int nc = grid[0].size();
		dp.resize(nr, vector<int>(nc, nr * nc));
		int ans = 0;
		for (int r = 0; r < nr; r++)
		{
			for (int c = 0; c < nc; c++)
			{
				if (grid[r][c] == 2)
				{
					dfs(0, grid, r, c);
				}
			}
		}
		for (int r = 0; r < nr; r++)
		{
			for (int c = 0; c < nc; c++)
			{
				if (grid[r][c] != 0)
				{
					ans = max(dp[r][c], ans);
				}
			}
		}
		return ans == nr * nc ? -1 : ans;
	}
	int orangesRotting_BFS(vector<vector<int>>& grid)
	{
		int nr = grid.size();
		int nc = grid[0].size();
		queue<pair<int, int>> que;
		int cnt = 0;//��¼���ʳ��ӵ�����
		for (int i = 0; i < nr; i++)
		{
			for (int j = 0; j < nc; j++)
			{
				if (grid[i][j] == 2)
				{
					que.push(pair<int, int>{ i, j });
				}
				else if (grid[i][j] == 1)
				{
					cnt++;
				}
			}
		}
		int ans = 0;
		while (!que.empty())
		{
			if (cnt == 0)//hands up��������Ҫ���ж��Ƿ�Ϊ�յ� ��Ϊ��ֻʣ�����һ����ʱ�� ʵ�����Ѿ����ȥ�� ��Ϊ����ǰ��1��
			{
				break;
			}
			int len = que.size();
			ans++;
			for (int i = 0; i < len; i++)
			{
				pair<int, int> temp = que.front();
				que.pop();
				int r = temp.first;
				int c = temp.second;
				if (r - 1 >= 0 && grid[r - 1][c] == 1) { grid[r - 1][c] = 2; que.push(pair<int, int>{r - 1, c}); cnt--; }
				if (r + 1 < nr && grid[r + 1][c] == 1) { grid[r + 1][c] = 2; que.push(pair<int, int>{r + 1, c}); cnt--; }
				if (c - 1 >= 0 && grid[r][c - 1] == 1) { grid[r][c - 1] = 2; que.push(pair<int, int>{r, c - 1}); cnt--; }
				if (c + 1 < nc && grid[r][c + 1] == 1) { grid[r][c + 1] = 2; que.push(pair<int, int>{r, c + 1}); cnt--; }
			}
		}
		if (cnt > 0)
		{
			return -1;
		}
		return ans;
	}
private:
	vector <vector<int>> dp;
};
/*
int main()
{
	vector<vector<int>> grid = {
		{2,1,1},
		{1,1,0},
		{0,1,1}
	};
	Solution_994 sol;
	cout<<sol.orangesRotting_BFS(grid);
}
*/




class Solution_207 //��������
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		vector<int> In_degree(numCourses, 0);//���ÿ��������
		for (auto i : prerequisites)
		{
			In_degree[i[1]]++;
		}
		queue<int> que;//���������Ϊ0�ĵ����que��
		int ans = 0;//������¼visited��ĸ���
		for (int i = 0; i < numCourses; i++)
		{
			if (In_degree[i] == 0)
			{
				que.push(i);
				ans++;
			}
		}
		while (!que.empty())
		{
			int temp = que.front();
			que.pop();
			for (auto i : prerequisites)
			{
				if (i[0] == temp)
				{
					In_degree[i[1]]--;
					if (In_degree[i[1]] == 0)
					{
						que.push(i[1]);
						ans++;
					}
				}
			}
		}
		if (ans != numCourses)
		{
			return false;
		}
		return true;
	}
};
/*
int main()
{
	vector<vector<int>> prerequisites = { {1, 0}, {0,1} };
	int numCourses = 2;
	Solution_207 sol;
	cout<<sol.canFinish(numCourses, prerequisites);
}
*/








//�����������ͱ���
struct node
{
	char ch;//��ʾ�ĸ��ַ�
	int val;//��ʾȨֵ
	string str;
	node* left = nullptr;
	node* right = nullptr;
	node() :ch('*') {}
	node(pair<char, int> pa) { ch = pa.first; val = pa.second; }
};

class mycomparison_huffman
{
public:
	mycomparison_huffman() {};
	~mycomparison_huffman() {};
	bool operator()(const node* lhs, const node* rhs)
	{
		return lhs->val > rhs->val;
	}
};

class Huffman_Coding
{
public:
	Huffman_Coding() :head(nullptr) {};
	~Huffman_Coding() {};
	int n = 0;//n�����м����ַ���Ȩֵ
	priority_queue<node*, vector<node*>, mycomparison_huffman> que;//�������ȶ��а���Ȩֵ����
	unordered_map<char, string> hash;//���ڴ洢�ַ��������
	int WPL = 0;//����WPL;
	int sum = 0;//��¼�����ַ��ĸ���
	void cin_data()
	{
		cin >> n;
		cout << "������" << n << "���ַ�����Ȩֵ:" << endl;
		for (int i = 0; i < n; i++)
		{
			char ch;
			cin >> ch;
			int val;
			cin >> val;
			sum += val;
			node* temp = new node(pair<char, int>(ch, val));
			que.push(temp);
		}
		//չʾ���ȶ�������
		//while (!que.empty())
		//{
		//	node* temp = que.top();
		//	que.pop();
		//	cout << temp->ch << '\t' << temp->val<<endl;
		//}
	}
	void Create_Huffman_tree()
	{
		while (que.size() != 1)
		{
			node* cur = new node();
			node* temp1 = que.top();
			que.pop();
			node* temp2 = que.top();
			que.pop();
			cur->val = temp1->val + temp2->val;
			cur->left = temp1;
			cur->right = temp2;
			head = cur;
			que.push(cur);
		}
	}
	void Coding_on_tree_and_calculate_WPL()
	{
		if (head == nullptr)
		{
			return;
		}
		queue<node*> que;
		que.push(head);
		while (!que.empty())
		{
			int que_size = que.size();
			for (int i = 0; i < que_size; i++)
			{
				node* cur = que.front();
				que.pop();
				if (cur->left != nullptr)
				{
					cur->left->str += (cur->str + '0');
					que.push(cur->left);
				}
				if (cur->right != nullptr)
				{
					cur->right->str += (cur->str + '1');
					que.push(cur->right);
				}
				if (cur->ch != '*')
				{
					WPL += cur->val * cur->str.size();
					hash.insert(pair<char, string>(cur->ch, cur->str));
				}
			}
		}
	}
	void display_tree()
	{
		if (head == nullptr)
		{
			return;
		}
		cout << "----------" << endl;
		cout << "����չʾ��������:(����BFS��ʽ����)" << endl;
		queue<node*> que;
		que.push(head);
		while (!que.empty())
		{
			int que_size = que.size();
			for (int i = 0; i < que_size; i++)
			{
				node* cur = que.front();
				cout << cur->ch << '\t' << cur->val << '\t';
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
			cout << endl;
		}
		cout << "-------------" << endl;
	}
	void display_coding()
	{
		cout << "------------" << endl;
		cout << "����չʾ�������������ַ����Ӧ��:" << endl;
		for (auto& i : hash)
		{
			cout << i.first << '\t' << i.second << endl;
		}
		cout << "------------" << endl;
	}
	void display_WPL()
	{
		cout << "----------" << endl;
		cout << "WPL=" << WPL << endl;
		cout << "----------" << endl;
	}
	void display_Average_Coding_Length()
	{
		cout << "----------" << endl;
		cout << "ƽ�����볤�ȣ�" << 1.0 * WPL / sum << endl;
		cout << "----------" << endl;
	}
private:
	node* head;
};

/*
int main()
{
	Huffman_Coding huff;
	huff.cin_data();
	huff.Create_Huffman_tree();
	huff.display_tree();
	huff.Coding_on_tree_and_calculate_WPL();
	huff.display_coding();
	huff.display_WPL();
	huff.display_Average_Coding_Length();
}
*/





struct point
{
	int num;
	vector<point*> vec;//��ʾ�ɸõ������ӵ���Щ��
	point(int val) :num(val) {}
};

class Graph
{
public:
	Graph() :head(nullptr) {}

	bool fun(int val, point* temp)//���ܺ���   ���ڲ��ش��� �ж�val�Ƿ���temp��temp��ָ��ĵ���ͬ
	{
		if (val == temp->num)
		{
			return true;
		}
		for (auto i : temp->vec)
		{
			if (val == i->num)
			{
				return true;
			}
		}
		return false;
	}

	Graph(vector<int>& nums)//�������һ��ͼ
	{
		//�������һ����Сͼ
		srand((unsigned)time(nullptr));
		set<int> exclude;//��ʾͼ�����е�
		vector<point*> vec;
		for (auto& i : nums)//������е㶼��ͼ��
		{
			exclude.insert(i);
		}
		int first = rand() % nums.size();
		head = new point(first);
		point* cur = head;
		exclude.erase(first);
		vec.push_back(cur);
		while (!exclude.empty())
		{
			int ran = rand() % nums.size();//��0��nums.size()���������һ���� ��Ϊ���
			if (exclude.find(ran) != exclude.end())//�õ㻹�ڼ�����
			{
				point* temp = new point(ran);
				exclude.erase(ran);
				cur->vec.push_back(temp);
				cur = cur->vec[0];
				vec.push_back(cur);
			}
		}
		//����ӱ�
		for (auto& i : vec)
		{
			int ran_num = rand() % 3 + 1;//�����ʾһ������ran_num���� ���3���� 
			vector<int> hash(nums.begin(), nums.end());
			for (int j = 1; j < ran_num; j++)
			{
				int ran = rand() % vec.size();//��ѡ����� ��vec[i]���� �п��������֮ǰ������ʱ���õĵ���ߺ�i��ͬ ����Ҫ����
				while (fun(ran, i))
				{
					ran = (ran + 1) % vec.size();
				}
				i->vec.push_back(vec[ran]);
			}
		}
		vec[vec.size() - 1]->vec.push_back(vec[0]);//ע���������Ҫ��������� ������������ʱ�����һ�������һ������������  ��Ϊ���һ�������ֻ����ȱ� ��û�г��ȱ� ���Ե�ʹ��DFS��ʱ����ܻ������ѭ�����޷��˳�    ���Գ�����ɾȥ�����Ȼ���ִ�м���
		//�����������չʾ���ڵ�֮����������
		cout << "����Ϊ������ɵ�ԭͼ�ṹ:" << endl;
		for (auto i : vec)
		{
			cout << "num=" << i->num << '\t';
			for (auto j : i->vec)
			{
				cout << "to" << j->num << '\t';
			}
			cout << endl;
		}
		cout << endl;
	}

	~Graph()
	{
		if (head != nullptr)
		{
			delete head;
		}
	}

	vector<int> BFS(vector<int>& nums)
	{
		cout << "BFS:" << endl;
		unordered_set<int> visited;//���ڱ���Ѿ����ʹ��Ľڵ�
		queue<point*> que;
		que.push(head);
		visited.insert(head->num);
		while (visited.size() != nums.size())
		{
			if (que.empty())
			{
				break;
			}
			point* cur = que.front();
			que.pop();
			for (auto& i : cur->vec)
			{
				if (visited.find(i->num) == visited.end())//˵���ýڵ�δ�����ʹ�
				{
					que.push(i);
					visited.insert(i->num);
				}
			}
		}
		return vector<int>(visited.begin(), visited.end());
	}

	void traversal(point* cur, unordered_set<int>& ans, vector<int> nums)
	{
		if (ans.find(cur->num) == ans.end())//δ�ҵ�
		{
			ans.insert(cur->num);
			while (ans.size() != nums.size())//ֻҪδ�ҵ�ȫ���������˳� �����
			{
				cur = cur->vec[rand() % (cur->vec.size())];//���ѡ��һ����
				traversal(cur, ans, nums);
			}
		}
	}
	vector<int> DFS(vector<int> nums)
	{
		cout << "DFS:" << endl;
		if (head == nullptr)
		{
			return vector<int>(0);
		}
		unordered_set<int> ans;//�ȿ��������� Ҳ�����������ش���
		traversal(head, ans, nums);
		return vector<int>(ans.begin(), ans.end());
	}


private:
	point* head;//��ʾͼ��ĳ����
};


//int main()
//{
//	vector<int> nums = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
//	Graph gra(nums);
//	for (auto& i : gra.BFS(nums))
//	{
//		cout << i << '\t';
//	}
//	cout << endl;
//	for (auto& i : gra.DFS(nums))
//	{
//		cout << i << '\t';
//	}
//}







class kama_103
{
public:
	kama_103()
	{
		cin >> n >> m;
		matrix.resize(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int k;
				cin >> k;
				matrix[i].push_back(k);
			}
		}
	};
	~kama_103() {};
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//��������
	bool can_to_1(int row, int col)
	{
		return row == 0 || col == 0;
	}
	bool can_to_2(int row, int col, vector<vector<int>>& matrix)
	{
		return row == matrix.size() - 1 || col == matrix[0].size() - 1;
	}
	bool bfs(int row, int col, vector<vector<int>>& matrix)
	{
		queue<pair<int, int>> que;
		set<pair<int, int>> visited;
		que.push(pair<int, int>(row, col));
		visited.insert(pair<int, int>(row, col));
		bool panduan[2] = { false,false };
		while (!que.empty())
		{
			pair<int, int> temp = que.front();
			que.pop();
			panduan[0] = can_to_1(temp.first, temp.second) || panduan[0];
			panduan[1] = can_to_2(temp.first, temp.second, matrix) || panduan[1];
			for (int i = 0; i < 4; i++)
			{
				int next_x = temp.first + dir[i][0];
				int next_y = temp.second + dir[i][1];
				if (next_x < 0 || next_x >= matrix.size() || next_y < 0 || next_y >= matrix[0].size())
				{
					continue;
				}
				if (matrix[next_x][next_y] <= matrix[temp.first][temp.second] && visited.find(pair<int, int>(next_x, next_y)) == visited.end())
				{
					que.push(pair<int, int>(next_x, next_y));
					visited.insert(pair<int, int>(next_x, next_y));
				}
			}
		}
		return panduan[0] && panduan[1];
	}
	void display()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (bfs(i, j, matrix))
				{
					cout << i << ' ' << j << endl;
				}
			}
		}
	}
private:
	int n, m;
	vector<vector<int>> matrix;
};


/*
int main()
{
	kama_103 aaa;
	aaa.display();
}
*/






//����ͼ����ȫ�ɴ��� kama_105
/*
int main()
{
	int n, k;
	cin >> n >> k;
	vector<list<int>> graph(n + 1);
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	set<int> visited;
	visited.insert(1);
	queue<int> que;
	que.push(1);
	while (!que.empty())
	{
		int temp = que.front();
		que.pop();
		list<int> keys = graph[temp];
		for (auto key : keys)
		{
			if (visited.find(key) == visited.end())
			{
				visited.insert(key);
				que.push(key);
			}
		}
	}
	if (visited.size() == n)
	{
		cout << 1;
	}
	else
	{
		cout << -1;
	}
}
*/





//110. �ַ�������
/*
�ֵ� strList �д��ַ��� beginStr �� endStr ��ת��������һ������������γɵ����У�
�����е�һ���ַ����� beginStr��
���������һ���ַ����� endStr��
ÿ��ת��ֻ�ܸı�һ���ַ���
ת�������е��м��ַ����������ֵ� strList �е��ַ�����
���������ַ��� beginStr �� endStr ��һ���ֵ� strList���ҵ��� beginStr �� endStr �����ת�������е��ַ�����Ŀ�����������������ת�����У����� 0��
��������
��һ�а���һ������ N����ʾ�ֵ� strList �е��ַ��������� �ڶ��а��������ַ������ÿո�������ֱ���� beginStr �� endStr�� ���� N �У�ÿ��һ���ַ��������� strList �е��ַ�����
�������
���һ������������� beginStr ת���� endStr ��Ҫ�����ת�������е��ַ������������������������ת�����У������ 0
*/
bool kama_110_fun(string str1, string str2)
{
	int n = 0;//nΪ����ͬ�ַ�����
	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] != str2[i])
		{
			n++;
		}
	}
	if (n == 1)
	{
		return true;
	}
	return false;
}
/*
int main()
{
	int n;
	cin >> n;
	string beginStr, endStr;
	cin >> beginStr >> endStr;
	vector<string> strList(n);
	for (int i = 0; i < n; i++)
	{
		cin >> strList[i];
	}
	set<string> visited;
	queue<string> que;
	que.push(beginStr);
	int ans = 0;
	while (!que.empty())
	{
		ans++;
		int len = que.size();
		for (int i = 0; i < len; i++)
		{
			string temp = que.front();
			que.pop();
			if (kama_110_fun(temp, endStr))
			{
				ans += 1;
				cout << ans;
				return 0;
			}
			for (int j = 0; j < strList.size(); j++)
			{
				if (visited.find(strList[j]) == visited.end() && kama_110_fun(temp, strList[j]))
				{
					que.push(strList[j]);
					visited.insert(strList[j]);
				}
			}
		}
	}
	cout << 0;
	return 0;
}
*/




class DSU//Disjoint Set Union ���鼯
{
public:
	vector<int> father;
	DSU() { cin >> n; };
	~DSU() {};
	void Init()//��ʼ��
	{
		for (int i = 0; i < n; i++)
		{
			father.push_back(i);
		}
	}
	int find(int u)//Ѱ��
	{
		if (father[u] == u)
		{
			return u;
		}
		father[u] = find(father[u]);
	}
	bool isSame(int u, int v)//�ж��Ƿ���ͬһ��������
	{
		u = find(u);
		v = find(v);
		return u == v;
	}
	void join(int u, int v)//��v���뵽u��
	{
		u = find(u);
		v = find(v);
		if (u == v)return;
		father[v] = u;
	}
	//���Ը�����Ŀ����ʵ��·��ѹ��
private:
	int n;
};



/*
108. ��������
ʱ�����ƣ�1.000S  �ռ����ƣ�256MB
��Ŀ����
�����Կ�����һ��ͼ��ӵ�� n ���ڵ�� n - 1 ���ߵ���ͨ�޻�����ͼ����
�ָ���һ��ӵ�� n ���ڵ㣨�ڵ����Ǵ� 1 �� n���� n ���ߵ���ͨ����ͼ�����ҳ�һ������ɾ���ıߣ�ɾ����ͼ���Ա��һ������
��������
��һ�а���һ������ N����ʾͼ�Ľڵ�����ͱߵĸ�����
���� N �У�ÿ�а����������� s �� t����ʾͼ�� s �� t ֮����һ���ߡ�
�������
���һ������ɾ���ıߡ�����ж���𰸣���ɾ����׼�����������ֵ������ߡ�
����ʾ��
3
1 2
2 3
1 3
���ʾ��
1 3
*/
class kama_108
{
public:
	vector<pair<int, int>> matrix;
	vector<int> father;
	kama_108()
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			matrix.push_back(pair<int, int>(a, b));
		}
		for (int i = 0; i <= n; i++)//��ʼ��
		{
			father.push_back(i);
		}
	};
	int find(int a, vector<int>& father)
	{
		if (a == father[a])
		{
			return a;
		}
		return find(father[a], father);
	}
	void get_ans()
	{
		for (auto& i : matrix)
		{
			int u = find(i.first, father);
			int v = find(i.second, father);
			if (u == v)
			{
				cout << i.first << " " << i.second;
				return;
			}
			else
			{
				father[i.second] = i.first;
			}
		}
	}
	~kama_108() {};

private:
	int n;
};



//����ʽ���� ��������Ϊ��
struct Knight
{
	int x, y;
	int f;
	Knight() {} 
	Knight(int a, int b) :x(a), y(b) {}
	bool operator < (const Knight& k) const
	{
		return k.f < f;
	}
};
class Astar
{
public:


	Knight start;
	int dir[8][2] = { -2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2 };//�����յķ���
	vector<vector<int>> moves{ 10,vector<int>(10,INT_MAX) };//��ʾ����
	priority_queue<Knight> que;
	Astar() { cin >> a1 >> a2 >> b1 >> b2; start.x = a1; start.y = a2;	start.f = Heuristic(start); moves[a1][a2] = 0; };
	~Astar() {};

	int Heuristic(const Knight& k)
	{
		return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);
	}

	void astar_bfs()
	{
		Knight cur, next;
		que.push(start);
		while (!que.empty())
		{
			cur = que.top();
			que.pop();
			if (cur.x == b1 && cur.y == b2)
			{
				break;
			}
			for (int i = 0; i < 8; i++)
			{
				next.x = cur.x + dir[i][0];
				next.y = cur.y + dir[i][1];
				if (next.x < 1 || next.x >= moves.size() || next.y < 1 || next.y >= moves[0].size())
				{
					continue;
				}
				if (moves[next.x][next.y] == INT_MAX)
				{
					moves[next.x][next.y] = moves[cur.x][cur.y] + 1;
					next.f = Heuristic(next);
					que.push(next);
				}
			}
		}
	}
	void display_moves()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (moves[i][j] == INT_MAX)
				{
					cout << 0 << '\t';
				}
				else
				{
					cout << moves[i][j] << '\t';
				}
			}
			cout << endl;
		}
	}
private:
	int a1, a2;
	int b1, b2;//���յ�λ��
};
/*
int main()
{
	Astar as;
	as.astar_bfs();
	as.display_moves();
}
*/