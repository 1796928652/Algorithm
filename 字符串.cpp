#include <string>
#include<vector>
#include<iostream>
using namespace std;

//58. ���һ�����ʵĳ���
//��
//����һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ����� ���һ�� ���ʵĳ��ȡ�
//���� ��ָ������ĸ��ɡ��������κοո��ַ���������ַ���
//ʾ�� 1��
//���룺s = "Hello World"
//�����5
//���ͣ����һ�������ǡ�World��������Ϊ5��
//ʾ�� 2��
//���룺s = "   fly me   to   the moon  "
//�����4
//���ͣ����һ�������ǡ�moon��������Ϊ4��
//ʾ�� 3��
//���룺s = "luffy is still joyboy"
//�����6
//���ͣ����һ�������ǳ���Ϊ6�ġ�joyboy����
//��ʾ��
//1 <= s.length <= 104
//s ����Ӣ����ĸ�Ϳո� ' ' ���
//s �����ٴ���һ������
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
//344. ��ת�ַ���
//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
//ʾ�� 1��
//���룺s = ["h", "e", "l", "l", "o"]
//�����["o", "l", "l", "e", "h"]
//ʾ�� 2��
//���룺s = ["H", "a", "n", "n", "a", "h"]
//�����["h", "a", "n", "n", "a", "H"]
//��ʾ��
//1 <= s.length <= 105
//s[i] ���� ASCII ����еĿɴ�ӡ�ַ�
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


//541. ��ת�ַ��� II
//����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���
//���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
//���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
//ʾ�� 1��
//���룺s = "abcdefg", k = 2
//�����"bacdfeg"
//ʾ�� 2��
//���룺s = "abcd", k = 2
//�����"bacd"
//��ʾ��
//1 <= s.length <= 104
//s ����СдӢ�����
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


//151. ��ת�ַ����еĵ���
//����һ���ַ��� s �����㷴ת�ַ����� ���� ��˳��
//���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����
//���� ���� ˳��ߵ��� ���� ֮���õ����ո����ӵĽ���ַ�����
//ע�⣺�����ַ��� s�п��ܻ����ǰ���ո�β��ո���ߵ��ʼ�Ķ���ո񡣷��صĽ���ַ����У����ʼ�Ӧ�����õ����ո�ָ����Ҳ������κζ���Ŀո�
//ʾ�� 1��
//���룺s = "the sky is blue"
//�����"blue is sky the"
//ʾ�� 2��
//���룺s = "  hello world  "
//�����"world hello"
//���ͣ���ת����ַ����в��ܴ���ǰ���ո��β��ո�
//ʾ�� 3��
//���룺s = "a good   example"
//�����"example good a"
//���ͣ�����������ʼ��ж���Ŀո񣬷�ת����ַ�����Ҫ�����ʼ�Ŀո���ٵ�����һ����
//��ʾ��
//1 <= s.length <= 104
//s ����Ӣ�Ĵ�Сд��ĸ�����ֺͿո� ' '
//s �� ���ٴ���һ�� ����
//���ף�����ַ�������ʹ�õı����������һ�ֿɱ��������ͣ��볢��ʹ�� O(1) ����ռ临�Ӷȵ� ԭ�� �ⷨ
//��������ò�ͬ�ķ������
//˼·һ ˫ָ��
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



//28. �ҳ��ַ����е�һ��ƥ������±�
//���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ������� needle ���� haystack ��һ���֣��򷵻� - 1 ��
//ʾ�� 1��
//���룺haystack = "sadbutsad", needle = "sad"
//�����0
//���ͣ�"sad" ���±� 0 �� 6 ��ƥ�䡣
//��һ��ƥ������±��� 0 �����Է��� 0 ��
//ʾ�� 2��
//���룺haystack = "leetcode", needle = "leeto"
//����� - 1
//���ͣ�"leeto" û���� "leetcode" �г��֣����Է��� - 1 
//��ʾ��
//1 <= haystack.length, needle.length <= 104
//haystack �� needle ����СдӢ���ַ����
//˼·һ �������
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
//    �������������ǳ���Ҫ  KMP�㷨
//���㷨�Ĺؼ����ڣ��ڵ�ǰ���ı�����ģʽ�������Ĺ����У��������˲�ƥ�䣬��γ�������Ѿ�ƥ��Ĳ��֡�����������㷨�ĺ������
// ��˵��KMP�㷨֮ǰ  ��������ȷ ǰ׺�ͺ�׺  �Լ�ǰ��׺��  ǰ׺��������ĩβ���Ұ���ͷ�ַ���һ���ַ����е������Ӵ�  ��׺��������ͷ�ַ��Ұ���β�ַ���һ���ַ����е������Ӵ�
//����һ�����ӱ���aabaaf
//a��ǰ��׺��Ϊ0������Ϊ0��
//aa��ǰ��׺��Ϊa������Ϊ1��
//aab��ǰ׺aa����׺ab������ͬ����ȡǰ׺a����׺b������ͬ������Ϊ0��
//aaba��ǰ׺aab����׺aba������ͬ����ȡǰ׺aa����׺ba������ͬ����ȡǰ׺a����׺a����ͬ������Ϊ1��
//aabaa��ǰ׺aaba����׺abaa������ͬ����ȡǰ׺aab����׺baa������ͬ����ȡǰ׺aa����׺aa����ͬ������Ϊ2��
//aabaaf��ǰ׺aabaa����׺abaaf������ͬ����ȡǰ׺aaba����׺baaf������ͬ����ȡǰ׺aab����׺aaf������ͬ����ȡǰ׺aa����׺af������ͬ����ȡǰ׺a����׺f������ͬ������Ϊ0.
// ���Ը��ַ�����ǰ��׺��Ϊ010120
//�粻���� �ٸ���һ������  aabaab
// a: ǰ��׺��Ϊ0������Ϊ0��
// aa:ǰ��׺��Ϊa,����Ϊ1��
// aab��ǰ׺Ϊaa����׺Ϊab������ͬ����ȡǰ׺a,��׺b������ͬ������Ϊ0��
// aaba��ǰ׺Ϊaab����׺Ϊaba������ͬ����ȡǰ׺aa��ȡ��׺ba������ͬ����ȡǰ׺a����׺a����ͬ������Ϊ1��
// aabaa��ǰ׺aaba����׺abaa������ͬ����ȡǰ׺aab����׺baa������ͬ����ȡǰ׺aa����׺aa����ͬ������Ϊ2��
// aabaab��ǰ׺Ϊaabaa����׺Ϊabaab������ͬ����ȡǰ׺aaba����׺Ϊbaab������ͬ����ȡǰ׺aab��ȡ��׺aab����ͬ������Ϊ3��
// ���Ը��ַ�����ǰ��׺��Ϊ010123��
// ͨ���������� Ӧ�ÿ�������ǰ��׺ �Լ�ǰ��׺��
// 
//int main()
//{
//	string haystack = "leetcode", needle = "leeto";
//	cout << strStr(haystack, needle);
//}
//int main()
//{
//	string s = "aabaaab";//������ӿ��������� Ϊʲô��j��i����ͬ�������Ҫд��j=next[j-1]  ������ֱ������s[i]=0�� �൱��next���������Լ�
//	for (auto i : getnext(s))
//	{
//		cout << i << '\t';
//	}
//}
vector<int> getnext(string s)
{
	int j = 0; //i�����׺ĩβ j����ǰ׺ĩβ  ע��j����������ǰ׺ĩβ ����һ�����κ�����Ŀǰ������չ����󹫹��Ӵ��ĳ���
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