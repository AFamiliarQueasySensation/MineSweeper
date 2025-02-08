#include "pushbutton.h"

#define BUTTON_LEN 50
#define BUTTON_WID 50

PushButton::PushButton(QWidget *parent)
    : QPushButton(parent)
{
    initializeButton();
}

/**
 * Initializes a button for the Constructor, as well as restart game
 */
void PushButton::initializeButton()
{
    setObjectName("regularButton");
    setStyleSheet(
        "QPushButton#regularButton {"
        "   color : black;"
        "   background-color : white;"
        "   border-style : outset;"
        "   border-width : 2px;"
        "   border-radius : 2.5px;"
        "   border-color : gray;"

        "}");
    retain = sizePolicy();
    retain.setRetainSizeWhenHidden(true);
    isbomb = false;
    nearbomb = 0;
    flagged = false;
    pressed = false;
    questioned = false;
}

void PushButton::setButtonGeometry(QPoint point)
{
    setGeometry(QRect(point, QSize(BUTTON_LEN, BUTTON_WID)));
}

// Doesn't do much
void PushButton::mousePressEvent(QMouseEvent *event) {}

// Removes drop shadow when you release it
void PushButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        if (!pressed)
        {

            if (!getFlagged() && !isQuestioned())
            {
                setFlagged();
                setText("F");
            }
            else if (getFlagged() && !isQuestioned())
            {
                setQuestioned();
                this->flagged = false;
                setText("?");
            }
            else
            {
                this->questioned = false;
                setText("");
            }
        }
    }

    if (event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}

void PushButton::setPressed()
{
    if (!isbomb && nearbomb == 0)
    {
        setVisible(false);
    }

    pressed = true;
    setGraphicsEffect(nullptr);
    setStyleSheet(

        "QPushButton#regularButton {"
        "   background-color : gray;"
        "   border-style : outset;"
        "   border-width : 2px;"
        "   border-radius : 2.5px;"
        "   border-color : gray;"
        "}"

    );

    if (isbomb)
    {
        setStyleSheet("background-image : url(../resources/mine.png)");
    }

    if (nearbomb > 0)
    {
        setText(QString::fromStdString(std::to_string(nearbomb)));
    }
}

bool PushButton::isPressed()
{
    return pressed;
}

void PushButton::setBombFlag()
{
    // 2 setText("B");
    isbomb = true;
}

void PushButton::resetBombFlag()
{
    isbomb = false;
}

int PushButton::nearBombCount()
{
    return nearbomb;
}

void PushButton::addNearBomb()
{
    if (!isbomb)
    {
        nearbomb += 1;

    }
}

void PushButton::resetNearBomb()
{
    nearbomb = 0;
}

bool PushButton::getBombFlag()
{
    return isbomb;
}

void PushButton::setFlagged()
{
    flagged = true;
}

bool PushButton::getFlagged()
{
    return flagged;
}

void PushButton::resetFlagged()
{
    flagged = false;
}

void PushButton::setQuestioned()
{
    this->questioned = true;
}

bool PushButton::isQuestioned()
{
    return this->questioned;
}

PushButton::~PushButton() {}
