import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import "User.js" as User

Item{
    anchors.fill: parent

    Item{
        width: parent.width / 4
        height: parent.height / 5
        anchors.centerIn: parent

        ColumnLayout{
            anchors.fill: parent
            TextField{
                id: login
                Layout.fillWidth: true
                placeholderText: qsTr("Login")
            }
            TextField{
                id: password
                Layout.fillWidth: true
                placeholderText: qsTr("Password")
            }
            Text{
                id: status
                text: ""
            }

            Button{
                text: qsTr("Login")
                Layout.fillWidth: true
                onClicked: {
                    if( User.loginVerification(login.text) ){
                        if( User.changeLogin(login.text, password.text) ){
                            status.color = "green"
                            status.text = qsTr("Login success")

                            otherdata.userLogin = login.text
                            otherdata.userFullName = User.getFullUserName(login.text)
                            stack.pop( stack.get(0) )
                        }else{
                            status.color = "red"
                            status.text = qsTr("Login filed")
                        }
                    }else{
                        status.color = "red"
                        status.text = qsTr("Login uncorrectly")
                    }
                }
            }
        }
    }
}

