# OSG
编写OSG代码的示例：

书籍上展示的是：在windows上使用vc6实现示例代码。

这里演示如何使用cmake来实现示例代码。

	cmake_minimum_required(VERSION 2.8)

	project(test)
	set(CMAKE_BUILD_TYPE debug)

	set(OSG_PATH "/home/kdh/install/osg/OpenSceneGraph-3.4.0/")
	set( OSG_LIBRARIES
		OpenThreads
		osg
		osgDB
		osgUtil
		osgGA
		osgViewer
		osgText)
	
	# 添加include需要的目录
	include_directories("${OSG_PATH}/include")
	include_directories("${OSG_PATH}/build/include")

	# 添加link需要的目录
	link_directories("${OSG_PATH}/build/lib")

	add_executable(test main.cpp)
	target_link_libraries(test ${OSG_LIBRARIES})
