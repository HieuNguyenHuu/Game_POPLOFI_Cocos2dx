#include "SplashScene.h"
#include "StartScene.h"


Scene * SplashScene::createScene()
{
	return SplashScene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool SplashScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

 	auto sprite = Sprite::create(SPLASH_LOGO);
    if (sprite == nullptr)
    {
        problemLoading("'logo.png'");
    }
    else
    {
        sprite->setScale(0.8f);
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        this->addChild(sprite);
    }
    this->scheduleOnce(SEL_SCHEDULE(&SplashScene::switchtomainmenu), SPLASH_SCENE_SHOW_TIME);

	return true;
}

void SplashScene::switchtomainmenu(float dt)
{
    Scene* scene = StartScene::createScene();
    TransitionFade *transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);
    Director::getInstance()->replaceScene(transition);
}