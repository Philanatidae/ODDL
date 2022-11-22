# Define test executable
add_executable(ODDL-tests)
target_link_libraries(ODDL-tests PRIVATE
    Catch2::Catch2
    ODDL)
add_subdirectory(src)
