#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include <QMouseEvent>
#include <QPainter>
#include <QSoundEffect>
#include <QUrl>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent),
      timer(new QTimer(this)),
      m_map(new Map(this)),
      bgSound(new QSoundEffect(this)),
      explodingSound(new QSoundEffect(this))
{
    initScene(); // 初始化场景
    playGame(); // 开始游戏
}

MainScene::~MainScene()
{
}

void MainScene::initScene()
{
    setFixedSize(GAME_WIDTH, GAME_HEIGHT); // 设置初始化窗口大小
    setWindowTitle(GAME_TITLE); // 设置窗口标题
    setWindowIcon(QIcon(GAME_ICON)); // 设置窗口图标资源（加头文件 #include <QIcon>）

    timer->setInterval(GAME_RATE); // 定时器设置

    reorder = 0;

    // 随机数种子
    srand((unsigned int)time(NULL));  //头文件  #include <ctime>

    // 设置背景音效参数
    bgSound->setSource(QUrl::fromLocalFile(SOUND_BACKGROUND));
    bgSound->setVolume(0.5f);
    bgSound->setLoopCount(QSoundEffect::Infinite);
    // 设置背景音效参数
    explodingSound->setSource(QUrl::fromLocalFile(SOUND_BOMB));
    explodingSound->setVolume(0.5f);
}

void MainScene::playGame()
{
    //启动定时器
    timer->start();

    //监听定时器
    connect(timer,&QTimer::timeout,[=](){
        //敌机出场
        enemyToScene();
        //更新游戏中元素的坐标
        updatePosition();
        //重新绘制图片
        update();
        // 碰撞检测
        collisionDetection();
    });
    //启动背景音乐
    bgSound->play();
}

void MainScene::updatePosition()
{
    // 平滑移动飞机
    int x = hero.rect->x();
    int y = hero.rect->y();
    if (moveLeft)  x -= HERO_SPEED;
    if (moveRight) x += HERO_SPEED;
    if (moveUp)    y -= HERO_SPEED;
    if (moveDown)  y += HERO_SPEED;
    // 边界判断
    if (x < 0) x = 0;
    if (x > GAME_WIDTH - hero.rect->width()) x = GAME_WIDTH - hero.rect->width();
    if (y < 0) y = 0;
    if (y > GAME_HEIGHT - hero.rect->height()) y = GAME_HEIGHT - hero.rect->height();
    hero.setPosition(x, y);

    // 更新地图坐标
    m_map->setPosition();

    // 发射子弹
    hero.shoot();

    // 计算子弹坐标
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!hero.bullets[i].isFree)
        {
            hero.bullets[i].updatePosition();
        }
    }

    // 敌机坐标计算
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        //非空闲敌机 更新坐标
        if(enemys[i].isFree == false)
        {
            enemys[i].updatePosition();
        }
    }

    //计算爆炸播放的图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(bombs[i].isFree == false)
        {
            bombs[i].updateInfo();
        }
    }
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0, m_map->m_y, *(m_map->m_picture));
    painter.drawPixmap(0, m_map->m_y + GAME_HEIGHT, *(m_map->m_picture));

    //绘制英雄
    //painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);
    painter.drawPixmap(hero.rect->x(), hero.rect->y(), *hero.picture);

    //绘制子弹
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!hero.bullets[i].isFree)
        {
            painter.drawPixmap(hero.bullets[i].rect->x(),
                               hero.bullets[i].rect->y(),
                               *hero.bullets[i].picture);
        }
    }

    //绘制敌机
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(enemys[i].isFree == false)
        {
            painter.drawPixmap(enemys[i].rect->x(),
                               enemys[i].rect->y(),
                               *enemys[i].picture);
        }
    }

    //绘制爆炸图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(bombs[i].isFree == false)
        {
            painter.drawPixmap(bombs[i].X,bombs[i].Y,bombs[i].m_pixArr[bombs[i].index]);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - hero.rect->width() * 0.5; //鼠标位置 - 飞机矩形的一半
    int y = event->y() - hero.rect->height() * 0.5;

    //边界检测
    if(x <= 0 )
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - hero.rect->width())
    {
        x = GAME_WIDTH - hero.rect->width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - hero.rect->height())
    {
        y = GAME_HEIGHT - hero.rect->height();
    }
    hero.setPosition(x,y);
}

//实现键盘事件
void MainScene::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left)  moveLeft = true;
    if(e->key() == Qt::Key_Right) moveRight = true;
    if(e->key() == Qt::Key_Up)    moveUp = true;
    if(e->key() == Qt::Key_Down)  moveDown = true;
}
void MainScene::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left)  moveLeft = false;
    if(e->key() == Qt::Key_Right) moveRight = false;
    if(e->key() == Qt::Key_Up)    moveUp = false;
    if(e->key() == Qt::Key_Down)  moveDown = false;
}

void MainScene::collisionDetection()
{
    // 遍历所有非空闲的敌机
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
        if(enemys[i].isFree)
        {
            //空闲飞机 跳转下一次循环
            continue;
        }

        //遍历所有 非空闲的子弹
        for(int j = 0 ; j < BULLET_NUM;j++)
        {
            if(hero.bullets[j].isFree)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }

            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
            if(enemys[i].rect->intersects(*hero.bullets[j].rect))
            {
                enemys[i].isFree = true;
                hero.bullets[j].isFree = true;

                //播放音效
                explodingSound->play();

                //播放爆炸效果
                for(int k = 0 ; k < BOMB_NUM;k++)
                {
                    if(bombs[k].isFree)
                    {
                        //爆炸状态设置为非空闲
                        bombs[k].isFree = false;
                        //更新坐标
                        bombs[k].X = enemys[i].rect->x();
                        bombs[k].Y = enemys[i].rect->y();
                        break;
                    }
                }

            }
        }
    }
}

void MainScene::enemyToScene()
{
    reorder++;
    if(reorder < ENEMY_INTERVAL)
    {
        return;
    }

    reorder = 0;

    for(int i = 0 ; i< ENEMY_NUM; i++)
    {
        if(enemys[i].isFree)
        {
            //敌机空闲状态改为false
            enemys[i].isFree = false;
            //设置坐标
            enemys[i].rect->moveTo(rand() % (GAME_WIDTH - enemys[i].rect->width()),
                                       -enemys[i].rect->height());
            break;
        }
    }
}
