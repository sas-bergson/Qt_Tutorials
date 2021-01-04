import QtQuick 2.2
import QtQuick.Controls 2.2

Page {
    id: page
    visible: true
    anchors.fill: parent
    title: qsTr("Hello World")

    Column {
        id: main_container
        spacing: 5
        anchors.fill: parent

        Row {
            id: header
            height: parent.height * 0.071
            width: parent.width

            Rectangle {
                height: parent.height
                width: 4 * parent.width / 5
                color: "teal"
                anchors.leftMargin: 8
                anchors.left: parent.left
                Text {
                    id: menu_btn
                    anchors.centerIn: parent
                    text: qsTr("OpenWallet (" + Math.round(
                                   parent.height) + "x" + Math.round(
                                   parent.width) + ")")
                }
            }
            Rectangle {
                id: rectangle
                height: parent.height
                width: parent.width / 5
                color: "skyblue"
                anchors.rightMargin: 8
                anchors.right: parent.right
                ToolButton {
                    id: logo
                    anchors.centerIn: parent
                    text: qsTr("(" + Math.round(
                                   parent.height) + "x" + Math.round(
                                   parent.width) + ")⋮")
                }
            }
        }

        ScrollView {
            id: scrollView
            width: parent.width
            height: parent.height * 0.78
            contentWidth: width
            contentHeight: height * 2
            anchors.top: header.bottom
            anchors.topMargin: 8
            clip: true
            ListView {
                id: listView
                model: 200
                delegate: ItemDelegate {
                    text: "Item " + index
                }
            }
        }

        Row {
            id: footer
            height: parent.height * 0.1
            anchors.top: scrollView.bottom
            anchors.topMargin: 8
            width: parent.width

            Rectangle {
                height: parent.height
                width: 49 * parent.width / 101
                color: "skyblue"
                anchors.leftMargin: 8
                anchors.left: parent.left
                ToolButton {
                    id: left_btn
                    anchors.centerIn: parent
                    text: qsTr("left(" + Math.round(
                                   parent.height) + "x" + Math.round(
                                   parent.width) + ")⋮")
                }
            }
            Rectangle {
                height: parent.height
                width: 49 * parent.width / 101
                color: "skyblue"
                anchors.rightMargin: 8
                anchors.right: parent.right
                ToolButton {
                    id: right_btn
                    anchors.centerIn: parent
                    text: qsTr("right(" + Math.round(
                                   parent.height) + "x" + Math.round(
                                   parent.width) + ")⋮")
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.6600000262260437;height:480;width:640}D{i:8;anchors_height:480;anchors_width:640}
}
##^##*/

