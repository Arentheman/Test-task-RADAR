# CMake generated Testfile for 
# Source directory: C:/Users/АРЕНАЙК/Desktop/Тестовое задание/CSVTESTER/CSVTests
# Build directory: C:/Users/АРЕНАЙК/Desktop/Тестовое задание/build/CSVTests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(AllTests "C:/Users/АРЕНАЙК/Desktop/Тестовое задание/build/CSVTests/Debug/CSVTests.exe")
  set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/АРЕНАЙК/Desktop/Тестовое задание/CSVTESTER/CSVTests/CMakeLists.txt;14;add_test;C:/Users/АРЕНАЙК/Desktop/Тестовое задание/CSVTESTER/CSVTests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(AllTests "C:/Users/АРЕНАЙК/Desktop/Тестовое задание/build/CSVTests/Release/CSVTests.exe")
  set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/АРЕНАЙК/Desktop/Тестовое задание/CSVTESTER/CSVTests/CMakeLists.txt;14;add_test;C:/Users/АРЕНАЙК/Desktop/Тестовое задание/CSVTESTER/CSVTests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(AllTests "C:/Users/АРЕНАЙК/Desktop/Тестовое задание/build/CSVTests/MinSizeRel/CSVTests.exe")
  set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/АРЕНАЙК/Desktop/Тестовое задание/CSVTESTER/CSVTests/CMakeLists.txt;14;add_test;C:/Users/АРЕНАЙК/Desktop/Тестовое задание/CSVTESTER/CSVTests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(AllTests "C:/Users/АРЕНАЙК/Desktop/Тестовое задание/build/CSVTests/RelWithDebInfo/CSVTests.exe")
  set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/АРЕНАЙК/Desktop/Тестовое задание/CSVTESTER/CSVTests/CMakeLists.txt;14;add_test;C:/Users/АРЕНАЙК/Desktop/Тестовое задание/CSVTESTER/CSVTests/CMakeLists.txt;0;")
else()
  add_test(AllTests NOT_AVAILABLE)
endif()
subdirs("third_party/googletest")
