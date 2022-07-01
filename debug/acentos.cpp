#include <iostream>
#include <string>

int main(){
    std::string c;
    std::cin >> c;
    std::cout << c.size() << std::endl;
    std::cout << (int)c[0] << std::endl;
    std::cout << (int)c[1] << std::endl;
}