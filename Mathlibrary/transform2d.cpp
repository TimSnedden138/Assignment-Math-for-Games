#include "transform2d.h"
#include"mathutils.h"
#include <iostream>
transform2d::transform2d()

{
	localPos = { 0,0 };
	localScale = { 1,1 };
	localRot = 0;
	parent = nullptr;
}



void transform2d::translate(const vec2 & offset)
{
	localPos = offset;
}



void transform2d::rotate(const float angle)
{
	localRot += angle;

}



void transform2d::lookAt(const transform2d & target)
{
	localRot = target.localRot;
}



vec2 transform2d::forward() const
{
	if (localRot == 180) {
		return vec2(localPos.getPerpCW());
	}
	if (localRot == -180) {
		return vec2(localPos.getPerpCCW());
	}
	return vec2(localPos);
}



void transform2d::setForward(const vec2 & newFwd)
{
	newFwd.angleBetween(localPos);
}



mat3 transform2d::getTRSMatrix() const
{
	return mat3(0,0,localScale.x,0, localPos.x,localPos.y,0,0, localScale.y);
}
mat3 transform2d::getTSMatrix() const

{
	return mat3(localScale.x, 0, localPos.x,0, localScale.y, localPos.y,0, 0, 1);
}



vec2 transform2d::worldPosition() const

{
	if (parent != nullptr)
	{

	}
	return localPos;
}



float transform2d::worldRotation() const

{
	if (parent != nullptr)
	{
		return localRot * parent->localRot;
	}
	return localRot;

}

vec2 transform2d::worldScale() const

{
	if (parent != nullptr)
	{

	}
	return localScale;
}



void transform2d::setParent(transform2d * _parent)

{
	parent = _parent;
}



transform2d * transform2d::getParent()

{

	return parent;

}



transform2d const * transform2d::getParent() const

{

	return getParent();

}

transform2d * transform2d::getChildren()
{
	if (children.size() > 0)

	{
		return children[0];
	}
	return nullptr;
}



transform2d * const * transform2d::getChildren() const

{
	return getChildren();
}	



size_t transform2d::getChildrenCount() const

{

	return children.size();
}