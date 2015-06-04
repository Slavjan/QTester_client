import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import "Content/User.js" as User


ApplicationWindow {
    id: root
    title: qsTr("QTester")

    width: 900
    height: 600
    minimumWidth: 760
    minimumHeight: 520

    visible: true
    Item{
        id: config

        property int  margin: 10
        property int  padding: 6

        property bool alwaysPromptAuthentication : false /*recomended : false*/
    }
    Item{
        id: otherdata


        property string lessonTitle
        property string themeTitle

        property string userLogin: username;
        property string userFullName: User.getFullUserName(username)
    }

    Item{
        id: permission

        property bool markingQuestions : true;
        property bool saveResults      : true;
        property bool testUsage        : true;
        property bool adminRole        : false;
        property bool rootRole         : false;
    }

    /*
    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }
    */

    /*ListModel {
        id: pageModel
        ListElement {
            title: "Buttons"
            page: "content/ButtonPage.qml"
        }
        ListElement {
            title: "Sliders"
            page: "content/SliderPage.qml"
        }
        ListElement {
            title: "ProgressBar"
            page: "content/ProgressBarPage.qml"
        }
        ListElement {
            title: "Tabs"
            page: "content/TabBarPage.qml"
        }
        ListElement {
            title: "TextInput"
            page: "content/TextInputPage.qml"
        }
    }*/

    StackView {
        id: stack
        initialItem: Qt.resolvedUrl('Content/Welcome.qml')

        delegate: StackViewDelegate {
                function transitionFinished(properties){
                    properties.exitItem.opacity = 1
                    console.log( "Stack.Depth(" + stack.depth + ")" ) // #Debug : depth of stuck
                }

                pushTransition: StackViewTransition {
                    PropertyAnimation {
                        duration: 200
                        easing.type: Easing.InOutQuad
                        target: enterItem
                        property: "scale"
                        from: 0
                        to: 1
                    }
                    PropertyAnimation {
                        duration: 200
                        easing.type: Easing.InOutQuad
                        target: exitItem
                        property: "scale"
                        from: 1
                        to: 0
                    }
                }
            }
    }

    /*
    MessageDialog {
        id: messageDialog
        title: qsTr("May be you have a going to fuck, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
    */
    Component.onCompleted: {
        if( config.alwaysPromptAuthentication ){
            stack.push( Qt.resolvedUrl('Content/Login.qml') );
        }
    }
}
