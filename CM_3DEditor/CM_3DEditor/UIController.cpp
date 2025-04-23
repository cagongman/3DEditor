#include "UIController.h"
#include "EditorMain.h"
#include "Viewerwidget.h"
#include "Filemanager.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QAction>

UIController::UIController(QObject* parent)
    : QObject(parent) {}

void UIController::setupConnections(EditorMain* window, ViewerWidget* viewer, FileManager* fileManager) {
    QAction* openObj = window->menuBar()->addAction("Open OBJ...");
    QObject::connect(openObj, &QAction::triggered, [window, fileManager, viewer]() {
        QString fn = QFileDialog::getOpenFileName(window, "Open OBJ", "", "OBJ Files (*.obj)");
        if (!fn.isEmpty() && fileManager->loadOBJ(fn, viewer->GetScene())) {
            viewer->update();
        }
    });
    // TODO: add more UI actions
}