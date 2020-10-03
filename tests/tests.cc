#include "Evolvent/Evolvent.h"
#include "gtest/gtest.h"

TEST(EvolventTests, Constructors){
    Program2::Evolvent e;
    EXPECT_EQ(e.getR(), 1);
    Program2::Evolvent z(5);
    EXPECT_EQ(z.getR(), 5);
}
