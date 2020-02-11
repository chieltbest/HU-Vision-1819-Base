add_library(image INTERFACE)
target_link_directories(image INTERFACE .)
target_compile_features(image INTERFACE cxx_std_17)
