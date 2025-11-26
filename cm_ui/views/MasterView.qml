import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Client Management")

    StackView {
        id: contentFrame
        initialItem: "qrc:/views/SplashView.qml"
    }
}
