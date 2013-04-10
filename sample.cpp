#include <iostream>
using namespace std;
int main(void)
{
    int n = 4;
    int a[] = {2, 2, 3, 3};
    for(int k = 0; k < 4; k++){
        int temp = a[0];
        for(int i = 1; i < n; i++)
            a[i - 1] = a[i];
        a[n - 1] = temp;
        for(int j = 0; j < n; j++)
            cout << a[j];
        cout << endl;
    }
    return 0;
}
