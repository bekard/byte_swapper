#pragma once

#include <QLineEdit>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *a_pParent = nullptr);
    ~MainWindow() override = default;

private:
	void FillCentralLayout();
	void ConnectWidgets();
	void ConfigureMainWindow();

	bool AreAllFieldsFilled() const;

	QString GetFieldsErrorMsg() const;

private slots:
	void ChooseFileForSwap();
	void ChooseSwappedFile();

	void SwapBytes();

private:
    QWidget*		m_pCentralWidget;
    QGridLayout* 	m_pCentralLayout;

	QLabel*			m_pOriginalFileLabel;
	QLineEdit*		m_pOriginalFileNameEdit;
	QPushButton*	m_pOriginalFileChooseBtn;

	QLabel*			m_pSwappedFileLabel;
	QLineEdit*		m_pSwappedFileNameEdit;
	QPushButton*	m_pSwappedFileChooseBtn;

    QLabel*			m_pMethodLabel;
    QComboBox*		m_pMethodsBox;
    QPushButton*	m_pAddMethodButton;

    QPushButton*	m_pSwapButton;
};

void ShowErrorMsg(const QString& a_qsTitle, const QString& a_qsMsg);
