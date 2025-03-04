CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0)
PROJECT(NV)

SET(NV_CMAKE_DIR "${NV_SOURCE_DIR}/cmake")
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${NV_CMAKE_DIR}")

IF(WIN32)
	SET(GNUWIN32 "${NV_SOURCE_DIR}/extern/gnuwin32")
	SET(CMAKE_INCLUDE_PATH "${GNUWIN32}/include")
	SET(CMAKE_LIBRARY_PATH "${GNUWIN32}/lib")
	
	SET(GLUT_ROOT_PATH "${NV_SOURCE_DIR}/extern/glut")
ENDIF(WIN32)

INCLUDE(${NV_CMAKE_DIR}/OptimalOptions.cmake)
MESSAGE(STATUS "Setting optimal options")
MESSAGE(STATUS "  Processor: ${NV_SYSTEM_PROCESSOR}")
MESSAGE(STATUS "  Compiler Flags: ${CMAKE_CXX_FLAGS}")

IF(NVTT_SHARED)
	SET(NVCORE_SHARED TRUE)
	SET(NVMATH_SHARED TRUE)
	SET(NVIMAGE_SHARED TRUE)
ENDIF(NVTT_SHARED)


ADD_SUBDIRECTORY(src)

IF(WIN32)
	ADD_SUBDIRECTORY(extern/gnuwin32)
ENDIF(WIN32)
