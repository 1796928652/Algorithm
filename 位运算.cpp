#include<iostream>
#include<vector>
using namespace std;
//����λ��������  ��1010101   101010
int weishu(int n)//����n�Ķ����Ʊ�ʾ�µ�λ��
{
	int count = 0;
	while (n)
	{
		n = n >> 1;
		count += 1;
	}
	return count;
}
bool hasAlternatingBits(int n)//˼·1   ����1& ����������ʶ������ת�����Ҳ����ж�
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
bool hasAlternatingBits2(int n)//˼·2 �ǽ��䲻����3��11������&�ж� ����в�������������������11��3����0��00�� �罻�������������һλ���ж�
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

//�󼯺ϵ������Ӽ�   ���������˶�̬����
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
//�󼯺ϵ������Ӽ�   �����֮ǰ �������˶�ά��̬����  ��ʵ������ΧֵҲ������һ����ά��̬������vector<vector<int>> fun()
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




//�Ӽ�������ܺ������
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




//�ڲ�ʹ��+��-������� ʵ�����������
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
//242. ��Ч����ĸ��λ��
//���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
//ע�⣺�� s �� t ��ÿ���ַ����ֵĴ�������ͬ����� s �� t ��Ϊ��ĸ��λ�ʡ�
//����: s = "anagram", t = "nagaram"
//��� : true
//ʾ�� 2 :
//���� : s = "rat", t = "car"
//��� : false
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