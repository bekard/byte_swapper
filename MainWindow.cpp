#include <QFileDialog>
#include <QMessageBox>

#include "consts.h"
#include "MainWindow.h"
#include "swaps.h"

MainWindow::MainWindow(QWidget *a_pParent)
	: QMainWindow(a_pParent),
	  m_pCentralWidget(new QWidget),
	  m_pCentralLayout(new QGridLayout),
	  m_pOriginalFileLabel(new QLabel("File to Swap:")),
	  m_pOriginalFileNameEdit(new QLineEdit),
	  m_pOriginalFileChooseBtn(new QPushButton("Choose")),
	  m_pSwappedFileLabel(new QLabel("Swapped File:")),
	  m_pSwappedFileNameEdit(new QLineEdit),
	  m_pSwappedFileChooseBtn(new QPushButton("Choose")),
	  m_pMethodLabel(new QLabel("Swap Method:")),
	  m_pMethodsBox(new QComboBox),
	  m_pAddMethodButton(new QPushButton("Add")),
	  m_pSwapButton(new QPushButton("Swap!"))
{
	FillCentralLayout();
	ConnectWidgets();
	ConfigureMainWindow();
}

void MainWindow::FillCentralLayout()
{
	m_pCentralLayout->addWidget(m_pOriginalFileLabel, 0, 0);
	m_pCentralLayout->addWidget(m_pOriginalFileNameEdit, 1, 0); m_pOriginalFileNameEdit->setText("C:\\usr\\test swap\\test1.dat");
	m_pCentralLayout->addWidget(m_pOriginalFileChooseBtn, 1, 1);

	m_pCentralLayout->addWidget(m_pSwappedFileLabel, 2, 0);
	m_pCentralLayout->addWidget(m_pSwappedFileNameEdit, 3, 0); m_pSwappedFileNameEdit->setText("C:\\usr\\test swap\\test1 - swapped.dat");
	m_pCentralLayout->addWidget(m_pSwappedFileChooseBtn, 3, 1);

	m_pCentralLayout->addWidget(m_pMethodLabel, 4, 0);
	m_pMethodsBox->addItems(GetDefaultMethodsList());
	m_pMethodsBox->setEnabled(false);
	m_pCentralLayout->addWidget(m_pMethodsBox, 5, 0);
	m_pCentralLayout->addWidget(m_pAddMethodButton, 5, 1);

	m_pCentralLayout->addWidget(m_pSwapButton, 6, 0, Qt::AlignHCenter);

	m_pCentralWidget->setLayout(m_pCentralLayout);
}

void MainWindow::ConnectWidgets()
{
	QObject::connect(m_pOriginalFileChooseBtn, SIGNAL(clicked()), this, SLOT(ChooseFileForSwap()));
	QObject::connect(m_pSwappedFileChooseBtn, SIGNAL(clicked()), this, SLOT(ChooseSwappedFile()));
	QObject::connect(m_pSwapButton, SIGNAL(clicked()), this, SLOT(SwapBytes()));
}

void MainWindow::ConfigureMainWindow()
{
	setCentralWidget(m_pCentralWidget);
	setFixedSize(450, 170);
}

bool MainWindow::AreAllFieldsFilled() const
{
	return	!m_pOriginalFileNameEdit->text().isEmpty() &&
			!m_pSwappedFileChooseBtn->text().isEmpty();
}

QString MainWindow::GetFieldsErrorMsg() const
{
	QString qsMsg;
	if(m_pOriginalFileNameEdit->text().isEmpty()) {
		qsMsg += "- The file name for the bytes flip is not specified\n";
	}
	if(m_pSwappedFileNameEdit->text().isEmpty()) {
		qsMsg += "- The name of the file to which new data will be written is not specified\n";
	}
	return qsMsg;
}

void MainWindow::ChooseFileForSwap()
{
	const QString qsFileName(QFileDialog::getOpenFileName(this, "Choose File for Swap"));
	m_pOriginalFileNameEdit->setText(qsFileName);
}

void MainWindow::ChooseSwappedFile()
{
	const QString qsFileName(QFileDialog::getSaveFileName(this, "Choose Name for Swapped File"));
	m_pSwappedFileNameEdit->setText(qsFileName);
}

void MainWindow::SwapBytes()
{
	if(AreAllFieldsFilled()) {
		SwapInFile(
			m_pOriginalFileNameEdit->text().toStdString(),
			m_pSwappedFileNameEdit->text().toStdString(),
			std::vector<size_t>{1,0}
		);
	} else {
		ShowErrorMsg("Error", GetFieldsErrorMsg());
	}
}

void ShowErrorMsg(const QString& a_qsTitle, const QString& a_qsMsg)
{
	QMessageBox MsgBox(QMessageBox::Warning, a_qsTitle, a_qsMsg);
	MsgBox.exec();
}
