#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char* argv[]) {

    /*
     * `QApplication` 的作用：
     * 1. 初始化 Qt 应用所需要的资源，比如字体、颜色、事件循环、样式等等
     * 2. 管理主事件循环
     * 3. 管理应用级别的资源，比如所有的窗口、构件、信号、槽等等
     */
    QApplication app(argc, argv);

    // NOTE: Qt 的构件建议使用指针，因为它们都是 `QObject` 的子类
    // NOTE: 指针不用手动释放，在 `app.exec()` 结束后自动释放

    /*
     * `QLineEdit` 表示行输入编辑器，即输入一行的那种输入框
     */
    QLineEdit* id_input = new QLineEdit();
    QLineEdit* password_input = new QLineEdit();

    id_input->setText("Enter your ID: ");
    password_input->setText("Enter your password: ");

    /*
     * `QPushButton` 是按钮，用鼠标点击的那种按钮
     */
    QPushButton* commit_button = new QPushButton();
    QPushButton* cancel_button = new QPushButton();

    commit_button->setText("Commit");
    cancel_button->setText("Cancel");

    /*
     * `QLabel` 是一个显示型构件，不响应用户输入，只负责展示信息
     */
    QLabel* label = new QLabel();
    label->setText("Enter your information");

    // NOTE: 初始化好了构件就需要进行布局了，有两种布局方式：水平布局和垂直布局

    /*
     * 输入 ID 和 password 的构件应该是垂直的
     * 所以使用 `QVBoxLayout`
     */
    QVBoxLayout* login_info = new QVBoxLayout();
    login_info->addWidget(id_input);
    login_info->addWidget(password_input);

    /*
     * commit button 和 cancel button 应该是水平的
     * 所以应该使用 `QHBoxLayout`
     */
    QHBoxLayout* instruction_buttons = new QHBoxLayout();
    instruction_buttons->addWidget(commit_button);
    instruction_buttons->addWidget(cancel_button);

    /*
     * 还缺少一个主布局，将所有的小布局连接起来
     * 主布局应该是垂直的，使用 `QVBoxLayout`
     * NOTE: 添加 widget 和添加 layout 的方法是不同的
     */
    QVBoxLayout* main_layout = new QVBoxLayout();
    main_layout->addWidget(label);
    main_layout->addLayout(login_info);
    main_layout->addLayout(instruction_buttons);

    // NOTE: 通过 `Widget` 创建窗口，连接主布局然后显示，否则布局不会显示出来
    QWidget *window = new QWidget();
    window->setLayout(main_layout);
    window->setWindowTitle("QQ Login System");
    window->show();

    return app.exec();
}


