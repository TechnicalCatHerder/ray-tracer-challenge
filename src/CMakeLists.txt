# Add source files
set(SOURCE_FILES 
    main.cpp 
    tuple.cpp  # Assuming tuple.cpp is part of the build
)

# Create executable
add_executable(ray_tracer ${SOURCE_FILES})

# Target-specific include directories
target_include_directories(ray_tracer PUBLIC ../include)
