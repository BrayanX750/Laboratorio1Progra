# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Labbb1_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Labbb1_autogen.dir/ParseCache.txt"
  "Labbb1_autogen"
  )
endif()
