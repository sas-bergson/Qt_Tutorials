import QtQuick 2.12
import QtQuick.Controls 2.5

Image {
    id: bubble
    //x: 258
    //y: 132
    fillMode: Image.PreserveAspectFit
    source: "Bluebubble.svg"
    smooth: true
    property real centerX
    property real centerY
    property real bubbleCenter
}
