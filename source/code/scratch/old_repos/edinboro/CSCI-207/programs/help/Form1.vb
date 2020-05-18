Public Class Form1

    'Declaring a Structure and making an object from that Structure
    Structure Blah
        Dim variable1 As Integer
        Dim variable2 As String
    End Structure
    Dim BlahObject() As Blah

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        'Open a specific text file
        Dim textfile As String
        OpenFileDialog1.Filter = "text files (*.txt)|*.txt|All files (*.*)|*.*"
        OpenFileDialog1.ShowDialog()
        textfile = OpenFileDialog1.FileName

        'Read in file'
        Dim Data() = IO.File.ReadAllLines(textfile)
        Dim n As Integer = Data.Count - 1 'get rid of the extra entry at the end of the file'
        ReDim Data(n) 'Restore the list so that every entry is valid

    End Sub
End Class
