QT += qml quickcontrols2 sql

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    androidquirks.h \
    period.h \
    wrecord.h

SOURCES += \
        main.cpp \
        period.cpp \
        wrecord.cpp

RESOURCES += qml.qrc \
                        icons/index.theme \
                        $$files(icons/*.png, true)

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
unix:!macx:
{
    android:
    {
        DISTFILES += \
    android-sources/AndroidManifest.xml \
            android-sources/AndroidManifest.xml \
            android-sources/AndroidManifest.xml \
    android-sources/build.gradle \
            android-sources/build.gradle \
    android-sources/gradle.properties \
    android-sources/gradle/wrapper/gradle-wrapper.jar \
            android-sources/gradle/wrapper/gradle-wrapper.jar \
    android-sources/gradle/wrapper/gradle-wrapper.properties \
            android-sources/gradle/wrapper/gradle-wrapper.properties \
    android-sources/gradlew \
            android-sources/gradlew \
    android-sources/gradlew.bat \
            android-sources/gradlew.bat \
            android-sources/res/values/libs.xml \
    android-sources/res/values/libs.xml
        ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
        # déploie la base de données avec l'apk
        deployment.files += eWallet.sqlite
        deployment.path = /assets/db
        INSTALLS += deployment
    }
    !android:
    {
        # copie la base de données dans le dossier build
        CONFIG += file_copies
        COPIES += bd
        bd.files = eWallet.sqlite
        bd.path = $$OUT_PWD/
        bd.base = $$PWD/
    }
}

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_EXTRA_LIBS = \
        /home/sas/QT_projects/QT_quick/Qt_quick_tutorials/Qt_tutorial_12/../../../../Android/Sdk/android_openssl/latest/arm/libcrypto_1_1.so \
        /home/sas/QT_projects/QT_quick/Qt_quick_tutorials/Qt_tutorial_12/../../../../Android/Sdk/android_openssl/latest/arm/libssl_1_1.so \
        $$PWD/../../../../Android/Sdk/android_openssl/latest/arm64/libcrypto_1_1.so \
        $$PWD/../../../../Android/Sdk/android_openssl/latest/arm64/libssl_1_1.so
}
