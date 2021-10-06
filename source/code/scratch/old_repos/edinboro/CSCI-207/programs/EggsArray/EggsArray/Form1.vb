Public Class Form1

    Private Sub btnLoad_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnLoad.Click

        'The file where the egg weight data is stored'
        Const EGG_FILE As String = "eggs.txt"

        'string array of eggs weights'
        'Used to bring in the data from the file'
        Dim eggsInput() As String = IO.File.ReadAllLines(EGG_FILE)

        'float array of eggs'
        'Used to hold the actual value(not the string representation) of egg weights'
        Dim eggs(eggsInput.Length) As Double

        Dim numberOfJumboEggs As Integer = 0

        'loop through the string array of eggs and,'
        'convert each one to a float before adding it to the float array of eggs.'
        For x As Integer = 0 To eggsInput.Length - 1
            eggs(x) = CDbl(eggsInput(x))
        Next

        'output all of the egg weights into a listbox'
        For x As Integer = 0 To eggsInput.Length - 1
            lstbxEggs.Items.Add(eggs(x))
        Next

        'Calculate the amount of JUMBO eggs'
        For x As Integer = 0 To eggsInput.Length - 1
            If eggs(x) < 2.25 And eggs(x) >= 2 Then
                numberOfJumboEggs += 1
            End If
        Next
    End Sub
End Class
