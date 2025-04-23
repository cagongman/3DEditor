#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EditorMain.h"

class ViewerWidget;
class FileManager;
class UIController;

class EditorMain : public QMainWindow
{
    Q_OBJECT

public:
    EditorMain(QWidget *parent = nullptr);
    ~EditorMain();

private:
    Ui::EditorMainClass ui;

    ViewerWidget* m_viewer;
    FileManager* m_fileManager;
    UIController* m_uiController;
};
