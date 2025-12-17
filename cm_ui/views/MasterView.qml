import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import assets 1.0
import components 1.0

Window {
    width: 1366
    height: 800
    visible: true
    title: qsTr("Client Management")

    Component.onCompleted: contentFrame.replace("qrc:/views/DashboardView.qml")

    // Wire up view to react to navigation signals
    Connections {
        target: masterController.ui_navigationController
        // These are slots
        function onGoCreateClientView() {
            contentFrame.replace("qrc:/views/CreateClientView.qml")
        }

        function onGoDashboardView() {
            contentFrame.replace("qrc:/views/DashboardView.qml")
        }

        function onGoEditClientView(client) {
            contentFrame.replace("qrc:/views/EditClientView.qml", {selectedClient: client})
        }

        function onGoFindClientView() {
            contentFrame.replace("qrc:/views/FindClientView.qml")
        }

        function onGoRssView() {
            contentFrame.replace("qrc:/views/RssView.qml")
        }
    }

    NavigationBar {
        id: navigationBar
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
}
