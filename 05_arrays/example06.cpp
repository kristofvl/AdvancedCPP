#include <iostream>
//#include <algorithm>

int main() {
    int myArray[] = { 54, 21, 8, 27, 10, 5, 30, 12 };

    // Use std::for_each to print all elements smaller
    // than 35 and sum these:
    int sum = 0;
    std::for_each(std::begin(myArray), std::end(myArray),
        [&sum](int n) {
            if (n < 35) {
                sum += n;
                std::cout << n << " ";
            }
        });
    std::cout << "\n sum = " << sum << '\n';
}
