#include<string>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<unordered_set>
#include<vector>
using namespace std;
// ��ϣ����
// 
// 
// 
//����һ������ Ҫ�����������ֻ����һ�ε������ܺ�
// ˼·�����ù�ϣ�� �±��ʾ���� �����ݱ�ʾ�����ĳ��ִ��� �������Ϊ1��������
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


//242. ��Ч����ĸ��λ��
//���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
//ע�⣺�� s �� t ��ÿ���ַ����ֵĴ�������ͬ����� s �� t ��Ϊ��ĸ��λ�ʡ�
//����: s = "anagram", t = "nagaram"
//��� : true
//ʾ�� 2 :
//���� : s = "rat", t = "car"
//��� : false
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
//����һ���������� nums �������� 2 * n ��������
//����Ҫ�� nums ���ֳ� n �����ԣ����㣺
//ÿ��Ԫ�� ֻ����һ�� ���ԡ�
//ͬһ�����е�Ԫ�� ��� ��
//������Խ� nums ���ֳ� n �����ԣ����㷵�� true �����򷵻� false ��
//nums = [3, 2, 3, 2, 2, 2]
//�����true
//���ͣ�
//nums ���ܹ��� 6 ��Ԫ�أ���������Ӧ�ñ����ֳ� 6 / 2 = 3 �����ԡ�
//nums ���Ի��ֳ�(2, 2) ��(3, 3) ��(2, 2) ����������Ҫ��
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




//ȫ��ĸ�� ָ����Ӣ����ĸ����ÿ����ĸ����һ�εľ��ӡ�
//����һ������СдӢ����ĸ��ɵ��ַ��� sentence �������ж� sentence �Ƿ�Ϊ ȫ��ĸ�� ��
//����ǣ����� true �����򣬷��� false ��
//���룺sentence = "thequickbrownfoxjumpsoverthelazydog"
//�����true
//���ͣ�sentence ����Ӣ����ĸ����ÿ����ĸ����һ�Ρ�
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



//����һ���������� nums ��
//���һ������(i, j) ���� nums[i] == nums[j] �� i < j ���Ϳ�����Ϊ����һ�� ������ ��
//���غ����Ե���Ŀ
// ˼·һ����������ҵ�����������i��j
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
//����˼·���������
// ˼·��������hash������¼�±�Ϊi�������ֵĸ���Ȼ����ans�ۼ�  �Լ����һ��ans���ۼӣ�
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





//2006. ��ľ���ֵΪ K ��������Ŀ
//����һ���������� nums ��һ������ k �����㷵������(i, j) ����Ŀ������ i < j �� | nums[i] - nums[j]| == k ��
//	| x | ��ֵ����Ϊ��
//	��� x >= 0 ����ôֵΪ x ��
//	��� x < 0 ����ôֵΪ - x
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



//930. ����ͬ�Ķ�Ԫ������
//����һ����Ԫ���� nums ����һ������ goal ������ͳ�Ʋ������ж��ٸ���Ϊ goal �� �ǿ� �����顣
//������ �������һ���������֡�
//ʾ�� 1��
//���룺nums = [1, 0, 1, 0, 1], goal = 2
//�����4
//�� 4 ��������ĿҪ��������飺[1, 0, 1]��[1, 0, 1, 0]��[0, 1, 0, 1]��[1, 0, 1]
//1 <= nums.length <= 3 * 104
//nums[i] ���� 0 ���� 1
//0 <= goal <= nums.length
// ˼·һ  �ӿ�ͷ��ʼ���� ÿ�α���;�ж���¼��  ��ǰ�����Ϳ����Ƿ����goal ����ڸϽ���¼����֪��������1ֹͣ
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
//}//ע��÷�����ʱ�临�Ӷ�Ϊn**2��
// ˼·����hash��  �ȶ�nums����ǰ׺�� ����hash�����±�Ϊgoal�ĵط�����Ϊ1 Ҫʹ���±�Ϊgoal��������ݼ�¼���м����ܺ�Ϊgoal  һ��Ҫ�ú�˼����������
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



//�����ĸ��������� nums1��nums2��nums3 �� nums4 �����鳤�ȶ��� n ����������ж��ٸ�Ԫ��(i, j, k, l) �����㣺
//0 <= i, j, k, l < n
//nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
//ʾ�� 1��
//���룺nums1 = [1, 2], nums2 = [-2, -1], nums3 = [-1, 2], nums4 = [0, 2]
//�����2
//���ͣ�
//����Ԫ�����£�
//1. (0, 0, 0, 1)->nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0)->nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
// ˼·һֱ���Ĳ�����������
// ˼·������������unordermap��������nums1��nums2���п��ܵĺͣ������������м�Ϊ������  ��˫�ر���nums3��nums4��ǰ�������к�Ϊ0���õ���Ӧ��i��j��k��l
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


//299. ��������Ϸ
//д��һ���������֣��������Ѳ���������Ƕ��١�����ÿ�²�һ�Σ���ͻ����һ������������Ϣ����ʾ��
//�²��������ж���λ�������ֺ�ȷ��λ�ö��¶��ˣ���Ϊ "Bulls"����ţ����
//�ж���λ�������ֲ¶��˵���λ�ò��ԣ���Ϊ "Cows"����ţ����Ҳ����˵����β²����ж���λ�ǹ�ţ���ֿ���ͨ����������ת���ɹ�ţ���֡�
//����һ���������� secret �����Ѳ²������ guess �����㷵�ض�������β²����ʾ��
//��ʾ�ĸ�ʽΪ "xAyB" ��x �ǹ�ţ������ y ����ţ������A ��ʾ��ţ��B ��ʾ��ţ��
//��ע���������ֺ����Ѳ²�����ֶ����ܺ����ظ����֡�
//ʾ�� 1��
//���룺secret = "1807", guess = "7810"
//�����"1A3B"
//���ͣ����ֺ�λ�ö��ԣ���ţ���� '|' ���ӣ����ֲ¶�λ�ò��ԣ���ţ���Ĳ���б��Ӵֱ�ʶ��
//"1807"
//"7810"
//ʾ�� 2��
//���룺secret = "1123", guess = "0111"
//�����"1A1B"
//���ͣ����ֺ�λ�ö��ԣ���ţ���� '|' ���ӣ����ֲ¶�λ�ò��ԣ���ţ���Ĳ���б��Ӵֱ�ʶ��
//"1123"        "1123"
//|      or     |
//"0111"        "0111"
//ע�⣬������ƥ��� 1 �У�ֻ��һ����������ţ�����ֲ¶�λ�ò��ԣ���ͨ���������зǹ�ţ���֣����н���һ�� 1 ���Գ�Ϊ��ţ����
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



/*128. ���������
�ѽ��
�е�
��ر�ǩ
�����ҵ
����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨���������*/
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