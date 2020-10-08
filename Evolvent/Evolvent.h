#ifndef EVOLVENT_EVOLVENT_H
#define EVOLVENT_EVOLVENT_H
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstring>

namespace Program2{
    struct Point {
        double x;
        double y;
    };
    class Evolvent {
    private:
        double r;//радиус окружности
    public:
        //конструктор
        Evolvent (double rad = 1);
        //сеттер
        Evolvent& setR (double rad);
        //геттер
        double getR () const {return r;};
        //расстояние до центра в зависимости от угла
        double distance (double a) const;
        //координаты
        Point coordinates (double a) const;
        //длина дуги
        double arcLength (double angle) const;
        //радиус кривизны
        double curRadius (double arc) const;
        //текстовое уравнение
        char* form() const;
    };

    template <class T>
    int getNum (T &a){
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }

    inline bool correct (double a) {
        return !(a < 0 || a >= 2 * M_PI);
    }
}

#endif //EVOLVENTEVOLVENT_H