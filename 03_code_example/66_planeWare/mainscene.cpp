#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>


MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    // 创建背景音乐对象
    backGroundMusic = new QSound(SOUND_BACKGROUND);

    // 初始化场景
    initScene();
}

MainScene::~MainScene()
{
    delete backGroundMusic;
}

void MainScene::initScene()
{
    // 初始化窗口大小
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);

    // 设置窗口标题
    setWindowTitle(GAME_TITLE);

    // 加载图标
    setWindowIcon(QIcon(GAME_ICON));

    // 定时器设置
    m_Timer.setInterval(GAME_RATE);

    // 启动游戏接口
    playGame();

    m_recorder = 0;

    // 随机数种子
    srand((unsigned int )time(NULL));
}

void MainScene::playGame()
{
    // 启动定时器
    m_Timer.start();

    //  监听 定时器
    connect(&m_Timer, &QTimer::timeout, [=](){
       // 更新游戏中元素的坐标
       updatePosition();

       // 重新绘制图片
       update();

       // 敌机出场
       enemyToScene();

       // 碰撞检测
       collisionDetection();
    });

    // 启动背景音乐
    backGroundMusic->play();
    backGroundMusic->setLoops(QSound::Infinite);
}

void MainScene::updatePosition()
{
    // 更新地图坐标
    m_map.mapPosition();

    // 测试子弹代码
    // temp_bullet.m_Free = false;
    // temp_bullet.updatePosition();

    // 发射子弹
    m_hero.shoot();
    for (int i = 0; i < BULLET_NUM; i++)
    {
        // 如果子弹状态为非空闲，计算发射位置
        if (!m_hero.m_bullets[i].m_Free)
            m_hero.m_bullets[i].updatePosition();
    }

    // 敌机坐标计算
    for (int i = 0; i < ENEMY_NUM; i++)
    {
        // 非空闲敌机 更新坐标
        if (!m_enemys[i].m_Free)
            m_enemys[i].updatePosition();
    }

    // 计算爆炸播放的图片
    for (int i = 0; i < BOMB_NUM; i++)
    {
        if (!m_bombs[i].m_Free)
            m_bombs[i].updateInfo();
    }
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // 绘制地图
    painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
    painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

    // 绘制飞机
    painter.drawPixmap(m_hero.m_X, m_hero.m_Y, m_hero.m_Plane);

    // 绘制子弹
    //painter.drawPixmap(temp_bullet.m_X, temp_bullet.m_Y, temp_bullet.m_Bullet);
    for (int i = 0; i < BULLET_NUM; i++)
    {
        // 如果子弹状态为非空，计算发射位置
        if (!m_hero.m_bullets[i].m_Free)
            painter.drawPixmap(m_hero.m_bullets[i].m_X, m_hero.m_bullets[i].m_Y, m_hero.m_bullets[i].m_Bullet);
    }

    // 绘制敌机
    for (int i = 0; i < ENEMY_NUM; i++)
    {
        // 如果子弹状态为非空，计算发射位置
        if (!m_enemys[i].m_Free)
            painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_enemy);
    }

    // 绘制爆炸图片
    for (int i = 0; i < BOMB_NUM; i++)
    {
        if (!m_bombs[i].m_Free)
            painter.drawPixmap(m_bombs[i].m_X, m_bombs[i].m_Y, m_bombs[i].m_pixArr[m_bombs[i].m_index]);
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_hero.m_Rect.width() * 0.5; // 鼠标位置 - 飞机矩形的一半
    int y = event->y() - m_hero.m_Rect.height() * 0.5;

    // 边界检测
    if (x <= 0)
        x = 0;

    if (x >= GAME_WIDTH - m_hero.m_Rect.width())
        x = GAME_WIDTH - m_hero.m_Rect.width();

    if (y <= 0)
        y = 0;

    if (y >= GAME_HEIGHT - m_hero.m_Rect.height())
        y = GAME_HEIGHT - m_hero.m_Rect.height();

    m_hero.setPosition(x, y);
}

void MainScene::enemyToScene()
{
    m_recorder++;
    if (m_recorder < ENEMY_INTERVAL)
        return;

    m_recorder = 0;

    for (int i = 0; i < ENEMY_NUM; i++)
    {
        if (m_enemys[i].m_Free)
        {
            // 敌机空闲状态改为false
            m_enemys[i].m_Free = false;

            // 设置坐标
            m_enemys[i].m_X = rand()%(GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    for (int i = 0; i < ENEMY_NUM; i++)
    {
        if(m_enemys[i].m_Free)
            continue;

        for (int j = 0; j < BULLET_NUM; j++)
        {
              if (m_hero.m_bullets[j].m_Free)
                  continue;

              if (m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
              {
                  // 消除碰撞的子弹和敌机
                  m_enemys[i].m_Free = true;
                  m_hero.m_bullets[j].m_Free = true;

                  // 播放爆炸效果
                  for (int k = 0; k < BOMB_NUM; k++)
                  {
                      if (m_bombs[k].m_Free)
                      {
                          // 爆炸状态设置为非空闲
                          m_bombs[k].m_Free = false;

                          // 更新坐标
                          m_bombs[k].m_X = m_enemys[i].m_X;
                          m_bombs[k].m_Y = m_enemys[i].m_Y;
                          break;
                      }
                  }

                  // 爆炸音效
                  QSound::play(SOUND_BOMB);
              }
        }
    }
}

