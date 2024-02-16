# Add source files
set(SOURCE_FILES 
    main.cpp 
    tuple.cpp
)

# Create executable
add_executable(ray_tracer ${SOURCE_FILES})

# Target-specific include directories
target_include_directories(ray_tracer PUBLIC ../include)
