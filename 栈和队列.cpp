#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include<unordered_map>
#include<map>
#include<cctype>
#include<ctype.h>
#include <string>
using namespace std;
//232. ��ջʵ�ֶ���
//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
//ʵ�� MyQueue �ࣺ
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false
//˵����
//�� ֻ�� ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ�� push to top, peek / pop from top, size, �� is empty �����ǺϷ���
class MyQueue {
private:
    stack<int> instack, outstack;
    void in2out()
    {
        while (!instack.empty())
        {
            outstack.push(instack.top());
            instack.pop();
        }
    }
public:
    MyQueue()
    {

    }

    void push(int x) // ��Ԫ�� x �Ƶ����е�ĩβ
    {
        instack.push(x);
    }

    int pop()  //�Ӷ��еĿ�ͷ�Ƴ�������Ԫ�� 
    {
        if (outstack.empty())
        {
            in2out();
        }
        int x = outstack.top();
        outstack.pop();
        return x;
    }

    int peek() //���ض��п�ͷ��Ԫ��
    {
        if (outstack.empty())
        {
            in2out();
        }
        return outstack.top();
    }

    bool empty() // �������Ϊ�գ����� true �����򣬷��� false
    {
        return instack.empty() && outstack.empty();
    }
};

//225. �ö���ʵ��ջ
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
//ʵ�� MyStack �ࣺ
//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��
//ע�⣺
//��ֻ��ʹ�ö��еĻ������� ���� Ҳ���� push to back��peek / pop from front��size �� is empty ��Щ������
class MyStack {
public:
    queue<int> q;
    MyStack() {}

    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (size_t i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int r = q.front();
        q.pop();
        return r;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};
//20. ��Ч������
//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
//ʾ�� 1��
//���룺s = "()"
//�����true
//ʾ�� 2��
//���룺s = "()[]{}"
//�����true
//ʾ�� 3��
//���룺s = "(]"
//�����false
//ע�⣺([)]�����ǲ����Ե� ������({[]})
bool isValid(string s)
{
    if (((s.size() >> 1) & 1) == 1)
    {
        return false;
    }
    unordered_map<char, char> pair =
    {
        {'(',')'},
        {'{','}'},
        {'[',']'}
    };
    stack<char> st;
    for (auto i : s)
    {
        if (pair.count(i))
        {
            if (st.empty() || st.top() != pair[i])
            {
                return false;
            }
            st.pop();
        }
        else
        {
            st.push(i);
        }
    }
    return st.empty();
}

//1047. ɾ���ַ����е����������ظ���
//������Сд��ĸ��ɵ��ַ��� S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�
//�� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����
//����������ظ���ɾ�������󷵻����յ��ַ������𰸱�֤Ψһ��
//ʾ����
//���룺"abbaca"
//�����"ca"
//���ͣ�
//���磬�� "abbaca" �У����ǿ���ɾ�� "bb" ��������ĸ��������ͬ�����Ǵ�ʱΨһ����ִ��ɾ���������ظ��֮�����ǵõ��ַ��� "aaca"��������ֻ�� "aa" ����ִ���ظ���ɾ�����������������ַ���Ϊ "ca"
// ˼· ����ջ��˼��  ע�� ����ջ��˼����ָ ��һ��Ҫ��ջ��ָ���ݽṹ�����ϵģ� �����Բο�ջ������ģʽ����ջ���ջ��
//  �����ַ���s ������ �½�һ��ջ ���ջ��û��Ԫ������� ���ջ����Ԫ������ջ�ڵ�top������ͬ��ôtop������ջ
string removeDuplicates(string s)
{
    string st;
    for (auto i : s)
    {
        if (!st.empty() && i == st.back())
        {
            st.pop_back();
        }
        else
        {
            st.push_back(i);
        }
    }
    return st;
}
//int main()
//{
//    string s = "abbaca";
//    cout << removeDuplicates(s);
//}

//150. �沨�����ʽ��ֵ
//����һ���ַ������� tokens ����ʾһ������ �沨����ʾ�� ��ʾ���������ʽ��
//�������ñ��ʽ������һ����ʾ���ʽֵ��������
//ע�⣺
//��Ч�����Ϊ '+'��'-'��'*' �� '/' ��
//ÿ����������������󣩶�������һ������������һ�����ʽ��
//��������֮��ĳ������� ����ض� ��
//���ʽ�в����������㡣
//������һ�������沨����ʾ����ʾ���������ʽ��
//�𰸼������м������������ 32 λ ������ʾ��
//ʾ�� 1��
//���룺tokens = ["2", "1", "+", "3", "*"]
//�����9
//���ͣ�����ʽת��Ϊ��������׺�������ʽΪ��((2 + 1) * 3) = 9
//ʾ�� 2��
//���룺tokens = ["4", "13", "5", "/", "+"]
//�����6
//���ͣ�����ʽת��Ϊ��������׺�������ʽΪ��(4 + (13 / 5)) = 6
//ʾ�� 3��
//���룺tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//�����22
//���ͣ�����ʽת��Ϊ��������׺�������ʽΪ��
//((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22
//��ʾ��
//1 <= tokens.length <= 104
//tokens[i] ��һ�������"+"��"-"��"*" �� "/"���������ڷ�Χ[-200, 200] �ڵ�һ������
//�沨�����ʽ��
//�沨�����ʽ��һ�ֺ�׺���ʽ����ν��׺����ָ���д�ں��档
//ƽ��ʹ�õ���ʽ����һ����׺���ʽ����(1 + 2) * (3 + 4) ��
//����ʽ���沨�����ʽд��Ϊ((1 2 + ) (3 4 + )*) ��
//�沨�����ʽ��Ҫ�����������ŵ㣺
//ȥ�����ź���ʽ�����壬��ʽ����д�� 1 2 + 3 4 + *Ҳ�������ݴ���������ȷ�����
//�ʺ���ջ�������㣺������������ջ�����������ȡ��ջ���������ֽ��м��㣬�������ѹ��ջ��
//   ������˼·�����뵽������ջ��ջ�Ĳ���  �е��鷳�����ж�����ַ����ܷ���Ϊ������ջ������Ϊ�ַ�����-����Ϊ������
bool isNumber(const string& str)
{
    int n = str.size();
    if (n == 1 && str[0] == '-')
    {
        return false;
    }
    int i = 0;
    for (char const& c : str)
    {
        if (i == 0 && c == '-')
        {
            ++i;
            continue;
        }
        if (isdigit(c) == 0)
        {
            return false;
        }
    }
    return true;
}
int evalRPN(vector<string>& tokens)
{
    int n = tokens.size();
    stack<int> stk;
    for (size_t i = 0; i < n; i++)
    {
        if (isNumber(tokens[i]))
        {
            stk.push(atoi(tokens[i].c_str()));
        }
        else
        {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            if (tokens[i][0] == '+')
            {
                stk.push(a + b);
            }
            else if (tokens[i][0] == '-')
            {
                stk.push(a - b);
            }
            else if (tokens[i][0] == '*')
            {
                stk.push(a * b);
            }
            else
            {
                stk.push(a / b);
            }
        }
        cout << stk.top();
    }
    return stk.top();
}
//int main()
//{
//    vector<string> tokens = { "4","3","-" };
//    cout << evalRPN(tokens);
//}



//239. �����������ֵ
//����һ���������� nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��
//���� ���������е����ֵ ��
//ʾ�� 1��
//���룺nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
//�����[3, 3, 5, 5, 6, 7]
//���ͣ�
//�������ڵ�λ��                ���ֵ
//-------------- - ---- -
//[1  3 - 1] - 3  5  3  6  7    3
//1[3 - 1 - 3] 5  3  6  7       3
//1  3[-1 - 3  5] 3  6  7       5
//1  3 - 1[-3  5  3] 6  7       5
//1  3 - 1 - 3[5  3  6] 7       6
//1  3 - 1 - 3  5[3  6  7]      7
//ʾ�� 2��
//���룺nums = [1], k = 1
//�����[1]
//��ʾ��
//1 <= nums.length <= 105
//- 104 <= nums[i] <= 104
//1 <= k <= nums.length
//�������  ʱ�临�Ӷ�Ϊ��n-k)*k
vector<int> maxSlidingWindow_1(vector<int>& nums, int k)
{
    int len = nums.size();
    vector<int> a;
    for (size_t i = 0; i <= len - k; i++)
    {
        int max_x = -10000;
        for (size_t j = i; j < i + k; j++)
        {
            if (max_x < nums[j])
            {
                max_x = nums[j];
            }
        }
        a.push_back(max_x);
    }
    return a;
}
//�������� ������һ�������ݼ��Ķ��� ���е�ͷ�����ǻ������ڵ����ֵ �����д�ŵ����±꣨�Ա��˳���  
// ʱ�临�Ӷ�Ϊ O(n)
vector<int> maxSlidingWindow_2(vector<int>& nums, int k)
{
    size_t len = nums.size();
    vector<int> ans;
    list<int> que;
    for (size_t i = 0; i < k; i++)
    {
        while (!que.empty() && nums[i] > nums[que.back()])
        {
            que.pop_back();
        }
        que.push_back(i);
    }
    ans.push_back(nums[que.front()]);
    for (size_t i = k; i < len; i++)
    {
        while (!que.empty() && nums[i] > nums[que.back()])
        {
            que.pop_back();
        }
        que.push_back(i);
        if (que.front() <= i - k)
        {
            que.pop_front();
        }
        ans.push_back(nums[que.front()]);
    }
    return ans;
}
//int main()
//{
//    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
//    for (auto i : maxSlidingWindow(nums, 3))
//    {
//        cout << i << '\t';
//    }
//}

//���ȶ���Ԥ����
//��һ������Ϊn������(n��10�ı���)��ÿ����a��������[0,9]�е�������
// С������������ÿ�������ֵĴ�����̫ƽ���������ĵ�i�����Ĵ���Ϊb;��
// ����������ɸ�����ֵʹ����10�������ֵĴ������(������n/10)�����ʴ��ۺ�����Ϊ���١�
//�����ʽ
//����ĵ�һ�а���һ��������n��
//������n�У���i�а�����������a?, b?����һ���ո�ָ���
int nums_count_averagr()
{
    int n;
    cin >> n;
    int target = n / 10;
    long long int sum = 0;
    map<int, priority_queue<int, vector<int>, greater<int> >> nums;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;
        nums[a].push(b);
        if (nums[a].size() > target)
        {
            sum += nums[a].top();
            nums[a].pop();
        }
    }
    return sum;
}
//347. ǰ K ����ƵԪ��
//����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�����԰� ����˳�� ���ش𰸡�
//ʾ�� 1:
//����: nums = [1, 1, 1, 2, 2, 3], k = 2
//��� : [1, 2]
//ʾ�� 2 :
//���� : nums = [1], k = 1
//    ��� : [1]
//    ��ʾ��
//    1 <= nums.length <= 105
//    k ��ȡֵ��Χ��[1, �����в���ͬ��Ԫ�صĸ���]
//    ��Ŀ���ݱ�֤��Ψһ�����仰˵��������ǰ k ����ƵԪ�صļ�����Ψһ��
//    ���ף���������㷨��ʱ�临�Ӷ� ���� ���� O(n log n) ������ n �������С
class Stack_priority_queue {
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
public:
    Stack_priority_queue()
    {}
    ~Stack_priority_queue()
    {
    }
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        size_t len = nums.size();
        unordered_map<int, int> hash;
        for (size_t i = 0; i < nums.size(); i++)
        {
            ++hash[nums[i]];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (auto i : hash)
        {
            pri_que.push(i);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        for (auto i : result)
        {
            cout << i << '\t';
        }
        return result;
    }
private:
};
//int main()
//{
//    vector<int> nums = { 1,1,1,2,2,3 };
//    Solution sol;
//    sol.topKFrequent(nums, 2);
//}