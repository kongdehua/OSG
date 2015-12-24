#include <osgViewer/Viewer>

#include <osg/Node>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Group>
#include <osg/Billboard>
#include <osg/Texture2D>
#include <osg/Image>
#include <osg/PositionAttitudeTransform>
#include <osg/MatrixTransform>

#include <osgDB/ReadFile>
#include <osgDB/WriteFile>

#include <osgUtil/Optimizer>

osg::ref_ptr<osg::Node> createBillboardTree(
	osg::ref_ptr<osg::Image> image)
{
	// 创建四边形
	osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry();

	// 设置顶点
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array();
	v->push_back(osg::Vec3(-0.5, 0.0, -0.5));
	v->push_back(osg::Vec3(+0.5, 0.0, -0.5));
	v->push_back(osg::Vec3(+0.5, 0.0, +0.5));
	v->push_back(osg::Vec3(-0.5, 0.0, +0.5));

	geometry->setVertexArray(v.get());

	// 设置法线
	osg::ref_ptr<osg::Vec3Array> normal = new osg::Vec3Array();
	normal->push_back(  osg::Vec3(1.0f, 0.0f, 0.0f) 
										^ osg::Vec3(0.0f, 0.0f, 1.0f) );

	geometry->setNormalArray(normal.get());
	geometry->setNormalBinding(osg::Geometry::BIND_OVERALL);

	// 设置纹理坐标
	osg::ref_ptr<osg::Vec2Array> vt = new osg::Vec2Array();
}

int main()
{
	return 0;
};

