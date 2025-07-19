#ifndef MAP_H
#define MAP_H
#include <QObject>
#include <QPixmap>

/**
 * @brief 游戏地图类
 * 1、出于游戏效率地考虑，数据成员全部设为public
 * 2、地图图片对象m_picture为指针，在堆上分配内存
 */
class Map : public QObject
{
public:
    // 构造函数
    Map(QObject* parent);

    /**
     * @brief 地图滚动坐标计算
     */
    void setPosition();

public:
    /**
     * @brief 地图图片对象
     */
    QPixmap* m_picture;
    /**
     * @brief 地图中第一张图片的Y轴坐标，地图中第二张图片的Y轴坐标为 m_y+GAME_HEIGHT
     */
    int m_y;
    /**
     * @brief 地图中第二张图片的Y轴坐标
     */
//    int m_y2;

    /**
     * @brief 地图滚动幅度
     */
    int m_scroll_speed;
};

#endif
