int sqrt(int n) // O(logn)
{
    if (n < 2)
    {
        return n;
    }
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

// For printing all permutations use next_permutation in c++
vector<int> v = {1, 2, 3};
do
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
} while (next_permutation(v.begin(), v.end()));

// For printing combinations (sorted)

vector<int> combination;
int n = 20, m = 4, cnt = 0;

void get_combination(int i = 0, int last_val = 0)
{
    if (i == m)
    {
        ++cnt;  // increment the count of combinations
        return; // you can print the combination here if needed
    }

    for (int j = last_val + 1; j <= n; ++j)
    {
        combination.push_back(j);
        // Think: dynamically create one more loop
        get_combination(i + 1, j); // backtracking
        combination.pop_back();    // remove the last element and backtrack
    }
}

int main()
{

    get_combination();
    cout << cnt << "\n"; // output the count of combinations
    return 0;
}

// Actually I think there is better time comp.
//  Merge ar1[0..n1-1] and ar2[0..n2-1] into ar3
void mergeArrays(vector<int> &ar1, vector<int> &ar2,
                 vector<int> &ar3)
{
    int i = 0, j = 0, k = 0;
    int n1 = ar1.size();
    int n2 = ar2.size();

    while (i < n1 && j < n2)
    {

        // Pick smaller of the two current
        // elements and move ahead in the
        // array of the picked element
        if (ar1[i] < ar2[j])
            ar3[k++] = ar1[i++];
        else
            ar3[k++] = ar2[j++];
    }

    // if there are remaining elements of
    // the first array, move them
    while (i < n1)
        ar3[k++] = ar1[i++];

    // Else if there are remaining elements of
    // the second array, move them
    while (j < n2)
        ar3[k++] = ar2[j++];
}