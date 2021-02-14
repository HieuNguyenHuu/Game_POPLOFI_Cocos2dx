
#include "GameScene.h"

Scene* GameScene::createScene()
{
    return GameScene::create();
}
bool d = false;

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	gamelayer = new Layer();
	this->addChild(gamelayer, -10);

	gamelayer->setAnchorPoint(Point::ANCHOR_MIDDLE);

	/*gamelayer->setPosition(Vec2(origin.x+(visibleSize.width/2), origin.y+(visibleSize.height/2)));*/


	//AudioEngine::play2d(MUSIC1_PATH);

	SimpleAudioEngine::getInstance()->playBackgroundMusic("s90_Tick_of_time.wav", true);

	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.2);

	auto sf_bg1 = SpriteFrameCache::getInstance();
	sf_bg1->addSpriteFramesWithFile("texture/texture.plist", "texture/texture.png");

	sf_character = SpriteFrameCache::getInstance();
	sf_character->addSpriteFramesWithFile("texture/texture.plist", "texture/texture.png");

	auto sf_ball = SpriteFrameCache::getInstance();
	sf_ball->addSpriteFramesWithFile("texture/texture.plist", "texture/texture.png");

	auto bg = cocos2d::LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(bg, -11);

	auto controller = Sprite::create("controller.png");
	controller->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	controller->setOpacity(100);
	this->addChild(controller, 20);


	Manager_Background::get_intances()->addSF_Layer(sf_bg1, gamelayer);
	Manager_Enemy::get_intances()->addSF_Layer(sf_bg1, gamelayer);
	Manager_Character::get_intances()->addSF_Layer(sf_character, gamelayer);
	Manager_Ball::get_intances()->addSF_Layer(sf_ball, gamelayer);


	Manager_Background::get_intances()->addBackground();

	Manager_Enemy::get_intances()->addEnemy(ENEMY_DOC_STAND);

	Manager_Background::get_intances()->addTable();

	Manager_Ball::get_intances()->addBall();

	Manager_Character::get_intances()->addCharacter();

	Manager_Background::get_intances()->addParticle();

	Manager_Background::get_intances()->addParticle();

    secperbeat = 60.0f / MUSIC_1_BPM;


    /*Vec2 enemyrect = Manager_Enemy::get_intances()->getEnemy()->getPosition();

    if (Manager_Ball::get_intances()->getBall()->getBoundingBox().containsPoint(enemyrect)) {
        Manager_Ball::get_intances()->getBall()->stopAllActions();
        auto movetopbot = MoveTo::create(secperbeat - (float) 1.0f/60.0f, Vec2(visibleSize.width / 2 + origin.x,
                                                visibleSize.height / 2 + origin.y -200));

        Manager_Ball::get_intances()->getBall()->runAction(movetopbot);

    }*/

	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [&](Touch* touch, Event* event){

		return true;
	};

	listener->onTouchMoved = [&](Touch* touch, Event* event){
	};

	listener->onTouchEnded = [&](Touch* touch, Event* event){

		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		//log("%f %f %f", touch->getLocation().x, touch->getLocation().y, visibleSize.height/2 + origin.y -300);

        if((touch->getLocation().y < visibleSize.height/2 + origin.y -150) && (Manager_Character::get_intances()->getCharacter()->getPosition() == Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y - 300))
           ){
            Manager_Character::get_intances()->anihitmf();
            log("cc = haham");
        }
		if((touch->getLocation().y >  visibleSize.height/2 + origin.y -200) && (touch->getLocation().x >  visibleSize.width/2 + origin.x ) && (Manager_Character::get_intances()->getCharacter()->getPosition() == Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y - 300))
		   ){
			Manager_Character::get_intances()->anihitright();
			log("cc = hahar");
		}
		if((touch->getLocation().y >  visibleSize.height/2 + origin.y -200) && (touch->getLocation().x <  visibleSize.width/2 + origin.x ) && (Manager_Character::get_intances()->getCharacter()->getPosition() == Vec2(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y - 300))
		   ){
			Manager_Character::get_intances()->anihitleft();
			log("cc = hahal");
		}

		//d = false;
	};


    auto seq = Sequence::create(MoveTo::create( 1.0f, gamelayer->getPosition() + Vec2(30, 30))
            ,MoveTo::create( 1.0f, gamelayer->getPosition() + Vec2(-30, 30) )
            ,MoveTo::create( 1.0f, gamelayer->getPosition() ),MoveTo::create( 1.0f, gamelayer->getPosition() + Vec2(-30, -30) )
            ,MoveTo::create( 1.0f, gamelayer->getPosition() + Vec2(30, -30) )
            ,MoveTo::create( 1.0f, gamelayer->getPosition() ),nullptr);

    gamelayer->runAction(RepeatForever::create(seq));



	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	this->schedule(CC_SCHEDULE_SELECTOR(GameScene::upbeat), secperbeat);

	this->scheduleUpdate();

	return true;
}

bool repeart = false;

Sprite * counte;

Sprite * countc;

void GameScene::update(float dt) {

	/*if ( ( repeart) || (Manager_Ball::get_intances()->getBall()->getPositionY() < 0)){
	    counte = Sprite::create("sECountDown_0.png");
	    counte->setPosition(Vec2(visibleSize.width /2 + origin.x + 50, visibleSize.height/2 + origin.y+ 350));
	    counte->setScale(8);

       /* auto animation = GameScene::createAnimation("sECountDown_", 2, 0.1f);
        auto animate = Animate::create(animation);
        animate->retain();

        counte->runAction(animate);

        counte->setVisible(true);

        countc = Sprite::create("sEDrop_0.png");
        countc->setPosition(Vec2(visibleSize.width /2 + origin.x - 50, visibleSize.height/2 + origin.y - 300));
        countc->setScale(8);

        countc->setVisible(true);

        Vec2 enemyrect = Manager_Enemy::get_intances()->getEnemy()->getPosition() - Vec2(0, 30);

        if (Manager_Ball::get_intances()->getBall()->getBoundingBox().containsPoint(enemyrect)) {
            Manager_Ball::get_intances()->getBall()->stopAllActions();
            auto movetopbot = MoveTo::create(secperbeat - (float) 1.0f/60.0f, Vec2(visibleSize.width / 2 + origin.x,
                                                                                   visibleSize.height / 2 + origin.y -200));
            Manager_Ball::get_intances()->getBall()->runAction(movetopbot);
        }

        repeart = false;
	}*/
	//else {
	//
	    /*counte->setVisible(false);

        countc->setVisible(false);


        hithit = Manager_Character::get_intances()->getCharacter()->getSpriteFrame() ==
                 sf_character->getSpriteFrameByName("sPlayerBotHitRight_0.png") ||
                 Manager_Character::get_intances()->getCharacter()->getSpriteFrame() ==
                 sf_character->getSpriteFrameByName("sPlayerBotHitLeft_0.png");

        Vec2 enemyrect = Manager_Enemy::get_intances()->getEnemy()->getPosition() - Vec2(0, 30);

        Rect characterrect = Manager_Character::get_intances()->getCharacter()->getBoundingBox();

        collisionenemyandball = Manager_Ball::get_intances()->getBall()->getBoundingBox().containsPoint(
                enemyrect);

        collisioncharacterandball = Manager_Ball::get_intances()->getBall()->getBoundingBox().intersectsRect(
                characterrect);

        if (collisionenemyandball) {

            int dd = randomValueBetween(0, 0);

            if (dd == 0) {
                if (!checkc) {
                    SimpleAudioEngine::getInstance()->playEffect(MUSIC1_BASS, false, 2.0f, 1.0f,
                                                                 1.0f);
                    SimpleAudioEngine::getInstance()->setEffectsVolume(0.3);
                    Manager_Ball::get_intances()->getBall()->stopAllActions();
                    auto movetopbot = MoveTo::create((float) 60 / MUSIC1_BPM - dt,
                                                     Vec2(visibleSize.width / 2 + origin.x,
                                                          visibleSize.height / 2 + origin.y - 250));
                    Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
                    rightc = false;
                    leftc = false;
                    checkc = true;
                    checke = false;
                    repeart = false;
                }
            } else if (dd == 1) {
                if (!checkc) {
                    SimpleAudioEngine::getInstance()->playEffect(MUSIC1_BASS, false, 2.0f, 1.0f,
                                                                 1.0f);
                    SimpleAudioEngine::getInstance()->setEffectsVolume(0.3);
                    Manager_Ball::get_intances()->getBall()->stopAllActions();
                    auto movetopbot = MoveTo::create((float) 60 / MUSIC1_BPM - dt,
                                                     Vec2(visibleSize.width / 2 + origin.x + 200,
                                                          visibleSize.height / 2 + origin.y - 250));
                    Manager_Ball::get_intances()->getBall()->runAction(movetopbot);
                    rightc = true;
                    leftc = false;
                    checkc = true;
                    checke = false;
                    repeart = false;
                }
            } else {
                if (!checkc) {
                    SimpleAudioEngine::getInstance()->playEffect(MUSIC1_BASS, false, 2.0f, 1.0f,
                                                                 1.0f);
                    SimpleAudioEngine::getInstance()->setEffectsVolume(0.3);
                    Manager_Ball::get_intances()->getBall()->stopAllActions();
                    auto movetopbot = MoveTo::create((float) 60 / MUSIC1_BPM - dt,
                                                     Vec2(visibleSize.width / 2 + origin.x - 200,
                                                          visibleSize.height / 2 + origin.y - 250));
                    Manager_Ball::get_intances()->getBall()->runAction(movetopbot);
                    rightc = false;
                    leftc = true;
                    checkc = true;
                    checke = false;
                    repeart = false;
                }
            }

        }
        if (collisioncharacterandball) {

            int dd = randomValueBetween(0, 0);

            if (dd == 0) {
                if (hithit) {
                    if (!checke) {
                        Manager_Ball::get_intances()->getBall()->stopAllActions();
                        SimpleAudioEngine::getInstance()->playEffect(MUSIC1_BASS, false, 2.0f, 1.0f,
                                                                     1.0f);
                        SimpleAudioEngine::getInstance()->setEffectsVolume(0.3);
                        auto movetopbot = MoveTo::create((float) 60 / MUSIC1_BPM - dt,
                                                         Vec2(visibleSize.width / 2 + origin.x,
                                                              visibleSize.height / 2 + origin.y +
                                                              350));
                        Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
                        righte = false;
                        lefte = false;
                        checkc = false;
                        checke = true;
                        repeart = false;
                    }
                } else {
                    if (!checke) {
                        Manager_Ball::get_intances()->getBall()->stopAllActions();
                        SimpleAudioEngine::getInstance()->playEffect(MUSIC1_BASS, false, 2.0f, 1.0f,
                                                                     1.0f);
                        SimpleAudioEngine::getInstance()->setEffectsVolume(0.3);
                        auto movetopbot = MoveTo::create((float) 60 / MUSIC1_BPM - dt,
                                                         Vec2(visibleSize.width / 2 + origin.x,
                                                              visibleSize.height / 2 + origin.y -
                                                              800));
                        Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
                        righte = false;
                        lefte = false;
                        checkc = false;
                        checke = true;
                        repeart = true;
                    }
                }

            } else if (dd == 1) {
                if (hithit) {
                    if (!checke) {
                        Manager_Ball::get_intances()->getBall()->stopAllActions();
                        SimpleAudioEngine::getInstance()->playEffect(MUSIC1_BASS, false, 2.0f, 1.0f,
                                                                     1.0f);
                        SimpleAudioEngine::getInstance()->setEffectsVolume(0.3);
                        auto movetopbot = MoveTo::create((float) 60 / MUSIC1_BPM - dt,
                                                         Vec2(visibleSize.width / 2 + origin.x +
                                                              150,
                                                              visibleSize.height / 2 + origin.y +
                                                              320));
                        Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
                        righte = true;
                        lefte = false;
                        checkc = false;
                        checke = true;
                        repeart = false;
                    }
                } else {
                    if (!checke) {
                        Manager_Ball::get_intances()->getBall()->stopAllActions();
                        SimpleAudioEngine::getInstance()->playEffect(MUSIC1_BASS, false, 2.0f, 1.0f,
                                                                     1.0f);
                        SimpleAudioEngine::getInstance()->setEffectsVolume(0.3);
                        auto movetopbot = MoveTo::create((float) 60 / MUSIC1_BPM - dt,
                                                         Vec2(visibleSize.width / 2 + origin.x +
                                                              150,
                                                              visibleSize.height / 2 + origin.y -
                                                              800));
                        Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
                        righte = true;
                        lefte = false;
                        checkc = false;
                        checke = true;
                        repeart = true;
                    }
                }
            } else {
                if (hithit) {
                    if (!checke) {
                        Manager_Ball::get_intances()->getBall()->stopAllActions();
                        SimpleAudioEngine::getInstance()->playEffect(MUSIC1_BASS, false, 2.0f, 1.0f,
                                                                     1.0f);
                        SimpleAudioEngine::getInstance()->setEffectsVolume(0.3);
                        auto movetopbot = MoveTo::create((float) 60 / MUSIC1_BPM - dt,
                                                         Vec2(visibleSize.width / 2 + origin.x -
                                                              150,
                                                              visibleSize.height / 2 + origin.y +
                                                              320));
                        Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
                        righte = false;
                        lefte = true;
                        checkc = false;
                        checke = true;
                        repeart = false;
                    }
                } else {
                    if (!checke) {
                        Manager_Ball::get_intances()->getBall()->stopAllActions();
                        SimpleAudioEngine::getInstance()->playEffect(MUSIC1_BASS, false, 2.0f, 1.0f,
                                                                     1.0f);
                        SimpleAudioEngine::getInstance()->setEffectsVolume(0.3);
                        auto movetopbot = MoveTo::create((float) 60 / MUSIC1_BPM - dt,
                                                         Vec2(visibleSize.width / 2 + origin.x -
                                                              150,
                                                              visibleSize.height / 2 + origin.y -
                                                              800));
                        Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
                        righte = false;
                        lefte = true;
                        checkc = false;
                        checke = true;
                        repeart = true;
                    }
                }
            }
        }
        if ((Manager_Character::get_intances()->getCharacter()->getPosition() ==
             Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 300))) {
            Manager_Character::get_intances()->aniidle();
        }
        if ((lefte)) {
            if (Manager_Ball::get_intances()->getBall()->getPosition().y >
                visibleSize.height / 2 + origin.y + 150) {
                Manager_Enemy::get_intances()->anihitleft();
            }
        } else if ((righte)) {
            if (Manager_Ball::get_intances()->getBall()->getPosition().y >
                visibleSize.height / 2 + origin.y + 150) {
                Manager_Enemy::get_intances()->anihitright();
            }
        } else if ((!righte) && (!lefte)) {
            if (Manager_Ball::get_intances()->getBall()->getPosition().y >
                visibleSize.height / 2 + origin.y + 150) {
                Manager_Enemy::get_intances()->anihitmf();
            }
        }
        if ((Manager_Enemy::get_intances()->getEnemy()->getPosition() ==
             Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 350)) &&
            (checkc)) {
            Manager_Enemy::get_intances()->aniidle();
        }*/
   // }

}
bool layercheck = false;

void GameScene::upbeat(float dt) {

	/*if (layercheck) {
		gamelayer->setScale(1.02f);
		layercheck = false;
	}else {
		gamelayer->setScale(1.0f);
		layercheck = true;
	}

	//Manager_Ball::get_intances()->update(dt);
	Manager_Background::get_intances()->update(dt);
*/

	/*Rect enemyrect = Manager_Enemy::get_intances()->getEnemy()->getBoundingBox();
	Rect characterrect = Manager_Character::get_intances()->getCharacter()->getBoundingBox();

	collisionenemyandball = Manager_Ball::get_intances()->getBall()->getBoundingBox().intersectsRect(enemyrect);
	collisioncharacterandball = Manager_Ball::get_intances()->getBall()->getBoundingBox().intersectsRect(characterrect);*/

	/*Vec2 enemyrect = Manager_Enemy::get_intances()->getEnemy()->getPosition();
	Vec2 characterrect = Manager_Character::get_intances()->getCharacter()->getPosition();

	collisionenemyandball =  Manager_Ball::get_intances()->getBall()->getBoundingBox().containsPoint(enemyrect);
	collisioncharacterandball = Manager_Ball::get_intances()->getBall()->getBoundingBox().containsPoint(characterrect);

	log("cc eb %d cb %d" , collisionenemyandball,collisioncharacterandball );*/

	/*
        //auto movetopbot = MoveTo::create(dt, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 250));*/
	/* if (collisionenemyandball){


         int dd = random(0, 0 );

             if (dd == 0) {
                 Manager_Ball::get_intances()->getBall()->stopAllActions();
                 auto movetopbot = MoveTo::create(dt, Vec2(visibleSize.width / 2 + origin.x,
                                                           visibleSize.height / 2 + origin.y - 300));
                 Manager_Ball::get_intances()->getBall()->runAction(movetopbot);
                 rightc = false;
                 leftc = false;
             }
             else if (dd == 1) {
                 Manager_Ball::get_intances()->getBall()->stopAllActions();
                 auto movetopbot = MoveTo::create(dt, Vec2(visibleSize.width / 2 + origin.x + 200,
                                                           visibleSize.height / 2 + origin.y - 300));
                 Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
                 rightc = true;
                 leftc = false;
             }
             else {
                 Manager_Ball::get_intances()->getBall()->stopAllActions();
                 auto movetopbot = MoveTo::create(dt, Vec2(visibleSize.width / 2 + origin.x - 200,
                                                           visibleSize.height / 2 + origin.y - 300));
                 Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
                 rightc = false;
                 leftc = true;
             }

     }
     if (collisioncharacterandball){

         int dd = random(0, 2 );

         if (dd == 0) {
             Manager_Ball::get_intances()->getBall()->stopAllActions();
             auto movetopbot = MoveTo::create(dt, Vec2(visibleSize.width / 2 + origin.x,
                                                       visibleSize.height / 2 + origin.y + 350));
             Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
             righte = false;
             lefte = false;
         }
         else if (dd == 1) {
             Manager_Ball::get_intances()->getBall()->stopAllActions();
             auto movetopbot = MoveTo::create(dt, Vec2(visibleSize.width / 2 + origin.x + 200,
                                                       visibleSize.height / 2 + origin.y + 350));
             Manager_Ball::get_intances()->getBall()->runAction((movetopbot));
             righte = true;
             lefte = false;
         }
         else {
             Manager_Ball::get_intances()->getBall()->stopAllActions();
             auto movetopbot = MoveTo::create(dt, Vec2(visibleSi

    */

}

int GameScene::randomValueBetween(int low, int high)
{
    return (((int)rand() / RAND_MAX) * (high - low)) + low;
}

/*Animation* GameScene::createAnimation(std::string prefixName, int numberofFrame, float delay) {
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
}*/


