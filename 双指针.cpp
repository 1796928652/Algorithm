#include<vector>
#include <iostream>
using namespace std;
//15. ����֮��
//����һ���������� nums ���ж��Ƿ������Ԫ��[nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ����
//�㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
//ע�⣺���в����԰����ظ�����Ԫ�顣
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
//˼·һ ˫ָ��  �����i��j�Դ����±�
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
//˼·�� ���Ӷ���deque�ĽǶȳ���   ����ǵû�ͷ��һ��
//��������˫�˶���          
//����˫�˶���֧�ִӶ���ͷ������ķ�����������ǿ��������ַ���һ��һ�����ʴ���Ȼ�󽫵���ѹ����е�ͷ�����ٽ�����ת���ַ������ɡ�
//class Solution {
//public:
//    string reverseWords(string s) {
//        int left = 0, right = s.size() - 1;
//        // ȥ���ַ�����ͷ�Ŀհ��ַ�
//        while (left <= right && s[left] == ' ') ++left;
//
//        // ȥ���ַ���ĩβ�Ŀհ��ַ�
//        while (left <= right && s[right] == ' ') --right;
//
//        deque<string> d;
//        string word;
//
//        while (left <= right) {
//            char c = s[left];
//            if (word.size() && c == ' ') {
//                // ������ push �����е�ͷ��
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




/*283. �ƶ���
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
��ע�� �������ڲ���������������ԭ�ض�������в���*/
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

/*11. ʢ���ˮ������
����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵���(i, 0) ��(i, height[i]) ��
�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
�����������Դ�������ˮ����*/
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





//����ʵ�� ˫�˷�
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