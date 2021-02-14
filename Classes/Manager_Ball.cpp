#include "Manager_Ball.h"

void Manager_Ball::addSF_Layer(SpriteFrameCache* sf_a, Layer* layer_a)
{
    sf = sf_a;
    layer = layer_a;
}


void Manager_Ball::update(float dt) {

    /*Vec2 topposition = Vec2(visibleSize.width / 2 + origin.x,
                            visibleSize.height / 2 + origin.y + 300);
    Vec2 botpostion = Vec2(visibleSize.width / 2 + origin.x,
                           visibleSize.height / 2 + origin.y - 200);
    if (ball->getPosition() > topposition) {
        ball->stopAllActions();
        auto movetopbot = MoveTo::create(dt, Vec2(visibleSize.width / 2 + origin.x,
                                                  visibleSize.height / 2 + origin.y - 250));
        ball->runAction(movetopbot);
    }
    if (ball->getPosition() < botpostion) {
        ball->stopAllActions();
        auto movebottop = MoveTo::create(dt, Vec2(visibleSize.width / 2 + origin.x,
                                                  visibleSize.height / 2 + origin.y + 350));
        ball->runAction(movebottop);
    }*/

}

void Manager_Ball::addBall() {
   /* ball = Sprite::createWithSpriteFrame(sf->getSpriteFrameByName(BALL_0));
    ball->setScale(10);
    ball->setPosition(Manager_Enemy::get_intances()->getEnemy()->getPosition());
    //ball->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    layer->addChild(ball);*/
}

Animation* Manager_Ball::createAnimation(std::string prefixName, int numberofFrame, float delay) {
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
Manager_Ball* Manager_Ball::instances = nullptr;

Manager_Ball * Manager_Ball::get_intances()
{
    if (instances == nullptr) {
        instances = new Manager_Ball();
    }
    return instances;
}

Manager_Ball::Manager_Ball() {
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
}

Sprite *Manager_Ball::getBall() {
    return ball;
}








