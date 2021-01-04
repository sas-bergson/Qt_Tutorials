import QtQuick 2.6
import QtQuick.Window 2.3
import QtQuick.Controls 2.2

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    DatePicker {
        id: date_picker
    }
}
