#include "test.h"

int main(void)
{


    bool check = false;
    check = test<uint32>(read_and_Write, 22);
    if(check == true)
    {
        std::cout << "Done unsigned char.\n";
    }
    else
    {
        std::cout << "Error unsigned char.\n";
    }

    std::cout << "Do not forget to look in the output.txt file to see the results.\n";

    return 0;
}