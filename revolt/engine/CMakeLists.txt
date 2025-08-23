# Define the executable target for the Revolt Engine
add_executable(RevoltEngine
    src/main.cpp
    src/Engine.cpp
    src/project/Project.cpp
)

# Link the engine against the spdlog library.
# The spdlog::spdlog target is an INTERFACE library created by FetchContent.
# Linking to it provides the necessary include directories and compile definitions.
target_link_libraries(RevoltEngine PRIVATE spdlog::spdlog)

# Explicitly state that this target requires C++20 features.
# This is good practice for clarity and future compatibility.
target_compile_features(RevoltEngine PRIVATE cxx_std_20)

# Set a custom output directory for the final executable.
# This keeps the build directory organized.
set_target_properties(RevoltEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
