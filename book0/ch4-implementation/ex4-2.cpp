#include <iostream>

int main()
{
    int unsigned n;
    std::cin >> n;

    int result{0};
    if (n >= 20)
    {
        result = 35'500;
        n -= 20;
        while (n != -1)
        {
            result += 3'600 * (n == 3) + 1'575 * (n != 3);
            --n;
        }
    }
    else if (n >= 10)
    {
        result = 17'775;
        n -= 10;
        while (n != -1)
        {
            result += 3'600 * (n == 3) + 1'575 * (n != 3);
            --n;
        }
    }
    else
    {
        while (n != -1)
        {
            result += 3'600 * (n == 3) + 1'575 * (n != 3);
            --n;
        }
    }
    std::cout << result << std::endl;

    return 0;
}