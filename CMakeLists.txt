cmake_minimum_required(VERSION 3.10)
project(SpreadsheetJC)

set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_PREFIX_PATH /usr/local/Cellar/qt5/5.6.1-1)
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )

add_executable(SpreadsheetJC main.cpp SpreadSheet.cpp SpreadSheet.h Cell.cpp Cell.h SpreadSheetTest.cpp CellMin.cpp CellMin.h CellMax.cpp CellMax.h CellAvg.cpp CellAvg.h CellSum.cpp CellSum.h CellVal.cpp CellVal.h Subject.h Observer.h Subject.cpp)

qt5_use_modules(SpreadsheetJC Core Widgets Gui)
get_target_property(QtCore_location Qt5::Core LOCATION)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
include_directories(cmake_modules)

add_subdirectory(tests/lib/googletest-master)
include_directories(tests/lib/googletest-master/googletest/include)
include_directories(tests/lib/googletest-master/googlemock/include)

target_link_libraries(SpreadsheetJC gtest gtest_main)




