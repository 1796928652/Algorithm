#include<iostream>
#include<vector>
using namespace std;
//��̬�滮����
// 
// 
// 
// 
//������������¥�ݡ���Ҫ n ������ܵ���¥����
//ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
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



//����������
// 
// ��̬�滮�����������
// dp����   ���ƹ�ʽ  ��ʼ��   ����˳��   ������
// 
// 
// 
// 
// 674. �������������
//����һ��δ��������������飬�ҵ���� ���������������У������ظ����еĳ��ȡ�
//���������������� �����������±� l �� r��l < r��ȷ�����������ÿ�� l <= i < r������ nums[i] < nums[i + 1] ����ô������[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] �����������������С�
//	ʾ�� 1��
//	���룺nums = [1, 3, 5, 4, 7]
//	�����3
//	���ͣ����������������[1, 3, 5], ����Ϊ3��
//	����[1, 3, 5, 7] Ҳ�������������, �������������ģ���Ϊ 5 �� 7 ��ԭ�����ﱻ 4 ������
//	ʾ�� 2��
//	���룺nums = [2, 2, 2, 2, 2]
//	�����1
//	���ͣ����������������[2], ����Ϊ1��
//	��ʾ��
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


//300. �����������
//����һ���������� nums ���ҵ�������ϸ���������еĳ��ȡ�
//������ ���������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳�����磬[3, 6, 2, 7] ������[0, 3, 1, 6, 2, 2, 7] �������С�
//ʾ�� 1��
//���룺nums = [10, 9, 2, 5, 3, 7, 101, 18]
//�����4
//���ͣ��������������[2, 3, 7, 101]����˳���Ϊ 4 ��
//ʾ�� 2��
//���룺nums = [0, 1, 0, 3, 2, 3]
//�����4
//ʾ�� 3��
//���룺nums = [7, 7, 7, 7, 7, 7, 7]
//�����1
//1 <= nums.length <= 2500
//- 104 <= nums[i] <= 104
// ˼· �� ����һ����̬����dp dp[i]�ĺ����Ǵ�0��i�����������i��������������еĳ���
// ���������ǵ��ƹ�ʽ  ����i����������Ǳ�ȡ�� ����һ���±�j ���j�����������ҪС��i�����������dp[i]=dp[j]+1  ����j�����������һ��ֻ��һ�� ��������Ҫ��� ����������dp[j]�����ֵ
// ����ƹ�ʽ���Ա�ʾΪdp[i]=max(dp[j]+1,dp[i]);
// �����￼�ǳ�ʼ��������  ����ÿ�������ܺ����Լ���Ϊһ������ ����ÿ��dpֵ��Ϊ1
// �������⣺ ֱ����i���� i����nums��ÿ�������±� �����±�j j��0��i�ҵ���i��ʱ�������������г���
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
//   ������һ�����һ�εĲ������ �Ƿ����� ��Ϊ��һ��Ҫ����������dp[i]ֻ��dp[i-1]�й� ������û���������Ժ�0��i��ĳ����j��dp[j]���йأ�����




//718. ��ظ�������
//�������������� nums1 �� nums2 ������ ���������� ������ ���������������ĳ��� ��
//ʾ�� 1��
//���룺nums1 = [1, 2, 3, 2, 1], nums2 = [3, 2, 1, 4, 7]
//�����3
//���ͣ�������Ĺ�����������[3, 2, 1] ��
//ʾ�� 2��
//���룺nums1 = [0, 0, 0, 0, 0], nums2 = [0, 0, 0, 0, 0]
//�����5
//��ʾ��
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 100
//˼·һ ����������ҵ���ͬ������ �����ظ������鳤��  �ҵ������ظ����鳤��
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
//˼·�� ��̬�滮  �Ȳ���˼·�� ֱ�������� �������
//                     ���� nums1 = [1, 2, 3, 2, 1], nums2 = [3, 2, 1, 4, 7]
//          �����ȿ�һ����άͼ  
//	                 1		2		3		2		1
//				3	 				1				
//				2	 		1				2(1+1)	
//				1	 1								3(2+1)
//				4			0										
//				7
//             Ч��ͼ��
//					0       0       0       0       0       0
//					0       0       0       1       0       0
//					0       0       1       0       0       0
//					0       1       0       0       0       0
//					0       0       2       0       0       0
//					0       0       0       3       0       0
//	      ���ѷ���  ����һ���ظ������������� �����ܹ��ɵĳ���(�ڱ���������) ������һ���ظ��������ڱ���ﹹ�ɵĳ��ȼ�1������
//	      ��ô�ɴ� д�����ǵ�״̬ת�Ʒ��� dp[i][j]=dp[i-1][j-1]+1
//	      ������Ҫע����� Խ������  �����ظ���������ĵ�һ���ظ����� ���ǵ�״̬ת�Ʒ��̿��ܻط���Խ������ �������Ƕ��һ�к�һ��
//		  ��� ��ѭ���� ����һ������ man_n ����ѭ���ҵ����ֵ
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

//����һ�κ��� ��Ҫ�����仯 ������һ��һ��Ҫ����
//1143. �����������
//���������ַ��� text1 �� text2�������������ַ������ ���������� �ĳ��ȡ���������� ���������� ������ 0 ��
//һ���ַ����� ������ ��ָ����һ���µ��ַ�����������ԭ�ַ����ڲ��ı��ַ������˳��������ɾ��ĳЩ�ַ���Ҳ���Բ�ɾ���κ��ַ�������ɵ����ַ�����
//���磬"ace" �� "abcde" �������У��� "aec" ���� "abcde" �������С�
//�����ַ����� ���������� ���������ַ�������ͬӵ�е������С�
//ʾ�� 1��
//���룺text1 = "abcde", text2 = "ace"
//�����3
//���ͣ�������������� "ace" �����ĳ���Ϊ 3 ��
//ʾ�� 2��
//���룺text1 = "abc", text2 = "abc"
//�����3
//���ͣ�������������� "abc" �����ĳ���Ϊ 3 ��
//ʾ�� 3��
//���룺text1 = "abc", text2 = "def"
//�����0
//���ͣ������ַ���û�й��������У����� 0 ��
//��ʾ��
//1 <= text1.length, text2.length <= 1000
//text1 �� text2 ����СдӢ���ַ����
//˼· ������һ�ζ�̬�滮���� Ҳ��ͨ�������άdp�����
//            �ȸ�����άͼ �������
//	                      a		b		c		d		e
//	                  a	  1		0		0		0		0
//					  c	  0		0		2(1+1)	0		0
//					  e	  0		0		0		0		3(2+1)
//	         ��ͼ�в��ѿ��� ��ʵ��̬ת�Ʒ���Ϊ dp[i][j] =  0��i-1��0��j-1������淶Χ�����ֵ +1 
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
//          �����ڱ�������ѭ������Ƕ��������ѭ��  �ᵼ�³�ʱ����  ���Ը÷��� ����0��i-1��0��j-1���淶Χ������ֵ��Ҫ�Ż�
//			  ������Կ�����hash�� ͨ��hash����ʹ���ظ�����֮���ж�Ӧ���±��ϵ
//			                 �������һ������
//			                          a		b	c	d	e
//                             1<-a	  1
//			                 5<-e                       2
//			                 3<-c               2
//                      ���Կ�������cͨ��hash���Ӧ3��λ�� �����ֱ��ͨ���ұ�3С����  ������������ͻȻ�뵽hash���Ǻ��鷳  ����
//			  ����˼·   ���԰������Ǹ����ĳ�����������
//			      a		b		c		d		e
//			  a	  1		1		1		1		1
//			  c	  1		1		2(1+1)	2		2
//			  e	  1		1		2		2		3(2+1)
//			  ��ʱ�� ״̬ת�Ʒ���
//			                    if (text1[i]==text2[j]) ��dp[i][j] = dp[i - 1][j - 1] + 1
//								else   dp[i][j]=max(dp[i-1][j],dp[i][j-1] 
//                              ��Ҫ��ϸ����Ϊʲôelse������������dp��������
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


//����һ��ʵ��̫����  ��������һ�⣨���ģ�
//1035. ���ཻ����
//������������ˮƽ���ϰ�������˳��д�� nums1 �� nums2 �е�������
//���ڣ����Ի���һЩ������������ nums1[i] �� nums2[j] ��ֱ�ߣ���Щֱ����Ҫͬʱ�������㣺
//nums1[i] == nums2[j]
//�һ��Ƶ�ֱ�߲����κ��������ߣ���ˮƽ�ߣ��ཻ��
//��ע�⣬���߼�ʹ�ڶ˵�Ҳ�����ཻ��ÿ������ֻ������һ�����ߡ�
//�����ַ������������������ؿ��Ի��Ƶ������������
//ʾ�� 1
//���룺nums1 = [1, 4, 2], nums2 = [1, 2, 4]
//�����2
//���ͣ����Ի���������������ߣ�����ͼ��ʾ��
//���޷��������������ཻ��ֱ�ߣ���Ϊ�� nums1[1] = 4 �� nums2[2] = 4 ��ֱ�߽���� nums1[2] = 2 �� nums2[1] = 2 ��ֱ���ཻ��
//ʾ�� 2��
//���룺nums1 = [2, 5, 1, 2, 5], nums2 = [10, 5, 2, 1, 5, 2]
//�����3
//ʾ�� 3��
//���룺nums1 = [1, 3, 7, 1, 7, 5], nums2 = [1, 9, 2, 5, 1]
//�����2
//��ʾ��
//1 <= nums1.length, nums2.length <= 500
//1 <= nums1[i], nums2[j] <= 2000
////    ����˼·   ��������ҩ������
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


//53.����������
//����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
//������ �������е�һ���������֡�
//ʾ�� 1��
//���룺nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//�����6
//���ͣ�����������[4, -1, 2, 1] �ĺ����Ϊ 6 ��
//ʾ�� 2��
//���룺nums = [1]
//�����1
//ʾ�� 3��
//���룺nums = [5, 4, -1, 7, 8]
//�����23
//��ʾ��
//1 <= nums.length <= 105
//- 104 <= nums[i] <= 104
//Ҫ��ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ��
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


//392. �ж�������
//�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�
//�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���
//���ף�
//����д�������� S������ S1, S2, ..., Sk ���� k >= 10�ڣ�����Ҫ���μ�������Ƿ�Ϊ T �������С�����������£���������ı���룿
//ʾ�� 1��
//���룺s = "abc", t = "ahbgdc"
//�����true
//ʾ�� 2��
//���룺s = "axc", t = "ahbgdc"
//�����false
//��ʾ��
//0 <= s.length <= 100
//0 <= t.length <= 10 ^ 4
//�����ַ�����ֻ��Сд�ַ����
// 
// ˼·һ����̬�滮   ˼·�����漸������
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
// ˼·�� ��// ���Ǵ�˫ָ��ĽǶȿ��ǵ�
// ��i����һ���ѭ��  ������һָ��j ���ڱ�������е��±�  
// �������ȵ��ַ���j++  ����ж�j�Ƿ���������г��� �������Ϊtrue
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







//724. Ѱ������������±�
//����һ���������� nums ������������ �����±� ��
//���� �����±� �������һ���±꣬���������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//��������±�λ����������ˣ���ô�����֮����Ϊ 0 ����Ϊ���±����಻����Ԫ�ء���һ����������±�λ���������Ҷ�ͬ�����á�
//��������ж�������±꣬Ӧ�÷��� ������ ����һ����������鲻���������±꣬���� - 1 ��
//���룺nums = [1, 7, 3, 6, 5, 6]
//�����3
//���ͣ�
//�����±��� 3 ��
//�����֮�� sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ��
//�Ҳ���֮�� sum = nums[4] + nums[5] = 5 + 6 = 11 ��������ȡ�
//ʾ�� 2��
//���룺nums = [1, 2, 3]
//����� - 1
//���ͣ�
//�����в���������������������±ꡣ
//ʾ�� 3��
//���룺nums = [2, 1, -1]
//�����0
//���ͣ�
//�����±��� 0 ��
//�����֮�� sum = 0 �����±� 0 ��಻����Ԫ�أ���
//�Ҳ���֮�� sum = nums[1] + nums[2] = 1 + -1 = 0
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


//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽��
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

//��ҽ���2 ������β�����أ���  ���Ҫ��ٵ�һ�䷿ ��ô��ٷ�Χ���ǵ�һ�䵽�����ڶ��䣬���Ҫ��ٵڶ��䷿����ô��ٷ�Χ���ǵڶ��䵽������һ��  ������������۾��У�
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

//��ҽ��������
//ɾ������õ���
//����һ���������� nums ������Զ�������һЩ������
//ÿ�β����У�ѡ������һ�� nums[i] ��ɾ��������� nums[i] �ĵ�����֮�������ɾ�� ���� ���� nums[i] - 1 �� nums[i] + 1 ��Ԫ�ء�
//��ʼ��ӵ�� 0 ����������������ͨ����Щ������õ�������
//�����˼·�ĺ����������±�����ʾ�������  ���±���ָ��ֵ���Ǿ�������ĸ���
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


/*121. ������Ʊ�����ʱ��
����һ������ prices �����ĵ� i ��Ԫ�� prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�
��ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ�����һ���㷨�����������ܻ�ȡ���������
��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 ��
ʾ�� 1��
���룺[7, 1, 5, 3, 6, 4]
�����5
���ͣ��ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6 - 1 = 5 ��
ע���������� 7 - 1 = 6, ��Ϊ�����۸���Ҫ��������۸�ͬʱ���㲻��������ǰ������Ʊ��
ʾ�� 2��
���룺prices = [7, 6, 4, 3, 1]
�����0
���ͣ������������, û�н������, �����������Ϊ 0*/
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
	//for (int i = 0; i < len; i++) ��ʵ������Բ�����ʼ�� ��Ϊ��ʼ���ɱ����������棻
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


//���뷽��
//һ��������ĸ A - Z ����Ϣͨ������ӳ������� ���� ��
//'A' -> "1"
//'B' -> "2"
//.......
//'Z' -> "26"
//Ҫ ���� �ѱ������Ϣ���������ֱ����������ӳ��ķ���������ӳ�����ĸ�������ж��ַ����������磬"11106" ����ӳ��Ϊ��
//"AAJF" ������Ϣ����Ϊ(1 1 10 6)
//"KJF" ������Ϣ����Ϊ(11 10 6)
//ע�⣬��Ϣ���ܷ���Ϊ(1 11 06) ����Ϊ "06" ����ӳ��Ϊ "F" ���������� "6" �� "06" ��ӳ���в����ȼۡ�
//����һ��ֻ�����ֵ� �ǿ� �ַ��� s ������㲢���� ���� ������ ���� ��
//��Ŀ���ݱ�֤�𰸿϶���һ�� 32 λ ��������
//ʾ�� 1��
//���룺s = "12"
//�����2
//���ͣ������Խ���Ϊ "AB"��1 2������ "L"��12����
//ʾ�� 2��
//���룺s = "226"
//�����3
//���ͣ������Խ���Ϊ "BZ" (2 26), "VF" (22 6), ���� "BBF" (2 2 6) ��
//ʾ�� 3��
//���룺s = "06"
//�����0
//���ͣ�"06" �޷�ӳ�䵽 "F" ����Ϊ����ǰ���㣨"6" �� "06" �����ȼۣ���
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








//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ����
//���ܹ��ж�������ͬ��·����
// ˼·һ ��������ϵĽǶȳ���  ������Ҫ�����Ͻ��ߵ����½������Ҫ��m+n-2�� ����m+n-2����ֻ��Ҫ��m-1����n-1������Cmin(m-1,n-1)/(m+n-2��
//int uniquePaths(int m, int n)
//{
//    int sum = 1;
//    for (int x = m + n - 2, y = 1; y < min(m, n); x--, y++)
//    {
//        sum = sum * x / y;
//    }
//    return sum;
//}
//˼·�� �ӵݹ�ĽǶȳ���  Ҫ�ߵ���m,n)�ķ���Ϊ�ߵ���m-1��n�������ߵ���m��n-1���ķ���֮�ͣ�
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
//�����ǵ������ĵݹ�����Դ����ݵ�ʱ��ִ��Ч�����ⲻ�� ��Ľ��Ż�
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
//�����������ö�̬�������洢��ÿ������߷�������Ч�ʼӿ�




//����һ�������Ǹ������� m x n ���� grid �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
//˵����ÿ��ֻ�����»��������ƶ�һ����
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






//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish������
//���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
//�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
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
//LCR 091. ��ˢ����
//������һ�ŷ��ӣ��� n ����ÿ�����ӿ��Ա���ˢ�ɺ�ɫ����ɫ������ɫ��������ɫ�е�һ�֣�����Ҫ��ˢ���еķ��Ӳ���ʹ�����ڵ�����������ɫ������ͬ��
//��Ȼ����Ϊ�г��ϲ�ͬ��ɫ����ļ۸�ͬ�����Է��ӷ�ˢ�ɲ�ͬ��ɫ�Ļ��ѳɱ�Ҳ�ǲ�ͬ�ġ�ÿ�����ӷ�ˢ�ɲ�ͬ��ɫ�Ļ�������һ�� n x 3 ������������ costs ����ʾ�ġ�
//���磬costs[0][0] ��ʾ�� 0 �ŷ��ӷ�ˢ�ɺ�ɫ�ĳɱ����ѣ�costs[1][2] ��ʾ�� 1 �ŷ��ӷ�ˢ����ɫ�Ļ��ѣ��Դ����ơ�
//��������ˢ�����з������ٵĻ��ѳɱ���
//ʾ�� 1��
//���� : costs = [[17, 2, 17], [16, 16, 5], [14, 3, 19]]
//��� : 10
//���� : �� 0 �ŷ��ӷ�ˢ����ɫ��1 �ŷ��ӷ�ˢ����ɫ��2 �ŷ��ӷ�ˢ����ɫ��
//���ٻ��� : 2 + 5 + 3 = 10��
//ʾ�� 2��
//���� : costs = [[7, 6, 2]]
//��� : 2
//��ʾ :
//    costs.length == n
//    costs[i].length == 3
//    1 <= n <= 100
//    1 <= costs[i][j] <= 20
// ˼· �������������  ����dp[i][j]��ȡֵ����min(costs[i][j]+dp[i-1][x]  x����0��2�г�j������������)
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



//����һ�������� triangle ���ҳ��Զ����µ���С·���͡�
//ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ����ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ��������㡣Ҳ����˵�������λ�ڵ�ǰ�е��±� i ����ô��һ�������ƶ�����һ�е��±� i �� i + 1 ��
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
//}    ps:��˼����=�Ƿ��н�ʡ�ռ�����������ù������飩




//��һ���� '0' �� '1' ��ɵĶ�ά�����ڣ��ҵ�ֻ���� '1' ����������Σ��������������
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
//��������Ǻ���  ��������һ�⣻
// // 1277. ͳ��ȫΪ 1 ���������Ӿ���
//����һ�� m* n �ľ��󣬾����е�Ԫ�ز��� 0 ���� 1������ͳ�Ʋ�����������ȫ�� 1 ��ɵ� ������ �Ӿ���ĸ�����
//ʾ�� 1��
//���룺matrix =
//[
//	[0, 1, 1, 1],
//		[1, 1, 1, 1],
//		[0, 1, 1, 1]
//]
//�����15
//���ͣ�
//�߳�Ϊ 1 ���������� 10 ����
//�߳�Ϊ 2 ���������� 4 ����
//�߳�Ϊ 3 ���������� 1 ����
//�����ε����� = 10 + 4 + 1 = 15.
//ʾ�� 2��
//���룺matrix =
//[
//	[1, 0, 1],
//		[1, 1, 0],
//		[1, 1, 0]
//]
//�����7
//���ͣ�
//�߳�Ϊ 1 ���������� 6 ����
//�߳�Ϊ 2 ���������� 1 ����
//�����ε����� = 6 + 1 = 7.
//��ʾ��
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

//����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
//����ַ����ķ�����ԭʼ�ַ�����ͬ������ַ�����Ϊ�����ַ�����
// ����һ  �������� ���ж������ĸ�Ƿ���ͬ�����ж���һ����ĸ�Ƿ���ͬ
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
//������ ���ö�̬�滮��˼��  ��������:������չ��  ����ǻ��Ĵ����ڲ�����ͬ ����������չһλ�������Ƿ���ͬ Ȼ�󷵻����
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










//��������  �����޵Ŀռ���װ��ֵ����ߵ���Ʒ
//int bag(vector<int> a, vector<int> b, int m)//a����ÿ����Ʒ����� b����ÿ����Ʒ�ļ�ֵ m���������ܿռ��С
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


//416. �ָ�Ⱥ��Ӽ�
//����һ�� ֻ���������� �� �ǿ� ���� nums �������ж��Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�
//ʾ�� 1��
//���룺nums = [1, 5, 11, 5]
//�����true
//���ͣ�������Էָ��[1, 5, 5] ��[11] ��
//ʾ�� 2��
//���룺nums = [1, 2, 3, 5]
//�����false
//���ͣ����鲻�ָܷ������Ԫ�غ���ȵ��Ӽ���
//��ʾ��
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


//494. Ŀ���
//����һ���Ǹ��������� nums ��һ������ target ��
//�������е�ÿ������ǰ��� '+' �� '-' ��Ȼ�������������������Թ���һ�� ���ʽ ��
//���磬nums = [2, 1] �������� 2 ֮ǰ��� '+' ���� 1 ֮ǰ��� '-' ��Ȼ���������õ����ʽ "+2-1" ��
//���ؿ���ͨ��������������ġ����������� target �Ĳ�ͬ ���ʽ ����Ŀ
//ʾ�� 1��
//���룺nums = [1, 1, 1, 1, 1], target = 3
//�����5
//���ͣ�һ���� 5 �ַ���������Ŀ���Ϊ 3 ��
//- 1 + 1 + 1 + 1 + 1 = 3
//+ 1 - 1 + 1 + 1 + 1 = 3
//+ 1 + 1 - 1 + 1 + 1 = 3
//+ 1 + 1 + 1 - 1 + 1 = 3
//+ 1 + 1 + 1 + 1 - 1 = 3
//ʾ�� 2��
//���룺nums = [1], target = 1
//�����1
//��ʾ��
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



//���ʲ��
//����һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣������������ֵ��г��ֵ�һ����������ƴ�ӳ� s �򷵻� true��
//ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�
//bool wordBreak(string s, vector<string>& wordDict) {
//    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//    vector<bool> dp(s.size() + 1, false);
//    dp[0] = true;
//    for (int i = 1; i <= s.size(); i++) {   // ��������
//        for (int j = 0; j < i; j++) {       // ������Ʒ
//            string word = s.substr(j, i - j); //substr(��ʼλ�ã���ȡ�ĸ���)
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


//873. ���쳲����������еĳ���
//������� X_1, X_2, ..., X_n ����������������˵���� 쳲�����ʽ �ģ�
//n >= 3
//�������� i + 2 <= n������ X_i + X_{ i + 1 } = X_{ i + 2 }
//����һ���ϸ�����������������γ����� arr ���ҵ� arr �����쳲�����ʽ�������еĳ��ȡ����һ�������ڣ�����  0 ��
//ʾ�� 1��
//���� : arr = [1, 2, 3, 4, 5, 6, 7, 8]
//��� : 5
//���� : ���쳲�����ʽ������Ϊ[1, 2, 3, 5, 8] ��
//ʾ�� 2��
//���� : arr = [1, 3, 7, 11, 12, 14, 18]
//��� : 3
//���� : ���쳲�����ʽ��������[1, 11, 12]��[3, 11, 14] �Լ�[7, 11, 18] ��
//��ʾ��
//3 <= arr.length <= 1000
//1 <= arr[i] < arr[i + 1] <= 10 ^ 9
//˼· ע��쳲��������е����һ�������ǵ����ڶ��������뵹������������֮�� ����Ҳ����˵ ����������ȡ�벻ȡ����ǰ�������־�����
//  Ȼ����dp[][]  dp[i][j]��ֵΪ��jΪ������һ��������iΪ�����ڶ�������쳲����������г���  
//                        j=i+k  kΪ����ֵ   ���k�������еĻ� ��ôdp[i][j]=d[k][i]+1
//											 ���k���������еĻ� ��ôdp[i][j]=2 ��ʾi��j�Գɳ���Ϊ2��������
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


//673. ����������еĸ���
//����һ��δ������������� nums �� ��������������еĸ��� ��
//ע�� ������б����� �ϸ� �����ġ�
//ʾ�� 1:
//����: [1, 3, 5, 4, 7]
//��� : 2
//���� : ����������������У��ֱ���[1, 3, 4, 7] ��[1, 3, 5, 7]��
//ʾ�� 2 :
//���� : [2, 2, 2, 2, 2]
//��� : 5
//���� : ����������еĳ�����1�����Ҵ���5�������еĳ���Ϊ1��������5
int findNumberOfLIS(vector<int>& nums)
{
	int length = nums.size();
	vector<int> dp(length, 1);
	vector<int> count(length, 1);
	if (nums.size() <= 1)
	{
		return nums.size();
	}
	//dp[i]��i֮ǰ������i������������еĳ���Ϊdp[i]
	//count[i]����nums[i]Ϊ��β���ַ���������������еĸ���Ϊcount[i]
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