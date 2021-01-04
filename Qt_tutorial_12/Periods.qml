import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Controls 2.2
import QtQuick.Window 2.3

Page {
    width: parent.width
    padding: 10

    Connections {
        target: Period
        function onBalanceChanged() {
            console.log("period_balance has changed to ", Period.balance)
            balance_label.text = "Balance = " + Period.balance + " XAF"
            balance_label.color = parseInt(
                        Period.balance) > 0 ? "#0000FF" : "#FF0000"
            balance_label.visible = true
        }
        function onWalletRecordsChanged() {
            console.log("wallet_records list has changed to ")
            wallet_records_list.visible = true
        }
        function onWalletRecordsError() {
            console.log("WalletRecordsError: No records found for this period  ",
                        period_selection_combo.currentText)
            balance_label.text = "No records found for this period !!!"
            balance_label.color = "#FF0000"
            balance_label.visible = true
            wallet_records_list.visible = false
        }
        function onPeriodsListError() {
            console.log("PeriodListError:No period records where found at all  !!!")
            balance_label.text = "No Period records found at all !!!"
            balance_label.color = "#FF0000"
            balance_label.visible = true
            wallet_records_list.visible = false
        }
    }

    Column {
        id: page_column
        width: parent.width
        spacing: 15
        Row {
            Label {
                id: page_introduction
                wrapMode: Label.Wrap
                text: "Wallet transaction records for selected periods"
            }
        }

        Row {
            ComboBox {
                id: period_selection_combo
                width: page_introduction.width
                model: Period.periodsList
                enabled: true
            }
        }
        Row {
            spacing: 20
            Label {
                wrapMode: Label.Wrap
                text: "Last transaction records :"
                anchors.verticalCenter: parent.verticalCenter
            }
            SpinBox {
                id: nb_of_records_limit_spin
                enabled: period_selection_combo.count > 0 ? true : false
                value: 5
                editable: true
            }
        }
        Row {
            spacing: 20
            Button {
                id: records_list_cancel_btn
                enabled: period_selection_combo.count > 0 ? true : false
                text: "Cancel"
                onClicked: {
                    wallet_records_list.visible = false
                    balance_label.visible = false
                }
            }
            Button {
                id: records_list_show_btn
                enabled: period_selection_combo.count > 0 ? true : false
                text: "Show"
                onClicked: {
                    if (Period.selectWalletRecordsFor(
                                period_selection_combo.currentText)) {
                        wallet_records_list.visible = true
                    }
                    if (Period.selectBalanceFor(
                                period_selection_combo.currentText)) {
                        balance_label.visible = true
                    }
                }
            }
            Button {
                id: record_list_delete_btn
                enabled: period_selection_combo.count > 0 ? true : false
                text: "Delete"
                onClicked: {
                    Period.execSQL(
                                "DELETE FROM period WHERE (CAST(period.year as TEXT) || '-' ||CAST(period.month as TEXT) || '-' ||CAST(period.day as TEXT)) LIKE '"
                                + period_selection_combo.currentText + "'")
                    wallet_records_list.visible = false
                    balance_label.visible = false
                }
            }
        }
        Row {
            Wrecords {
                id: wallet_records_list
                visible: false
                width: page_column.width //tabs.width
                height: Screen.desktopAvailableHeight * 0.45
                color: "#cfcfcf"
            }
        }
        Row {
            Label {
                id: balance_label
                visible: false
                anchors.margins: 5
                wrapMode: Label.Wrap
                text: "Balance = " + Period.balance + " XAF"
                color: parseInt(Period.balance) > 0 ? "#0000FF" : "#FF0000"
            }
        }
    }
}
/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/

