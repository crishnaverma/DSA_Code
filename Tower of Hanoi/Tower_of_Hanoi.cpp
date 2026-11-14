
#include <iostream>
using namespace std;

void Toh(int n, int source, int helper, int destination)
{
    if(n == 1)
    {
        cout << "Disk Moved " << n << " from " << source << " to " << destination << endl;
        return;
    }

    Toh(n-1, source, destination, helper);

    cout << "Disk Moved " << n << " from " << source << " to " << destination << endl;

    Toh(n-1, helper, source, destination);
}

int main()
{
    Toh(3, 1, 2, 3);
    return 0;
}
