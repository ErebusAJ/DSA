#include <iostream>

using namespace std;

void towerOfHanoi(int n, char source, char intermidiate, char destination)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, destination, intermidiate);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, intermidiate, source, destination);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
