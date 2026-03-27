#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void check_point(Point const a, Point const b, Point const c, Point const p, std::string name) {
    std::cout << "Point " << name << ": ";
    if (bsp(a, b, c, p))
        std::cout << "\033[32mINSIDE\033[0m" << std::endl;
    else
        std::cout << "\033[31mOUTSIDE\033[0m" << std::endl;
}

int main() {
    Point const a(0, 0);
    Point const b(10, 0);
    Point const c(5, 10);

    std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    check_point(a, b, c, Point(5, 5), "Inside (5, 5)");

    check_point(a, b, c, Point(15, 15), "Outside (15, 15)");
    check_point(a, b, c, Point(-1, -1), "Outside (-1, -1)");

    check_point(a, b, c, Point(5, 0), "On Edge AB (5, 0)");
    check_point(a, b, c, Point(2.5f, 5), "On Edge AC (2.5, 5)");

    check_point(a, b, c, Point(0, 0), "Vertex A (0, 0)");

    check_point(a, b, c, Point(5, 0.1f), "Just inside (5, 0.1)");

    return 0;
}