#include "EditorMain.h"
#include "ViewerWidget.h"
#include "FileManager.h"
#include "UIController.h"

EditorMain::EditorMain(QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::EditorMainClass()),
    m_viewerWidget(new ViewerWidget(this)),
    m_fileManager(new FileManager(this)),
    m_uiController(new UIController(this)) 
{
    ui->setupUi(this);
    setCentralWidget(m_viewerWidget);
}

EditorMain::~EditorMain()
{}