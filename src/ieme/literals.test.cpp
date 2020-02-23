#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ieme/literals.hpp>

#include <ieme/fraction_queries.hpp>

#include <type_traits>


using namespace ieme;
using namespace ieme::literals;


TEST_CASE("Fraction literals have the expected symbolic equivalents",
          "[literals]")
{
  REQUIRE(are_identical(3 / 4_Fr, fraction(3, 4)));
  REQUIRE(are_identical(-3 / 4_Fr, fraction(-3, 4)));
  REQUIRE(are_identical(3 / -4_Fr, fraction(3, -4)));
  REQUIRE(are_identical(-3 / -4_Fr, fraction(-3, -4)));
}

TEST_CASE("The type of numerator in a fraction literal drives the "
          "representation type of the resulting fraction",
          "[literals]")
{
  REQUIRE(std::is_same_v<decltype(3 / 4_Fr), fraction<int>>);
  REQUIRE(std::is_same_v<decltype(3U / 4_Fr), fraction<unsigned int>>);
  REQUIRE(std::is_same_v<decltype(3L / 4_Fr), fraction<long int>>);
  REQUIRE(std::is_same_v<decltype(3UL / 4_Fr), fraction<unsigned long int>>);
}

TEST_CASE("Fraction literals can be used within complex arithmetic expressions",
          "[literals]")
{
  REQUIRE(3 + 4 / -3_Fr * 2 / 5_Fr == fraction(37, 15));
}

TEST_CASE("Decimal fraction literals have the expected fractional equivalents",
          "[literals]")
{
  REQUIRE(2.3_Dec == 2 + 3 / 10_Fr);
  REQUIRE(94.332_Dec == 94L + 332 / 1000_Fr);
  REQUIRE(9.22E+3_Dec == 9220);
  REQUIRE(7.543E-10_Dec == 7543L / 10'000'000'000'000_Fr);
  REQUIRE(0xC.Ap2_Dec == 0x65 / 0x2_Fr);
  REQUIRE(0xC1.A1p-10_Dec == 0xC1A1 / 0x40000_Fr);
}
