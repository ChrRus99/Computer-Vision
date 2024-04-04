cmake_minimum_required(VERSION 3.2)

# Set C++17 (minimum version required for this project)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the project name
project(FinalProject)

# Find OpenCV library
find_package(OpenCV REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS})

# Create executables
add_executable(	Main "src/Main.cpp" "src/FoodRecognizer_and_LeftoverEstimator.cpp" "src/ROIsDetection.cpp" "src/FoodsDetection.cpp" "src/FoodsSegmentation.cpp" "src/PerformanceEvaluation.cpp" "src/DatasetCategories.cpp" "src/library/Util.cpp" "include/library/Color.h")

# Link against OpenCV library
target_link_libraries(Main ${OpenCV_LIBS})