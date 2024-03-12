// Shipping Cost Calculator

#include <iostream>

int main() {
    double length = 0;
    double width = 0;
    double height = 0;

    const int dimension_l = 10;
    const double base_cost = 2.50;

    const int tier1_threshold = 100; // volume
    const int tier2_threshold = 500; // volume

    const double tier1_surcharge = 0.10; // 10% extra
    const double tier2_surcharge = 0.25; // 25% extra

    std::cout << "All dimension must be 10 inches or less or we cannot ship it :)" << std::endl;
    std::cout << "Write package dimension (length, width, height) in inches (seperated by space):";
    std::cin >> length;
    std::cin >> width;
    std::cin >> height;

    if (length <= 10) {
        if (width <= 10) {
            if (height <= 10) {
                double package_cost = 0;
                double package_volume = width * height * length;
                package_cost = base_cost;
                if (package_volume >= tier2_threshold) {
                    package_cost += package_cost * tier2_surcharge;
                }
                else if (package_volume >= tier1_surcharge) {
                    package_cost += package_cost * tier1_surcharge;
                }

                std::cout << "The volume of your package is: " << package_volume << std::endl;
                std::cout << "Your package will cost $" << package_cost << " to ship" << std::endl;
            } else {
                std::cout << "Sorry, we cannot ship this package: Height of the package is greater than 10.";
            }
        } else {
            std::cout << "Sorry, we cannot ship this package: Width of the package is greater than 10.";
        }
    } else {
        std::cout << "Sorry, we cannot ship this package: Length of the package is greater than 10.";
    }


    return 0;
}