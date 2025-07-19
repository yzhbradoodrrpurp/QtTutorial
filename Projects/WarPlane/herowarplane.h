#ifndef HEROFLIGHTER_H
#define HEROFLIGHTER_H
#include "bullet.h"

#include <QPixmap>
#include <QRect>

/**
 * @brief 英雄战机类
 */
class HeroWarplane
{
public:
    HeroWarplane();

    /**
     * @brief 发射子弹
     */
    void shoot();

    /**
     * @brief 设置飞机位置
     * @param x x坐标
     * @param y
     */
    void setPosition(int x, int y);

public:
    /**
     * @brief 飞机图片资源对象
     */
    QPixmap* picture;

    /**
     * @brief 飞机的矩形边框（左上角为飞机坐标）
     */
    QRect* rect;

    /**
     * @brief 弹匣（子弹数组）
     */
    Bullet bullets[BULLET_NUM];

    /**
     * @brief 子弹发射间隔记录
     */
    int reorder;

};

#endif // HEROFLIGHTER_H
