#include <osg/ArgumentParser>
#include <osg/ApplicationUsage>

#include <osgDB/ReadFile>
#include <osgDB/FileNameUtils>
#include <osgDB/fstream>

#include <iostream>

#include <osgViewer/Viewer>

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer =
		new osgViewer::Viewer();

	osg::ref_ptr<osg::Group> root = new osg::Group();

	osg::ref_ptr<osg::Node> node = 
		osgDB::readNodeFile("../cow.osg");

	root->addChild(node.get());

	/*
	osgUtil::Optimizer optimizer;
	optimizer.optimize(root.get());
	*/

	viewer->setSceneData(root.get());
	viewer->realize();
	viewer->run();
	return 0;
};

