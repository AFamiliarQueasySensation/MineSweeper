#include "mainwindow.h"
#include "ui_mainwindow.h"

#define RES_WIDTH 625
#define RES_LENGTH 1110

#define LEN_HOR 30
#define LEN_VER 16

#define MAXIMUM (LEN_HOR * LEN_VER) // ALSO last position in the map

#define BOMB_COUNT 99

#define BUTTON_SIZE 35

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setFixedSize(RES_LENGTH, RES_WIDTH);
    this->setWindowTitle(QString("Mine Sweeper"));
    QSignalMapper *signalMapper = new QSignalMapper;

    // Creates the Table and mapps them all and connects them with a signal mapper
    // Just using simpliestic Multiply by row add by column logic
    for (int j = 0; j < LEN_HOR; j++)
    {
        for (int i = 0; i < LEN_VER; i++)
        {
            PushButton *button = new PushButton(this);
            button->setGeometry(LEN_VER + (BUTTON_SIZE + 1) * j, LEN_HOR + i * (BUTTON_SIZE + 1), BUTTON_SIZE, BUTTON_SIZE);
            push_button_map[j + i * LEN_HOR] = button;
            connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(button, j + i * LEN_HOR);
        }
    }

    randomBombMaker();
    connect(signalMapper, &QSignalMapper::mappedInt, this, &MainWindow::onLeftMouseClicked);
}

// Death Screne Message Box
void MainWindow::loseMenu()
{
    QMessageBox msgBox;
    msgBox.setText("You Died");
    msgBox.setInformativeText("Would you like to play again?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int rec = msgBox.exec();
    switch (rec)
    {
    case QMessageBox::Yes:
        restartGame();
        break;
    case QMessageBox::No:

        QApplication::quit();
        break;
    }
}

// Win Screne Message Box
void MainWindow::winMenu()
{
    QMessageBox msgBox;
    msgBox.setText("You Win!!");
    msgBox.setInformativeText("Would you like to play again?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int rec = msgBox.exec();
    switch (rec)
    {
    case QMessageBox::Yes:

        restartGame();
        break;
    case QMessageBox::No:

        QApplication::quit();
        break;
    }
}

// This clears everything in the game, and then remakes the bombs n stuff
void MainWindow::restartGame()
{
    for (auto &i : push_button_map)
    {
        i->initializeButton();
        i->setText("");
        i->setVisible(true);
    }
    win_counter = 0;
    randomBombMaker();
}

// Generates random bombs on the grid
void MainWindow::randomBombMaker()
{

    // Needed because apparenlty need to see for randomness
    srand(time(0));

    std::array<int, BOMB_COUNT> temp = {};

    for (int i = 0; i < BOMB_COUNT; i++)
    {

        int random = rand() % MAXIMUM;

        // Checks if random is in the array (already used position)
        while (std::find(temp.begin(), temp.end(), random) != temp.end())
        {
            random = (random + 7) % MAXIMUM;
        }

        temp[i] = random;
        push_button_map[random]->setBombFlag();

        // Setting up near by bombs on grid

        // LEFT
        if (random - 1 >= 0 && random % LEN_HOR != 0 && random != 0)
        {
            push_button_map[random - 1]->addNearBomb();
        }
        // RIGHT
        if (random + 1 <= MAXIMUM && (random + 1) % LEN_HOR != 0)
        {
            push_button_map[random + 1]->addNearBomb();
        }

        // UP
        if (random - LEN_HOR >= 0)
        {
            push_button_map[random - LEN_HOR]->addNearBomb();
        }
        // DOWN
        if (random + LEN_HOR < MAXIMUM)
        {
            push_button_map[random + LEN_HOR]->addNearBomb();
        }
        // UP LEFT
        if (random - LEN_HOR - 1 >= 0 && random % LEN_HOR != 0 && random - 1 != 0)
        {
            push_button_map[random - LEN_HOR - 1]->addNearBomb();
        }
        // UP RIGHT
        if (random - LEN_HOR + 1 >= 0 && (random + 1) % LEN_HOR != 0)
        {
            push_button_map[random - LEN_HOR + 1]->addNearBomb();
        }
        // DOWN LEFT
        if (random + LEN_HOR < MAXIMUM && random % LEN_HOR != 0)
        {
            push_button_map[random + LEN_HOR - 1]->addNearBomb();
        }

        // DOWN RIGHT
        if (random + LEN_HOR + 1 < MAXIMUM && (random + 1) % LEN_HOR != 0)
        {
            push_button_map[random + LEN_HOR + 1]->addNearBomb();
        }
    }
}

// Win by finding how many square and subtracting amount of bombs deployed
inline void MainWindow::checkWin()
{
    // You win menu
    if (win_counter == (LEN_HOR * LEN_VER) - BOMB_COUNT)
    {
        winMenu();
    }
}

// Recursively finds all of the empty squares
void MainWindow::findOtherEmptySquares(int random)
{

    // Empty Squares
    if (push_button_map[random]->nearBombCount() == 0)
    {
        if (!push_button_map[random]->isPressed())
        {
            win_counter++;
            push_button_map[random]->setPressed();
            checkWin();
            // qDebug() << win_counter;
        }
    }
    // Bass
    // You Pressed on a bomb
    if (push_button_map[random]->getBombFlag())
    {
        loseMenu();
        return;
    }

    // More than one near bomb count
    if (push_button_map[random]->nearBombCount() > 0)
    {
        if (!push_button_map[random]->isPressed())
        {
            win_counter++;
            push_button_map[random]->setPressed();
            checkWin();
        }
        // qDebug() << win_counter;
        return;
    }

    else
    {

        // UP
        if (random - LEN_HOR >= 0 && !push_button_map[random - LEN_HOR]->isPressed())
        {
            findOtherEmptySquares(random - LEN_HOR);
        }
        // LEFT
        if (random - 1 >= 0 && random % LEN_HOR != 0 && random != 0 && !push_button_map[random - 1]->isPressed())
        {
            findOtherEmptySquares(random - 1);
        }

        // RIGHT
        if (random + 1 <= MAXIMUM && (random + 1) % LEN_HOR != 0 && !push_button_map[random + 1]->isPressed())
        {
            findOtherEmptySquares(random + 1);
        }

        // DOWN
        if (random + LEN_HOR < MAXIMUM && !push_button_map[random + LEN_HOR]->isPressed())
        {
            findOtherEmptySquares(random + LEN_HOR);
        }

        // UP LEFT
        if (random - LEN_HOR - 1 >= 0 && random % LEN_HOR != 0 && random - 1 != 0 && !push_button_map[random - LEN_HOR - 1]->isPressed())
        {
            findOtherEmptySquares(random - LEN_HOR - 1);
        }
        // UP RIGHT
        if (random - LEN_HOR + 1 >= 0 && (random + 1) % LEN_HOR != 0 && !push_button_map[random - LEN_HOR + 1]->isPressed())
        {
            findOtherEmptySquares(random - LEN_HOR + 1);
        }
        // DOWN LEFT
        if (random + LEN_HOR - 1 < MAXIMUM && random % LEN_HOR != 0 && !push_button_map[random + LEN_HOR - 1]->isPressed())
        {
            findOtherEmptySquares(random + LEN_HOR - 1);
        }

        // DOWN RIGHT
        if (random + LEN_HOR + 1 < MAXIMUM && (random + 1) % LEN_HOR != 0 && !push_button_map[random + LEN_HOR + 1]->isPressed())
        {
            findOtherEmptySquares(random + LEN_HOR + 1);
        }
    }
}

void MainWindow::onRightMouseClicked(int button_num)
{
    // qDebug() << button_num << " : Right mouse clicked";
}

// From PushButtonReleaseevent Emitted into this, on left mouse button
void MainWindow::onLeftMouseClicked(int button_num)
{

    // qDebug() << button_num << " : Left mouse clicked= " << push_button_map[button_num]->getFlagged();
    findOtherEmptySquares(button_num);
}

// Not sure if I need this
void MainWindow::onRightClicked0()
{
    onRightMouseClicked(0);
}

void MainWindow::onLeftClicked0()
{
    onLeftMouseClicked(0);
}

MainWindow::~MainWindow()
{
}
