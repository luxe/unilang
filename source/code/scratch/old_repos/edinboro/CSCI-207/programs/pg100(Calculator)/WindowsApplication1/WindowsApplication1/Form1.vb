Public Class Form1

    'When the Addition button is clicked, calulate and display the results.'
    'The Two numbers are not calculated if a field is empty or they both do not contain numeric values.'
    Private Sub btnAdd_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnAdd.Click
        If txtNumber1.TextLength <> 0 And txtNumber2.TextLength <> 0 Then
            If IsNumeric(txtNumber1.Text) = True And IsNumeric(txtNumber2.Text) = True Then
                txtAnswer.Text = txtNumber1.Text & " + " & txtNumber2.Text & " = " & CStr(CInt(txtNumber1.Text) + CInt(txtNumber2.Text))
            End If
        End If
    End Sub

    'When the Subtraction button is clicked, calulate and display the results.'
    'The Two numbers are not calculated if a field is empty or they both do not contain numeric values.'
    Private Sub btnSubtract_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSubtract.Click
        If txtNumber1.TextLength <> 0 And txtNumber2.TextLength <> 0 Then
            If IsNumeric(txtNumber1.Text) = True And IsNumeric(txtNumber2.Text) = True Then
                txtAnswer.Text = txtNumber1.Text & " - " & txtNumber2.Text & " = " & CStr(CInt(txtNumber1.Text) - CInt(txtNumber2.Text))
            End If
        End If
    End Sub

    'When the Multiply button is clicked, calulate and display the results.'
    'The Two numbers are not calculated if a field is empty or they both do not contain numeric values.'
    Private Sub btnMultiply_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnMultiply.Click
        If txtNumber1.TextLength <> 0 And txtNumber2.TextLength <> 0 Then
            If IsNumeric(txtNumber1.Text) = True And IsNumeric(txtNumber2.Text) = True Then
                txtAnswer.Text = txtNumber1.Text & " x " & txtNumber2.Text & " = " & CStr(CInt(txtNumber1.Text) * CInt(txtNumber2.Text))
            End If
        End If
    End Sub
End Class
