import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import "User.js" as User
import QtQuick.LocalStorage 2.0

Item {
    id: welcome

    /*
    function findGreetings() {
        var db = LocalStorage.openDatabaseSync("QMLTestDb", "1.0", "The Example QML SQL!", 1000000);

        db.transaction(
            function(tx) {
                console.log('transaction start')
                // Create the database if it doesn't already exist
                tx.executeSql('CREATE TABLE IF NOT EXISTS Greeting(salutation TEXT, salutee TEXT)');

                // Add (another) greeting row
                tx.executeSql('INSERT INTO Greeting VALUES(?, ?)', [ 'hello', 'world' ]);

                // Show all added greetings
                var rs = tx.executeSql('SELECT * FROM Greeting');

                var r = ""
                for(var i = 0; i < rs.rows.length; i++) {
                    r += rs.rows.item(i).salutation + ", " + rs.rows.item(i).salutee + "\n"
                }
                console.log(r)
            }
        )
    }

    Component.onCompleted: findGreetings()
    */

    Item{
        id: center_item
        anchors.centerIn: parent
        width: parent.width/2
        height: parent.height-100
        ColumnLayout{
            anchors.fill: parent

            Image {
                id: _Logo
                width: 100
                height: 100
                anchors{
                    horizontalCenter: parent.horizontalCenter
                }

                source: "/images/qt-logo.png"
            }

            Label {
                Layout.fillWidth: true
                text: qsTr("Welcome to QTester")
                font.pixelSize: 22
                horizontalAlignment: Text.AlignHCenter
            }

            Item{
                height: 100
            }

            ComboBox{
                Layout.preferredWidth: root.width/3
                anchors.horizontalCenter: parent.horizontalCenter
                model: [otherdata.userFullName, qsTr("Switch user ...")]

                onCurrentIndexChanged: {
                    if(currentIndex > 0) // Non-System user login
                        stack.push( Qt.resolvedUrl('Login.qml') );
                    currentIndex = 0
                }
            }



            Label {
                text: qsTr("<html>Source code: <a href=\"https://github.com/LibertaSoft/QTester\">GitHub</a></html>")
                onLinkActivated: Qt.openUrlExternally(link)
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Item{
                // VSpacer
                Layout.fillHeight: true
            }

            Button {
                Layout.fillWidth: true
                visible: permission.testUsage
                text: qsTr("Begin new test")
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked:{
//                enabled = false
                    stack.push( Qt.resolvedUrl('Testing/Configure.qml') );
//                enabled = true
                }
            }
            Button {
                Layout.fillWidth: true
                visible: permission.adminRole || permission.rootRole
                text: qsTr("Administration")
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked:{
                    //stack.push( Qt.resolvedUrl('ConfigureNewTest.qml') )
                }
            }

            Item{
                // VSpacer
                Layout.fillHeight: true
            }
        }
    }
}
