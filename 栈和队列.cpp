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
//232. 用栈实现队列
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//实现 MyQueue 类：
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
//说明：
//你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的
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

    void push(int x) // 将元素 x 推到队列的末尾
    {
        instack.push(x);
    }

    int pop()  //从队列的开头移除并返回元素 
    {
        if (outstack.empty())
        {
            in2out();
        }
        int x = outstack.top();
        outstack.pop();
        return x;
    }

    int peek() //返回队列开头的元素
    {
        if (outstack.empty())
        {
            in2out();
        }
        return outstack.top();
    }

    bool empty() // 如果队列为空，返回 true ；否则，返回 false
    {
        return instack.empty() && outstack.empty();
    }
};

//225. 用队列实现栈
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//实现 MyStack 类：
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
//注意：
//你只能使用队列的基本操作 —— 也就是 push to back、peek / pop from front、size 和 is empty 这些操作。
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
//20. 有效的括号
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
//示例 1：
//输入：s = "()"
//输出：true
//示例 2：
//输入：s = "()[]{}"
//输出：true
//示例 3：
//输入：s = "(]"
//输出：false
//注意：([)]这样是不可以的 但允许({[]})
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

//1047. 删除字符串中的所有相邻重复项
//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
//示例：
//输入："abbaca"
//输出："ca"
//解释：
//例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"
// 思路 运用栈的思想  注意 运用栈的思想是指 不一定要用栈（指数据结构意义上的） 但可以参考栈的运作模式（入栈与出栈）
//  对于字符串s 遍历它 新建一个栈 如果栈内没有元素则加入 如果栈内有元素且与栈内的top（）相同那么top（）出栈
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

//150. 逆波兰表达式求值
//给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
//请你计算该表达式。返回一个表示表达式值的整数。
//注意：
//有效的算符为 '+'、'-'、'*' 和 '/' 。
//每个操作数（运算对象）都可以是一个整数或者另一个表达式。
//两个整数之间的除法总是 向零截断 。
//表达式中不含除零运算。
//输入是一个根据逆波兰表示法表示的算术表达式。
//答案及所有中间计算结果可以用 32 位 整数表示。
//示例 1：
//输入：tokens = ["2", "1", "+", "3", "*"]
//输出：9
//解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
//示例 2：
//输入：tokens = ["4", "13", "5", "/", "+"]
//输出：6
//解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
//示例 3：
//输入：tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//输出：22
//解释：该算式转化为常见的中缀算术表达式为：
//((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22
//提示：
//1 <= tokens.length <= 104
//tokens[i] 是一个算符（"+"、"-"、"*" 或 "/"），或是在范围[-200, 200] 内的一个整数
//逆波兰表达式：
//逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
//平常使用的算式则是一种中缀表达式，如(1 + 2) * (3 + 4) 。
//该算式的逆波兰表达式写法为((1 2 + ) (3 4 + )*) 。
//逆波兰表达式主要有以下两个优点：
//去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + *也可以依据次序计算出正确结果。
//适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
//   这道题的思路不难想到就是入栈出栈的操作  有点麻烦的是判断这个字符串能否作为数字入栈还是作为字符串“-”作为操作符
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



//239. 滑动窗口最大值
//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//返回 滑动窗口中的最大值 。
//示例 1：
//输入：nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
//输出：[3, 3, 5, 5, 6, 7]
//解释：
//滑动窗口的位置                最大值
//-------------- - ---- -
//[1  3 - 1] - 3  5  3  6  7    3
//1[3 - 1 - 3] 5  3  6  7       3
//1  3[-1 - 3  5] 3  6  7       5
//1  3 - 1[-3  5  3] 6  7       5
//1  3 - 1 - 3[5  3  6] 7       6
//1  3 - 1 - 3  5[3  6  7]      7
//示例 2：
//输入：nums = [1], k = 1
//输出：[1]
//提示：
//1 <= nums.length <= 105
//- 104 <= nums[i] <= 104
//1 <= k <= nums.length
//暴力求解  时间复杂度为（n-k)*k
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
//单调队列 队列是一个单调递减的队列 队列的头部就是滑动窗口的最大值 队列中存放的是下标（以便退出）  
// 时间复杂度为 O(n)
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

//优先队列预备题
//有一个长度为n的数组(n是10的倍数)，每个数a都是区间[0,9]中的整数。
// 小明发现数组里每种数出现的次数不太平均，而更改第i个数的代价为b;，
// 他想更改若干个数的值使得这10种数出现的次数相等(都等于n/10)，请问代价和最少为多少。
//输入格式
//输入的第一行包含一个正整数n。
//接下来n行，第i行包含两个整数a?, b?，用一个空格分隔。
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
//347. 前 K 个高频元素
//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
//示例 1:
//输入: nums = [1, 1, 1, 2, 2, 3], k = 2
//输出 : [1, 2]
//示例 2 :
//输入 : nums = [1], k = 1
//    输出 : [1]
//    提示：
//    1 <= nums.length <= 105
//    k 的取值范围是[1, 数组中不相同的元素的个数]
//    题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
//    进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小
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