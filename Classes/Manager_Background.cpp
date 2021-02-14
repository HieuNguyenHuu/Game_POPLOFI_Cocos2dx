#include "Manager_Background.h"

void Manager_Background::addSF_Layer(SpriteFrameCache* sf_a, Layer* layer_a)
{
    sf = sf_a;
    layer = layer_a;
}

void Manager_Background::addBackground() {
    /*background = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BG1_BG));
    background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    background->setScale(1.05);

    layer->addChild(background);

    objbg = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(OBJ_BG1_ROADSIGNAL));
    objbg->setPosition(Vec2(1780, 800));
    objbg->setScale(8);
    auto animation = Manager_Background::createAnimation("bg1_roadsign_", 8, 0.08f);
    auto animate = Animate::create(animation);
    animate->retain();
    objbg->runAction(RepeatForever::create(animate));

    layer->addChild(objbg);*/


}

void Manager_Background::update(float dt) {


   if (ptscheck){
       /*particleSystem->setStartColor(Color4F(0.0f, 1.0f, 0.0f, 1.0f));
       particleSystem->setEndColor(Color4F(0.0f, 1.0f, 0.0f, 1.0f));*/
       particleSystem->setVisible(false);
       //particleSystem->updateDisplayedOpacity(0);

      /* background->setScale(1.08);
       objbg->setScale(8.08);
       table->setScale(8.03);*/
       ptscheck = false;

    }
    else {
       /*particleSystem->setStartColor(Color4F(0.5f, 0.5f, 0.0f, 0.5f));
       particleSystem->setEndColor(Color4F(0.5f, 0.5f, 0.0f, 0.5f));*/
       particleSystem->setVisible(true);
       //particleSystem->updateDisplayedOpacity(255);
     /*  background->setScale(1.05);
       objbg->setScale(8);
       table->setScale(8);*/
      ptscheck = true;

    }

}

void Manager_Background::addParticle() {
    particleSystem = ParticleSystemQuad::create(PT_BLINKING);
    particleSystem->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    layer->addChild(particleSystem);

    particleSystem->setVisible(true);

}

void Manager_Background::addTable() {
    /*table = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(OBJ_BG_TABLE));
    table->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    table->setScale(8);
    layer->addChild(table);*/
}

Animation* Manager_Background::createAnimation(std::string prefixName, int numberofFrame, float delay) {
    Vector<SpriteFrame*> animFrames;
    for (int i = 0; i <= numberofFrame; i++) {
        char buffer[30] = { 0 };
        sprintf(buffer, "%d.png", i);
        std::string str = prefixName + buffer;
        auto frame = sf->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    animation = Animation::createWithSpriteFrames(animFrames, delay);
    return animation;
}



Manager_Background* Manager_Background::instances = nullptr;

Manager_Background * Manager_Background::get_intances()
{
    if (instances == nullptr) {
        instances = new Manager_Background();
    }
    return instances;
}

Manager_Background::Manager_Background() {
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
}





