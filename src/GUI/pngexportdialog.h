#ifndef PNGEXPORTDIALOG_H
#define PNGEXPORTDIALOG_H

#include <QDialog>
#include "margins.h"

class FileSelectWidget;
class QSpinBox;
class QCheckBox;

struct PNGExport
{
	QString fileName;
	QSize size;
	Margins margins;
	bool antialiasing;
};

class PNGExportDialog : public QDialog
{
	Q_OBJECT

public:
	PNGExportDialog(PNGExport &exp, QWidget *parent = 0);

public slots:
	void accept();

private:
	PNGExport &_export;

	FileSelectWidget *_fileSelect;
	QSpinBox *_width;
	QSpinBox *_height;
	QSpinBox *_topMargin;
	QSpinBox *_bottomMargin;
	QSpinBox *_leftMargin;
	QSpinBox *_rightMargin;
	QCheckBox *_antialiasing;
};

#endif // PNGEXPORTDIALOG_H
