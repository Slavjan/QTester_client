import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

ColumnLayout{
    property string type : "radio"
    ExclusiveGroup { id: answers }
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
    RadioButton{
        id: answer1
        exclusiveGroup: answers
        text: "Answer 1"
        onCheckedChanged: answerChecked(0, checked)
    }
    RadioButton{
        id: answer2
        exclusiveGroup: answers
        text: "Answer 2"
        onCheckedChanged: answerChecked(1, checked)
    }
    RadioButton{
        id: answer3
        exclusiveGroup: answers
        text: "Answer 3"
        onCheckedChanged: answerChecked(2, checked)
    }
    RadioButton{
        id: answer4
        exclusiveGroup: answers
        text: "Answer 4"
        onCheckedChanged: answerChecked(3, checked)
    }
    RadioButton{
        id: answer5
        exclusiveGroup: answers
        text: "Answer 5"
        onCheckedChanged: answerChecked(4, checked)
    }
}

