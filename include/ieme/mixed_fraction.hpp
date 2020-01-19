#pragma once

#include <ieme/fraction.hpp>


namespace ieme {


template <typename Rep, typename Ops = safe_ops>
class mixed_fraction final {

public:
    using fraction_type = fraction<Rep, Ops>;
    using rep_type = typename fraction<Rep, Ops>::rep_type;
    using ops_type = typename fraction<Rep, Ops>::ops_type;

    constexpr mixed_fraction() noexcept = default;
    constexpr mixed_fraction(
        const Rep& whole_part,
        const fraction<Rep, Ops>& fractional_part) noexcept;
    constexpr mixed_fraction(const fraction<Rep, Ops>& value) noexcept;

    constexpr fraction<Rep, Ops> as_fraction() const noexcept;
    constexpr operator fraction<Rep, Ops>() const noexcept;

    constexpr const Rep& whole_part() const noexcept { return whole_part_; }
    constexpr fraction<Rep, Ops> fractional_part() const noexcept;

private:
    static constexpr fraction<Rep, Ops>
    combine(const Rep& whole_part,
            const fraction<Rep, Ops>& fractional_part) noexcept;

    Rep whole_part_ = 0;
    fraction<Rep, Ops> fractional_part_;
};


// =============================================================================


template <typename Rep, typename Ops>
constexpr mixed_fraction<Rep, Ops>::mixed_fraction(
    const Rep& whole_part,
    const fraction<Rep, Ops>& fractional_part) noexcept :
    mixed_fraction {combine(whole_part, fractional_part)}
{
}

template <typename Rep, typename Ops>
constexpr mixed_fraction<Rep, Ops>::mixed_fraction(
    const fraction<Rep, Ops>& value) noexcept :
    whole_part_ {trunc(value)},
    fractional_part_ {abs(value - whole_part_)}
{
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> mixed_fraction<Rep, Ops>::as_fraction() const
    noexcept
{
    return combine(whole_part_, fractional_part_);
}

template <typename Rep, typename Ops>
constexpr mixed_fraction<Rep, Ops>::operator fraction<Rep, Ops>() const noexcept
{
    return as_fraction();
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> mixed_fraction<Rep, Ops>::fractional_part() const
    noexcept
{
    return fractional_part_;
}

template <typename Rep, typename Ops>
constexpr fraction<Rep, Ops> mixed_fraction<Rep, Ops>::combine(
    const Rep& whole_part,
    const fraction<Rep, Ops>& fractional_part) noexcept
{
    return (whole_part > 0) ? whole_part + fractional_part
                            : whole_part - fractional_part;
}


}; // namespace ieme