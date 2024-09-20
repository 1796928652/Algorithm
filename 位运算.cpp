#include<iostream>
#include<vector>
using namespace std;
//交替位二进制数  如1010101   101010
int weishu(int n)//计算n的二进制表示下的位数
{
	int count = 0;
	while (n)
	{
		n = n >> 1;
		count += 1;
	}
	return count;
}
bool hasAlternatingBits(int n)//思路1   是与1& 设立两个标识符交替转换并且不断判断
{
	bool flag1;
	if ((n & 1) == 1)
	{
		flag1 = 1;
	}
	else
	{
		flag1 = 0;
	}
	bool flag2;
	int s = weishu(n);
	for (int i = 1; i < s; i++)
	{
		if (((n >> i) & 1) == 1)
		{
			flag2 = 1;
		}
		else
		{
			flag2 = 0;
		}
		if (flag1 == flag2)
		{
			return false;
		}
		else
		{
			flag1 = flag1 + flag2;
			flag2 = flag1 - flag2;
			flag1 = flag1 - flag2;
		}
	}
	return true;
}
bool hasAlternatingBits2(int n)//思路2 是将其不断与3（11）进行&判断 如果有不交替的情况发生则结果是11（3）或0（00） 如交替则继续进行下一位的判断
{
	while (n)
	{
		if ((n & 3) == 3 || (n & 3) == 0)
		{
			return false;
		}
		n = n >> 1;
	}
	return true;
}
//int main()
//{
//	cout << hasAlternatingBits(5) << endl;
//	cout << hasAlternatingBits2(5);
//}

//求集合的所有子集   这里运用了动态数组
void miji1(int* p, int length)
{
	vector<int> s;
	for (int i = 1; i < (1 << length); i++)
	{
		int j = i;
		int k = 0;
		while (j != 0)
		{
			if ((j & 1) == 1)
			{
				s.push_back(p[k]);
			}
			j = (j >> 1);
			k += 1;
		}
		for (vector<int>::iterator i = s.begin(); i != s.end(); i++)
		{
			cout << *i;
		}
		cout << endl;
		s.clear();
	}
}
//int main()
//{
//	int a[] = { 1,2,3 };
//	fun(a, 3);
//}
//求集合的所有子集   相较于之前 这里用了二维动态数组  其实函数范围值也可以是一个二维动态数组用vector<vector<int>> fun()
void miji2(int* p, int length)
{
	vector<vector<int>> subsets;
	vector<int> s;
	for (int i = 0; i < (1 << length); i++)
	{
		int j = i;
		int k = 0;
		while (j != 0)
		{
			if ((j & 1) == 1)
			{
				s.push_back(p[k]);
			}
			j = (j >> 1);
			k += 1;
		}
		subsets.push_back(s);
		s.clear();
	}
	for (vector<vector<int>>::iterator l = subsets.begin(); l != subsets.end(); l++)
	{
		cout << "[";
		for (vector<int>::iterator it = (*l).begin(); it != (*l).end(); it++)
		{
			cout << *it << ",";
		}
		cout << "]";
		cout << endl;
	}

}
//int main()
//{
//	int a[] = { 1,2,3 };
//	fun(a, 3);
//}




//子集的异或总和再求和
int yihuoqiuhe(int* p, int length)
{
	int Sum = 0;
	for (int i = 0; i < (1 << length); i++)
	{
		int j = i;
		int k = 0;
		int sum = 0;
		while (j != 0)
		{
			if ((j & 1) == 1)
			{
				sum ^= p[k];

			}
			j = (j >> 1);
			k += 1;
		}
		Sum += sum;
	}
	return Sum;
}
//int main()
//{
//	int a[] = { 1,2,3 };
//
//	cout << fun(a, 3);
//}




//在不使用+与-的情况下 实现两整数相加
int fun(int a, int b)
{
	return b == 0 ? a : fun(a ^ b, (a & b) << 1);
}
//int main()
//{
//	cout << fun(2, 2);
//}
// 
// 
//242. 有效的字母异位词
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
//输入: s = "anagram", t = "nagaram"
//输出 : true
//示例 2 :
//输入 : s = "rat", t = "car"
//输出 : false
bool isAnagram(string s, string t)
{
	int hash[26] = { 0 };
	for (auto i : s)
	{
		++hash[i - 'a'];
	}
	for (auto j : t)
	{
		--hash[j - 'a'];
	}
	for (auto i : hash)
	{
		if (i != 0)
		{
			return false;
		}
	}
	return true;
}