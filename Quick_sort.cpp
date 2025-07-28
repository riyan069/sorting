#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    int n;
    cin >> n;
    int arr[n + 10];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int stack[n];

    int top = -1;

    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0)
    {
        int high = stack[top--];
        int low = stack[top--];

        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        if (pi - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high)
        {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
