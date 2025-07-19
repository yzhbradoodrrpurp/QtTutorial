#include "map.h"
#include "config.h"
#include <QDebug>

Map::Map(QObject *parent)
    : QObject(parent),
    m_picture(new QPixmap(MAP_PATH)), // 初始化加载地图对象
    m_y(-GAME_HEIGHT),// 设置地图起始y轴坐标
//    m_y2(0), // 设置地图其实y轴坐标
    m_scroll_speed(MAP_SCROLL_SPEED) // 设置地图滚动速度
{
}

void Map::setPosition()
{
    //处理第一张图片滚动
    m_y += MAP_SCROLL_SPEED;
    if(m_y >= 0)
    {
        m_y =-GAME_HEIGHT;
    }

    //处理第二张图片滚动
//    m_y2 += MAP_SCROLL_SPEED;
//    if(m_y2 >= GAME_HEIGHT )
//    {
//        m_y2 =0;
//    }
}
