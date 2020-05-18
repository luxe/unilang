Public Class frmFace

    Private Sub btnFrown_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnFrown.Click
        'Change the face to a frown'
        lblFace.Text = "L"
        btnFrown.Visible = False
        btnSmile.Visible = True
    End Sub

    Private Sub btnSmile_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSmile.Click
        'Change the face to a smile'
        lblFace.Text = "J"
        btnSmile.Visible = False
        btnFrown.Visible = True
    End Sub
End Class
