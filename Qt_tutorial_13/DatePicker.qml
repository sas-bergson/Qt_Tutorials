import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import Qt.labs.calendar 1.0

GroupBox {
    anchors.fill: parent

    property string selected_date
    property string selected_year

    onSelected_dateChanged: console.log("new selection = ", selected_date)
    onSelected_yearChanged: console.log("new selection = ", selected_year)

    background: Rectangle {
        color: "transparent"
        border.color: "#21be2b"
        border.width: 2
        radius: 4
    }

    ColumnLayout {
        Frame {
            id: calendar_title_row
            spacing: 5
            Layout.fillWidth: true
            background: Rectangle {
                color: "transparent"
                border.color: "#21be2b"
                border.width: 2
                radius: 4
            }
            RoundButton {
                id: calendar_title_left_btn
                radius: 5
                text: qsTr("\u2329")
                font.bold: true
                width: month_grid.width * 0.2
            }
            RowLayout {
                id: calendar_title_label
                spacing: 5
                RoundButton {
                    id: calendar_month_btn
                    radius: 2.5
                    Text {
                        anchors.fill: parent
                        text: '<b>' + "0" + '</b>'
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        color: "#0000FF"
                    }
                }
                RoundButton {
                    id: calendar_year_btn
                    radius: 2.5
                    Text {
                        anchors.fill: parent
                        text: '<b>' + "2021" + '</b>'
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        color: "#0000FF"
                    }
                }
            }
            RoundButton {
                id: calendar_title_right_btn
                radius: 5
                text: qsTr("\u232A")
                font.bold: true
            }
        }
    }
}
