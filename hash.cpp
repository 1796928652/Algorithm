#include<string>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<unordered_set>
#include<vector>
using namespace std;
// 哈希表部分
// 
// 
// 
//给定一个数组 要求求出数组中只出现一次的数的总和
// 思路是运用哈希表 下标表示该数 而内容表示该数的出现次数 如何内容为1则相加求和
//int sumOfUnique(vector<int>& nums)
//{
//	int hash[101] = { 0 };
//	int sum = 0;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		hash[nums[i]] += 1;
//	}
//	for (auto i = 0; i < 101; i++)
//	{
//		cout << hash[i] << '\t';
//	}
//	for (int i = 0; i <= 101; i++)
//	{
//		if (hash[i] == 1)
//		{
//			sum += i;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	vector<int> nums = { 1, 2, 3, 2 };
//	cout << sumOfUnique(nums);
//}


//242. 有效的字母异位词
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
//输入: s = "anagram", t = "nagaram"
//输出 : true
//示例 2 :
//输入 : s = "rat", t = "car"
//输出 : false
//bool isAnagram(string s, string t)
//{
//	int hash[26] = { 0 };
//	for (auto i : s)
//	{
//		++hash[i - 'a'];
//	}
//	for (auto j : t)
//	{
//		--hash[j - 'a'];
//	}
//	for (auto i : hash)
//	{
//		if (i != 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
// 
// 
// 
// 
// 
// 
// 
//给你一个整数数组 nums ，它包含 2 * n 个整数。
//你需要将 nums 划分成 n 个数对，满足：
//每个元素 只属于一个 数对。
//同一数对中的元素 相等 。
//如果可以将 nums 划分成 n 个数对，请你返回 true ，否则返回 false 。
//nums = [3, 2, 3, 2, 2, 2]
//输出：true
//解释：
//nums 中总共有 6 个元素，所以它们应该被划分成 6 / 2 = 3 个数对。
//nums 可以划分成(2, 2) ，(3, 3) 和(2, 2) ，满足所有要求
//bool divideArray(vector<int>&nums)
//{
//	int hash[501] = { 0 };
//	for (int i = 0; i < nums.size(); i++)
//	{
//		hash[nums[i]] += 1;
//	}
//	for (int i = 1; i < nums.size(); i++)
//	{
//		if ((hash[i] & 1) == 1)
//		{
//			return false;
//		}
//	}
//	return true;
//}




//全字母句 指包含英语字母表中每个字母至少一次的句子。
//给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为 全字母句 。
//如果是，返回 true ；否则，返回 false 。
//输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
//输出：true
//解释：sentence 包含英语字母表中每个字母至少一次。
//bool checkIfPangram(string sentence)
//{
//	int hash[26] = { 0 };
//	for (int i = 0; i < sentence.size(); i++)
//	{
//		hash[sentence[i] - 'a'] = 1;
//	}
//	for (auto i : hash)
//	{
//		if (i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	string sentence = "thequickbrownfoxjumpsoverthelazydog";
//	cout << checkIfPangram(sentence);
//}



//给你一个整数数组 nums 。
//如果一组数字(i, j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。
//返回好数对的数目
// 思路一：两层遍历找到满足条件的i与j
//int numIdenticalPairs(vector<int>&nums)
//{
//	int n = nums.size();
//	int sum = 0;
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (nums[i] == nums[j])
//			{
//				sum += 1;
//			}
//		}
//	}
//	return sum;
//}
//建议思路二反复体会
// 思路二：利用hash表来记录下标为i的数出现的个数然后用ans累加  自己体会一下ans的累加；
//int numIdenticalPairs2(vector<int>& nums)
//{
//	int hash[101] = { 0 };
//	int ans = 0;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		ans += hash[nums[i]];
//		hash[nums[i]] += 1;
//	}
//	return ans;
//}
//int main()
//{
//	vector<int> nums = { 1, 2, 3, 1, 1, 3 };
//	cout << numIdenticalPairs2(nums);
//}





//2006. 差的绝对值为 K 的数对数目
//给你一个整数数组 nums 和一个整数 k ，请你返回数对(i, j) 的数目，满足 i < j 且 | nums[i] - nums[j]| == k 。
//	| x | 的值定义为：
//	如果 x >= 0 ，那么值为 x 。
//	如果 x < 0 ，那么值为 - x
//int countKDifference(vector<int>& nums, int k)
//{
//	int n = nums.size();
//	int hash[101] = { 0 };
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		hash[nums[i]] += 1;
//	}
//	for (int i = k; i < 101; i++)
//	{
//		if (hash[i] != 0 && hash[i - k] != 0)
//		{
//			sum += hash[i] * hash[i - k];
//		}
//	}
//	return sum;
//}
//int main()
//{
//	vector<int> nums = { 1, 2, 2, 1 };
//	int k = 1;
//	cout << countKDifference(nums, k);
//}



//930. 和相同的二元子数组
//给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。
//子数组 是数组的一段连续部分。
//示例 1：
//输入：nums = [1, 0, 1, 0, 1], goal = 2
//输出：4
//有 4 个满足题目要求的子数组：[1, 0, 1]、[1, 0, 1, 0]、[0, 1, 0, 1]、[1, 0, 1]
//1 <= nums.length <= 3 * 104
//nums[i] 不是 0 就是 1
//0 <= goal <= nums.length
// 思路一  从开头开始遍历 每次遍历途中都记录下  当前遍历和看看是否等于goal 如等于赶紧记录下来知道再遇到1停止
//int numSubarraysWithSum(vector<int>&nums, int goal)
//{
//	int n = nums.size();
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int goals = goal;
//		for (int j = i; j < n; j++)
//		{
//			if (nums[j] == 1)
//			{
//				goals -= 1;
//			}
//			if (goals == 0)
//			{
//				sum += 1;
//			}
//			if (goals == -1)
//			{
//				break;
//			}
//		}
//		cout << sum << endl;
//	}
//	return sum;
//}//注意该方法的时间复杂度为n**2；
// 思路二：hash表法  先对nums进行前缀和 再在hash表中下标为goal的地方设置为1 要使得下标为goal后面的内容记录着有几个总和为goal  一定要好好思考！！！！
//int numSubarraysWithSum2(vector<int>& nums, int goal)
//{
//	int n = nums.size();
//	int hash[60000] = { 0 };
//	for (int i = 1; i < n; i++)
//	{
//		nums[i] += nums[i - 1];
//	}
//	int sum = 0;
//	hash[goal] = 1;
//	for (int i = 0; i < n; i++)
//	{
//		sum += hash[nums[i]];
//		++hash[nums[i] + goal];
//	}
//	return sum;
//}
//int main()
//{
//	vector<int> nums = { 1,0,1,0,1 };
//	int goal = 2;
//	cout << numSubarraysWithSum2(nums, goal);
//}



//给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组(i, j, k, l) 能满足：
//0 <= i, j, k, l < n
//nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
//示例 1：
//输入：nums1 = [1, 2], nums2 = [-2, -1], nums3 = [-1, 2], nums4 = [0, 2]
//输出：2
//解释：
//两个元组如下：
//1. (0, 0, 0, 1)->nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0)->nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
// 思路一直接四层遍历暴力求解
// 思路二：可以先用unordermap容器填载nums1与nums2所有可能的和（在这里容器中计为负数）  再双重遍历nums3，nums4与前面容器中和为0即得到相应的i，j，k，l
//int fourSumCount(vector<int>&nums1, vector<int>&nums2, vector<int>&nums3, vector<int>&nums4)
//{
//	unordered_map<int, int> _12;
//	int sum = 0;
//	for (auto i : nums1)
//	{
//		for (auto j : nums2)
//		{
//			_12[-(i + j)] += 1;
//		}
//	}
//	for (auto i : nums3)
//	{
//		for (auto j : nums4)
//		{
//			if (_12[i + j])
//			{
//				sum += _12[i + j];
//			}
//		}
//	}
//	return sum;
//}


//299. 猜数字游戏
//写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：
//猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），
//有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
//给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。
//提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。
//请注意秘密数字和朋友猜测的数字都可能含有重复数字。
//示例 1：
//输入：secret = "1807", guess = "7810"
//输出："1A3B"
//解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
//"1807"
//"7810"
//示例 2：
//输入：secret = "1123", guess = "0111"
//输出："1A1B"
//解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
//"1123"        "1123"
//|      or     |
//"0111"        "0111"
//注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字
string int_to_string(int x)
{
	string s;
	if (x == 0)
	{
		return "0";
	}
	while (x)
	{
		s += (x % 10 + '0');
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
string getHint(string secret, string guess)
{
	int hash1[10] = { 0 };
	int hash2[10] = { 0 };
	int x = 0;
	int y = 0;
	for (int i = 0; i < secret.size(); ++i)
	{
		if (secret[i] == guess[i])
		{
			++x;
		}
		else
		{
			++hash1[secret[i] - '0'];
			++hash2[guess[i] - '0'];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		y += min(hash1[i], hash2[i]);
	}
	string ans;
	ans += int_to_string(x);
	ans += 'A';
	ans += int_to_string(y);
	ans += 'B';
	return ans;
}
//int main()
//{
//	string secret = "1", guess = "0";
//	cout << getHint(secret, guess) << endl;
//	cout << int_to_string(172);
//}



/*128. 最长连续序列
已解答
中等
相关标签
相关企业
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题*/
class Solution128 {
public:
	int longestConsecutive(vector<int>& nums)
	{
		unordered_set<int> nums_set;
		for (auto i : nums)
		{
			nums_set.insert(i);
		}
		int max_len = 0;
		for (auto i : nums_set)
		{
			if (!nums_set.count(i - 1))
			{
				int cur = i;
				int len = 1;
				while (nums_set.count(cur + 1))
				{
					len += 1;
					cur += 1;
				}
				max_len = max(max_len, len);
			}
		}
		return max_len;
	}
};