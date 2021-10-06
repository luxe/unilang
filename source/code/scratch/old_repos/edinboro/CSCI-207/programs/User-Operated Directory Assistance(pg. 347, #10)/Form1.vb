'Trevor Hickey'
'Visual Basic 207'
'Tucker'
'10/28'

Public Class frmUserOperatedDirectoryAssistance

    'The file where Employ data is stored'
    Const EMPLOYEE_FILE As String = "Employee.txt"

    'string array of employee data'
    'Used to bring in the data from the file'
    Dim employeeInput() As String = IO.File.ReadAllLines(EMPLOYEE_FILE)

    'Various Lists containing employee infromation'
    Dim employeesFirstName As New ArrayList()
    Dim employeesLastName As New ArrayList()
    Dim extensions As New ArrayList()
    Dim buttonCode As New ArrayList()


    'Build all the necessary lists of information used'
    Private Sub BuildLists()

        'Build List for employeesFirstName, 
        'employeesLastName, and extensions'
        For i = 0 To employeeInput.Length - 1 Step 3
            employeesLastName.Add(employeeInput(i))
            employeesFirstName.Add(employeeInput(i + 1))
            extensions.Add(employeeInput(i + 2))
        Next i

        'Build List for each button code'
        For i = 0 To employeesLastName.Count() - 1 Step 1
            buttonCode.Add(GetNumber(employeesLastName.Item(i).ToString.ElementAtOrDefault(0)))
            buttonCode.Item(i) &= GetNumber(employeesLastName.Item(i).ToString.ElementAtOrDefault(1))
            buttonCode.Item(i) &= GetNumber(employeesLastName.Item(i).ToString.ElementAtOrDefault(2))
            buttonCode.Item(i) &= GetNumber(employeesFirstName.Item(i).ToString.ElementAtOrDefault(0))
        Next i

    End Sub

    'Converts a letter into the key button it corresponds to'
    Function GetNumber(ByVal character As Char) As String
        Select Case character
            Case "a", "b", "c", "A", "B", "C"
                Return "2"
            Case "d", "e", "f", "D", "E", "F"
                Return "3"
            Case "g", "h", "i", "G", "H", "I"
                Return "4"
            Case "j", "k", "l", "J", "K", "L"
                Return "5"
            Case "m", "n", "o", "M", "N", "O"
                Return "6"
            Case "p", "q", "r", "s", "P", "Q", "R", "S"
                Return "7"
            Case "t", "u", "v", "T", "U", "V"
                Return "8"
            Case "w", "x", "y", "z", "W", "X", "Y", "Z"
                Return "9"
        End Select
        Return ""
    End Function

    Private Sub btn1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn1.Click
        txtCode.Text &= "1"
        BuildLists()
    End Sub

    Private Sub btn2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn2.Click
        txtCode.Text &= "2"
    End Sub

    Private Sub btn3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn3.Click
        txtCode.Text &= "3"
    End Sub

    Private Sub btn4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn4.Click
        txtCode.Text &= "4"
    End Sub

    Private Sub btn5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn5.Click
        txtCode.Text &= "5"
    End Sub

    Private Sub btn6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn6.Click
        txtCode.Text &= "6"
    End Sub

    Private Sub btn7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn7.Click
        txtCode.Text &= "7"
    End Sub

    Private Sub btn8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn8.Click
        txtCode.Text &= "8"
    End Sub

    Private Sub btn9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn9.Click
        txtCode.Text &= "9"
    End Sub

    Private Sub btn10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn10.Click
        txtCode.Text &= "*"
    End Sub

    Private Sub btn11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn11.Click
        txtCode.Text &= "0"
    End Sub

    Private Sub btn12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn12.Click
        txtCode.Text &= "#"
    End Sub

    Private Sub btnReset_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnReset.Click
        lstbxPeople.Items.Clear()
        txtCode.Clear()
    End Sub

    'Get the Employee extension numbers for the data entered by the user'
    Private Sub btnInstructions_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnInstructions.Click
        lstbxPeople.Items.Clear()
        BuildLists() 'Build all the lists'

        'Loop through and display all the matches'
        For i = 0 To buttonCode.Count() - 1 Step 1
            If buttonCode.Item(i).ToString = txtCode.Text Then
                lstbxPeople.Items.Add(employeesFirstName.Item(i).ToString + " " + employeesLastName.Item(i).ToString + " x" + extensions.Item(i).ToString)
            End If
        Next i

    End Sub
End Class
