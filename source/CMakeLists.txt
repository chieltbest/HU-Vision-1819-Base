
add_subdirectory(week1)

add_executable(main ExternalDLL/ExternalDLL/Main.cpp
		ExternalDLL/ExternalDLL/DefaultExtraction.cpp
		ExternalDLL/ExternalDLL/DefaultLocalization.cpp
		ExternalDLL/ExternalDLL/DefaultPreProcessing.cpp
		ExternalDLL/ExternalDLL/DLLExecution.cpp
		#		ExternalDLL/ExternalDLL/export.cpp
		ExternalDLL/ExternalDLL/Feature.cpp
		ExternalDLL/ExternalDLL/FeatureMap.cpp
		ExternalDLL/ExternalDLL/GrayscaleAlgorithm.cpp
		ExternalDLL/ExternalDLL/HereBeDragons.cpp
		ExternalDLL/ExternalDLL/Image.cpp
		ExternalDLL/ExternalDLL/ImageFactory.cpp
		ExternalDLL/ExternalDLL/ImageIO.cpp
		ExternalDLL/ExternalDLL/IntensityImage.cpp
		ExternalDLL/ExternalDLL/IntensityImagePrivate.cpp
		ExternalDLL/ExternalDLL/IntensityImageStudent.cpp
		ExternalDLL/ExternalDLL/PostProcessing.cpp
		ExternalDLL/ExternalDLL/Representation.cpp
		ExternalDLL/ExternalDLL/RGBImage.cpp
		ExternalDLL/ExternalDLL/RGBImagePrivate.cpp
		ExternalDLL/ExternalDLL/RGBImageStudent.cpp
		ExternalDLL/ExternalDLL/SonnetXVIII.cpp
		ExternalDLL/ExternalDLL/StudentExtraction.cpp
		ExternalDLL/ExternalDLL/StudentLocalization.cpp
		ExternalDLL/ExternalDLL/StudentPreProcessing.cpp)
target_compile_features(main PUBLIC cxx_std_17)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

target_include_directories(main PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(main ${OpenCV_LIBS} image)

