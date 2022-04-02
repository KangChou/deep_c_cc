cmake_minimum_required(VERSION 3.4)
project(test)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "-std=c++11")

include_directories( /usr/include/python2.7)		    
add_executable(readTF readTF.cpp)
target_link_libraries(readTF -lpython2.7)

# sudo apt-get install python-dev   # for python2.x installs
# sudo apt-get install python3-dev  # for python3.x installs
# sudo apt-get install python3.6-dev
# "`pkg-config --cflags --libs python2`"