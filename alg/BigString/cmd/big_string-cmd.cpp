/* R. Fabbri, 2024 */
#include <iostream>
#include <string>
#include <vector>
#include "big_string.h"

int main() {
    std::string str1, str2;
    
    // Read two lines from stdin
    if (!std::getline(std::cin, str1)) {
        std::cerr << "Error reading first string." << std::endl;
        return 1;
    }
    if (!std::getline(std::cin, str2)) {
        std::cerr << "Error reading second string." << std::endl;
        return 1;
    }

    std::vector<char> out(str1.length() + str2.length() + 1);

    big_string_cat(str1.c_str(), str2.c_str(), out.data());

    std::cout << out.data() << std::endl;

    return 0;
}
