#include <iostream>

// building  = compiling, linking, creating an executable file

int main()
{
    int favorite_number = 0;
    std::cout << "Enter with your favorite number: ";
    std::cin >> favorite_number;
    std::cout << "Your favorite number is " << favorite_number << ", and this is amazing!" << std::endl;
    return 0;
}
