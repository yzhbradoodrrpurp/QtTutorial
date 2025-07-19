#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>
#include <QRect>

/**
 * @brief 子弹类
 */
class Bullet
{
public:
    Bullet();

    /**
     * @brief 更新子弹坐标
     */
    void updatePosition();

public:
    /**
     * @brief 子弹资源对象
     */
    QPixmap* picture;

    /**
     * @brief 子弹的矩形边框（用于碰撞检测）
     */
    QRect* rect;

    /**
     * @brief 子弹移动速度
     */
    int speed;

    /**
     * @brief 子弹是否闲置
     */
    bool isFree;
};

#endif // BULLET_H
