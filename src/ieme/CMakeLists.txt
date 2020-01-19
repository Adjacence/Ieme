add_library(Ieme fraction.cpp
                 ieme.cpp
                 literals.cpp
                 mixed_fraction.cpp
                 unit_fraction.cpp)
target_include_directories(Ieme PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../../include)
target_compile_features(Ieme PUBLIC cxx_std_17)
add_library(Ieme::Ieme ALIAS Ieme)

add_executable(FractionTest fraction.test.cpp)
target_link_libraries(FractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME FractionTest COMMAND FractionTest)

add_executable(LiteralsTest literals.test.cpp)
target_link_libraries(LiteralsTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME LiteralsTest COMMAND LiteralsTest)

add_executable(MixedFractionTest mixed_fraction.test.cpp)
target_link_libraries(MixedFractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME MixedFractionTest COMMAND MixedFractionTest)

add_executable(UnitFractionTest unit_fraction.test.cpp)
target_link_libraries(UnitFractionTest PUBLIC Ieme Catch2::Catch2)
add_test(NAME UnitFractionTest COMMAND UnitFractionTest)