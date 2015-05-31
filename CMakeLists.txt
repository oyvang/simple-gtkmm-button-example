cmake_minimum_required (VERSION 2.8.4)
project (main)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

INCLUDE(FindPkgConfig)

add_executable(main
    main.cpp
)

    #dependencies
    pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
    include_directories(${GTKMM_INCLUDE_DIRS} )
    link_directories(${GTKMM_LIBRARY_DIRS})
    target_link_libraries(main ${GTKMM_LIBRARIES})
