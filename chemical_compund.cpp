#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    int x;
    // Monoatomic masses
    cin >> a;
    cin >> b;

    // Diatomic masses
    cin >> c;
    c *= 2;
    cin >> d;
    d *= 2;

    // Compund mass
    cin >> x;

    int maxCount = 0;

    for (int countA = 0; countA <= x / a; ++countA)
    {
        for (int countB = 0; countB <= x / b; ++countB)
        {
            for (int countC = 0; countC <= x / c; ++countC)
            {
                for (int countD = 0; countD <= x / d; ++countD)
                {
                    // Calculate the total mass for this combination
                    int totalMass = countA * a + countB * b + countC * c + countD * d;

                    // If the total mass matches X, update the maximum count
                    if (totalMass == x)
                    {
                        int totalMolecules = countA + countB + countC + countD;
                        maxCount = max(maxCount, totalMolecules);
                    }
                }
            }
        }
    }

    cout << maxCount;
}