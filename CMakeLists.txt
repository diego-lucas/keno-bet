cmake_minimum_required(VERSION 3.0)
project ( Keno VERSION 1.0 LANGUAGES CXX )

#=== App target ===
set( APP_NAME "keno" )

include_directories( include )

add_executable( ${APP_NAME} src/main.cpp)

# define C++11 standard
set_target_properties( ${APP_NAME} PROPERTIES CXX_STANDARD 11 )