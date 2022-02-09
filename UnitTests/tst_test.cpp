#include <QString>
#include <QtTest>

#include "filereadingutils.h"


// add necessary includes here

class Test : public QObject
{
    Q_OBJECT

private:
    const inline static QString MAIN_INDEX_RESOURCE = ":/Res/Templates/main_index.html";
    const inline static QString COMMENT_TEMPLATE_RESOURCE = ":/Res/Templates/comment_template.html";
    const inline static QString NEGATIVE_COMMENT_TEMPLATE_RESOURCE = ":/Res/Templates/comment_template_negative.html";
    const inline static QString COMMENT_TEXT_DISPLAY_TEMPLATE_RESOURCE = ":/Res/Templates/comment_text_display.html";
    const inline static QString COMMENT_HEADER_DISPLAY_TEMPLATE_RESOURCE = ":/Res/Templates/comment_header_display.html";
    const inline static QString TEST_RESOURCE = ":/Res/Templates/testFile.txt";
    const inline static QString TEST_HTML_RESOURCE = ":/Res/Templates/htmlTest.html";

private slots:
    void caseResources();
    void caseReadingUtils();
    void caseGenerationUtils();
};

void Test::caseResources()
{
    QString resources[] = { MAIN_INDEX_RESOURCE, COMMENT_TEMPLATE_RESOURCE, NEGATIVE_COMMENT_TEMPLATE_RESOURCE,
                            COMMENT_TEXT_DISPLAY_TEMPLATE_RESOURCE, COMMENT_HEADER_DISPLAY_TEMPLATE_RESOURCE };

    for(QString res_path : resources){
        QFile resource(res_path);

        QVERIFY2(resource.open(QIODevice::ReadOnly | QIODevice::Text), QString("Can't read %1").arg(res_path).toLocal8Bit().constData());
        resource.close();
    }
}

void Test::caseReadingUtils()
{
    QList<int> lines = {1, 2};

    QString result = FileReadingUtils::readGivenLines(&lines, TEST_RESOURCE);
    QVERIFY(result == "Line2\nLine3\n");
}

void Test::caseGenerationUtils()
{
    QString expected;
    QFile file(TEST_HTML_RESOURCE);

    file.open(QIODevice::ReadOnly);
    expected = file.readAll();
    file.close();


    QString input;
    QFile comment_temple_file(COMMENT_TEMPLATE_RESOURCE);

    comment_temple_file.open(QIODevice::ReadOnly);
    input = comment_temple_file.readAll();
    comment_temple_file.close();

    input =  input.replace("${code}", "code;");

    QVERIFY(expected == input);
}

QTEST_APPLESS_MAIN(Test)

#include "tst_test.moc"
