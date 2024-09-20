#include<vector>
#include<string>
#include<concurrent_priority_queue.h>
#include<queue>
#include<list>
#include<iostream>
using namespace std;
//455. 分发饼干
//假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
//对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
//示例 1:
//输入: g = [1, 2, 3], s = [1, 1]
//输出 : 1
//解释 :
//你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1, 2, 3。
//虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
//所以你应该输出1。
//示例 2 :
//输入 : g = [1, 2], s = [1, 2, 3]
//输出 : 2
//解释 :
//你有两个孩子和三块小饼干，2个孩子的胃口值分别是1, 2。
//你拥有的饼干数量和尺寸都足以让所有孩子满足。
//所以你应该输出2.
int findContentChildren(vector<int>& g, vector<int>& s)
{
	priority_queue<int, vector<int>, greater<int>> children;
	priority_queue<int, vector<int>, greater<int>> biscuit;
	for (auto i : g)
	{
		children.push(i);
	}
	for (auto j : s)
	{
		biscuit.push(j);
	}
	int content = 0;
	while (!children.empty() && !biscuit.empty())
	{
		if (children.top() == biscuit.top())
		{
			++content;
			children.pop();
			biscuit.pop();
		}
		else if (children.top() > biscuit.top())
		{
			biscuit.pop();
		}
		else
		{
			++content;
			children.pop();
			biscuit.pop();
		}
	}
	return content;
}
//int main()
//{
//	vector<int> g = { 1,2 };
//	vector<int> s = { 1,2,3 };
//	cout << findContentChildren(g, s);
//}



//376. 摆动序列
//如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
//例如，[1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值(6, -3, 5, -7, 3) 是正负交替出现的。
//相反，[1, 4, 7, 2, 5] 和[1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
//子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
//给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
//示例 1：
//输入：nums = [1, 7, 4, 9, 2, 5]
//输出：6
//解释：整个序列均为摆动序列，各元素之间的差值为(6, -3, 5, -7, 3) 。
//示例 2：
//输入：nums = [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
//输出：7
//解释：这个序列包含几个长度为 7 摆动序列。
//其中一个是[1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为(16, -7, 3, -3, 6, -8) 。
//示例 3：
//输入：nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
//输出：2
//这道题可以画一个折线图 就能发现解题思路
int wiggleMaxLength(vector<int>& nums)
{
	int n = nums.size();
	if (n < 2)
	{
		return n;
	}
	int prevdiff = nums[1] - nums[0];
	int ret = prevdiff != 0 ? 2 : 1;
	for (int i = 2; i < n; i++)
	{
		int diff = nums[i] - nums[i - 1];
		if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0))
		{
			ret++;
			prevdiff = diff;
		}
	}
	return ret;
}
//int main()
//{
//	vector<int> nums = { 3,3,3,2,5 };
//	cout << wiggleMaxLength(nums);
//}


//122. 买卖股票的最佳时机 II
//给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
//在每一天，你可以决定是否购买和 / 或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
//返回 你能获得的 最大 利润 。
//示例 1：
//输入：prices = [7, 1, 5, 3, 6, 4]
//输出：7
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
//随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
//总利润为 4 + 3 = 7 。
//示例 2：
//输入：prices = [1, 2, 3, 4, 5]
//输出：4
//解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
//总利润为 4 。
//示例 3：
//输入：prices = [7, 6, 4, 3, 1]
//输出：0
//解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0
//对于股票买卖没有限制 所以这里可以和上一题一样 画一个折线图 当有往上增长的趋势时就卖出。而价格减少时则不需要考虑。
int maxProfit_2(vector<int>& prices)
{
	int sum = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] - prices[i - 1] > 0)
		{
			sum += prices[i] - prices[i - 1];
		}
	}
	return sum;
}


//55. 跳跃游戏
//给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
//示例 1：
//输入：nums = [2, 3, 1, 1, 4]
//输出：true
//解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
//示例 2：
//输入：nums = [3, 2, 1, 0, 4]
//输出：false
//解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
//提示：
//1 <= nums.length <= 104
//0 <= nums[i] <= 10
//思路是 只需要求出其能到达的最大位置与n进行比较便可
//        在其能到达最大位置里看是否蕴有能比其到达更远位置的数。 一步一步扩展最大位置 直到穷尽到最大位置
bool canJump(vector<int>& nums)
{
	if (nums.size() == 1)
	{
		return true;
	}
	int len = nums.size() - 1;
	int max_n = nums[0]; //max_n代表所能到达的最大位置下标
	for (int i = 0; i <= max_n; i++)
	{
		max_n = max(nums[i] + i, max_n);
		if (max_n >= len)
		{
			return true;
		}
	}
	return false;
}
//int main()
//{
//	vector<int> nums = { 3,2,1,0,4 };
//	cout << canJump(nums);
//}


//跳跃游戏二
//思路一 从动态规划的角度思考 定义dp[i]为表示到i这个位置所需的最小方案数 
//    那么从设么位置能到i呢？  假设从a1,a2,a3等等这些位置都能抵达i
//         但问题来了 对于i我们还需保存a1,a2等等这些点位的信息  是否太麻烦？
//               换给角度思考  我们就从a1,a2这些位置开始提前考虑到i的最小方案数
//                    a1能到达i 那么i的方案数至少有一种是 dp[a1]+1   a2也能到达 那么到达i的方案数还有一种是dp[a2]+1   我们只需要拿到dp[i]=min(dp[a1],dp[a2],dp[a3],...)+1
int jump(vector<int>& nums)
{
	vector<int> dp(nums.size(), INT_MAX); 
	dp[0] = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int j = i + nums[i];
		if (j >= nums.size() - 1)
		{
			return dp[i] + 1;
		}
		for (int m = i + 1; m <= j && m < nums.size(); m++)
		{
			dp[m] = min(dp[m], dp[i] + 1);
		}
	}
	for (auto i : dp)
	{
		cout << i << '\t';
	}
	return dp[nums.size() - 1];
}
//思路二 与上一题类似 我们只需要参考上一题的模板 多设置一个记录步骤的变量
int Jump_two(vector<int>& nums)
{
	if (nums.size() == 1)
	{
		return true;
	}
	int len = nums.size() - 1;
	int max_n = nums[0];
	int privious_max_n = 0;
	int ans = 0;
	for (int i = 0; i <= privious_max_n; i++)
	{
		max_n = max(nums[i] + i, max_n);
		if (i==privious_max_n)
		{
			privious_max_n = max_n;
			++ans;
		}
		if (privious_max_n >= len)
		{
			break;
		}
	}
	return ans;
}



//763. 划分字母区间
//给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
//注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
//返回一个表示每个字符串片段的长度的列表。
//示例 1：
//输入：s = "ababcbacadefegdehijhklij"
//输出：[9, 7, 8]
//解释：
//划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
//示例 2：
//输入：s = "eccbbbbdec"
//输出：[10]
//因为操作过程中对于for循环的终止条件是动态变化的 所以将本题与跳跃游戏放于上下文
//   由于同一字母要出现在同一片段中，所以每个字母都有其所能到达的最远下标
//  在遍历s中  对于每个内部的循环的终止条件是依照其内部所有字母所能到达的最远下标
vector<int> partitionLabels(string s)
{
	int hash[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		hash[s[i] - 'a'] = max(hash[s[i] - 'a'], i);
	}
	vector<int> ans;
	int len = s.size();
	int i = 0;
	while (i < len)
	{
		int right = hash[s[i] - 'a'];
		int j = i;
		for (; j <= right; j++)
		{
			right = max(hash[s[j] - 'a'], right);
		}
		ans.push_back(j - i);
		i = j;
	}
	return ans;
}
//int main()
//{
//	string s = "eccbbbbdec";
//	for (auto i : partitionLabels(s))
//	{
//		cout << i << '\t';
//	}
//}





//1005. K 次取反后最大化的数组和
//给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
//选择某个下标 i 并将 nums[i] 替换为 - nums[i] 。
//重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
//以这种方式修改数组后，返回数组 可能的最大和 。
//示例 1：
//输入：nums = [4, 2, 3], k = 1
//输出：5
//解释：选择下标 1 ，nums 变为[4, -2, 3] 。
//示例 2：
//输入：nums = [3, -1, 0, 2], k = 3
//输出：6
//解释：选择下标(1, 2, 2) ，nums 变为[3, 1, 0, 2] 。
//示例 3：
//输入：nums = [2, -3, -1, 5, -4], k = 2
//输出：13
//解释：选择下标(1, 4) ，nums 变为[2, 3, -1, 5, 4]
// 思路是对数组进行排序 排序后，对应有如下几种可能
//       1。 k小于负数的数量，则将最小的几个负数变为正即可
//       2.  k大于负数的数量，则变完后选择一个绝对值最小的数 k多次作用与这个数 最后统计进数组 
int largestSumAfterKNegations(vector<int>& nums, int k)
{
	int sum = 0;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	int min_fabs = fabs(nums[0]);
	for (int i = 0; i < len; i++)
	{
		min_fabs = min(min_fabs, (int)fabs(nums[i]));
		if (nums[i] < 0 && k != 0)
		{
			--k;
			sum += fabs(nums[i]);
			continue;
		}
		sum += nums[i];
	}
	if ((k & 1) == 1)
	{
		sum -= 2 * min_fabs;
	}
	return sum;
}
//int main()
//{
//	vector<int> nums = { 5,6,9,-3,3 };
//	cout << largestSumAfterKNegations(nums, 2);
//}


//134. 加油站
//在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i + 1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 - 1 。如果存在解，则 保证 它是 唯一 的。
//示例 1:
//输入: gas = [1, 2, 3, 4, 5], cost = [3, 4, 5, 1, 2]
//输出 : 3
//解释 :
//从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
//开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
//开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
//开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
//开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
//开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
//因此，3 可为起始索引。
//示例 2:
//输入: gas = [2, 3, 4], cost = [3, 4, 3]
//输出 : -1
//解释 :
//你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
//我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
//开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
//开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
//你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
//因此，无论怎样，你都不可能绕环路行驶一周
// 思路 由于每次加油消耗油  所以我们可以构建一个hash表 表示每次支出或收入情况  如果加的油多那么则为正 如果减的油多那么则为负
//    以实例1为例 hash可表示为 -2 -2 -2 3 3
//      由于车要行驶完全程 所以其油箱绝对不可以出现负数情况 
//          如果hash表中的所有数之和为负数 那么车无论怎么走都不可能走完全程 直接return -1
//          如果hash表中的所有数之和为正或为0，那么小车有可能走完全程
//             那么小车在怎样的情况下最有可能走完全程呢？
//                我们先对hash表画一个波峰波谷图
//             -2             -3
//                 -4      -3
//                     -6
//                       不难发现小车在波谷开始向上攀爬能走完全程
//                从感性上来讲  因为折线图从波谷往上走 意味着小车的油量一直在累积 （哪怕中间有曲折存在）
//            所以我们只要找到折线图的最小值便可
//     有一些边边角角问题 需要注意 hash中存在0的话 波谷不能停留在原处 是要一定往后走的 （比如gas={2，0，0，0，0...} cost={0,1,0,0,0...}
//    还有万一波谷处于最后一位 那么要特殊处理。
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int len = gas.size();
	vector<int> hash(len, 0);
	for (int i = 0; i < len; i++)
	{
		hash[i] = gas[i] - cost[i];
	}
	int min_x = hash[0];
	int min_i = 0;
	for (int i = 1; i < len; i++)
	{
		hash[i] += hash[i - 1];
		if (min_x >= hash[i])
		{
			min_x = hash[i];
			min_i = i;
		}
	}
	if (hash[len - 1] >= 0)
	{
		if (min_i + 1 == len)
		{
			return 0;
		}
		return min_i + 1;
	}
	return -1;
}
//int main()
//{
//	vector<int> gas = { 1,2 };
//	vector<int> cost = { 2,1 };
//	cout << canCompleteCircuit(gas, cost);
//}


//135. 分发糖果
//n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
//你需要按照以下要求，给这些孩子分发糖果：
//每个孩子至少分配到 1 个糖果。
//相邻两个孩子评分更高的孩子会获得更多的糖果。
//请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
//示例 1：
//输入：ratings = [1, 0, 2]
//输出：5
//解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
//示例 2：
//输入：ratings = [1, 2, 2]
//输出：4
//解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
//第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
//提示：
//n == ratings.length
//1 <= n <= 2 * 104
//0 <= ratings[i] <= 2 * 10
//   抬头言：同事二主 顾此失彼
//     对于此题 我们先考虑一边的情况
//   先从左往右 如果rating[i]>ratings[i-1] 那么i要比i-1多拿一个糖果 
//   再从右往左走 如果rating[i]>ratings[i+1] 那么是否i只需要简单比i+1多拿一个糖果呢？
//           是又不是  是 是因为i的的确确要比i+1多拿 
//                     不是 是因为 从左往右看 万一i比i-1还要大 那么i可就要比 i-1与i+1中多的那个还要多拿一个糖果了
//  最后return 数组求和
//      思考！ 我们是否可以参照上一题波峰波谷的思路给出答案呢？ （单调队列？？？）（单调队列中存储的元素为下标）（用单调队列的弹出过程去模拟构建波峰波谷图的过程）
int candy(vector<int>& ratings)
{
	vector<int> nums(ratings.size(), 1);
	for (int i = 1; i < ratings.size(); i++)
	{
		if (ratings[i] > ratings[i - 1])
		{
			nums[i] = nums[i - 1] + 1;
		}
	}
	for (int i = ratings.size() - 2; i >= 0; i--)
	{
		if (ratings[i] > ratings[i + 1])
		{
			nums[i] = max(nums[i], nums[i + 1] + 1);
		}
	}
	int sum = 0;
	for (auto i : nums)
	{
		sum += i;
	}
	return sum;
}
//int main()
//{
//	vector<int> ratings = { 1,0,2 };
//	cout << candy(ratings);
//}



//860. 柠檬水找零
//在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
//注意，一开始你手头没有任何零钱。
//给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
//示例 1：
//输入：bills = [5, 5, 5, 10, 20]
//输出：true
//解释：
//前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
//第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
//第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
//由于所有客户都得到了正确的找零，所以我们输出 true。
//示例 2：
//输入：bills = [5, 5, 10, 10, 20]
//输出：false
//解释：
//前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
//对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
//对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
//由于不是每位顾客都得到了正确的找零，所以答案是 false
//   提醒 当顾客给20时 我们的找零方式既可以是10+5 又可以是5+5+5
bool lemonadeChange(vector<int>& bills)
{
	int hash[3] = { 0,0,0 };
	for (int i = 0; i < bills.size(); i++)
	{
		if (bills[i] == 5)
		{
			++hash[0];
		}
		else if (bills[i] == 10)
		{
			++hash[1];
			--hash[0];
		}
		else
		{
			if (hash[1] > 0)
			{
				++hash[2];
				--hash[1];
				--hash[0];
			}
			else
			{
				hash[0] -= 3;
			}
		}
		for (auto i : hash)
		{
			cout << i << '\t';
		}
		cout << endl;
		if (hash[0] < 0 || hash[1] < 0 || hash[2] < 0)
		{
			return false;
		}
	}
	return true;
}
//int main()
//{
//	vector<int> bills = { 5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5 };
//	cout << lemonadeChange(bills);
//}


//406. 根据身高重建队列
//假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
//请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
//示例 1：
//输入：people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
//输出： [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
//解释：
//编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
//编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
//编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
//编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
//编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
//编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
//因此 [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]] 是重新构造后的队列。
//示例 2：
//输入：people = [[6, 0], [5, 0], [4, 0], [3, 2], [2, 2], [1, 4]]
//输出： [[4, 0], [5, 0], [2, 2], [3, 2], [1, 4], [6, 0]]
//思路是 先对people进行按身高从大到小排序 （如遇到同身高则比较第二位 第二位小的放前，第二位大的放后）
//   再一次遍历 对第二位进行处理 身高较矮的只需要看第二位与当前的所处的位置 差  依据这个差往前插入；
//          在数据结构上 由于数组并不是很方便插入操作 所以采用列表。
class reconstructqueue {
public:
	static bool mycomparison(vector<int>& lhs1, vector<int>& lhs2)
	{
		if (lhs1[0] == lhs2[0])
		{
			return lhs1[1] < lhs2[1];
		}
		return lhs1[0] > lhs2[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
	{
		sort(people.begin(), people.end(), mycomparison);
		list<vector<int>> que;
		for (int i = 0; i < people.size(); i++)
		{
			int position = people[i][1];
			auto it = que.begin();
			while (position--)//寻找插入位置
			{
				it++;
			}
			que.insert(it, people[i]);
		}
		return vector<vector<int>>(que.begin(), que.end());
	}
};


//452. 用最少数量的箭引爆气球
//有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。
//一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
//给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
//示例 1：
//输入：points = [[10, 16], [2, 8], [1, 6], [7, 12]]
//输出：2
//解释：气球可以用2支箭来爆破 :
//-在x = 6处射出箭，击破气球[2, 8]和[1, 6]。
//- 在x = 11处发射箭，击破气球[10, 16]和[7, 12]。
//示例 2：
//输入：points = [[1, 2], [3, 4], [5, 6], [7, 8]]
//输出：4
//解释：每个气球需要射出一支箭，总共需要4支箭。
//示例 3：
//输入：points = [[1, 2], [2, 3], [3, 4], [4, 5]]
//输出：2
//解释：气球可以用2支箭来爆破 :
//-在x = 2处发射箭，击破气球[1, 2]和[2, 3]。
//- 在x = 4处射出箭，击破气球[3, 4]和[4, 5]
// 思路是排序后 对首位元素的右值所能包括后位元素的最大左值
class FindMinArrowShots 
{
public:
	int findMinArrowShots(vector<vector<int>>& points) 
	{
		int res = 0;
		if (!points.size())return res;
		sort(points.begin(), points.end(), [](const vector<int>& x, const vector<int>& y) {return x[1] < y[1]; });
		int arrow = points[0][1];
		for (vector<int>& point : points)
		{
			if (point[0] > arrow)
			{
				arrow = point[1];
				res++;
			}
		}
		return res + 1;
	}
};



//435. 无重叠区间
//给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
//示例 1:
//输入: intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]
//输出 : 1
//解释 : 移除[1, 3] 后，剩下的区间没有重叠。
//示例 2 :
//输入 : intervals = [[1, 2], [1, 2], [1, 2]]
//输出 : 2
//解释 : 你需要移除两个[1, 2] 来使剩下的区间没有重叠。
//示例 3 :
//输入 : intervals = [[1, 2], [2, 3]]
//输出 : 0
//解释 : 你不需要移除任何区间，因为它们已经是无重叠的了
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
	sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y)
		{
			if (x[0] != y[0])
			{
				return x[0] < y[0];
			}
			else
			{
				return x[1] < y[1];
			}
		});
	int ans = 0;
	int right = intervals[0][1];//right 表示上次记录的所有右边界所能达到的最小右边界
	for (int i = 1; i < intervals.size(); i++)
	{
		if (right <= intervals[i][0])//无重叠
		{
			right = intervals[i][1];//则更新新的右边界
		}
		else//重叠  如果前面一位虽然左边界小但右边界极大的话 那么下一个甚至后几个都有可能包含在里面 所以要保留最小的右边界 建议画图
		{
			ans++;
			right = min(right, intervals[i][1]);//要选取最小的右边界
		}
	}
	return ans;
}





//56. 合并区间
//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
//示例 1：
//输入：intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
//输出： [[1, 6], [8, 10], [15, 18]]
//解释：区间[1, 3] 和[2, 6] 重叠, 将它们合并为[1, 6].
//示例 2：
//输入：intervals = [[1, 4], [4, 5]]
//输出： [[1, 5]]
//解释：区间[1, 4] 和[4, 5] 可被视为重叠区间。
//提示：
//1 <= intervals.length <= 104
//intervals[i].length == 2
//0 <= starti <= endi <= 10
//  由于前几题的铺垫 思路应该没什么难度
//        但我觉得这道题解的代码功底很强  很值得参考！！！
//             而且先对于前几题 这道题直接对ans做改变 而非 得出答案后再加入到ans中
vector<vector<int>> merge_extend(vector<vector<int>>& intervals)
{
	if (intervals.size() == 0)
	{
		return intervals;
	}
	sort(intervals.begin(), intervals.end(), [](const vector<int>& vec1, const vector<int>& vec2)
		{
			if (vec1[0] == vec2[0])
			{
				return vec1[1] < vec2[1];
			}
			return vec1[0] < vec2[0];
		});
	int len = intervals.size();
	vector<vector<int>> ans;
	ans.push_back(*intervals.begin());
	for (int i = 1; i < len; i++)
	{
		if (ans.back()[1] >= intervals[i][0])
		{
			ans.back()[1] = max(ans.back()[1], intervals[i][1]);
		}
		else
		{
			ans.push_back(intervals[i]);
		}
	}
	return ans;
}
//int main()
//{
//	vector<vector<int>> intervals = {
//		{1,4},
//		{5,6}
//	};
//	for (auto i : merge_extend(intervals))
//	{
//		for (auto j : i)
//		{
//			cout << j << '\t';
//		}
//		cout << endl;
//	}
//}




//738. 单调递增的数字
//当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
//给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
//示例 1:
//输入: n = 10
//输出 : 9
//示例 2 :
//输入 : n = 1234
//输出 : 1234
//示例 3 :
//输入 : n = 332
//输出 : 299
//注意可能动态改变的题目写多了 但该题目不能动态改变原来的数字  不然只可能会得到一个相对较大的数而非最大数 比如（963856657）
bool increasing_function(string s)
{
	if (s.size() == 1)
	{
		return true;
	}
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i - 1] > s[i])
		{
			return false;
		}
	}
	return true;
}
int monotoneIncreasingDigits(int n)
{
	string s = to_string(n);
	int flag = s.size();
	for (int i = flag - 1; i > 0; i--)
	{
		if (s[i - 1] > s[i])
		{
			flag = i;
			s[i - 1]--;
		}
	}
	for (int i = flag; i < s.size(); i++)
	{
		s[i] = '9';
	}
	return stoi(s);
}
//int main()
//{
//	cout << monotoneIncreasingDigits(963856657);
//}



