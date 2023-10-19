#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPainter>
#include <QList>
#include <QTimer>
#include <QKeyEvent>
#include <QString>
#include <QRandomGenerator>
#include <QObject>

class SnakeItem;
class Snake;
class GameField;

class SnakeItem
{
    friend Snake;
    friend GameField;
public:
    SnakeItem(int x, int y);
private:
    int m_x;
    int m_y;
};

class Snake
{
    friend GameField;
public:
    Snake();
private:
    QList<SnakeItem*> m_snakeBody;
    int m_snakeBeingSize;
    enum SnakeDirection
    {
        up,
        left,
        down,
        right
    };
    SnakeDirection m_snake_Direction;
};

class GameField : public QWidget
{
   Q_OBJECT

public:
    GameField();
    virtual ~GameField();
protected:
    virtual void paintEvent(QPaintEvent *e) override;
    virtual void keyPressEvent(QKeyEvent *e) override;
private:
    Snake *m_snake;
    SnakeItem *m_food;
    int m_snakeItemSize;
    QTimer *m_moveSnakeTimer;
    int m_score;
    int m_fieldSize;
    bool m_isPause;
    bool m_isMoveBlocked;
    bool m_isGameOver;
    void StartNewGame();
    void CreateFood();
    void SetGameStatus();
    void GameOver();
private slots:
    void MoveSnakesSlot();
signals:
    void ChangeTextSignal(QString text);
};

#endif // GAME_H
