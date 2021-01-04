import QtQuick 2.0
import QtQml.Models 2.2

Rectangle {

    width: 200
    height: 100
    DelegateModel {
        id: visualModel
        model: ListModel {
            ListElement {
                val: 2020
            }
            ListElement {
                val: 2021
            }
        }
        delegate: Rectangle {
            height: 25
            width: 100
            Text {
                text: "val: " + val
            }
        }
    }

    ListView {
        anchors.fill: parent
        model: visualModel
    }
}
