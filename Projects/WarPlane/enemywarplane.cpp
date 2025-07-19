#include "enemywarplane.h"
#include "config.h"

EnemyWarplane::EnemyWarplane():
    picture(new QPixmap(ENEMY_PATH)), // 敌机图片资源加载
    rect(new QRect(0, 0, picture->width(), picture->width())), //敌机矩形
    isFree(true), // 敌机状态
    speed(ENEMY_SPEED) // 敌机速度
{
}

void EnemyWarplane::updatePosition()
{
    //空闲状态，不计算坐标
    if(isFree)
    {
        return;
    }

    rect->moveTo(rect->x(), rect->y() + speed);

    if(rect->y() >= GAME_HEIGHT + rect->height())
    {
        isFree = true;
    }
}
