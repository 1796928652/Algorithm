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
// Prim 算法
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
	* 核心步骤有三
	* 1.找到距离生成树最小的节点
	* 2.将该节点加入到生成树中
	* 3.更新剩余节点到生成树的距离
	*/
/*
	vector<int> minDist(v + 1, INT_MAX); //所有节点到最小生成树的最小距离
	vector<bool> IsInTree(v + 1, false); //判断是否在生成树中
	vector<int> path;//给出路径
	for (int i = 1; i < v; i++)
	{
		int cur = -1;
		for (int j = 1; j <= v; j++)
		{
			if (!IsInTree[j]&& (cur==-1 || minDist[j]<minDist[cur]))//这里cur==-1 是默认遇到的第一个节点就是所要选取的点而后面的比较大小是真正拿到所要选取的点
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
* kruskal的核心
* 1.每次找到权值最小且不会使最小生成树出现环的边
* 2.加入该边
*/
/*ps：找到权值最小的边通过排序可以完成
	  找到不会使原树出现环的边 理论上可以通过拓扑排序判断 但工作量过于庞大
	  这里可以使用并查集
	  使用并查集的思路是
			连接两个点时可以使一个为根节点一个为叶节点 根节点指向叶节点
			那么多添加一个节点则仍然原根节点指向叶节点
			连接另一棵树是可以原根节点指向树
	  具体实现可以用一位数组实现
*/
struct edge
{
	int p1, p2, val;//p1与p2分别表示两个点val表示权值
};
class Kruskal_solution
{
public:
	static bool cmp(edge x, edge y)
	{
		return x.val < y.val;
	}
	int FindFather(int v);
	void getedge();//输入边的数据
	void get_n();//输入有几个点
	void get_m();//输入有几条边
	int kruskal();
	Kruskal_solution();
	~Kruskal_solution();

private:
	vector<edge> e;
	vector<int> father;
	int n = 0, m = 0;//n表示点，m表示边
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










/*dijkstra算法
* 取离原点最近未访问节点 形成一个小路径（图）  //这里可以使用堆排序来取出最近未访问节点
* 将最近节点标记为访问过
* 更新未访问节点到源点的距离 
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
	vector<int> minDist(n + 1, INT_MAX);//其余节点到源点的最短距离
	vector<bool> visited(n + 1, false);//是否访问过节点
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






//利用堆排序的dijkstra
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
	int to;//to某节点
	int val;//边的权重
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
//		//第一步 选一个到源点最近且未被访问过的节点
//		pair<int, int> cur = que.top();
//		que.pop();
//		if (visited[cur.first])
//		{
//			continue;
//		}
//
//		//第二步 标记该节点为访问过
//		visited[cur.first] = true;
//
//		//更新未访问接待你到源点的距离
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






/*200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和 / 或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围*/
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



/*463. 岛屿的周长
给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长
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



/*695. 岛屿的最大面积
给你一个大小为 m x n 的二进制矩阵 grid 。
岛屿 是由一些相邻的 1 (代表土地)构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
岛屿的面积是岛上值为 1 的单元格的数目。
计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0
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
827. 最大人工岛
给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
返回执行此操作后，grid 中最大的岛屿面积是多少？
岛屿 由一组上、下、左、右四个方向相连的 1 形成。
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




//堆排序
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
	bool in_area(vector<vector<int>>& grid, int r, int c)//判断有无越界
	{
		return (0 <= r && r < grid.size()) &&
			(0 <= c && c < grid[0].size());
	}
	void dfs(int depth, vector<vector<int>>& grid, int r, int c)//depth是记录深度 如果腐败速度跟不上深度的话则只需记录腐败速度
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
		int cnt = 0;//记录新鲜橙子的数量
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
			if (cnt == 0)//hands up！！必须要有判断是否为空的 因为当只剩下最后一个的时候 实际上已经算进去了 因为是提前加1的
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




class Solution_207 //拓扑排序
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		vector<int> In_degree(numCourses, 0);//标记每个点的入度
		for (auto i : prerequisites)
		{
			In_degree[i[1]]++;
		}
		queue<int> que;//将所有入度为0的点放入que中
		int ans = 0;//用来记录visited点的个数
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








//哈夫曼建树和编码
struct node
{
	char ch;//表示哪个字符
	int val;//表示权值
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
	int n = 0;//n代表共有几组字符和权值
	priority_queue<node*, vector<node*>, mycomparison_huffman> que;//利用优先队列按照权值排序
	unordered_map<char, string> hash;//用于存储字符编码情况
	int WPL = 0;//计算WPL;
	int sum = 0;//记录所有字符的个数
	void cin_data()
	{
		cin >> n;
		cout << "请输入" << n << "组字符和其权值:" << endl;
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
		//展示优先队列内容
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
		cout << "以下展示哈夫曼树:(按照BFS方式呈现)" << endl;
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
		cout << "以下展示哈夫曼编码后的字符与对应码:" << endl;
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
		cout << "平均编码长度：" << 1.0 * WPL / sum << endl;
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
	vector<point*> vec;//表示由该点能连接到哪些点
	point(int val) :num(val) {}
};

class Graph
{
public:
	Graph() :head(nullptr) {}

	bool fun(int val, point* temp)//功能函数   用于查重处理 判断val是否于temp和temp所指向的点相同
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

	Graph(vector<int>& nums)//随机生成一个图
	{
		//随机生成一个最小图
		srand((unsigned)time(nullptr));
		set<int> exclude;//表示图外所有点
		vector<point*> vec;
		for (auto& i : nums)//起初所有点都在图外
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
			int ran = rand() % nums.size();//在0到nums.size()中随机生成一个数 作为起点
			if (exclude.find(ran) != exclude.end())//该点还在集合内
			{
				point* temp = new point(ran);
				exclude.erase(ran);
				cur->vec.push_back(temp);
				cur = cur->vec[0];
				vec.push_back(cur);
			}
		}
		//任意加边
		for (auto& i : vec)
		{
			int ran_num = rand() % 3 + 1;//随机表示一个点有ran_num条边 最多3条边 
			vector<int> hash(nums.begin(), nums.end());
			for (int j = 1; j < ran_num; j++)
			{
				int ran = rand() % vec.size();//挑选随机点 与vec[i]连接 有可能随机到之前构建树时所用的点或者和i相同 所以要查重
				while (fun(ran, i))
				{
					ran = (ran + 1) % vec.size();
				}
				i->vec.push_back(vec[ran]);
			}
		}
		vec[vec.size() - 1]->vec.push_back(vec[0]);//注意这里必须要有这条语句 这条语句的作用时将最后一个点与第一个点连接起来  因为最后一个点可能只有入度边 而没有出度边 所以当使用DFS的时候可能会进入死循环而无法退出    可以尝试着删去此语句然后多执行几遍
		//以下语句用于展示点于点之间的连接情况
		cout << "以下为随机生成的原图结构:" << endl;
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
		unordered_set<int> visited;//用于标记已经访问过的节点
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
				if (visited.find(i->num) == visited.end())//说明该节点未被访问过
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
		if (ans.find(cur->num) == ans.end())//未找到
		{
			ans.insert(cur->num);
			while (ans.size() != nums.size())//只要未找到全部就永不退出 深度搜
			{
				cur = cur->vec[rand() % (cur->vec.size())];//随机选择一条边
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
		unordered_set<int> ans;//既可以用作答案 也可以用作查重处理
		traversal(head, ans, nums);
		return vector<int>(ans.begin(), ans.end());
	}


private:
	point* head;//表示图中某个点
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
	int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//上下左右
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






//有向图的完全可达性 kama_105
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





//110. 字符串接龙
/*
字典 strList 中从字符串 beginStr 和 endStr 的转换序列是一个按下述规格形成的序列：
序列中第一个字符串是 beginStr。
序列中最后一个字符串是 endStr。
每次转换只能改变一个字符。
转换过程中的中间字符串必须是字典 strList 中的字符串。
给你两个字符串 beginStr 和 endStr 和一个字典 strList，找到从 beginStr 到 endStr 的最短转换序列中的字符串数目。如果不存在这样的转换序列，返回 0。
输入描述
第一行包含一个整数 N，表示字典 strList 中的字符串数量。 第二行包含两个字符串，用空格隔开，分别代表 beginStr 和 endStr。 后续 N 行，每行一个字符串，代表 strList 中的字符串。
输出描述
输出一个整数，代表从 beginStr 转换到 endStr 需要的最短转换序列中的字符串数量。如果不存在这样的转换序列，则输出 0
*/
bool kama_110_fun(string str1, string str2)
{
	int n = 0;//n为不相同字符个数
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




class DSU//Disjoint Set Union 并查集
{
public:
	vector<int> father;
	DSU() { cin >> n; };
	~DSU() {};
	void Init()//初始化
	{
		for (int i = 0; i < n; i++)
		{
			father.push_back(i);
		}
	}
	int find(int u)//寻根
	{
		if (father[u] == u)
		{
			return u;
		}
		father[u] = find(father[u]);
	}
	bool isSame(int u, int v)//判断是否在同一个集合中
	{
		u = find(u);
		v = find(v);
		return u == v;
	}
	void join(int u, int v)//将v加入到u中
	{
		u = find(u);
		v = find(v);
		if (u == v)return;
		father[v] = u;
	}
	//可以根据题目自行实现路径压缩
private:
	int n;
};



/*
108. 冗余连接
时间限制：1.000S  空间限制：256MB
题目描述
树可以看成是一个图（拥有 n 个节点和 n - 1 条边的连通无环无向图）。
现给定一个拥有 n 个节点（节点标号是从 1 到 n）和 n 条边的连通无向图，请找出一条可以删除的边，删除后图可以变成一棵树。
输入描述
第一行包含一个整数 N，表示图的节点个数和边的个数。
后续 N 行，每行包含两个整数 s 和 t，表示图中 s 和 t 之间有一条边。
输出描述
输出一条可以删除的边。如果有多个答案，请删除标准输入中最后出现的那条边。
输入示例
3
1 2
2 3
1 3
输出示例
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
		for (int i = 0; i <= n; i++)//初始化
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



//启发式搜索 以马走日为例
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
	int dir[8][2] = { -2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2 };//马走日的方向
	vector<vector<int>> moves{ 10,vector<int>(10,INT_MAX) };//表示棋盘
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
	int b1, b2;//最终的位置
};
/*
int main()
{
	Astar as;
	as.astar_bfs();
	as.display_moves();
}
*/