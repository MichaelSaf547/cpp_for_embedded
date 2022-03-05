#include "test.h"
#include <vector>

int main(void)
{
    bool check = false;

    check = test<uint16>(reserved, 13);
    if(check == true)
    {
        std::cout << "Done.\n";
    }
    else
    {
        std::cout << "Error.\n";
    }

    std::cout << "Do not forget to look in the output.txt file to see the results.\n";

    return 0;
}