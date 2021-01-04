import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Hello World From Qt Quick")
        font.pixelSize: Qt.application.font.pixelSize * 0.75
        padding: 5
    }

    Label {
        text: qsTr("Hello World !!!! You are on Page 2.")
        anchors.centerIn: parent
    }
}
