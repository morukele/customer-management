import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2

Window {
    width: 1024
    height: 768
    visible: true
    title: qsTr("Client Management")

    // Wire up view to react to navigation signals
    Connections {
        target: masterController.ui_navigationController
        // These are slots
        onGoCreateClientView: contentFrame.replace("qrc:/views/CreateClientView.qml")
        onGoDashboardView: contentFrame.replace("qrc:/views/DashboardView.qml")
        onGoEditClientView: contentFrame.replace("qrc:/views/EditClientView.qml", {selectedClient: client})
        onGoFindClientView: contentFrame.replace("qrc:/views/FindClientView.qml")
    }

    StackView {
        id: contentFrame
        anchors{
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }
        clip: true
        initialItem: "qrc:/views/SplashView.qml"
    }
    Component.onCompleted: contentFrame.replace("qrc:/views/DashboardView.qml")

    Rectangle {
        id: navigationBar
        anchors{
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
        width: 100
        color: "#008000"

        Column {
            Button {
                text: "Dashboard"
                onClicked: masterController.ui_navigationController.goDashboardView()
            }
            Button {
                text: "New Client"
                onClicked: masterController.ui_navigationController.goCreateClientView()
            }
            Button {
                text: "Find Client"
                onClicked: masterController.ui_navigationController.goFindClientView()
            }
        }
    }
}
