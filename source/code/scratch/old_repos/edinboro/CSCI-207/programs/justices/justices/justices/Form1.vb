Public Class Form1

    Private Sub OpenToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OpenToolStripMenuItem.Click

        Dim textfile As String
        OpenFileDialog1.Filter = "text files (*.txt)|*.txt|All files (*.*)|*.*"

        OpenFileDialog1.ShowDialog()
        textfile = OpenFileDialog1.FileName

        Dim JusticesTemp() = IO.File.ReadAllLines(textfile)
        Dim n As Integer = JusticesTemp.Count - 1 'counts the number of records'

        ReDim JusticesTemp(n) 'Now I have some variables to work with'

        Dim line As String
        Dim data() As String

        'In here I'll load up the array from the temp array and seperate the data into fields'
        For i As Integer = 0 To n
            line = JusticesTemp(i)
            data = line.Split(","c)
            JusticesTemp(i).FirstName = data(0)
            JusticesTemp(i).LastName = data(1)
            JusticesTemp(i).ApptBy = data(2)
            JusticesTemp(i).StateFrom = data(3)
            JusticesTemp(i).StartYear = CInt(data(4))
            JusticesTemp(i).EndYear = CInt(data(5))
        Next

        For i As Integer = 0 To
            ListBox1.Items.Add(JusticesTemp(i).FirstName & " " & JusticesTemp(i).LastName & " " & JusticesTemp(i).StateFrom)
        Next


    End Sub

    Private Sub ExitToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExitToolStripMenuItem.Click
        Me.Close()
    End Sub

    Private Sub LoadDataGridToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LoadDataGridToolStripMenuItem.Click
        Dim query = From Just In Justices
                    Order By Just.LastName Ascending
                    Select Just.LastName, Just.FirstName, Just.ApptBy, Just.StartYear, Just.EndYear, Just.StateFrom

        dvgJustices.DataSource = query.ToList
        dvgJustices.CurrentCell = Nothing
    End Sub
End Class
