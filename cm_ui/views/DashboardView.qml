import QtQuick 2.12
import assets 1.0

Item {
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground
        Text {
            anchors.centerIn: parent
            text: qsTr("Client Management System")
            color: Style.colourDataControlsFont
            font.pixelSize: Style.pixelSizeDataControls
        }
    }
}
