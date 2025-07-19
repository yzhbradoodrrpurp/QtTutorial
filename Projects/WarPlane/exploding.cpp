#include "exploding.h"

Exploding::Exploding()
{
    //初始化爆炸图片数组
    for(int i = 1 ;i <= BOMB_MAX ;i++)
    {
        //字符串拼接，类似  ":/res/bomb-1.png"
        QString str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    //初始化坐标
    X = 0;
    Y = 0;

    //初始化空闲状态
    isFree = true;

    //当前播放图片下标
    index = 0;

    //爆炸间隔记录
    reoder = 0;

}

void Exploding::updateInfo()
{
    //空闲状态
    if(isFree)
    {
        return;
    }

    reoder++;
    if(reoder < BOMB_INTERVAL)
    {
        //记录爆炸间隔未到，直接return，不需要切图
        return;
    }
    //重置记录
    reoder = 0;

    //切换爆炸播放图片
    index++;
    //注：数组中的下标从0开始，最大是6
    //如果计算的下标大于6，重置为0
    if(index > BOMB_MAX-1)
    {
        index = 0;
        isFree = true;
    }
}
