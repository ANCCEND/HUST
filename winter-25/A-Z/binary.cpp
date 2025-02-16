#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);

    while (m--)
    {
        int choice, x, y;
        cin >> choice;

        if (choice == 1)
        {
            cin >> x;
            int l = lower_bound(a, a + n, x) - a;
            int r = upper_bound(a, a + n, x) - a;
            cout << (r - l) << '\n';
        }
        else
        {
            cin >> x >> y;
            int l, r;
            switch (choice)
            {
            case 2: // [x, y]
                l = lower_bound(a, a + n, x) - a;
                r = upper_bound(a, a + n, y) - a;
                break;
            case 3: // [x, y)
                l = lower_bound(a, a + n, x) - a;
                r = lower_bound(a, a + n, y) - a;
                break;
            case 4: // (x, y]
                l = upper_bound(a, a + n, x) - a;
                r = upper_bound(a, a + n, y) - a;
                break;
            case 5: // (x, y)
                l = upper_bound(a, a + n, x) - a;
                r = lower_bound(a, a + n, y) - a;
                break;
            default:
                l = r = 0; // 无效操作
            }
            cout << max(0, r - l) << '\n';
        }
    }
    return 0;
}