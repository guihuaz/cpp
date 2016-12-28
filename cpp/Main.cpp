#include "Base64.h"
#include "algorithm.h"
#include <iostream>
#include <sstream>

using namespace zgh;
using namespace std;

void base64()
{
    stringstream oss;

    for (int i = 0; i < 64; ++i)
    {
        oss << to_base64(i);
    }
    string str = oss.str();

    cout << str << '\n';

    for (char c : str)
    {
        cout << from_base64(c) << ' ';
    }

}

void equalRange()
{
    int arr[] = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
    auto lower = zgh::lower_bound(begin(arr), end(arr), 4);
    auto upper = zgh::upper_bound(begin(arr), end(arr), 4);
    auto range = zgh::equal_range(begin(arr), end(arr), 4);
    auto range2 = zgh::equal_range2(begin(arr), end(arr), 4);

    cout << lower - arr << ", upper: " << upper - arr << ", range("
        << range.first - arr << ", " << range.second - arr << "),\nrange2: ("
        << range2.first - arr << ", " << range2.second - arr << ")\n";
}

int main()
{
    //base64();
    equalRange();
}