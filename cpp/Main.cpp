#include "Base64.h"
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

int main()
{
    base64();
}