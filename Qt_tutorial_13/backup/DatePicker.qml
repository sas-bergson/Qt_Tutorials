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
        Row {
            id: calendar_title_row
            spacing: 5
            Layout.fillWidth: true
            RoundButton {
                id: calendar_title_left_btn
                radius: 5
                text: qsTr("\u2329")
                font.bold: true
                width: month_grid.width * 0.2
                onClicked: {
                    if (month_grid.month > -1)
                        month_grid.month--
                    else {
                        month_grid.year--
                        month_grid.month = 12
                    }
                }
            }
            RowLayout {
                id: calendar_title_label
                spacing: 5
                RoundButton {
                    id: calendar_month_btn
                    radius: 2.5
                    width: month_grid.width * 0.3
                    Text {
                        anchors.fill: parent
                        text: '<b>' + month_grid.month + '</b>'
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        color: "#0000FF"
                    }
                }
                RoundButton {
                    id: calendar_year_btn
                    radius: 2.5
                    width: month_grid.width * 0.3
                    onClicked: {
                        if (month_grid.visible) {
                            month_grid.visible = false
                            year_grid.visible = true
                        } else {
                            month_grid.visible = true
                            year_grid.visible = false
                        }
                    }
                    Text {
                        anchors.fill: parent
                        text: '<b>' + month_grid.year + '</b>'
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
                width: month_grid.width * 0.2
                onClicked: {
                    if (month_grid.month < 12)
                        month_grid.month++
                    else {
                        month_grid.year++
                        month_grid.month = 1
                    }
                }
            }
        }
        DayOfWeekRow {
            id: dayofweek_row
            width: month_grid.width
            locale: Qt.locale("en_US")
        }
        MonthGrid {
            id: month_grid
            locale: Qt.locale("en_US")
            visible: true
            delegate: RoundButton {
                id: month_grid_item
                radius: 5
                opacity: model.month === month_grid.month ? 1 : 0
                text: model.day
                onClicked: {
                    selected_date = model.year + '-' + model.month + '-' + model.day
                }
            }
        }
    }
}
