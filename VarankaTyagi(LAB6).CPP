//3 SUM PROBLEM

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {-3, 1, 2, 5, 6, -3, 8, 1, 9, 2};

    int n = arr.size();

    sort(arr.begin(), arr.end());

    cout << "Triplets with sum 0:\n";

    for (int i = 0; i < n - 2; i++) {

        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0) {
                cout << arr[i] << " "
                     << arr[left] << " "
                     << arr[right] << endl;

                while (left < right && arr[left] == arr[left + 1])
                    left++;

                while (left < right && arr[right] == arr[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return 0;
}



//FIBONACCI SERIES 

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    int a = 1, b = 1, c;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; i++) {
        cout << a << " ";

        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}


// TOWER OF HANOI

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    
    if (n == 1)
    {
        cout << "Move disk 1 from " << source
             << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move disk " << n << " from " << source
         << " to " << destination << endl;

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}