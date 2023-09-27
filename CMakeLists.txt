# CMakeList.txt : CMake project for Project2_InversionsCount, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Project3_Randomization")

#set minimum c++ version to 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's QuickSort executable
add_executable (QuickSort "QuickSortMain.cpp"    "ArrayGen.h" "ArrayGen.cpp" "Project3_ConstDeff.h" "ArrayFromFile.h" "ArrayFromFile.cpp" "QuickSort.h" "RandomRange.h")

#Add source to this project's RSelect executable
add_executable(RSelect "RSelectMain.cpp"   "ArrayGen.h" "ArrayGen.cpp" "Project3_ConstDeff.h" "ArrayFromFile.h" "ArrayFromFile.cpp")

# TODO: Add tests and install targets if needed.
