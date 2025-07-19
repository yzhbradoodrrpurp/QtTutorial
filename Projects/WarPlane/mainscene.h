#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <qsoundeffect.h>
#include "map.h"
#include "herowarplane.h"
#include "bullet.h"
#include "enemywarplane.h"
#include "exploding.h"

/**
 * @brief 游戏主场景
 */
class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    /**
     * @brief initScene
     */
    void initScene();

    /**
     * @brief 启动游戏  用于启动定时器对象
     */
    void playGame();

    /**
     * @brief 更新坐标
     */
    void updatePosition();

    /**
     * @brief 绘图事件
     * @param event
     */
    void paintEvent(QPaintEvent *event);

    /**
     * @brief 敌机出场
     */
    void enemyToScene();

    /**
     * @brief 鼠标移动事件
     * @param event
     */
    void mouseMoveEvent(QMouseEvent *event);

    /**
     * @brief 键盘事件事件
     * @param event
     */
    void keyPressEvent(QKeyEvent *e);

    /**
     * @brief 新增键盘释放事件
     * @param e
     */
    void keyReleaseEvent(QKeyEvent *e) override;

    /**
     * @brief 碰撞检测
     */
    void collisionDetection();

public:
    /**
     * @brief 定时器对象
     */
    QTimer* timer;

    /**
     * @brief 地图对象
     */
    Map* m_map;

    /**
     * @brief 飞机对象
     */
    HeroWarplane hero;

    //敌机数组
    EnemyWarplane enemys[ENEMY_NUM];

    //敌机出场间隔
    int reorder;

    /**
     * @brief 爆炸数组
     */
    Exploding bombs[BOMB_NUM];

    /**
     * @brief 背景音效对象
     */
    QSoundEffect* bgSound;

    /**
     * @brief 爆炸音效对象
     */
    QSoundEffect* explodingSound;

    // 飞机移动方向标志
    bool moveLeft = false;
    bool moveRight = false;
    bool moveUp = false;
    bool moveDown = false;
};
#endif // WIDGET_H
