# AutoTest

AutoTest is a simple project inclusion that allows simple invokation of multiple
unit tests within Qt Creator.

This repository has been created to permit use of the `AutoTest` setup as a
Git submodule.

Further information is available at the `Source` line below.

## Usage
* Add the submodule to the project.
  `$ git submodule add https://bitbucket.org/cadcoder/autotest`
* Create the **Test** project as a *console* base app.
* Adjust the project file `.pro` to reflect the following options:
```
QT += testlib
QT -= gui

CONFIG += console
CONFIG -= app_bundle
```
* The **AutoTest** submodule includes the necessary main application entry
point (within the `main.cpp`) file. Remove the auto-generated `main.cpp` file if
it exists.
* Add inclusion file (`.pri`) to the project file (`.pro`). For example:
  `include(../autotest/AutoTest.pri)`
* Create test files similar to the example file below.
* Run the **Test** project and review output.

### Example Test File

```C++
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

```

### Example Output
```
********* Start testing of TestExample *********
Config: Using QtTest library 5.4.0, Qt 5.4.0 (x86_64-little_endian-lp64 shared (dynamic) release build; by Clang 6.0 (clang-600.0.54) (Apple))
PASS   : TestExample::initTestCase()
PASS   : TestExample::testWorking()
FAIL!  : TestExample::testFail() 'false' returned FALSE. (This test should fail)
Loc: [./../autotest/testexample.h(21)]
PASS   : TestExample::cleanupTestCase()
Totals: 3 passed, 1 failed, 0 skipped, 0 blacklisted
********* Finished testing of TestExample *********
```

### Source

>Qt Creator Blog: Running Multiple Unit Tests. 2015. Qt Creator Blog: Running Multiple Unit Tests. [ONLINE] Available at: http://qtcreator.blogspot.com.au/2009/10/running-multiple-unit-tests.html. [Accessed 2012].