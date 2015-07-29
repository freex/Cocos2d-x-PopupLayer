#include "HelloWorldScene.h"
#include "PopupLayer.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 添加背景图片
    /*  CCSprite* background = CCSprite::create("HelloWorld.png");
     background->setPosition(pointCenter);
     background->setScale(1.5f);
     this->addChild(background);    */
    auto sp = Sprite::create("background4.jpg");
    sp->setPosition(visibleSize/2);
    this->addChild(sp);
    //popupLayer();
    
    
    // 添加菜单
    Menu* menu = Menu::create();
    auto menuItemFont = MenuItemFont::create("PopupLayer", CC_CALLBACK_1(HelloWorld::menuCallback, this));
    menuItemFont->setPosition(visibleSize.width/2,visibleSize.height/2);
    menuItemFont->setColor(Color3B(255, 0, 0));
    menu->addChild(menuItemFont);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    return true;
}

void HelloWorld::popupLayer(){
    // 定义一个弹出层，传入一张背景图
    PopupLayer* pl = PopupLayer::create("bg.png");
    // ContentSize 是可选的设置，可以不设置，如果设置把它当作 9 图缩放
    pl->setContentSize(CCSizeMake(400, 280));
//    pl->setTitle("吾名一叶");
    pl->setContentText("有招聘信息的HR可以联系管理员发群公告！望管理员也给予积极配合，谢谢！群号：389970612   C/C++/OC/C#/JAVA/PHP/SQL....", 12, 10, 250);
    pl->setColor(Color3B(250, 60, 60));
    // 设置回调函数，回调传回一个 CCNode 以获取 tag 判断点击的按钮
    // 这只是作为一种封装实现，如果使用 delegate 那就能够更灵活的控制参数了
    pl->setCallbackFunc(this, callfuncN_selector(HelloWorld::buttonCallback));
    // 添加按钮，设置图片，文字，tag 信息
    pl->addButton("bt1.png", "bt2", "确定", 0);
    pl->addButton("bt1.png", "bt2.png", "取消", 1);
    // 添加到当前层
    this->addChild(pl);
}

void HelloWorld::menuCallback(cocos2d::Object *pSender){
    popupLayer();
}

void HelloWorld::buttonCallback(cocos2d::Node *pNode){
    CCLog("button call back. tag: %d", pNode->getTag());
}
