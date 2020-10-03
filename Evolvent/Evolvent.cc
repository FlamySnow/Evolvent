#include "Evolvent.h"

namespace Program2{
    Evolvent::Evolvent(double rad) {
        if (rad < 0)
            throw std::invalid_argument("Invalid radius");
        r = rad;
    }

    Evolvent& Evolvent::setR(double rad) {
        if (rad < 0)
            throw std::invalid_argument("Invalid radius");
        r = rad;
        return *this;
    }

    double Evolvent::distance(double a) const {
        return sqrt(2)*r*a;
    }

    Point Evolvent::coordinates(double a) const {
        Point p = {0, 0};
        p.x = r*(cos(a) + a*sin(a));
        p.y = r*(sin(a) - a*cos(a));
        return p;
    }

    double Evolvent::arcLength(double angle) const {
        return 0.5*r*angle*angle;
    }

    double Evolvent::curRadius(double arc) const {
        if (arc <= 0 || r == 0)
            throw std::invalid_argument("Invalid arc length or circle radius");
        return 1/sqrt(2*r*arc);
    }

    char* Evolvent::form() const {
        char* s;
        int l;
        if (r == 0) {
             s = "x = 0\ny = 0";
             return s;             
        }
        else {
            const char* s1 = "x =  * (cos(a) + a * sin(a))\ny =  * (sin(a) - a * cos(a))";
            l = strlen(s1) + 1;
            char num[20];
            sprintf(num, "%.2f", r);
            l += 2 * strlen(num);
            s = new char[l];
            sprintf(s, "x = %.2f * (cos(a) + a * sin(a))\ny = %.2f * (sin(a) - a * cos(a))", r, r);
            return s;
        }
    }
}