#include "Evolvent/Evolvent.h"
#include "gtest/gtest.h"

TEST(EvolventConstructor, DefaultConstructor){
    Program2::Evolvent e;
    ASSERT_EQ(1, e.getR());
}

TEST(EvolventConstructor, InitConstructor){
    Program2::Evolvent e(5.78);
    ASSERT_EQ(5.78, e.getR());
}

TEST(EvolventConstructor, TestException){
    ASSERT_ANY_THROW(Program2::Evolvent e(-1));
}

TEST(EvolventMethods, Setter){
    Program2::Evolvent e;
    e.setR(11.51);
    ASSERT_EQ(11.51, e.getR());
}

TEST(EvolventMethods, SetterException){
    Program2::Evolvent e;
    ASSERT_ANY_THROW(e.setR(-567));
}

TEST(EvolventMethods, Distance){
    Program2::Evolvent e;
    ASSERT_DOUBLE_EQ(4.4428791854156922, e.distance(3.14159));
}

TEST(EvolventMethods, Coordinates){
    Program2::Evolvent e;
    Program2::Point p = e.coordinates(3.14159);
    ASSERT_DOUBLE_EQ(-0.99999166350532032, p.x);
    ASSERT_DOUBLE_EQ(3.1415926535787322, p.y);
}

TEST(EvolventMethods, ArcLength){
    Program2::Evolvent e;
    ASSERT_DOUBLE_EQ(4.9347938640499995, e.arcLength(3.14159));
}

TEST(EvolventMethods, CurvatureRadius){
    Program2::Evolvent e;
    ASSERT_DOUBLE_EQ(0.31831015504887655, e.curRadius(e.arcLength(3.14159)));
}

TEST(EvolventMethods, CurRadiusExceptions){
    Program2::Evolvent e;
    ASSERT_ANY_THROW(e.curRadius(0));
    e.setR(0);
    ASSERT_ANY_THROW(e.curRadius(3.14159));
}

int _tmain(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}