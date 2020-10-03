#include "Evolvent/Evolvent.h"

using namespace Program2;

int main(int argc, char* argv[]) {
    Evolvent e (5);
    Point p;
    char* s = nullptr;
    double rad;
    double angle;
    int fl1 = 1;
    while (fl1) {
        std::cout << "Your evolvent is:" << std::endl;
        s = e.form();
        std::cout << s << std::endl;
        if (e.getR() != 0)
            delete [] s;
        std::cout << "Radius of circle: " << e.getR() << std::endl;
        char* er = "";
        std::cout << "Enter angle of rotation of the circle radius or some letter to exit:--> ";
        do {
            std::cout << er << std::endl;
            if (!getNum(angle)){
                return 0;
            }
            er = "Error: enter value of angle in interval [0; 2 * Pi)";
        } while (!correct(angle));
        try {
            std::cout << "Distance to center: " << e.distance(angle) <<std::endl;
            p = e.coordinates(angle);
            std::cout << "Coordinates: x = " << p.x << " y = " << p.y << std::endl;
            std::cout << "Arc length: " << e.arcLength(angle) << std::endl;
            std::cout << "Curvature radius: " << e.curRadius(e.arcLength(angle)) << std::endl;
        }
        catch (std::exception &ex){
            std::cout << ex.what() << std::endl;
        }
        std::cout << "Enter new circle radius or some letter to exit:--> ";
        std::cin >> rad;
        if (std::cin.good())
        {
            try {
                e.setR(rad);
            }
            catch (std::exception &ex){
                std::cout << ex.what() << std::endl;
            }
        }
        else
        {
            fl1 = 0;
        }
    }
    return 0;
}