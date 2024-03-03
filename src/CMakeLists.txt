# Add source files
set(SOURCE_FILES
    tuple.cpp
    math_functions.cpp
)

# Create executable
add_library(ray_tracer_lib ${SOURCE_FILES})

# Target-specific include directories
target_include_directories(ray_tracer_lib PUBLIC ../include)
