#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    int tree[n];
    for(int i = 0;i<n;i++)
    {
        cin>>tree[i];
    }
    for(int i =0;i<n;i++)
    {
        cout<<"tree node: "<<i<< "value:" <<tree[i]<<"/n";
        if (2 * i + 2 < n) {
            cout << "Right child: "
                 << tree[2 * i + 2] << endl;
        }
    }
    return 0;
}