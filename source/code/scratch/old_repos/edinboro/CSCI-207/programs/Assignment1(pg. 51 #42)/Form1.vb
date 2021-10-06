
Public Class frmEnterPersonalInformation

    'Instruct user to enter their name into the text box.'
    Private Sub txtFullName_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles txtFullName.GotFocus
        lblDirections.Text = "Enter your full name."
    End Sub

    'Instruct user to enter their phone number into the text box.'
    Private Sub txtPhoneNumber_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles txtPhoneNumber.GotFocus
        lblDirections.Text = "Enter your phone number, including area code."
    End Sub

End Class
