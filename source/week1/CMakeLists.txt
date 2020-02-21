add_library(image INTERFACE)
target_include_directories(image INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(image INTERFACE cxx_std_17)
