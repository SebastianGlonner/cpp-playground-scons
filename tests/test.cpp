//
// Created by Sebastian Glonner on 10.08.2019.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>

// fix issues
#undef CONNECT_DEFERRED

#include "library.h"

TEST_CASE( "test", "[single-file]" ) {
    REQUIRE( hello() == "Hello, World!" );
}