#ifndef TESTEXAMPLE
#define TESTEXAMPLE

#include "autotest.h"

class TestExample : public QObject
{
    Q_OBJECT
public:

private slots:
    void initTestCase() {
        //Initialise test if required
    }

    void testWorking() {
        QVERIFY(true);
    }

    void testFail() {
        QVERIFY2(false,"This test should fail");
    }

    void cleanupTestCase() {
        //Cleanup test if required
    }
};

DECLARE_TEST(TestExample)

#endif // TESTEXAMPLE
