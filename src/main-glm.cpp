#include <iostream>
#include <glm/vec3.hpp>

int main(void) {
    glm::vec3 a = glm::vec3(5, 14, -10);
    std::cout << "vec3 a:\t" << "x: " << a.x << ", y: " << a.y << ", z: " << a.z << '\n';

    glm::vec3 b = glm::vec3(7, -15, 8);
    std::cout << "vec3 b:\t" << "x: " << b.x << ", y: " << b.y << ", z: " << b.z << '\n';


    std::cout << '\n';

    
    std::cout << "a + b:\t" << "x: " << (a + b).x << ", y: " << (a + b).y << ", z: " << (a + b).z << '\n';
    std::cout << "a - b:\t" << "x: " << (a - b).x << ", y: " << (a - b).y << ", z: " << (a - b).z << '\n';
    std::cout << "a * b:\t" << "x: " << (a * b).x << ", y: " << (a * b).y << ", z: " << (a * b).z << '\n';
    std::cout << "a / b:\t" << "x: " << (a / b).x << ", y: " << (a / b).y << ", z: " << (a / b).z << '\n';
}