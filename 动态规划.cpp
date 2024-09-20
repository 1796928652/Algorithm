#include<iostream>
#include<vector>
using namespace std;
//动态规划部分
// 
// 
// 
// 
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//int numsWays(int n)
//{
//    int sum = 0;
//    if (n == 1 || n == 0)
//    {
//        return sum += 1;
//    }
//    else if (n == 2)
//    {
//        return sum += 2;
//    }
//    else
//    {
//        return numsWays(n - 1) + numsWays(n - 2);
//    }
//}
//int numsWays2(int n)
//{
//    vector<int> arr = { 1,1,2 };
//    for (int i = 3; i <= n; i++)
//    {
//        arr.push_back(arr[i - 2] + arr[i - 1]);
//    }
//    return arr[n];
//}



//子序列问题
// 
// 动态规划考虑五个问题
// dp含义   递推公式  初始化   遍历顺序   求出结果
// 
// 
// 
// 
// 674. 最长连续递增序列
//给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
//连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
//	示例 1：
//	输入：nums = [1, 3, 5, 4, 7]
//	输出：3
//	解释：最长连续递增序列是[1, 3, 5], 长度为3。
//	尽管[1, 3, 5, 7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
//	示例 2；
//	输入：nums = [2, 2, 2, 2, 2]
//	输出：1
//	解释：最长连续递增序列是[2], 长度为1。
//	提示：
//	1 <= nums.length <= 104
//	- 109 <= nums[i] <= 109
//	int findLengthOfLCIS(vector<int>&nums)
//{
//	size_t len = nums.size();
//	vector<int> dp(len, 1);
//	int max = 1;
//	for (int i = 1; i < len; i++)
//	{
//		if (nums[i] > nums[i - 1])
//		{
//			dp[i] = dp[i - 1] + 1;
//			if (max < dp[i])
//			{
//				max = dp[i];
//			}
//		}
//	}
//	return max;
//}
//int main()
//{
//	vector<int> nums = { 2,2,2,2 };
//	cout << findLengthOfLCIS(nums);
//}


//300. 最长递增子序列
//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3, 6, 2, 7] 是数组[0, 3, 1, 6, 2, 2, 7] 的子序列。
//示例 1：
//输入：nums = [10, 9, 2, 5, 3, 7, 101, 18]
//输出：4
//解释：最长递增子序列是[2, 3, 7, 101]，因此长度为 4 。
//示例 2：
//输入：nums = [0, 1, 0, 3, 2, 3]
//输出：4
//示例 3：
//输入：nums = [7, 7, 7, 7, 7, 7, 7]
//输出：1
//1 <= nums.length <= 2500
//- 104 <= nums[i] <= 104
// 思路 ： 定义一个动态数组dp dp[i]的含义是从0到i这个数（包括i）的最长递增子序列的长度
// 接下来考虑递推公式  由于i所代表的数是必取的 另设一个下标j 如果j所代表的数是要小于i所代表的数则dp[i]=dp[j]+1  由于j所代表的数不一定只有一个 所以我们要求出 符合条件的dp[j]的最大值
// 则递推公式可以表示为dp[i]=max(dp[j]+1,dp[i]);
// 接下里考虑初始化的问题  由于每个数都能和它自己成为一个序列 所以每个dp值都为1
// 遍历问题： 直接用i遍历 i代表nums中每个数的下标 另设下标j j从0到i找到第i个时的最大递增子序列长度
//int lengthOfLIS(vector<int>&nums)
//{
//	size_t n = nums.size();
//	vector<int> dp(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		dp[i] = 1;
//		for (int j = 0; j < i; j++)
//		{
//			if (nums[j] < nums[i])
//			{
//				dp[i] = max(dp[i], dp[j] + 1);
//			}
//		}
//	}
//	return *max_element(dp.begin(), dp.end());
//}
//   看看这一题和上一次的差别在于 是否连续 因为上一题要求连续所以dp[i]只和dp[i-1]有关 但本题没有连续所以和0到i中某个数j（dp[j]）有关！！！




//718. 最长重复子数组
//给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
//示例 1：
//输入：nums1 = [1, 2, 3, 2, 1], nums2 = [3, 2, 1, 4, 7]
//输出：3
//解释：长度最长的公共子数组是[3, 2, 1] 。
//示例 2：
//输入：nums1 = [0, 0, 0, 0, 0], nums2 = [0, 0, 0, 0, 0]
//输出：5
//提示：
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 100
//思路一 暴力求解先找到相同的数字 再求重复的数组长度  找到最大的重复数组长度
//int findLength(vector<int>&nums1, vector<int>&nums2)
//{
//	size_t len1 = nums1.size();
//	size_t len2 = nums2.size();
//	int maxn = 0;
//	for (int i = 0; i < len1; i++)
//	{
//		for (int j = 0; j < len2; j++)
//		{
//			if (nums1[i] == nums2[j])
//			{
//				int len = 1;
//				int m = i + 1;
//				int n = j + 1;
//				while (m < len1 && n < len2 && nums1[m] == nums2[n])
//				{
//					len += 1;
//					m++;
//					n++;
//				}
//				maxn = max(maxn, len);
//
//			}
//		}
//	}
//	return maxn;
//}
//思路二 动态规划  先不讲思路起 直接上例子 便于理解
//                     对于 nums1 = [1, 2, 3, 2, 1], nums2 = [3, 2, 1, 4, 7]
//          我们先看一个二维图  
//	                 1		2		3		2		1
//				3	 				1				
//				2	 		1				2(1+1)	
//				1	 1								3(2+1)
//				4			0										
//				7
//             效果图：
//					0       0       0       0       0       0
//					0       0       0       1       0       0
//					0       0       1       0       0       0
//					0       1       0       0       0       0
//					0       0       2       0       0       0
//					0       0       0       3       0       0
//	      不难发现  对于一段重复的子数组来讲 其所能构成的长度(在表格里的数字) 是由上一个重复数字所在表格里构成的长度加1的来的
//	      那么由此 写出我们的状态转移方程 dp[i][j]=dp[i-1][j-1]+1
//	      但还需要注意的是 越界问题  对于重复子数组里的第一个重复数字 我们的状态转移方程可能回发生越界问题 所以我们多加一行和一列
//		  最后 在循环中 设立一个变量 man_n 利用循环找到最大值
//int findLength2(vector<int>& nums1, vector<int>& nums2)
//{
//	size_t len1 = nums1.size();
//	size_t len2 = nums2.size();
//	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
//	int max_n = 0;
//	for (int i = 1; i <= len1; i++)
//	{
//		for (int j = 1; j <= len2; j++)
//		{
//			if (nums1[i - 1] == nums2[j - 1])
//			{
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//				if (max_n < dp[i][j])
//				{
//					max_n = dp[i][j];
//				}
//			}
//		}
//	}
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			cout << j << '\t';
//		}
//		cout << endl;
//	}
//	return max_n;
//}
//int main()
//{
//	vector<int> nums1 = { 1,2,3,2,1 };
//	vector<int> nums2 = { 3,2,1,4,7 };
//	cout << findLength2(nums1, nums2);
//}

//和上一次很像 但要做出变化 看完上一题一定要试试
//1143. 最长公共子序列
//给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
//一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
//例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
//两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
//示例 1：
//输入：text1 = "abcde", text2 = "ace"
//输出：3
//解释：最长公共子序列是 "ace" ，它的长度为 3 。
//示例 2：
//输入：text1 = "abc", text2 = "abc"
//输出：3
//解释：最长公共子序列是 "abc" ，它的长度为 3 。
//示例 3：
//输入：text1 = "abc", text2 = "def"
//输出：0
//解释：两个字符串没有公共子序列，返回 0 。
//提示：
//1 <= text1.length, text2.length <= 1000
//text1 和 text2 仅由小写英文字符组成
//思路 ：和上一次动态规划类似 也是通过创造二维dp来解决
//            先给出二维图 便于理解
//	                      a		b		c		d		e
//	                  a	  1		0		0		0		0
//					  c	  0		0		2(1+1)	0		0
//					  e	  0		0		0		0		3(2+1)
//	         从图中不难看出 其实动态转移方程为 dp[i][j] =  0到i-1与0到j-1这个交叉范围的最大值 +1 
//	int longestCommonSubsequence(string text1, string text2)
//{
//	size_t len1 = text1.size();
//	size_t len2 = text2.size();
//	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
//	int max = 0;
//	for (int i = 1; i <= len1; i++)
//	{
//		for (int j = 1; j <= len2; j++)
//		{
//			if (text1[i - 1] == text2[j - 1])
//			{
//				int max_dp = 0;
//				for (int m = 0; m < i; m++)
//				{
//					for (int n = 0; n < j; n++)
//					{
//						if (max_dp < dp[m][n])
//						{
//							max_dp = dp[m][n];
//						}
//					}
//				}
//				dp[i][j] = max_dp + 1;
//			}
//			if (max < dp[i][j])
//			{
//				max = dp[i][j];
//			}
//		}
//	}
//	return max;
//}
//int main()
//{
//	string text1 = "abc";
//	string text2 = "abc";
//	cout << longestCommonSubsequence(text1, text2);
//}
//          但由于本身两层循环里又嵌套了两层循环  会导致超时问题  所以该方法 在找0到i-1与0到j-1交叉范围里的最大值需要优化
//			  这里可以考虑下hash表 通过hash表来使得重复数字之间有对应的下标关系
//			                 这里给出一个例子
//			                          a		b	c	d	e
//                             1<-a	  1
//			                 5<-e                       2
//			                 3<-c               2
//                      可以看到这里c通过hash表对应3号位置 则可以直接通过找比3小的数  。。。。。。突然想到hash表还是很麻烦  所以
//			  换个思路   可以把上面那个表格改成下面这个表格
//			      a		b		c		d		e
//			  a	  1		1		1		1		1
//			  c	  1		1		2(1+1)	2		2
//			  e	  1		1		2		2		3(2+1)
//			  这时候 状态转移方程
//			                    if (text1[i]==text2[j]) 则dp[i][j] = dp[i - 1][j - 1] + 1
//								else   dp[i][j]=max(dp[i-1][j],dp[i][j-1] 
//                              但要仔细想想为什么else后面是这两个dp！！！！
//int longestCommonSubsequence(string text1, string text2)
//{
//	size_t len1 = text1.size();
//	size_t len2 = text2.size();
//	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
//	int maxn = 0;
//	for (int i = 1; i <= len1; i++)
//	{
//		for (int j = 1; j <= len2; j++)
//		{
//			if (text1[i - 1] == text2[j - 1])
//			{
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			}
//			else
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//			if (maxn < dp[i][j])
//			{
//				maxn = dp[i][j];
//			}
//		}
//	}
//	return maxn;
//}


//上面一题实在太好了  所以再来一题（开心）
//1035. 不相交的线
//在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
//现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：
//nums1[i] == nums2[j]
//且绘制的直线不与任何其他连线（非水平线）相交。
//请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
//以这种方法绘制线条，并返回可以绘制的最大连线数。
//示例 1
//输入：nums1 = [1, 4, 2], nums2 = [1, 2, 4]
//输出：2
//解释：可以画出两条不交叉的线，如上图所示。
//但无法画出第三条不相交的直线，因为从 nums1[1] = 4 到 nums2[2] = 4 的直线将与从 nums1[2] = 2 到 nums2[1] = 2 的直线相交。
//示例 2：
//输入：nums1 = [2, 5, 1, 2, 5], nums2 = [10, 5, 2, 1, 5, 2]
//输出：3
//示例 3：
//输入：nums1 = [1, 3, 7, 1, 7, 5], nums2 = [1, 9, 2, 5, 1]
//输出：2
//提示：
//1 <= nums1.length, nums2.length <= 500
//1 <= nums1[i], nums2[j] <= 2000
////    具体思路   换汤不换药！！！
//int maxUncrossedLines(vector<int>&nums1, vector<int>&nums2)
//{
//	size_t len1 = nums1.size();
//	size_t len2 = nums2.size();
//	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
//	int maxn = 0;
//	for (int i = 1; i <= len1; i++)
//	{
//		for (int j = 1; j <= len2; j++)
//		{
//			if (nums1[i - 1] == nums2[j - 1])
//			{
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			}
//			else
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//			if (maxn < dp[i][j])
//			{
//				maxn = dp[i][j];
//			}
//		}
//	}
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			cout << j << '\t';
//		}
//		cout << endl;
//	}
//	return maxn;
//}
//int main()
//{
//	vector<int> nums1 = { 2,5,1,2,5 };
//	vector<int> nums2 = { 10,5,2,1,5,2 };
//	cout << maxUncrossedLines(nums1, nums2);
//}


//53.最大子数组和
//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//子数组 是数组中的一个连续部分。
//示例 1：
//输入：nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//输出：6
//解释：连续子数组[4, -1, 2, 1] 的和最大，为 6 。
//示例 2：
//输入：nums = [1]
//输出：1
//示例 3：
//输入：nums = [5, 4, -1, 7, 8]
//输出：23
//提示：
//1 <= nums.length <= 105
//- 104 <= nums[i] <= 104
//要求实现复杂度为 O(n) 的解法，
//int maxSubArray(vector<int>&nums)
//{
//	size_t len = nums.size();
//	if (len == 1)
//	{
//		return nums[0];
//	}
//	vector<int> dp;
//	dp.push_back(nums[0]);
//	for (int i = 1; i < len; i++)
//	{
//		dp.push_back(max(nums[i], dp[i - 1] + nums[i]));
//	}
//	for (auto i : dp)
//	{
//		cout << i << '\t';
//	}
//	cout << endl;
//	return *max_element(dp.begin(), dp.end());
//}
//int main()
//{
//	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
//	cout << maxSubArray(nums);
//}


//392. 判断子序列
//给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
//字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
//进阶：
//如果有大量输入的 S，称作 S1, S2, ..., Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
//示例 1：
//输入：s = "abc", t = "ahbgdc"
//输出：true
//示例 2：
//输入：s = "axc", t = "ahbgdc"
//输出：false
//提示：
//0 <= s.length <= 100
//0 <= t.length <= 10 ^ 4
//两个字符串都只由小写字符组成
// 
// 思路一：动态规划   思路和上面几题相似
//bool isSubsequence(string s, string t)
//{
//	size_t len1 = s.size();
//	size_t len2 = t.size();
//	int maxn = 0;
//	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
//	for (int i = 1; i <= len1; i++)
//	{
//		for (int j = 1; j <= len2; j++)
//		{
//			if (s[i - 1] == t[j - 1])
//			{
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			}
//			else
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//			if (maxn < dp[i][j])
//			{
//				maxn = dp[i][j];
//			}
//		}
//	}
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			cout << j << '\t';
//		}
//		cout << endl;
//	}
//	if (maxn == len1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
// 
// 
// 思路二 ：// 这是从双指针的角度考虑的
// 用i遍历一遍大循环  再另设一指针j 用于标记子序列的下标  
// 如果有相等的字符则j++  最后判断j是否等于子序列长度 如等于则为true
//bool isSubsequence(string s, string t)
//{
//	size_t len1 = s.size();
//	size_t len2 = t.size();
//	int j = 0;
//	for (int i = 0; i < len2; i++)
//	{
//		if (t[i] == s[j])
//		{
//			j++;
//		}
//	}
//	if (j == len1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}







//724. 寻找数组的中心下标
//给你一个整数数组 nums ，请计算数组的 中心下标 。
//数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
//如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 - 1 。
//输入：nums = [1, 7, 3, 6, 5, 6]
//输出：3
//解释：
//中心下标是 3 。
//左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
//右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
//示例 2：
//输入：nums = [1, 2, 3]
//输出： - 1
//解释：
//数组中不存在满足此条件的中心下标。
//示例 3：
//输入：nums = [2, 1, -1]
//输出：0
//解释：
//中心下标是 0 。
//左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
//右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0
//int pivotIndex(vector<int>&nums)
//{
//	int sumright = 0;
//	int sumleft = 0;
//	int len = 0;
//	for (auto i : nums)
//	{
//		sumright += i;
//		len++;
//	}
//	sumright -= nums[0];
//	if (sumright == sumleft)
//	{
//		return 0;
//	}
//	sumleft += nums[0];
//	for (int i = 1; i < len; i++)
//	{
//		sumright -= nums[i];
//		if (sumleft == sumright)
//		{
//			return i;
//		}
//		sumleft += nums[i];
//	}
//	return -1;
//}
//int main()
//{
//	vector<int> nums = { 2, 1, -1 };
//	cout << pivotIndex(nums);
//}


//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额
//int rob(vector<int>& nums)
//{
//    int n = nums.size();
//    vector<int> a = { nums[0] };
//    if (n == 1)
//    {
//        return a[0];
//    }
//    else
//    {
//        a.push_back(max(nums[0], nums[1]));
//    }
//    for (int i = 2; i < n; i++)
//    {
//        a.push_back(max(a[i - 2] + nums[i], a[i - 1]));
//    }
//    return max(a[a.size() - 1], a[a.size() - 2]);
//}

//打家劫舍2 假设首尾相连呢？？  如何要打劫第一间房 那么打劫范围就是第一间到倒数第二间，如果要打劫第二间房，那么打劫范围就是第二间到倒数第一间  分两种情况讨论就行；
//int robRange(vector<int>& nums, int start, int end)
//{
//    int first = nums[start], second = max(nums[start], nums[start + 1]);
//    for (int i = start + 2; i <= end; i++)
//    {
//        int temp = second;
//        second = max(first + nums[i], second);
//        first = temp;
//    }
//    return second;
//}
//
//int rob(vector<int>& nums) {
//    int length = nums.size();
//    if (length == 1) {
//        return nums[0];
//    }
//    else if (length == 2) {
//        return max(nums[0], nums[1]);
//    }
//    return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
//}

//打家劫舍进化版
//删除并获得点数
//给你一个整数数组 nums ，你可以对它进行一些操作。
//每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
//开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数
//我这个思路的核心在于用下标来表示具体的数  而下标所指的值则是具体的数的个数
//int count(int n, vector<int>& nums)
//{
//    int count = 0;
//    for (auto i : nums)
//    {
//        if (n == i)
//        {
//            count += 1;
//        }
//    }
//    return count;
//}
//int deleteAndEarn(vector<int>& nums)
//{
//    vector<int>arr;
//    if (count(nums[0], nums) == nums.size())
//    {
//        return nums[0] * count(nums[0], nums);
//    }
//    sort(nums.begin(), nums.end());
//    for (auto it : nums)
//    {
//        cout << it;
//    }
//    cout << endl;
//    for (int j = 0; j <= nums[nums.size() - 1]; j++)
//    {
//        if (find(nums.begin(), nums.end(), j) == nums.end())
//        {
//            arr.push_back(0);
//        }
//        else
//        {
//            arr.push_back(count(j, nums));
//        }
//    }
//    for (auto i : arr)
//    {
//        cout << i;
//    }
//    cout << endl;
//    vector<int>s = { 0 };
//    s.push_back(arr[1]);
//    s.push_back(max(arr[2] * 2, s[1]));
//    for (int i = 3; i < arr.size(); i++)
//    {
//        s.push_back(max(i * arr[i] + s[i - 2], s[i - 1]));
//    }
//    return max(s[s.size() - 1], s[s.size() - 2]);
//
//}


/*121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
示例 1：
输入：[7, 1, 5, 3, 6, 4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6 - 1 = 5 。
注意利润不能是 7 - 1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2：
输入：prices = [7, 6, 4, 3, 1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0*/
int maxProfit_1(vector<int>& prices)
{
	int len = prices.size();
	vector<int> dp(len, 0);
	int min_x = prices[0];
	for (int i = 1; i < len; i++)
	{
		if (prices[i] > min_x)
		{
			dp[i] = max(dp[i - 1], prices[i] - min_x);
		}
		else
		{
			min_x = prices[i];
			dp[i] = dp[i - 1];
		}
	}
	return dp[len - 1];
}


int coinChange(vector<int>& coins, int amount)
{
	int len = coins.size();
	vector<int> dp(amount + 1, INT16_MAX);
	dp[0] = 0;
	//for (int i = 0; i < len; i++) 其实这里可以不做初始化 因为初始化可被包含在下面；
	//{
	//	dp[coins[i]] = 1;
	//}
	for (int i = 1; i < amount + 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i - coins[j] >= 0)
			{
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	if (dp[amount] == INT16_MAX)
	{
		return -1;
	}
	return dp[amount];
}


//解码方法
//一条包含字母 A - Z 的消息通过以下映射进行了 编码 ：
//'A' -> "1"
//'B' -> "2"
//.......
//'Z' -> "26"
//要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
//"AAJF" ，将消息分组为(1 1 10 6)
//"KJF" ，将消息分组为(11 10 6)
//注意，消息不能分组为(1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
//给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。
//题目数据保证答案肯定是一个 32 位 的整数。
//示例 1：
//输入：s = "12"
//输出：2
//解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
//示例 2：
//输入：s = "226"
//输出：3
//解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
//示例 3：
//输入：s = "06"
//输出：0
//解释："06" 无法映射到 "F" ，因为存在前导零（"6" 和 "06" 并不等价）。
//int numDecodings(string s)
//{
//	if (s[0] == '0')
//	{
//		return 0;
//	}
//	vector<int> dp(100, 0);
//	int len = s.size();
//	dp[0] = 1;
//	for (int i = 1; i < len; i++)
//	{
//		if (s[i] != '0')
//		{
//			dp[i] += dp[i - 1];
//		}
//		int val = (s[i - 1] - '0') * 10 + s[i] - '0';
//		if (val <= 26 && val >= 10)
//		{
//			if (i == 1)
//			{
//				dp[i]++;
//			}
//			else
//			{
//				dp[i] += dp[i - 2];
//			}
//		}
//	}
//	return dp[len - 1];
//}
//int main()
//{
//	string s = "202";
//	cout << numDecodings(s);
//}








//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//问总共有多少条不同的路径？
// 思路一 从排列组合的角度出发  机器人要从左上角走到右下角则必须要走m+n-2步 在这m+n-2步中只需要有m-1或者n-1步则有Cmin(m-1,n-1)/(m+n-2）
//int uniquePaths(int m, int n)
//{
//    int sum = 1;
//    for (int x = m + n - 2, y = 1; y < min(m, n); x--, y++)
//    {
//        sum = sum * x / y;
//    }
//    return sum;
//}
//思路二 从递归的角度出发  要走到（m,n)的方法为走到（m-1，n）或者走到（m，n-1）的方法之和；
//int uniquePaths2(int m, int n)
//{
//    if (m == 1 || n == 1)
//    {
//        return 1;
//    }
//    else
//    {
//        return uniquePaths2(m - 1, n) + uniquePaths2(m, n - 1);
//    }
//}
//但考虑到这样的递归在面对大数据的时候执行效率问题不高 需改进优化
//int uniquePaths3(int m, int n)
//{
//    vector<vector<int>> s(m, vector<int>(n));
//    for (int j = 0; j < n; j++)
//    {
//        s[0][j] = 1;
//    }
//    for (int j = 0; j < m; j++)
//    {
//        s[j][0] = 1;
//    }
//    for (int i = 1; i < m; i++)
//    {
//        for (int j = 1; j < n; j++)
//        {
//            s[i][j] = s[i - 1][j] + s[i][j - 1];
//        }
//    }
//    for (auto i : s)
//    {
//        for (auto j : i)
//        {
//            cout << j << '\t';
//        }
//        cout << endl;
//    }
//    return s[m - 1][n - 1];
//}
//这里我们运用动态数组来存储到每个点的走法，运行效率加快




//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//说明：每次只能向下或者向右移动一步。
//int minPathSum(vector<vector<int>>& grid)
//{
//    if (grid.size() == 0 || grid[0].size() == 0) {
//        return 0;
//    }
//    int rows = grid.size(), columns = grid[0].size();
//    for (int i = 1; i < columns; i++)
//    {
//        grid[0][i] = grid[0][i] + grid[0][i - 1];
//    }
//    for (int i = 1; i < rows; i++)
//    {
//        grid[i][0] = grid[i][0] + grid[i - 1][0];
//    }
//    for (int i = 1; i < rows; i++)
//    {
//        for (int j = 1; j < columns; j++)
//        {
//            grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
//        }
//    }
//    return grid[rows - 1][columns - 1];
//}
//int main()
//{
//    vector<vector<int>> cost = { {1,3,1},{1,5,1},{4,2,1} };
//    cout << minPathSum(cost);
//}






//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//网格中的障碍物和空位置分别用 1 和 0 来表示。
//int uniquePathsWithObstacles(vector<vector<int>>&obstacleGrid)
//{
//    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//    vector<int>s(n);
//    s[0] = (obstacleGrid[0][0] == 0);
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (obstacleGrid[i][j] == 1)
//            {
//                s[j] = 0;
//                continue;
//            }
//            if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
//            {
//                s[j] = s[j] + s[j - 1];
//            }
//        }
//    }
//    return s.back();
//}

//
//LCR 091. 粉刷房子
//假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。
//当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的正整数矩阵 costs 来表示的。
//例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。
//请计算出粉刷完所有房子最少的花费成本。
//示例 1：
//输入 : costs = [[17, 2, 17], [16, 16, 5], [14, 3, 19]]
//输出 : 10
//解释 : 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
//最少花费 : 2 + 5 + 3 = 10。
//示例 2：
//输入 : costs = [[7, 6, 2]]
//输出 : 2
//提示 :
//    costs.length == n
//    costs[i].length == 3
//    1 <= n <= 100
//    1 <= costs[i][j] <= 20
// 思路 ：广度优先搜索  关于dp[i][j]的取值则是min(costs[i][j]+dp[i-1][x]  x代表0到2中除j的另外两个数)
//	int minCost(vector<vector<int>>&costs)
//{
//	size_t rows = costs.size();
//	size_t columns = costs[0].size();
//	vector<vector<int>> dp(rows, vector<int>(columns, 0));
//	for (int i = 0; i < 3; i++)
//	{
//		dp[0][i] = costs[0][i];
//	}
//	for (int i = 1; i < rows; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			int minx = 10000;
//			for (int m = 0; m < 3; m++)
//			{
//				if (m != j)
//				{
//					minx = min(minx, costs[i][j] + dp[i - 1][m]);
//				}
//			}
//			dp[i][j] = minx;
//		}
//	}
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			cout << j << '\t';
//		}
//		cout << endl;
//	}
//	return *min_element(dp[rows - 1].begin(), dp[rows - 1].end());
//}
//int main()
//{
//	vector<vector<int>> costs = { {17, 2, 17},{16, 16, 5},{14, 3, 19} };
//	cout << minCost(costs);
//}



//给定一个三角形 triangle ，找出自顶向下的最小路径和。
//每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
//int minimumTotal(vector<vector<int>>&triangle)
//{
//    int rows = triangle.size(), column = triangle[0].size();
//    vector<vector<int>>s = triangle;
//    cout << "********" << endl;
//    for (int i = 1; i < rows; i++)
//    {
//        for (int j = 0; j <= i; j++)
//        {
//            if (j == 0)
//            {
//                s[i][j] = s[i][j] + s[i - 1][j];
//            }
//            else if (j == i)
//            {
//                s[i][j] = s[i][j] + s[i - 1][j - 1];
//            }
//            else
//            {
//                s[i][j] = s[i][j] + min(s[i - 1][j - 1], s[i - 1][j]);
//            }
//        }
//    }
//    for (auto i : s)
//    {
//        for (auto item : i)
//        {
//            cout << item << '\t';
//        }
//        cout << endl;
//    }
//    cout << endl;
//    int summin = s[rows - 1][0];
//    for (int i = 0; i < rows; i++)
//    {
//        if (summin > s[rows - 1][i])
//        {
//            summin = s[rows - 1][i];
//        }
//    }
//    return summin;
//
//}
//int main()
//{
//    vector<vector<int>> obstacleGrid;
//    obstacleGrid = {
//        {2} ,
//        {3,4},
//        {6,5,7},
//        {4,1,8,3}
//    };
//    cout << minimumTotal(obstacleGrid);
//}    ps:请思考是=是否有节省空间的做法（利用滚动数组）




//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
//matrix = [["1", "0", "1", "0", "0"],
//          ["1", "0", "1", "1", "1"], 
//          ["1", "1", "1", "1", "1"], 
//          ["1", "0", "0", "1", "0"]]
//int maximalSquare(vector<vector<char>>& matrix)
//{
//    size_t rows = matrix.size(), columns = matrix[0].size();
//    vector<vector<int>>matrix1 = { rows,vector<int>(columns) };
//    int max = '0';
//    for (int i = 0; i < columns; i++)
//    {
//        matrix1[0][i] = matrix[0][i] - '0';
//    }
//    for (int i = 0; i < rows; i++)
//    {
//        matrix1[i][0] = matrix[i][0] - '0';
//    }
//    for (auto i : matrix)
//    {
//        for (auto j : i)
//        {
//            if (j != '0')
//            {
//                max = 1;
//            }
//        }
//    }
//    for (int i = 1; i < rows; i++)
//    {
//        for (int j = 1; j < columns; j++)
//        {
//            if (matrix[i][j] != '0')
//            {
//                matrix1[i][j] = min(min(matrix1[i - 1][j - 1], matrix1[i - 1][j]), matrix1[i][j - 1]) + 1;
//            }
//            if (max < matrix1[i][j])
//            {
//                max = matrix1[i][j];
//            }
//        }
//    }
//    for (auto i : matrix1)
//    {
//        for (auto j : i)
//        {
//            cout << j << '\t';
//        }
//        cout << endl;
//    }
//    return pow(max, 2);
//}
//int main()
//{
//    vector<vector<char>>matrix =
//    {
//        {'1','0','1','0','0'},
//        {'1','0','1','1','1'},
//        {'1','1','1','1','1'},
//        {'1','0','0','1','0'}
//    };
//    cout << maximalSquare(matrix);
//}
// 
// 
// 
//上面这个是好题  所以再来一题；
// // 1277. 统计全为 1 的正方形子矩阵
//给你一个 m* n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。
//示例 1：
//输入：matrix =
//[
//	[0, 1, 1, 1],
//		[1, 1, 1, 1],
//		[0, 1, 1, 1]
//]
//输出：15
//解释：
//边长为 1 的正方形有 10 个。
//边长为 2 的正方形有 4 个。
//边长为 3 的正方形有 1 个。
//正方形的总数 = 10 + 4 + 1 = 15.
//示例 2：
//输入：matrix =
//[
//	[1, 0, 1],
//		[1, 1, 0],
//		[1, 1, 0]
//]
//输出：7
//解释：
//边长为 1 的正方形有 6 个。
//边长为 2 的正方形有 1 个。
//正方形的总数 = 6 + 1 = 7.
//提示：
//1 <= arr.length <= 300
//1 <= arr[0].length <= 300
//0 <= arr[i][j] <= 1
// 
//int countSquares(vector<vector<int>>&matrix)
//{
//	size_t rows = matrix.size();
//	size_t columns = matrix[0].size();
//	vector<vector<int>> dp = matrix;
//	for (size_t i = 1; i < rows; i++)
//	{
//		for (size_t j = 1; j < columns; j++)
//		{
//			if (dp[i][j] == 1 && dp[i - 1][j - 1] > 0 && dp[i - 1][j] > 0 && dp[i][j - 1] > 0)
//			{
//				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
//			}
//		}
//	}
//	int sum = 0;
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			sum += j;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	vector<vector<int>> matrix =
//	{
//		{0, 1, 1, 1},
//		{1, 1, 1, 1},
//		{0, 1, 1, 1}
//	};
//	cout << countSquares(matrix);
//}

//给你一个字符串 s，找到 s 中最长的回文子串。
//如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
// 方法一  从外向内 先判断外层字母是否相同，再判断下一个字母是否相同
//string longestPalindrome(string s)
//{
//    size_t len = s.length();
//    if (len < 2)
//    {
//        return s;
//    }
//    string a = s.substr(0, 1);
//    size_t maxlength = 0;
//    for (int i = 0; i < len; i++)
//    {
//        for (int j = len - 1; j > i; j--)
//        {
//            if (s[i] == s[j])
//            {
//                for (int m = i; m <= (i + j) / 2; m++)
//                {
//                    if (s[m] != s[i + j - m])
//                    {
//                        break;
//                    }
//                    if (m == (i + j) / 2)
//                    {
//                        if (j - i + 1 > maxlength)
//                        {
//                            maxlength = j - i + 1;
//                            a.clear();
//                            a = (s.substr(i, maxlength));
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return a;
//}
//int main()
//{
//    string s = "aacabdkacaa";
//    cout << longestPalindrome(s);
//
//}
//方法二 运用动态规划的思想  从内向外:中心扩展法  如果是回文串则内部必相同 再向两边扩展一位看两边是否相同 然后返回最大串
//pair<int, int> expandAroundCenter(const string& s, int left, int right) {
//    while (left >= 0 && right < s.size() && s[left] == s[right]) {
//        --left;
//        ++right;
//    }
//    return { left + 1, right - 1 };
//}
//
//string longestPalindrome(string s) {
//    int start = 0, end = 0;
//    pair<int, int>T1 = { 0,0 };
//    pair<int, int>T2 = { 0 ,0 };
//    for (int i = 0; i < s.size(); ++i) {
//        T1 = expandAroundCenter(s, i, i);
//        T2 = expandAroundCenter(s, i, i + 1);
//        if (T1.second - T1.first > end - start) {
//            start = T1.first;
//            end = T1.second;
//        }
//        if (T2.second - T2.first > end - start) {
//            start = T2.first;
//            end = T2.second;
//        }
//    }
//    return s.substr(start, end - start + 1);
//}
//int main()
//{
//    string s = "aacabdkacaa";
//    cout << longestPalindrome(s);
//}










//背包问题  在有限的空间里装价值度最高的物品
//int bag(vector<int> a, vector<int> b, int m)//a代表每个物品的体积 b代表每个物品的价值 m代表背包的总空间大小
//{
//	size_t row = a.size();
//	vector<vector<int>> dp = { row + 1,vector<int>(m + 1) };
//	for (int i = 0; i <= m; i++)
//	{
//		dp[0][i] = 0;
//	}
//	for (int i = 0; i <= row; i++)
//	{
//		dp[i][0] = 0;
//	}
//	for (int i = 1; i <= row; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (j >= a[i - 1])
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + b[i - 1]);
//			}
//			else
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//		}
//	}
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			cout << j << '\t';
//		}
//		cout << endl;
//	}
//	return dp[row][m];
//}


//416. 分割等和子集
//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//示例 1：
//输入：nums = [1, 5, 11, 5]
//输出：true
//解释：数组可以分割成[1, 5, 5] 和[11] 。
//示例 2：
//输入：nums = [1, 2, 3, 5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
//提示：
//1 <= nums.length <= 200
//1 <= nums[i] <= 100
//bool canPartition(vector<int>&nums)
//{
//	int sum = 0;
//	int max_num = 0;
//	for (auto i : nums)
//	{
//		sum += i;
//		if (i > max_num)
//		{
//			max_num = i;
//		}
//	}
//	if (sum & 1)
//	{
//		return false;
//	}
//	int target = sum / 2;
//	if (max_num > target)
//	{
//		return false;
//	}
//	size_t len = nums.size();
//	vector<vector<bool>> dp(len + 1, vector<bool>(target + 1, 0));
//	for (size_t i = 0; i < len; ++i)
//	{
//		dp[i][0] = 1;
//	}
//	for (size_t i = 1; i < len + 1; i++)
//	{
//		for (size_t j = 0; j <= target; j++)
//		{
//			if (j >= nums[i - 1])
//			{
//				dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - nums[i - 1]]);
//			}
//			else
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//		}
//	}
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			cout << j << "\t";
//		}
//		cout << endl;
//	}
//	return dp[len - 1][target];
//}
//int main()
//{
//	vector<int> nums = { 1,5,11,5 };
//	cout << canPartition(nums);
//}


//494. 目标和
//给你一个非负整数数组 nums 和一个整数 target 。
//向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
//返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目
//示例 1：
//输入：nums = [1, 1, 1, 1, 1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//- 1 + 1 + 1 + 1 + 1 = 3
//+ 1 - 1 + 1 + 1 + 1 = 3
//+ 1 + 1 - 1 + 1 + 1 = 3
//+ 1 + 1 + 1 - 1 + 1 = 3
//+ 1 + 1 + 1 + 1 - 1 = 3
//示例 2：
//输入：nums = [1], target = 1
//输出：1
//提示：
//1 <= nums.length <= 20
//0 <= nums[i] <= 1000
//0 <= sum(nums[i]) <= 1000
//- 1000 <= target <= 1000
//int findTargetSumWays(vector<int>&nums, int target)
//{
//	int len = nums.size();
//	int sum = 0;
//	for (auto i : nums)
//	{
//		sum += i;
//	}
//	if ((target + sum) & 1 || fabs(target) > sum)
//	{
//		return 0;
//	}
//	int sum_set = fabs((target + sum) / 2);
//	vector<vector<int>> dp(len + 1, vector<int>(sum_set + 1, 0));
//	dp[0][0] = 1;
//	for (int i = 1; i <= len; i++)
//	{
//		for (int j = 0; j <= sum_set; j++)
//		{
//			if (j >= nums[i - 1])
//			{
//				dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
//			}
//			else
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//		}
//	}
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			cout << j << "\t";
//		}
//		cout << endl;
//	}
//	return dp[len][sum_set];
//}
//int main()
//{
//	vector<int> nums = { 10,10 };
//	int target = -40;
//	cout << findTargetSumWays(nums, target);
//}



//单词拆分
//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
//注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//bool wordBreak(string s, vector<string>& wordDict) {
//    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//    vector<bool> dp(s.size() + 1, false);
//    dp[0] = true;
//    for (int i = 1; i <= s.size(); i++) {   // 遍历背包
//        for (int j = 0; j < i; j++) {       // 遍历物品
//            string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
//            if (wordSet.find(word) != wordSet.end() && dp[j]) {
//                dp[i] = true;
//            }
//        }
//    }
//    cout << "****" << endl;
//    for (auto i : dp)
//    {
//        cout << i << '\t';;
//    }
//    return dp[s.size()];
//}
//int main()
//{
//    string s = "aaaaaaa";
//    vector <string> wordDict = { "aaaa","aaa" };
//    cout << wordBreak(s, wordDict);
//}


//873. 最长的斐波那契子序列的长度
//如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：
//n >= 3
//对于所有 i + 2 <= n，都有 X_i + X_{ i + 1 } = X_{ i + 2 }
//给定一个严格递增的正整数数组形成序列 arr ，找到 arr 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。
//示例 1：
//输入 : arr = [1, 2, 3, 4, 5, 6, 7, 8]
//输出 : 5
//解释 : 最长的斐波那契式子序列为[1, 2, 3, 5, 8] 。
//示例 2：
//输入 : arr = [1, 3, 7, 11, 12, 14, 18]
//输出 : 3
//解释 : 最长的斐波那契式子序列有[1, 11, 12]、[3, 11, 14] 以及[7, 11, 18] 。
//提示：
//3 <= arr.length <= 1000
//1 <= arr[i] < arr[i + 1] <= 10 ^ 9
//思路 注意斐波那契序列的最后一个数字是倒数第二个数字与倒数第三个数字之和 所以也就是说 最后这个数字取与不取是由前两个数字决定的
//  然后定义dp[][]  dp[i][j]的值为以j为倒数第一个数和以i为倒数第二个数的斐波那契子序列长度  
//                        j=i+k  k为任意值   如果k在数组中的话 那么dp[i][j]=d[k][i]+1
//											 如果k不在数组中的话 那么dp[i][j]=2 表示i与j自成长度为2的子序列
//int searchInsert(vector<int>& nums, int target)
//{
//	int length = nums.size();
//	int right = length - 1;
//	int left = 0;
//	while (left <= right)
//	{
//		int middle = (right + left) / 2;
//		if (target < nums[middle])
//		{
//			right = middle - 1;
//		}
//		else if (target > nums[middle])
//		{
//			left = middle + 1;
//		}
//		else
//		{
//			return middle;
//		}
//	}
//	return -1;
//}
//int lenLongestFibSubseq(vector<int>& arr)
//{
//	size_t length = arr.size();
//	vector<vector<int>> dp(length, vector<int>(length, 1));
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			cout << j << '\t';
//		}
//		cout << endl;
//	}
//	cout << endl;
//	int ans = 0;
//	for (size_t i = 0; i < length; i++)
//	{
//		for (size_t j = i + 1; j < length; j++)
//		{
//			int k = searchInsert(arr, arr[j] - arr[i]);
//			if (k != -1)
//			{
//				dp[i][j] = dp[k][i] + 1;
//			}
//			else
//			{
//				dp[i][j] = 2;
//			}
//			ans = max(dp[i][j], ans);
//		}
//	}
//	for (auto i : dp)
//	{
//		for (auto j : i)
//		{
//			cout << j << '\t';
//		}
//		cout << endl;
//	}
//	return ans;
//}


//673. 最长递增子序列的个数
//给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
//注意 这个数列必须是 严格 递增的。
//示例 1:
//输入: [1, 3, 5, 4, 7]
//输出 : 2
//解释 : 有两个最长递增子序列，分别是[1, 3, 4, 7] 和[1, 3, 5, 7]。
//示例 2 :
//输入 : [2, 2, 2, 2, 2]
//输出 : 5
//解释 : 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5
int findNumberOfLIS(vector<int>& nums)
{
	int length = nums.size();
	vector<int> dp(length, 1);
	vector<int> count(length, 1);
	if (nums.size() <= 1)
	{
		return nums.size();
	}
	//dp[i]：i之前（包括i）最长递增子序列的长度为dp[i]
	//count[i]：以nums[i]为结尾的字符串，最长递增子序列的个数为count[i]
	int maxCount = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				if (dp[j] + 1 > dp[i])
				{
					count[i] = count[j];
				}
				else if (dp[j] + 1 == dp[i])
				{
					count[i] += count[j];
				}
				dp[i] = max(dp[i], dp[j] + 1);
			}
			if (dp[i] > maxCount)
			{
				maxCount = dp[i];
			}
		}
	}
	for (auto i : dp)
	{
		cout << i << '\t';
	}
	cout << endl;
	for (auto j : count)
	{
		cout << j << '\t';
	}
	cout << endl;
	int result = 0;
	for (int i = 0; i < length; i++)
	{
		if (maxCount == dp[i])
		{
			result += count[i];
		}
	}
	return result;
}
//int main()
//{
//	vector<int> nums = { 1,3,5,4,7 };
//	cout << findNumberOfLIS(nums);
//}



struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val) 
	{
		while (head!=nullptr && head->val==val)
		{
			ListNode* temp = head;
			head = head->next;
			delete temp;
		}
		ListNode* p = head;
		ListNode* pre_p = nullptr;
		while (p!=nullptr)
		{
			if (p->val == val)
			{
				ListNode* temp = p;
				pre_p->next = p->next;
				p = p->next;
				delete temp;
				continue;
			}
			pre_p = p;
			p = p->next;
		}
		return head;
	}
};