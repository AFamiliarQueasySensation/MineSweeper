#pragma once
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QDebug>
#include <iostream>
#include <QSizePolicy>

class PushButton : public QPushButton
{

    Q_OBJECT

private:
    bool isbomb;
    int nearbomb;
    bool flagged;
    bool pressed;
    bool questioned;
    QSizePolicy retain;

public:
    explicit PushButton(QWidget *parent = nullptr);
    void setButtonGeometry(QPoint point);

    void setPressed();
    bool isPressed();

    void setBombFlag();
    void resetBombFlag();
    int nearBombCount();
    void addNearBomb();
    void resetNearBomb();
    bool getBombFlag() const;
    void setFlagged();
    bool getFlagged() const;
    void resetFlagged();
    void initializeButton();

    bool isQuestioned();
    void setQuestioned();

    ~PushButton();

private slots:
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void clicked();
    void clic_droit();
};