#include "catch.hpp"

#include "Calculator.h"

TEST_CASE("addition", "[calculator]") {
    Calculator myCalculator;
    REQUIRE(myCalculator.add(5, 5) == 10);
    REQUIRE(myCalculator.subtract(5, 2) == 3);
}