import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Item {
    id: testingConfiguration
    width: 900
    height: 600

    ListModel{
        id: themeModel;

    }
    ListModel{
        id: lessonsModel;
    }
    ListModel{
        id: professionModel;
    }


    function isStartTest(){
        return (_countQuestion.value > 0) && (_countQuestion.value <= _countQuestionAll.value);
    }

    ColumnLayout{
        anchors.fill: parent
        anchors.margins: config.margin

        Item{
            height: 30
        }
        Image{
            anchors.horizontalCenter: parent.horizontalCenter;
            source: "/images/qt-logo.png"
        }

        GroupBox{
            title: qsTr("Test configuration:");
            Layout.preferredWidth: parent.width
            anchors.margins: config.padding

            GridLayout { // Form Layout
                width: parent.width
                columns: 2
                rowSpacing: 16

                Label { text: qsTr("Profession: ") }
                RowLayout{
                    ComboBox{
                        id: _profession
                        Layout.fillWidth: true;
                        model: professionTitleModel;
//                        model : profList


                        onCurrentIndexChanged: {
//                            NetManager.sendPullRequestLessonsList(_profession.currentIndex);
                            lessonsModel.append(profList);
                            _lesson.enabled = true;
                            console.log(profList);

                        }
//                        onDataChanged: {professionModel.append( profList );}
                    }
                    ComboBox{
                        id: _course
                        currentIndex: 0
                        model: ["1 Курс","2 Курс","3 Курс","4 Курс"]
                    }
                }




                Label { text: qsTr("Lesson: ") }
                ComboBox{
                    id: _lesson
                    Layout.fillWidth: true;
                    model: lessonsModel.append(lessonsList)

                    onCurrentIndexChanged: {
//                        NetManager.sendPullRequestLessonsList(_lesson.currentIndex);
                        themeModel.append(themesList);
                        _theme.enabled = true;
                    }
                    Component.onCompleted: {
                        enabled = false
                    }
                }

                Label { text: qsTr("Theme: ") }
                ComboBox{
                    id: _theme
                    Layout.fillWidth: true;
                    model: themeModel;

                    onCurrentIndexChanged: {
//                        NetManager.sendPullRequestLessonsList(_theme.currentIndex);
                        _theme.enabled = true;
                    }
                    Component.onCompleted: {
                        enabled = false
                    }
                }

                Label { text: qsTr("Quantity of questions: ") }
                RowLayout{
                    Slider{
                        id: _countQuestionSlider
                        Layout.fillWidth: true;
                        minimumValue: 0
                        maximumValue: _countQuestionAll.value

                        onValueChanged: _countQuestion.value = value
                    }
                    SpinBox{
                        id: _countQuestion
                        minimumValue: 0
                        value: 1
                        maximumValue: _countQuestionAll.value

                        onValueChanged: {
                            _countQuestionSlider.value = value
                            _btnBeginTest.enabled = isStartTest()
                        }
                    }
                    Text{
                        text: qsTr(" / ", "of")
                    }
                    SpinBox{
                        id: _countQuestionAll
                        enabled: false
                        minimumValue: 0
                        value: 100
                        maximumValue: 99999

                        onValueChanged: {
                            _countQuestion.maximumValue = value
                            _countQuestionSlider.maximumValue = value
                        }
                    }
                }

                Label { text: qsTr("Time constraint: ") }
                RowLayout{
                    Slider{
                        id: _timeConstraintSlider
                        Layout.fillWidth: true;
                        minimumValue: 0
                        maximumValue: 120

                        onValueChanged: {
                            _timeConstraint.value = value
                        }
                    }
                    SpinBox{
                        id: _timeConstraint
                        value: 0
                        minimumValue: 0
                        maximumValue: 1200
                        suffix: qsTr("min")

                        onValueChanged: {
                            _timeConstraintSlider.value = value
                        }
                    }
                    ComboBox{
                        model: [qsTr("On all test"), qsTr("On one question")]
                    }
                }

                Label { text: "" }
                Text{
                    text: qsTr("Warning: ") + qsTr("You stuped, monkey")
                    color: "red"
                }
            }
        }

        RowLayout{
            anchors.right: parent.right

            Button{
                text: qsTr("Back")
                onClicked: stack.pop( Qt.resolvedUrl('Welcome.qml') )
            }
            Button{
                id: _btnBeginTest
                text: qsTr("Begin test")
                onClicked: {
                    if( isStartTest() ){
                        otherdata.lessonTitle = _lesson.currentText
                        otherdata.themeTitle = _theme.currentText
                        stack.push( Qt.resolvedUrl('Process.qml') )
                    }
                }
                Component.onCompleted: {
                    _btnBeginTest.enabled = isStartTest()
                }
            }
        }
    }
}
