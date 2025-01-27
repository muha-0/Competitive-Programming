void remove_leading_zeros(string &s)
{
    bool pushall = false;
    string res = "";
    int sz = s.size();
    for (int i = 0; i < sz; i++)
    {
        if (s[i] != '0')
        {
            pushall = true;
        }
        if (s[i] == '0' && pushall || s[i] != '0')
        {
            res += s[i];
        }
    }
    s = res;
}

// QuickSort
int partition(int arr[], int s, int e)
{
    int p = s;
    int i = s, j = e;
    while (i < j)
    {
        if (arr[i] < arr[j])
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
            p = j;
            i++;
        }
    }
    return p;
}

// Kadan, maxSubArray sum
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p);
    quickSort(arr, p + 1, e);
}

// Merge Sort
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
//
// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

void insertion_sort(int arr[], int n)
{ // incremental thinking O(n^2)
    // best case n steps if array is already sorted
    // worst case is when array is sorted reversely
    // average case is n^2 steps
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                continue;
            }
            break;
        }
    }
}
int Bs(int arr[], int s, int e, int target)
{
    if (s > e)
    {
        return -1;
    }
    int mid = (s + e) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return Bs(arr, s, mid - 1, target);
    }
    else
    {
        return Bs(arr, mid + 1, e, target);
    }
}
void selection_sort(int arr[], int n)
{ // O(n^2)
    // its best, worst, avg analysis are the same
    // not adaptive
    int min_index;
    for (int i = 0; i < n; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}
void count_sort(int arr[], int n)
{ // O(k+n) where k is the largest value and n is the size of the array
    // O(k) memory
    // assuming range 0-500
    vector<int> freq(501, 0);
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        while (freq[i] > 0)
        {
            freq[i]--;
            arr[index++] = i;
        }
    }
}
// Adding big integars using stack
string Add(const string &num1, const string &num2)
{
    stack<int> stck1, stck2;
    int sz1 = num1.size(), sz2 = num2.size();
    for (int i = 0; i < sz1; i++)
    {
        stck1.push(num1[i] - '0');
    }
    for (int i = 0; i < sz2; i++)
    {
        stck2.push(num2[i] - '0');
    }
    bool carry = false;
    stack<int> res;
    while (!stck1.empty() && !stck2.empty())
    {
        int digit = stck1.top() + stck2.top() + carry;
        if (digit >= 10)
        {
            carry = true;
            digit -= 10;
        }
        else
        {
            carry = false;
        }
        res.push(digit);
        stck1.pop(), stck2.pop();
    }
    while (!stck1.empty())
    {
        int digit = stck1.top() + carry;
        if (digit >= 10)
        {
            carry = true;
            digit -= 10;
        }
        else
        {
            carry = false;
        }
        res.push(digit);
        stck1.pop();
    }
    while (!stck2.empty())
    {
        int digit = stck2.top() + carry;
        if (digit >= 10)
        {
            carry = true;
            digit -= 10;
        }
        else
        {
            carry = false;
        }
        res.push(digit);
        stck2.pop();
    }
    if (carry)
    {
        res.push(1);
    }
    string str_res = "";
    while (!res.empty())
    {
        str_res += res.top() + '0';
        res.pop();
    }
    return str_res;
}
// return the index of the first element great than v[i]
// If no such element, use v.size()
deque<int> next_greater_idx(deque<int> v)
{
    stack<int> pos;

    for (int i = 0; i < (int)v.size(); ++i)
    {
        while (!pos.empty() && v[i] > v[pos.top()])
        {
            v[pos.top()] = i;
            pos.pop();
        }
        pos.push(i);
    }
    // all items in the stack are not answered
    while (!pos.empty())
    {
        v[pos.top()] = v.size();
        pos.pop();
    }

    return v;
}
// Number of digits
int numofdigits(int num)
{
    return 1 + (int)log10(num);
}
// Add two numbers
string Add(string s, string t)
{
    if (s.size() < t.size())
    {
        swap(s, t);
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int sz = t.size();
    int carry = 0;
    string res = "";
    for (int i = 0; i < sz; i++)
    {
        int ans = s[i] - '0' + t[i] - '0' + carry;
        if (ans >= 10)
        {
            carry = 1;
            ans %= 10;
        }
        else
        {
            carry = 0;
        }
        res += ans + '0';
    }
    sz = s.size();
    for (int i = t.size(); i < sz; i++)
    {
        int ans = s[i] - '0' + carry;
        if (ans >= 10)
        {
            carry = 1;
            ans %= 10;
        }
        else
        {
            carry = 0;
        }
        res += ans + '0';
    }
    if (carry)
    {
        res += '1';
    }
    reverse(res.begin(), res.end());
    return res;
}
// count digits of factorial of num
int count_digits(int num)
{
    // factorial exists only if num >= 0
    if (num < 0)
    {
        return 0;
    }
    // base case
    if (num <= 1)
    {
        return 1;
    }
    // else iterate through num and calculate the
    // value
    double d = 0;
    for (int i = 2; i <= num; i++)
    {
        d += log10(i);
    }
    return floor(d) + 1;
}
// Is sub str
bool IsSubStr(const string &s, const string &t)
{
    // Checks if s is a substring of t or not
    int sz1 = s.size(), sz2 = t.size();
    if (sz1 > sz2)
    {
        return false;
    }
    for (int i = 0; i < sz2 - sz1 + 1; i++)
    {
        if (t[i] == s[0])
        {
            bool match = true;
            for (int j = 0; j < sz1; j++)
            {
                if (s[j] != t[j + i])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return true;
            }
        }
    }
    return false;
}
vector<string> split(string text, char seperator)
{

    int sz = text.size();

    vector<string> arr;

    string tmp = "";
    for (int i = 0; i < sz; i++)
    {
        if (text[i] == seperator)
        {
            arr.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp += text[i];
        }
    }
    arr.push_back(tmp);
    return arr;
}
// seive
vector<int> seive(int n)
{
    vector<bool> isprime(n + 1, 1);
    isprime[0] = isprime[1] = 0;
    ;
    for (long long i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                isprime[j] = 0;
            }
        }
    }
    vector<int> primes;
    for (int i = 0; i < n + 1; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}
int BSfirst(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {

        // Normal Binary Search Logic
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;

        // If arr[mid] is same as x, we
        // update res and move to the left
        // half.
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}
// smaller than or equal the val
int BSsmallest(long long arr[], int s, int e, int x, int n)
{
    int low = s, high = e, res = -1;
    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;

        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}
/* If x is present in arr[] then returns
the index of LAST occurrence of x in
arr[0..n-1], otherwise returns -1 */
int BSlast(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {

        // Normal Binary Search Logic
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;

        // If arr[mid] is same as x, we
        // update res and move to the right
        // half.
        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}

string topostfix(const string &str)
{
    map<char, int> mp;
    mp['('] = 0;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['^'] = 3;
    string res = "";
    stack<char> stck;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            res += str[i];
        }
        else if (str[i] == '(')
        {
            stck.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (stck.top() != '(')
            {
                res += stck.top();
                stck.pop();
            }
            stck.pop();
        }
        else
        {
            if (stck.empty() || (stck.top() == '^' && str[i] == '^'))
            {
                stck.push(str[i]);
            }
            else
            {
                if (mp[str[i]] > mp[stck.top()])
                {
                    stck.push(str[i]);
                }
                else
                {
                    while (!stck.empty() && mp[str[i]] <= mp[stck.top()])
                    {
                        res += stck.top();
                        stck.pop();
                    }
                    stck.push(str[i]);
                }
            }
        }
    }
    while (!stck.empty())
    {
        res += stck.top();
        stck.pop();
    }
    return res;
}

double evaluate_postfix(const string &postfix)
{
    stack<double> stck;
    for (int i = 0; i < (int)postfix.size(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            stck.push((double)(postfix[i] - '0'));
        }
        else
        {
            double op2 = stck.top();
            stck.pop();
            double op1 = stck.top();
            stck.pop();
            double res;
            switch (postfix[i])
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '^':
                res = pow(op1, op2);
                break;
            }
            stck.push(res);
        }
    }
    return stck.top();
}

string topostfix_modified(const string &str)
{
    map<char, int> mp;
    mp['('] = 0;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['^'] = 3;
    string res = "";
    stack<char> stck;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            res += str[i];
        }
        else if (str[i] == '(')
        {
            stck.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (stck.top() != '(')
            {
                res += stck.top();
                stck.pop();
            }
            stck.pop();
        }
        else
        {
            if (stck.empty())
            {
                stck.push(str[i]);
            }
            else if (str[i] == '^' && stck.top() == '^')
            {
                res += '^';
            }
            else
            {
                if (mp[str[i]] >= mp[stck.top()])
                {
                    stck.push(str[i]);
                }
                else
                {
                    while (!stck.empty() && mp[str[i]] < mp[stck.top()])
                    {
                        res += stck.top();
                        stck.pop();
                    }
                    stck.push(str[i]);
                }
            }
        }
    }
    while (!stck.empty())
    {
        res += stck.top();
        stck.pop();
    }
    return res;
}
/*

1-reverse the string and be careful ( turns to ) and vice versa
**run topostfix function but modified as in 2,3**
2-only pop if top has greater precedence than infix[i] (no equal)
3-if infix[i] is ^ and top is ^ pop the top
4-after running postfix reverse the result and we are done

*/
string toprefix(const string &infix)
{
    string str = "";
    for (int i = infix.size() - 1; i >= 0; i--)
    {
        if (infix[i] == '(')
            str += ')';
        else if (infix[i] == ')')
            str += '(';
        else
            str += infix[i];
    }
    str = topostfix_modified(str);
    reverse(str.begin(), str.end());
    return str;
}
