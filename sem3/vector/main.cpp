#include "Vector.h"
#include <iostream>

void printMenu() {
    std::cout << "Menu Options:" << std::endl;
    std::cout << "1. Create a new vector" << std::endl;
    std::cout << "2. Display vector" << std::endl;
    std::cout << "3. Calculate length" << std::endl;
    std::cout << "4. Add vectors" << std::endl;
    std::cout << "5. Subtract vectors" << std::endl;
    std::cout << "6. Multiply vectors" << std::endl;
    std::cout << "7. Multiply vector by scalar" << std::endl;
    std::cout << "8. Divide vectors" << std::endl;
    std::cout << "9. Dot product" << std::endl;
    std::cout << "10. Compare vectors" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void createVector(Vector& v) {
    double xs, ys, zs, xe, ye, ze;
    std::cout << "Enter vector (x_start y_start z_start x_end y_end z_end): ";
    std::cin >> xs >> ys >> zs >> xe >> ye >> ze;
    v = Vector(xs, ys, zs, xe, ye, ze);
}

void displayVector(const Vector& v) {
    std::cout << "Vector: " << v << std::endl;
}

void calculateLength(const Vector& v) {
    std::cout << "Length: " << v.length() << std::endl;
}

int main() {
    Vector v1, v2, result;
    double scalar;
    int choice;

    while (true) {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            createVector(v1);
            break;
        case 2:
            displayVector(v1);
            break;
        case 3:
            calculateLength(v1);
            break;
        case 4:
            createVector(v2);
            result = v1 + v2;
            displayVector(result);
            break;
        case 5:
            createVector(v2);
            result = v1 - v2;
            displayVector(result);
            break;
        case 6:
            createVector(v2);
            result = v1 * v2;
            displayVector(result);
            break;
        case 7:
            std::cout << "Enter scalar: ";
            std::cin >> scalar;
            result = v1 * scalar;
            displayVector(result);
            break;
        case 8:
            createVector(v2);
            result = v1 / v2;
            displayVector(result);
            break;
        case 9:
            createVector(v2);
            try {
                double result = v1 ^ v2;
                std::cout << "Dot product: " << result << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        case 10:
            createVector(v2);
            if (v1 == v2) {
                std::cout << "Vectors are equal" << std::endl;
            }
            else {
                std::cout << "Vectors are not equal" << std::endl;
            }
            break;
        case 0:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
