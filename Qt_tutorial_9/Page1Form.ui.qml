import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    property alias bubble: bubble
    property alias mainWindow: mainWindow

    header: Label {
        text: qsTr("Rotate the phone to move the bubble")
        font.pixelSize: Qt.application.font.pixelSize * 0.75
        padding: 5
    }

    Rectangle {
        id: mainWindow
        color: "#ffffff"
        anchors.fill: parent

        Bubble {
            id: bubble
        }
    }
}

/*##^##
Designer {
    D{i:2;anchors_height:200;anchors_width:200;anchors_x:200;anchors_y:74}
}
##^##*/

