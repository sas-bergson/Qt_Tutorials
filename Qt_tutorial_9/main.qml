import QtQuick 2.15
import QtQuick.Controls 2.5
import QtSensors 5.9

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Accelerate Bubble")

    Accelerometer {
        id: accel
        dataRate: 100
        active: true
        onReadingChanged: {
            var newX = (bubble.x + calcRoll(accel.reading.x, accel.reading.y,
                                            accel.reading.z) * 0.1)
            var newY = (bubble.y - calcPitch(accel.reading.x, accel.reading.y,
                                             accel.reading.z) * 0.1)

            if (isNaN(newX) || isNaN(newY))
                return

            if (newX < 0)
                newX = 0

            if (newX > page1.mainWindow.width - bubble.width)
                newX = page1.mainWindow.width - bubble.width

            if (newY < 18)
                newY = 18

            if (newY > page1.mainWindow.height - bubble.height)
                newY = page1.mainWindow.height - bubble.height

            bubble.x = newX
            bubble.y = newY
        }
    }

    function calcPitch(x, y, z) {
        return -(Math.atan(y / Math.sqrt(x * x + z * z)) * 57.2957795)
    }

    function calcRoll(x, y, z) {
        return -(Math.atan(x / Math.sqrt(y * y + z * z)) * 57.2957795)
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form {
            id: page1
            Bubble {
                id: bubble
                centerX: mainWindow.width / 2
                centerY: mainWindow.height / 2
                bubbleCenter: bubble.width / 2
                x: bubble.centerX - bubble.bubbleCenter
                y: bubble.centerY - bubble.bubbleCenter
                Behavior on y {
                    SmoothedAnimation {
                        easing.type: Easing.Linear
                        duration: 100
                    }
                }
                Behavior on x {
                    SmoothedAnimation {
                        easing.type: Easing.Linear
                        duration: 100
                    }
                }
            }
        }

        Page2Form {
            id: page2
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }
}
