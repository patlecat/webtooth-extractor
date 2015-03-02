#ifndef CSVFILE_H
#define CSVFILE_H
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


#include <QObject>
#include <QMap>


// Implements CSV File handling according to RF4180 from the IETF
class CSVFile : public QObject
{
    Q_OBJECT
public:
    explicit CSVFile(QObject *parent = 0);
    ~CSVFile();

    bool WriteResultCSV(const QMap<QString, QString>& tbl_result, const QString& csvfilepath, const QString &csvSeparator);

signals:

public slots:

private:
    const QString endline = "\r\n"; // Standard end of line according to RFC4180
};

#endif // CSVFILE_H
