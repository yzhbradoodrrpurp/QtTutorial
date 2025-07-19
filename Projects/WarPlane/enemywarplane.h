#ifndef ENEMYFLIGHTER_H
#define ENEMYFLIGHTER_H

#include <QPixmap>

/**
 * @brief 敌机类
 */
class EnemyWarplane {
public:
    EnemyWarplane();

    /**
     * @brief 更新坐标
     */
    void updatePosition();

public:
    /**
     * @brief 敌机图片资源对象
     */
    QPixmap* picture;

    /**
     * @brief 敌机的矩形边框（左上角为飞机坐标，用于碰撞检测）
     */
    QRect* rect;

    /**
     * @brief 状态（是否可用）
     */
    bool isFree;

    /**
     * @brief 速度
     */
    int speed;

};

#endif // ENEMYFLIGHTER_H
