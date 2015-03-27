/*
This file is part of WebTooth-Extractor and for personal use the
GPL3 license applies. For any kind of commercial usage, you have to
acquire a commercial license before use. The copyright of the WebTooth
application and source code remains with Patrick Scheller and any
contributor to the project agrees with his commits to renounce to the
copyright of his parts completely.

WebTooth-Extractor is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License.

WebTooth-Extractor is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with WebTooth-Extractor. If not, see http://www.gnu.org/licenses/ .
*/

#include <QStandardPaths>
#include <QFileDialog>
#include <QDateTime>
#include <QDebug>

#include "properties.h"
#include "ui_properties.h"

Properties::Properties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Properties),
    sUrlPath(""),
    bCropThumb(true),
    thumbHeight(500),
    thumbWidth(300),
    sAuthor(""),
    sProjectNotes(""),
    uProjectUrl(""),
    sLastModificationDate(""),
    csvSeparator(",")
{
    ui->setupUi(this);

    QDateTime now = QDateTime::currentDateTime();
    //sLastModificationDate = now.toString(Qt::ISODate);
    //ui->lineEditLastModificationDate->setText(sLastModificationDate);
    hProjectData.insert("projectapp", "WebTooth-Extractor"); // Name of this application
    hProjectData.insert("projectname", ""); // Project-File-Name
    hProjectData.insert("projectauthor", "");
    hProjectData.insert("projectmodified", ""); // Date of last saved modification
    hProjectData.insert("projecnotes", "");
    hProjectData.insert("projecturl", "");
    hProjectData.insert("cropthumb", "true"); // true or falsse
    hProjectData.insert("thumbwidth", "300"); // in pixels
    hProjectData.insert("thumbheight", "500"); // in pixels
    hProjectData.insert("csvseparator", ","); // in pixels
}

Properties::~Properties()
{
    delete ui;
}

// Save-Button
void Properties::on_buttonBox_accepted()
{
    this->sUrlPath = ui->lineEdit_URL->text();
    bCropThumb = ui->checkBoxCropThumb->isChecked();
    thumbHeight = ui->spinBoxThumbHeight->value();
    thumbWidth = ui->spinBoxThumbWidth->value();
    sAuthor = ui->lineEditAuthorName->text();
    sProjectNotes = ui->plainTextEditUserNotes->toPlainText();
    csvSeparator = ui->lineEditCSVSeparator->text();

    hProjectData["projectauthor"] = sAuthor;
    hProjectData["projecnotes"] = sProjectNotes;
    hProjectData["projecturl"] = sUrlPath;
    hProjectData["cropthumb"] = (bCropThumb ? "true" : "false");
    hProjectData["thumbwidth"] = QString::number(thumbWidth);
    hProjectData["thumbheight"] = QString::number(thumbHeight);
    hProjectData["csvseparator"] = csvSeparator;
}

// Load after an OpenFile
void Properties::LoadData(void)
{
    sAuthor = hProjectData["projectauthor"];
    sProjectNotes = hProjectData["projecnotes"];
    sUrlPath = hProjectData["projecturl"];
    bCropThumb = (hProjectData["cropthumb"] == "true" ? true : false);
    thumbWidth = hProjectData["thumbwidth"].toShort();
    thumbHeight = hProjectData["thumbheight"].toShort();
    csvSeparator = hProjectData["csvseparator"];
    //qDebug() << "Properties:" << sAuthor << ", " << sProjectNotes << ", " << sUrlPath << ", " << (bCropThumb ? "true" : "false") << ", "
    //         << QString::number(thumbWidth) << ", " << QString::number(thumbHeight);

    ui->lineEdit_URL->setText(this->sUrlPath);
    ui->checkBoxCropThumb->setChecked(bCropThumb);
    ui->spinBoxThumbHeight->setValue(thumbHeight);
    ui->spinBoxThumbWidth->setValue(thumbWidth);
    ui->lineEditAuthorName->setText(sAuthor);
    ui->plainTextEditUserNotes->setPlainText(sProjectNotes);
    ui->lineEditCSVSeparator->setText(csvSeparator);
}

void Properties::on_toolButton_clicked()
{
    // Call the URL-FileDialog
    QUrl homePath(QStandardPaths::locate(QStandardPaths::DocumentsLocation, QString(), QStandardPaths::LocateDirectory));
    QUrl urlpath = QFileDialog::getOpenFileUrl(this, "Open URL Or Local HTML File", homePath, "HTML File (*.html *.htm);;Text Files (*.txt);;All Files (*.*)");

    if (!urlpath.isEmpty())
        ui->lineEdit_URL->setText(urlpath.toString());

}
qint16 Properties::getThumbWidth() const
{
    return thumbWidth;
}

void Properties::setThumbWidth(const qint16 &value)
{
    thumbWidth = value;
}

qint16 Properties::getThumbHeight() const
{
    return thumbHeight;
}

void Properties::setThumbHeight(const qint16 &value)
{
    thumbHeight = value;
}

bool Properties::getBCropThumb() const
{
    return bCropThumb;
}

void Properties::setBCropThumb(bool value)
{
    bCropThumb = value;
}

QString Properties::getSLastModificationDate() const
{
    return sLastModificationDate;
}

void Properties::setSLastModificationDate(const QString &value)
{
    sLastModificationDate = value;
    ui->lineEditLastModificationDate->setText(sLastModificationDate);
}

QString Properties::getSUserNotes() const
{
    return sUserNotes;
}

void Properties::setSUserNotes(const QString &value)
{
    sUserNotes = value;
}

QString Properties::getSAuthorName() const
{
    return sAuthorName;
}

void Properties::setSAuthorName(const QString &value)
{
    sAuthorName = value;
}

QString Properties::getSUrlPath() const
{
    return sUrlPath;
}

void Properties::setSUrlPath(const QString &value)
{
    sUrlPath = value;
}


void Properties::on_checkBoxCropThumb_toggled(bool checked)
{
    if (checked)
    {
        //ui->spinBoxThumbHeight->setReadOnly(false);
        ui->spinBoxThumbHeight->setEnabled(true);
    }
    else
    {
        //ui->spinBoxThumbHeight->setReadOnly(true);
        ui->spinBoxThumbHeight->setEnabled(false);
    }
}
QString Properties::getCsvSeparator() const
{
    return csvSeparator;
}

void Properties::setCsvSeparator(const QString &value)
{
    csvSeparator = value;
}

