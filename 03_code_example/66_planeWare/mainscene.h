#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"
#include <QSound>

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    void initScene();

    // 启动游戏，用于启动定时器对象
    void playGame();

    // 更新坐标
    void updatePosition();

    // 绘图事件
    void paintEvent(QPaintEvent *event);

    // 鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    // 敌机出场
    void enemyToScene();

    // 碰撞检测
    void collisionDetection();
public:
    QSound *backGroundMusic;

    QTimer m_Timer;

    // 地图对象
    Map m_map;

    // 飞机对象
    HeroPlane m_hero;

    // 测试子弹代码
    Bullet temp_bullet;

    // 敌机出场
    EnemyPlane m_enemys[ENEMY_NUM];

    // 敌机出场间隔记录
    int m_recorder;

    // 爆炸数组
    Bomb m_bombs[BOMB_NUM];
};
#endif // MAINSCENE_H
