#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int arr[100010], temp[100010];

void mergeSort(int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int l = left; l <= right; l++)
        arr[l] = temp[l];
}

int main()
{
    op();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
