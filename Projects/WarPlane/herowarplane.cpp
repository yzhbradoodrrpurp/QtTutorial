#include "herowarplane.h"
#include "config.h"

HeroWarplane::HeroWarplane():
    picture(new QPixmap(HERO_PATH)), // 初始化加载飞机图片资源
    rect(new QRect(GAME_WIDTH * 0.5 - picture->width() * 0.5,
                     GAME_HEIGHT - picture->height() - 50,
                     picture->width(),
                     picture->height())), // 初始化矩形框
    reorder(0) // 初始化发射间隔记录
{
}

void HeroWarplane::setPosition(int x, int y)
{
    rect->moveTo(x,y);
}

void HeroWarplane::shoot()
{
    //累加时间间隔记录变量
    reorder++;
    //判断如果记录数字 未达到发射间隔，直接return
    if(reorder < BULLET_INTERVAL)
    {
        return;
    }
    // 到达发射时间处理
    // 重置发射时间间隔记录
    reorder = 0;

    //发射子弹
    for(int i = 0; i < BULLET_NUM; i++)
    {
        //如果是空闲的子弹进行发射
        if(bullets[i].isFree)
        {
            //将改子弹空闲状态改为假
            bullets[i].isFree = false;
            //设置发射的子弹坐标
            bullets->rect->moveTo(rect->x() + rect->width() * 0.5 - 10, rect->y() - 25);
            break;
        }
    }
}
