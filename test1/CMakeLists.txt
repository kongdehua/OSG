cmake_minimum_required(VERSION 2.8)

project(test1)

set(CMAKE_BUILD_TYPE debug)

set (OSG_PATH "/home/kdh/install/osg/OpenSceneGraph-3.4.0/")

macro(find_lib libname)
	find_library("LIB${libname}"
		NAMES ${libname}	
		PATHS "${OSG_PATH}/build/lib"
		) 
	#add_library(${LIB${libname}})
	#TARGET_ADD_LIBRARY(test1 ${LIB${libname}})
	#message(STATUS "LIB${libname} ${LIB${libname}}")
	#target_link_libraries(test1 ${LIBRARYNAME})
endmacro(find_lib)

find_lib(OpenThreads)
find_lib(osg)
find_lib(osgDB)
find_lib(osgUtil)
find_lib(osgGA)
find_lib(osgViewer)
find_lib(osgText)

#find_package(OSG )

set ( OSG_LIBRARIES 
	OpenThreads
	osg
	osgDB
	osgUtil
	osgGA
	osgViewer
	osgText)

message(STATUS "OSG_LIBRARIES : ${OSG_LIBRARIES}")
include_directories("${OSG_PATH}/include")
include_directories("${OSG_PATH}/build/include")
LINK_DIRECTORIES("${OSG_PATH}/build/lib")

add_executable(test1 main.cpp)

target_link_libraries(test1 ${OSG_LIBRARIES})
