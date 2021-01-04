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

        Column {
            id: question_content
            width: parent.width
            height: parent.height * 0.8
            spacing: 5

            ScrollView {
                id: scrollView
                width: parent.width
                height: parent.height
                contentWidth: width
                contentHeight: height * 2
                anchors.top: parent.top
                anchors.topMargin: 0
                clip: true
                Rectangle {
                    id: r1
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 1(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: r2
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.top: r1.bottom
                    anchors.topMargin: 8
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 2(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: r3
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.top: r2.bottom
                    anchors.topMargin: 8
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 3(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: r4
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.top: r3.bottom
                    anchors.topMargin: 8
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 4(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: r5
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.top: r4.bottom
                    anchors.topMargin: 8
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 5(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: r6
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.top: r5.bottom
                    anchors.topMargin: 8
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 6(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: r7
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.top: r6.bottom
                    anchors.topMargin: 8
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 7(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: r8
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.top: r7.bottom
                    anchors.topMargin: 8
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 8(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: r9
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.top: r8.bottom
                    anchors.topMargin: 8
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 9(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: r10
                    height: 100
                    width: parent.width
                    color: "darkcyan"
                    anchors.top: r9.bottom
                    anchors.topMargin: 8
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                    anchors.rightMargin: 8
                    anchors.right: parent.right
                    Text {
                        text: qsTr("question item 10(" + Math.round(
                                       parent.height) + "x" + Math.round(
                                       parent.width) + ")")
                        font.family: "Helvetica"
                        font.pointSize: 24
                        color: "red"
                        anchors.centerIn: parent
                    }
                }
            }

            Row {
                id: footer
                height: parent.height * 0.1
                anchors.top: scrollView.bottom
                anchors.topMargin: 5
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
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.6600000262260437;height:480;width:640}
}
##^##*/

