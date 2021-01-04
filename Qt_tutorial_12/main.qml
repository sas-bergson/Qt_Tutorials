import QtQuick 2.6
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: application_window
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight
    title: qsTr("E_Wallet")
    visible: true

    onVisibleChanged: console.log("Period.dbError = " + Period.dbError)

    property bool dbError: Period.dbError

    onDbErrorChanged: {
        if (Period.connection_error) {
            error_message_label.text = qsTr(
                        "Error: couldn't connect to the Database !!!!")
            error_dialog.open()
        }
    }

    Dialog {
        id: error_dialog
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
        standardButtons: Dialog.Close
        title: "Connection Error"
        Label {
            id: error_message_label
            text: ""
        }
    }

    Dialog {
        id: about_dialog
        modal: true
        focus: true
        title: "About E_Wallet"
        x: (application_window.width - width) / 2
        y: application_window.height / 6
        width: Math.min(application_window.width,
                        application_window.height) / 3 * 2
        contentHeight: about_message.height
        Label {
            id: about_message
            width: about_dialog.availableWidth
            text: "Qt tutorial 12 with  SQLite + Qt Quick "
            wrapMode: Label.Wrap
            font.pixelSize: 12
        }
    }

    header: ToolBar {
        RowLayout {
            spacing: 20
            anchors.fill: parent
            Label {
                id: header_label
                text: qsTr("E_Wallet")
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                id: header_toolButton
                icon.name: "menu"
                onClicked: menu.open()
            }
        }
    }

    Menu {
        id: menu
        x: parent.width - width
        transformOrigin: Menu.TopRight
        MenuItem {
            id: about
            text: "About"
            onTriggered: {
                about_dialog.open()
            }
        }
    }

    footer: Label {
        width: parent.width
        horizontalAlignment: Qt.AlignRight
        padding: 10
        text: qsTr("© http://dev.e_wallet.mobile")
        font.pixelSize: 14
        font.italic: true
    }

    Periods {
        id: period_page
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/

