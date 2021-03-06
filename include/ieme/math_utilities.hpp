#ifndef IEME_MATH_UTILITIES_HPP
#define IEME_MATH_UTILITIES_HPP

#include <type_traits>


namespace ieme {
namespace math_utilities {


template <typename Int>
constexpr Int abs(Int value) noexcept;

template <typename Int>
constexpr Int pow2(Int exponent) noexcept;

template <typename Int>
constexpr Int pow(Int base, Int exponent) noexcept;


// =============================================================================


template <typename Int>
constexpr Int abs(const Int value) noexcept
{
  return (value >= Int(0)) ? value : -value;
}

template <typename Int>
constexpr Int pow2(const Int exponent) noexcept
{
  using unsigned_type = std::make_unsigned_t<Int>;

  return Int(unsigned_type(1) << unsigned_type(exponent));
}

template <typename Int>
constexpr Int pow(const Int base, const Int exponent) noexcept
{
  if (exponent == Int(0))
    return Int(1);

  if (exponent % Int(2) == Int(1))
    return base * pow(base, exponent - Int(1));

  const auto squareRoot = pow(base, exponent / Int(2));

  return squareRoot * squareRoot;
}


}; // namespace math_utilities
}; // namespace ieme


#endif
