import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Item {
    id: testingProcess

    property bool testFinished: false

    width: 900
    height: 600

    Component.onCompleted: {
        var model = questionsModel.get(0);
        var answers = questionsModel.get(0)["answers"];
        _questionsGrid.dataChanged(model, answers)
    }

    /*
    Item {
        focus: true
        Keys.onPressed: {
            if (event.key == Qt.Key_Left) {
                console.log("move left");
                event.accepted = true;
            }
        }
        Keys.onReturnPressed: console.log("Pressed return");
    }
    */

    RowLayout{
        anchors.fill: parent
//        Layout.fillWidth: true
        Layout.preferredWidth: (testingProcess.width / 3) * 2
        anchors.margins: config.margin

        ColumnLayout{
            Layout.fillWidth: true
            Label{
                Layout.fillWidth: true
                text: otherdata.userFullName
            }
            RowLayout{
                Layout.fillWidth: true
                Label{
                    Layout.preferredWidth: (root.width / 3) - config.margin
                    wrapMode: Text.WordWrap
                    text: otherdata.lessonTitle
                }
                Label{
                    Layout.preferredWidth: (root.width / 3) - config.margin
                    wrapMode: Text.WordWrap
                    text: otherdata.themeTitle
                }
            }

            Label{
                id: textQuestion
                Layout.fillWidth: true
                Layout.fillHeight: true

                wrapMode: Text.WordWrap
                text: ""
            }

            GroupBox{
                Layout.fillWidth: true
                title: qsTr("Answers:")

                Loader {
                    id: answersLoader;

                    function setType(type){
                        switch(type){
                        case 'check':
                            source = "qrc:/Content/Testing/AnswerForms/CheckForm.qml";
                            break;
                        case 'radio':
                            source = "qrc:/Content/Testing/AnswerForms/RadioForm.qml";
                            break;
                        case 'text':
                            source = "qrc:/Content/Testing/AnswerForms/TextForm.qml"
                            break;
                        case 'regexp':
                            source = "qrc:/Content/Testing/AnswerForms/RegexpForm.qml"
                            break;
                        default:
                            console.log('Undefined question type: (' + type + ')')
                        }
                    }

                    anchors.fill: parent;
                    source: "qrc:/Content/Testing/AnswerForms/RadioForm.qml"
                    Connections{
                        target: answersLoader.item
                        ignoreUnknownSignals: true
                        onAnswerChecked: {
                            questionsModel.get(_questionsGrid.currentIndex)["answers"].setProperty(id,"userChecked",state);
                        }

                        onAnswerChenged: {
                            questionsModel.get(_questionsGrid.currentIndex)["answers"].setProperty(id,"userText",text);
                        }
                    }
                }
            }
            Rectangle{
                Layout.fillWidth: true
                height: 1
                color: "lightgray"
            }

            RowLayout{
                Layout.fillWidth: true
                CheckBox{
                    id: markIncorrectly
                    text: qsTr("Question incorrectly")
                    onCheckedChanged: {
                        questionsModel.setProperty(_questionsGrid.currentIndex, "markedError", checked)
                    }
                }
                CheckBox{
                    id: markDontKnow
                    text: qsTr("I don't know")
                    onCheckedChanged: {
                        questionsModel.setProperty(_questionsGrid.currentIndex, "markedDontKnow", checked)
                    }
                }
            } // RowLayout
        } // ColumnLayout

        ColumnLayout{
            ListModel{
                id: questionsModel
                ListElement{
                    text:"Разработчик языка программирования C++";
                    type: "radio"
                    markedDontKnow: false
                    markedError: false

                    answers: [
                        ListElement{ text: "Стив Джобс"; valid: false; userChecked: false; userText: "" },
                        ListElement{ text: "Бьёрне Строуструп"; valid: true; userChecked: false; userText: "" },
                        ListElement{ text: "Денис Ритчки"; valid: false; userChecked: false; userText: "" },
                        ListElement{ text: "Кен Томпсон"; valid: false; userChecked: false; userText: "" },
                        ListElement{ text: "Джон Кармак"; valid: false; userChecked: false; userText: "" }
                    ]
                }
                ListElement{
                    text:"Разработчик(и) языка программирования Си и ОС UNIX";
                    type: "check"
                    markedDontKnow: false
                    markedError: false

                    answers: [
                        ListElement{ text: "Бьёрне Строуструп"; valid: false; userChecked: false; userText: "" },
                        ListElement{ text: "Стив Джобс"; valid: false; userChecked: false; userText: "" },
                        ListElement{ text: "Джон Кармак"; valid: false; userChecked: false; userText: "" },
                        ListElement{ text: "Кен Томпсон"; valid: true; userChecked: false; userText: "" },
                        ListElement{ text: "Денис Ритчки"; valid: true; userChecked: false; userText: "" }
                    ]
                }
                ListElement{
                    text:"Свойство ООП подразумевающее сокрытие свойств и методов внутри класса.";
                    type: "text"
                    markedDontKnow: false
                    markedError: false

                    answers: [
                        ListElement{ text: "Инкапсуляция"; valid: true; userChecked: false; userText: ""}
                    ]
                }
            }

            RowLayout{
                Button{
                    Layout.preferredWidth: _questionsGrid.width

                    text: qsTr("Finish test")
                    iconName: "stop"
                    onClicked: {
                        if( testingProcess.testFinished ){
                            stack.pop( stack.get(0) );
                            return;
                        }
                        answersLoader.enabled = false;
                        //timer.stop();
                        testingProcess.testFinished = true;
                        text = qsTr("Return to main");
                        iconName = "back";
                    } // onClicked
                } // Button
            } // RowLayout

            GridView{
                id: _questionsGrid
                cellWidth: 48; cellHeight: cellWidth

                function toogleCurrentMark(){
                    if( currentItem.state == "marked" )
                        currentItem.state = "default"
                    else
                        currentItem.state = "marked"
                }

                property int cellInRow: (testingProcess.width / 3) / cellWidth;

                Layout.preferredWidth: cellWidth * cellInRow
                Layout.fillHeight: true

                Component.onCompleted: {
                    // #ToDo :
                    // select first item
                    // imitate click event
                }

                function dataChanged(model, answers){
                    textQuestion.text = model.text

                    answersLoader.setType( model.type );

                    for(var i = 0; i < answers.count; ++i){

                        if( model.type === 'text' || model.type === 'regexp' ){
                            answersLoader.item.setAnswerText(i, answers.get(i).userText);
                        }else{
                            answersLoader.item.setAnswerText(i, answers.get(i).text);
                            answersLoader.item.setChecked(i, answers.get(i).userChecked);
                        }

                    }

                    markIncorrectly.checked = model.markedError
                    markDontKnow.checked = model.markedDontKnow
                }

                model: questionsModel
                clip: true
                delegate: Rectangle{
                    id : _delegateQuestions
                    width: 46
                    height: width
                    opacity: 0.8
                    color: (GridView.isCurrentItem)? "lightsteelblue" : "lightgray";

                    Text{
                        anchors.centerIn: parent
                        text: index+1
                    }

                    Behavior on color{
                        ColorAnimation {duration: 100}
                    }

                    states: [
                        State {
                            name: "marked"
                            PropertyChanges {
                                target: _delegateQuestions
                                color: "gold"
                            }
                        },
                        State {
                            name: "acceptValid"
                            PropertyChanges {
                                target: _delegateQuestions
                                color: "lightgreen"
                            }
                        },
                        State {
                            name: "acceptInvalid"
                            PropertyChanges {
                                target: _delegateQuestions
                                color: "orangered"
                            }
                        },
                        State {
                            name: "accept"
                            PropertyChanges {
                                target: _delegateQuestions
                                color: "lightblue"

                            }
                        }
                    ]

                    MouseArea {
                        id: _questionsGridMouseArea
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton | Qt.RightButton
                        onClicked: {
                            _questionsGrid.focus = true
                            _questionsGrid.currentIndex = index
                            if( (mouse.button == Qt.RightButton)
                                    && permission.markingQuestions ){
                                _questionsGrid.toogleCurrentMark();
                            }
                            _questionsGrid.dataChanged(model, answers)

                        } // onClicked
                    } // MouseArea
                } // Rectangle
                highlightFollowsCurrentItem: true
                highlight: Rectangle {
                    x: _questionsGrid.currentItem.x
                    y: _questionsGrid.currentItem.y
                    color: "lightsteelblue"; radius: 5
                    Behavior on x { SpringAnimation { spring: 3; damping: 0.2 } }
                    Behavior on y { SpringAnimation { spring: 3; damping: 0.2 } }
                } // Rectangle
            } // GridView
            RowLayout{
                Label{
                    Layout.fillWidth: true
                    text: "15/100"
                    font.pixelSize: 26
                    horizontalAlignment: Qt.AlignLeft
                }
                Label{
                    Layout.fillWidth: true
                    text: "00:42:16"
                    font.pixelSize: 26
                    horizontalAlignment: Qt.AlignRight
                }
            }
        } // ColumnLayout
    } // RowLayout
} // testingProcess
