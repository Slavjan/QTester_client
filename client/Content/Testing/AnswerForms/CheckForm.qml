import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

ColumnLayout{
    property string type : "check"
    signal answerChecked(int id, bool state)
    function setAnswerText(id, text){
        switch(id){
            case 0: answer1.text = text; break;
            case 1: answer2.text = text; break;
            case 2: answer3.text = text; break;
            case 3: answer4.text = text; break;
            case 4: answer5.text = text; break;
            default: console.log("Error: id("+id+") is undefined;")
        }
    }
    function setChecked(id, state){
        switch(id){
        case 0: answer1.checked = state; break;
        case 1: answer2.checked = state; break;
        case 2: answer3.checked = state; break;
        case 3: answer4.checked = state; break;
        case 4: answer5.checked = state; break;
        default: console.log("Error: id("+id+") is undefined;")
        }
    }

    CheckBox{
        id: answer1
        text: "Answer 1"
        onCheckedChanged: answerChecked(0, checked)
    }
    CheckBox{
        id: answer2
        text: "Answer 2"
        onCheckedChanged: answerChecked(1, checked)
    }
    CheckBox{
        id: answer3
        text: "Answer 3"
        onCheckedChanged: answerChecked(2, checked)
    }
    CheckBox{
        id: answer4
        text: "Answer 4"
        onCheckedChanged: answerChecked(3, checked)
    }
    CheckBox{
        id: answer5
        text: "Answer 5"
        onCheckedChanged: answerChecked(4, checked)
    }
}

