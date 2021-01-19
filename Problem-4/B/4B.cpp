#include <bits/stdc++.h>
using namespace std;
int main()
{
    int d, sumTime, minimum = 0, maximum = 0;
    cin >> d >> sumTime;
    int times[d][2];
    int answer[d];
    for (int i = 0; i < d; i++)
    {
        cin >> times[i][0] >> times[i][1];
        minimum += times[i][0];
        maximum += times[i][1];
        answer[i] = times[i][0];
    }
    if (minimum <= sumTime && sumTime <= maximum)
    {
        cout << "YES" << endl;
        for (int i = 0; i < sumTime - minimum; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (answer[j] < times[j][1])
                {
                    answer[j] += 1;
                    break;
                }
            }
        }
        for (int i = 0; i < d; i++)
        {
            cout << answer[i] << " ";
        }
    }
    else
    {
        cout << "NO";
    }
}