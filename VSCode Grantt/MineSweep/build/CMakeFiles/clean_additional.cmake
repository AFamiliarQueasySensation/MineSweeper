# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MineSweep_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MineSweep_autogen.dir\\ParseCache.txt"
  "MineSweep_autogen"
  "_deps\\fmt-build\\CMakeFiles\\fmt_autogen.dir\\AutogenUsed.txt"
  "_deps\\fmt-build\\CMakeFiles\\fmt_autogen.dir\\ParseCache.txt"
  "_deps\\fmt-build\\fmt_autogen"
  )
endif()
