import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Rectangle {
    ListView {
        id: wallet_records_list_view
        anchors.fill: parent
        spacing: 10
        anchors.margins: 5
        model: Period.walletRecords
        delegate: ItemDelegate {
            width: parent.width
            height: row_dataset.implicitHeight
            Row {
                id: row_dataset
                spacing: 10
                Text {
                    text: model.modelData.date
                }
                Text {
                    text: "---->"
                }
                Text {
                    text: '<b>' + model.modelData.balance + ' XAF</b>'
                    font.italic: true
                    color: parseInt(
                               model.modelData.balance) > 0 ? "#0000FF" : "#FF0000"
                }
            }
        }
        focus: true
        clip: true
        ScrollIndicator.vertical: ScrollIndicator {}
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/

