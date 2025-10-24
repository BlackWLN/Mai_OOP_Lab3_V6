#include <gtest/gtest.h>
#include "../include/figure.hpp"
#include "../include/pentagon.hpp"
#include "../include/hexagon.hpp"
#include "../include/octagon.hpp"

TEST(FigureTest, PentagonCreation) {
    Pentagon pentagon(Point(0, 0), 5.0);
    EXPECT_NEAR(static_cast<double>(pentagon), 59.44, 0.1);
    EXPECT_TRUE(pentagon.center() == Point(0, 0));
}

TEST(FigureTest, HexagonCreation) {
    Hexagon hexagon(Point(1, 1), 3.0);
    EXPECT_NEAR(static_cast<double>(hexagon), 23.38, 0.1);
    EXPECT_TRUE(hexagon.center() == Point(1, 1));
}

TEST(FigureTest, OctagonCreation) {
    Octagon octagon(Point(2, 2), 4.0);
    EXPECT_NEAR(static_cast<double>(octagon), 77.25, 0.1);
    EXPECT_TRUE(octagon.center() == Point(2, 2));
}

TEST(FigureTest, EqualityTest) {
    Pentagon p1(Point(0, 0), 5.0);
    Pentagon p2(Point(0, 0), 5.0);
    Pentagon p3(Point(1, 1), 5.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(FigureTest, CopyAssignment) {
    Pentagon p1(Point(0, 0), 5.0);
    Pentagon p2;
    p2 = p1;
    
    EXPECT_TRUE(p1 == p2);
}

TEST(FigureTest, MoveAssignment) {
    Pentagon p1(Point(0, 0), 5.0);
    Pentagon p2;
    p2 = std::move(p1);
    
    EXPECT_NEAR(static_cast<double>(p2), 59.44, 0.1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}