#ifndef EXPLODING_H
#define EXPLODING_H
#include "config.h"
#include <QPixmap>
#include <QVector>

/**
 * @brief 爆炸效果类
 */
class Exploding
{
public:
    Exploding();

    //更新信息（播放图片下标、播放间隔）
    void updateInfo();

public:

    //放爆炸资源数组
    QVector<QPixmap> m_pixArr;

    //爆炸位置
    int X;
    int Y;

    //爆炸状态
    bool isFree;

    //爆炸切图的时间间隔
    int reoder;

    //爆炸时加载的图片下标
    int index;

};

#endif // EXPLODING_H
