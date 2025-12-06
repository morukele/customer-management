pragma Singleton
import QtQuick 2.15

Item {
    property alias fontAwesome: fontAwesomeLoader.name

    readonly property color colourBackground: "#efefef"

    readonly property color colourNavigationBarBackground: "#000000"
    readonly property color colourNavigationBarFont: "#ffffff"
    readonly property int pixelSizeNavigationBarIcon: 42
    readonly property int pixelSizeNavigationBarText: 22
    readonly property real heightNavigationButtonIcon: widthNavigationButtonIcon
    readonly property real heightNavigationButtonDescription: heightNavigationButtonIcon

    readonly property real widthNavigationButtonIcon: 80
    readonly property real widthNavigationBarCollapsed: widthNavigationButtonIcon
    readonly property real widthNavigationButtonDescription: 160
    readonly property real widthNavigationButton: widthNavigationButtonIcon + widthNavigationButtonDescription
    readonly property real heightNavigationButton: Math.max(heightNavigationButtonIcon, heightNavigationButtonDescription)
    readonly property real widthNavigationBarExpanded: widthNavigationButton

    readonly property color colourCommandBarBackground: "#cecece"
    readonly property color colourCommandBarFont: "#131313"
    readonly property color colourCommandBarFontDisabled: "#636363"
    readonly property real heightCommandBar: heightCommandButton
    readonly property int pixelSizeCommandBarIcon: 32
    readonly property int pixelSizeCommandBarText: 12

    readonly property real widthCommandButton: 80
    readonly property real heightCommandButton: widthCommandButton

    readonly property real sizeScreenMargin: 20

    readonly property color colourDataControlsBackground: "#ffffff"
    readonly property color colourDataControlsFont: "#131313"
    readonly property int pixelSizeDataControls: 18
    readonly property real widthDataControls: 400
    readonly property real heightDataControls: 40

    // load font
    FontLoader {
        id: fontAwesomeLoader
        source: "qrc:/assets/fontawesome.ttf"
    }
}
