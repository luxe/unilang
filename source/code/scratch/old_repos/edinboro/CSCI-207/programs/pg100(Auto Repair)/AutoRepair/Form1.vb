Public Class frmAutoRepair

    'Check to see if the appropiate data is entered into the text fields'
    'Post: returns a bool. True if they are all valid. False if anything is Invalid'
    Private Function CheckForValidDataInTextFields() As Boolean

        Dim errorMessage As String = ""
        CheckForValidDataInTextFields = True

        If txtCustomer.TextLength = 0 Then
            errorMessage &= "Enter a Value for Customer Name." & vbCrLf
        End If
        If txtCost.TextLength = 0 Or IsNumeric(txtCost.Text) = False Then
            errorMessage &= "Invalid data for Cost." & vbCrLf
        End If
        If txtHoursOfLabor.TextLength = 0 Or IsNumeric(txtHoursOfLabor.Text) = False Then
            errorMessage &= "Invalid data for Hours of labor." & vbCrLf
        End If

        'Display an Error Box if there is invalid data.'
        If Len(errorMessage) <> 0 Then
            MessageBox.Show(errorMessage, "ERROR")
            CheckForValidDataInTextFields = False
        End If

    End Function

    Private Sub DisplayAutoRepairBill()

        'Calculate the "Labor", "Parts", and "Total" cost
        Dim laborCost As Single = CSng(txtHoursOfLabor.Text) * 35
        Dim partsCost As Single = CSng(txtCost.Text) + (CSng(txtCost.Text) * 0.05)
        Dim totalCost As Single = laborCost + partsCost

        'Output the results to the list box and format them to 2 decimal places
        lstbxCustomerBill.Items.Add("Customer      " & txtCustomer.Text)
        lstbxCustomerBill.Items.Add("Labor Cost    $" & laborCost.ToString("#,##0.00"))
        lstbxCustomerBill.Items.Add("Parts Cost    $" & partsCost.ToString("#,##0.00"))
        lstbxCustomerBill.Items.Add("Total Cost    $" & totalCost.ToString("#,##0.00"))

    End Sub

    'When The button is clicked, calculate and display the Auto Repair bill.'
    Private Sub btnDisplayBill_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDisplayBill.Click
        If CheckForValidDataInTextFields() Then
            DisplayAutoRepairBill()
        End If
    End Sub

End Class
