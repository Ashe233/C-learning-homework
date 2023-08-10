
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "how many row or arrange?(input n,and there will be n^n numbers)\nn=";
    cin >> n;
    cout << "input your "<<n*n<<" numbers\n";
    int** b = new int* [n];
    int** a;
    for (int i = 0; i < n; i++) {
        b[i] = new int[n];
    }
    for (int z = 0; z < n; z++) {
        for (int i = 0; i < n; i++) {
            cin >> b[z][i];
        }
    }
    a = b;

    for (int z = 0; z < n; z++) {//行排序
        int* ta = *b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (**b > *((*b)+1)) {
                    int temp = *((*b) + 1);
                    *((*b) + 1) = **b;
                    **b = temp;
                }
                (*b)++;
            }
            *b = ta;
        }
        b++;
    }
    for (int z = 0; z < n; z++) {
        cout<<"row " << z + 1 << " arranged:";
        for (int i = 0; i < n; i++) {
            cout << a[z][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
