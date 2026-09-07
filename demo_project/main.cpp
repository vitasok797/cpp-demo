#include <./QApplication>
#include <./QPushButton>
#include <./QVBoxLayout>
#include <./QWidget>

auto main(int argc, char* argv[]) -> int
{
    auto app = QApplication(argc, argv);

    auto window = QWidget{};
    window.setWindowTitle("Minimal Qt app");
    window.resize(320, 240);

    auto* layout = new QVBoxLayout(&window);
    auto* button = new QPushButton("Close app", &window);

    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, &app, &QApplication::quit);

    window.show();
    return app.exec();
}
