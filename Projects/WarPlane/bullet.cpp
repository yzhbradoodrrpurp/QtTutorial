#include "bullet.h"

Bullet::Bullet():
    picture(new QPixmap(BULLET_PATH)), // 加载子弹资源
    rect(new QRect(GAME_WIDTH * 0.5 - picture->width() * 0.5,
                     GAME_HEIGHT,
                     picture->width(),
                     picture->height())), // 子弹矩形框。子弹坐标 初始坐标可随意设置，后期会重置
    speed(BULLET_SPEED), // 子弹速度
    isFree(true) // 子弹状态
{
}

void Bullet::updatePosition()
{
    // 如果子弹是空闲状态，不需要坐标计算
    // 玩家飞机可以控制子弹的空闲状态为false
    if(isFree)
    {
        return;
    }

    // 子弹向上移动
    rect->moveTo(rect->x(), rect->y() - speed);

    if(rect->y() <= -rect->height())
    {
        isFree = true;
    }
}
