#include<vector>
#include <iostream>
using namespace std;
//15. 三数之和
//给你一个整数数组 nums ，判断是否存在三元组[nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
//你返回所有和为 0 且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
//vector<vector<int>> threeSum(vector<int>&nums)
//{
//	vector<vector<int>> a;
//	int n = nums.size();
//	sort(nums.begin(), nums.end());
//	for (int i = 0; i < n; i++)
//	{
//		if (nums[i] > 0)
//		{
//			return a;
//		}
//		if (i > 0 && nums[i] == nums[i - 1])
//		{
//			continue;
//		}
//		int left = i + 1;
//		int right = n - 1;
//		while (left < right)
//		{
//			if (nums[left] + nums[right] + nums[i] > 0)
//			{
//				right--;
//			}
//			else if (nums[left] + nums[right] + nums[i] < 0)
//			{
//				left++;
//			}
//			else
//			{
//				a.push_back(vector<int>{ nums[left], nums[right], nums[i] });
//				while (left < right && nums[right] == nums[right - 1])
//				{
//					right--;
//				}
//				while (left < right && nums[left] == nums[left + 1])
//				{
//					left++;
//				}
//				right--;
//				left++;
//			}
//		}
//	}
//	return a;
//}
//int main()
//{
//	vector <int> nums = { 2,0,-2,-5,-5,-3,2,-4 };
//	for (auto i : threeSum(nums))
//	{
//		for (auto j : i)
//		{
//			cout << j << '\t';
//		}
//		cout << endl;
//	}
//}


//151. 反转字符串中的单词
//给你一个字符串 s ，请你反转字符串中 单词 的顺序。
//单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
//返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
//注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
//示例 1：
//输入：s = "the sky is blue"
//输出："blue is sky the"
//示例 2：
//输入：s = "  hello world  "
//输出："world hello"
//解释：反转后的字符串中不能存在前导空格和尾随空格。
//示例 3：
//输入：s = "a good   example"
//输出："example good a"
//解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
//提示：
//1 <= s.length <= 104
//s 包含英文大小写字母、数字和空格 ' '
//s 中 至少存在一个 单词
//进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法
//本题可以用不同的方法解决
//思路一 双指针  这里的i与j皆代表下标
//string reverseWords(string s)
//{
//	string a;
//	size_t len = s.size();
//	int i = len - 1;
//	while (i >= 0)
//	{
//		if (s[i] != ' ')
//		{
//			int j = i;
//			do
//			{
//				j--;
//			} while (j >= 0 && s[j] != ' ');
//			a += s.substr(j + 1, i - j) + ' ';
//			i = j;
//		}
//		i--;
//	}
//	a.pop_back();
//	cout << endl;
//	return a;
//}
//int main()
//{
//	string s = "abc d  ada ";
//	cout << reverseWords(s);
//}
//思路二 ：从队列deque的角度出发   这题记得回头看一下
//方法三：双端队列          
//由于双端队列支持从队列头部插入的方法，因此我们可以沿着字符串一个一个单词处理，然后将单词压入队列的头部，再将队列转成字符串即可。
//class Solution {
//public:
//    string reverseWords(string s) {
//        int left = 0, right = s.size() - 1;
//        // 去掉字符串开头的空白字符
//        while (left <= right && s[left] == ' ') ++left;
//
//        // 去掉字符串末尾的空白字符
//        while (left <= right && s[right] == ' ') --right;
//
//        deque<string> d;
//        string word;
//
//        while (left <= right) {
//            char c = s[left];
//            if (word.size() && c == ' ') {
//                // 将单词 push 到队列的头部
//                d.push_front(move(word));
//                word = "";
//            }
//            else if (c != ' ') {
//                word += c;
//            }
//            ++left;
//        }
//        d.push_front(move(word));
//
//        string ans;
//        while (!d.empty()) {
//            ans += d.front();
//            d.pop_front();
//            if (!d.empty()) ans += ' ';
//        }
//        return ans;
//    }
//};




/*283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作*/
class Solution283 
{
public:
	void moveZeroes(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				int j = i;
				while (nums[j] == 0)
				{
					j++;
					if (j == nums.size())
					{
						return;
					}
				}
				swap(nums[i], nums[j]);
			}
		}
	}
};

/*11. 盛最多水的容器
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是(i, 0) 和(i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。*/
class Solution11 {
public:
	int maxArea(vector<int>& height)
	{
		int ans = 0;
		int i = 0, j = height.size() - 1;
		while (i < j)
		{
			ans = max(ans, min(height[i], height[j]) * (j - i));
			if (height[i] < height[j])
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		return ans;
	}
};





//快排实现 双端法
class Dual_P_qsort
{
public:
	Dual_P_qsort();
	~Dual_P_qsort();
	void get_nums(vector<int> arr);
	int partition(int left, int right);
	void Dual_Pariotion_qsort(int left, int right);
	void display_nums();
private:
	vector<int> nums;
};
Dual_P_qsort::Dual_P_qsort() {}
Dual_P_qsort::~Dual_P_qsort() {}
int Dual_P_qsort::partition(int left, int right)
{
	int pivot = left;
	while (left != right)
	{
		while (right > left && nums[right] >= nums[pivot])
		{
			right--;
		}
		swap(nums[right], nums[pivot]);
		pivot = right;
		while (left < right && nums[left] <= nums[pivot])
		{
			left++;
		}
		swap(nums[left], nums[pivot]);
		pivot = left;
	}
	return pivot;
}
void Dual_P_qsort::Dual_Pariotion_qsort(int left, int right)
{
	if (left < right)
	{
		int pivot = partition(left, right);
		Dual_Pariotion_qsort(left, pivot - 1);
		Dual_Pariotion_qsort(pivot + 1, right);
	}
}
void Dual_P_qsort::get_nums(vector<int> arr)
{
	nums = arr;
}
void Dual_P_qsort::display_nums()
{
	for (auto i : nums)
	{
		cout << i << '\t';
	}
}
/*int main()
{
	vector<int> nums = { 46,79,56,38,40,84 };
	Dual_P_qsort arr;
	arr.get_nums(nums);
	arr.Dual_Pariotion_qsort(0, nums.size() - 1);
	arr.display_nums();
}
*/