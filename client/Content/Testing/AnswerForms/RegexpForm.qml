import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

ColumnLayout{
    property string type : "regexp"
    signal answerChenged(int id, string text)
    function setAnswerText(id, text){
            answer.text = text;
    }
    TextField{
        id: answer
        Layout.fillWidth: true
        onEditingFinished: answerChenged(0, text)
    }
}

