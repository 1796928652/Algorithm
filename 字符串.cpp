#include <string>
#include<vector>
#include<iostream>
using namespace std;

//58. 最后一个单词的长度
//简单
//给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串
//示例 1：
//输入：s = "Hello World"
//输出：5
//解释：最后一个单词是“World”，长度为5。
//示例 2：
//输入：s = "   fly me   to   the moon  "
//输出：4
//解释：最后一个单词是“moon”，长度为4。
//示例 3：
//输入：s = "luffy is still joyboy"
//输出：6
//解释：最后一个单词是长度为6的“joyboy”。
//提示：
//1 <= s.length <= 104
//s 仅有英文字母和空格 ' ' 组成
//s 中至少存在一个单词
int lengthOfLastWord(string s)
{
	size_t len = s.size();
	cout << len << endl;
	int count = 0;
	bool flag = false;
	for (int i = len - 1; ; --i)
	{
		if (i == -1)
		{
			return count;
		}
		if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A'))
		{
			count += 1;
			flag = true;
			cout << count << endl;
		}
		if (s[i] == ' ' && flag == true)
		{
			return count;
		}
	}
	return count;
}
//int main()
//{
//	string s = "a";
//	cout << lengthOfLastWord(s);
//}
//344. 反转字符串
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//示例 1：
//输入：s = ["h", "e", "l", "l", "o"]
//输出：["o", "l", "l", "e", "h"]
//示例 2：
//输入：s = ["H", "a", "n", "n", "a", "h"]
//输出：["h", "a", "n", "n", "a", "H"]
//提示：
//1 <= s.length <= 105
//s[i] 都是 ASCII 码表中的可打印字符
//void reverseString1(vector<char>&s)
//{
//	size_t len = s.size();
//	for (size_t i = 0; i < len / 2; i++)
//	{
//		int temp = s[i];
//		s[i] = s[len - 1 - i];
//		s[len - 1 - i] = temp;
//	}
//	for (auto i : s)
//	{
//		cout << i << "\t";
//	}
//}
//int main()
//{
//	vector<char> s = { 'a','c','d','e' };
//	reverseString(s);
//}


//541. 反转字符串 II
//给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//示例 1：
//输入：s = "abcdefg", k = 2
//输出："bacdfeg"
//示例 2：
//输入：s = "abcd", k = 2
//输出："bacd"
//提示：
//1 <= s.length <= 104
//s 仅由小写英文组成
//1 <= k <= 104
string reverseStr(string s, int k)
{
	int n = s.length();
	for (int i = 0; i < n; i += 2 * k) {
		reverse(s.begin() + i, s.begin() + min(i + k, n));
	}
	return s;
}
//int main()
//{
//	string s = "abc";
//	cout << reverseStr(s, 2);
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
//思路一 双指针
string reverseWords(string s)
{
	string a;
	size_t len = s.size();
	int i = len - 1;
	while (i >= 0)
	{
		if (s[i] != ' ')
		{
			int j = i;
			do
			{
				j--;
			} while (j >= 0 && s[j] != ' ');
			a += s.substr(j + 1, i - j) + ' ';
			i = j;
		}
		i--;
	}
	a.pop_back();
	cout << endl;
	return a;
}



//28. 找出字符串中第一个匹配项的下标
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回 - 1 。
//示例 1：
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
//示例 2：
//输入：haystack = "leetcode", needle = "leeto"
//输出： - 1
//解释："leeto" 没有在 "leetcode" 中出现，所以返回 - 1 
//提示：
//1 <= haystack.length, needle.length <= 104
//haystack 和 needle 仅由小写英文字符组成
//思路一 暴力求解
int strStr(string haystack, string needle)
{
	int len1 = haystack.size();
	int len2 = needle.size();
	for (int i = 0; i <= len1 - len2; i++)
	{
		int j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (j == len2)
			{
				return i;
			}
		}
	}
	return -1;
}
//    ！！！！！！非常重要  KMP算法
//该算法的关键在于：在当前对文本串和模式串检索的过程中，若出现了不匹配，如何充分利用已经匹配的部分。——这个是算法的核心理解
// 在说明KMP算法之前  我们先明确 前缀和后缀  以及前后缀表  前缀＝不包含末尾的且包含头字符的一个字符串中的所有子串  后缀＝不包含头字符且包含尾字符的一个字符串中的所有子串
//给出一个例子比如aabaaf
//a：前后缀都为0，长度为0；
//aa：前后缀都为a，长度为1；
//aab：前缀aa，后缀ab，不相同，再取前缀a，后缀b，不相同，长度为0；
//aaba：前缀aab，后缀aba，不相同，再取前缀aa，后缀ba，不相同，再取前缀a，后缀a，相同，长度为1；
//aabaa：前缀aaba，后缀abaa，不相同，再取前缀aab，后缀baa，不相同，再取前缀aa，后缀aa，相同，长度为2；
//aabaaf：前缀aabaa，后缀abaaf，不相同，再取前缀aaba，后缀baaf，不相同，再取前缀aab，后缀aaf，不相同，再取前缀aa，后缀af，不相同，再取前缀a，后缀f，不相同，长度为0.
// 所以该字符串的前后缀表为010120
//如不明白 再给出一个例子  aabaab
// a: 前后缀都为0，长度为0；
// aa:前后缀都为a,长度为1；
// aab；前缀为aa，后缀为ab，不相同，再取前缀a,后缀b，不相同，长度为0；
// aaba：前缀为aab，后缀为aba，不相同，再取前缀aa，取后缀ba，不相同，再取前缀a，后缀a，相同，长度为1；
// aabaa：前缀aaba，后缀abaa，不相同，再取前缀aab，后缀baa，不相同，再取前缀aa，后缀aa，相同，长度为2；
// aabaab：前缀为aabaa，后缀为abaab，不相同，再取前缀aaba，后缀为baab，不相同，再取前缀aab，取后缀aab，相同，长度为3；
// 所以该字符串的前后缀表为010123；
// 通过两个例子 应该可以明白前后缀 以及前后缀表
// 
//int main()
//{
//	string haystack = "leetcode", needle = "leeto";
//	cout << strStr(haystack, needle);
//}
//int main()
//{
//	string s = "aabaaab";//这个例子可用来解释 为什么在j与i不相同的情况下要写成j=next[j-1]  而不是直接宣判s[i]=0； 相当于next作用于他自己
//	for (auto i : getnext(s))
//	{
//		cout << i << '\t';
//	}
//}
vector<int> getnext(string s)
{
	int j = 0; //i代表后缀末尾 j代表前缀末尾  注意j不仅仅代表前缀末尾 还有一层隐形含义是目前所能扩展的最大公共子串的长度
	vector<int> next(s.size());
	next[0] = 0;
	for (int i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = next[j - 1];
		}
		if (s[i] == s[j])
		{
			j++;
		}
		next[i] = j;
	}
	return next;
}
int strStr_KMP(string haystack, string needle)
{
	if (needle.size() == 0)
	{
		return 0;
	}
	vector<int> next = getnext(needle);
	int j = 0;
	for (int i = 0; i < haystack.size(); i++)
	{
		while (j > 0 && haystack[i] != needle[j])
		{
			j = next[j - 1];
		}
		if (haystack[i] == needle[j])
		{
			++j;
		}
		if (j == needle.size())
		{
			return i - needle.size() + 1;
		}
	}
	return -1;
}