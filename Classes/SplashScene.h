#pragma once

#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "cocos2d.h"
#include "Definition.h"

USING_NS_CC;

class SplashScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SplashScene);
private:
	void switchtomainmenu(float dt);
};
#endif // __SPLASH_SCENE_H__