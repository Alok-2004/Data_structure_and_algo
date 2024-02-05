#include <iostream>
using namespace std;

void fun(int i, int n) {
    if (i > n) {
        return;
    }
    fun(i + 1, n);
    cout << i << endl;
}

int main() {
    int n;
    cin >> n;
    fun(1, n);
    return 0;
}
