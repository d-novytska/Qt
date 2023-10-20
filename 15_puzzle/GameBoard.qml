import QtQuick 2.0
import Game 1.0;

GridView
{
    id: root
    property alias root: root
    model: GameBoardModel{
    }

    cellHeight: height / root.model.dimention
    cellWidth: width / root.model.dimention

    delegate: Item{
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight

        visible: display !== root.model.hiddenElementValue

        Tile{
            anchors.fill: parent
            anchors.margins: 5

            displayText: display
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    root.model.move(index);
                }
            }
        }
    }
}


