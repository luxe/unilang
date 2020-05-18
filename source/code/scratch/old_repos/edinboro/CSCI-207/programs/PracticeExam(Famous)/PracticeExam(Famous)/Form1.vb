Public Class Form1

    'The file where Person data is stored'
    Const PERSON_FILE As String = "Famous.txt"

    'string array of person data'
    'Used to bring in the data from the file'
    Dim PesonInput() As String = IO.File.ReadAllLines(PERSON_FILE)

    Dim Names As New ArrayList()
    Dim Dates As New ArrayList()

    Private Sub BuildLists()

        For i = 0 To PesonInput.Length - 1 Step 1

            'Store Person Value'
            Names.Add(PesonInput(i))
            Names.Item(i) = Names.Item(i).ToString.Remove(Names.Item(i).ToString.LastIndexOf(","), Names.Item(i).ToString.Length() - Names.Item(i).ToString.LastIndexOf(","))
            lstbxNames.Items.Add(Names.Item(i))

            'Store Data Value'
            Dates.Add(PesonInput(i))
            Dates.Item(i) = Dates.Item(i).ToString.Substring(1 + Dates.Item(i).ToString.LastIndexOf(","))
            lstbxDates.Items.Add(Dates.Item(i))

        Next i

    End Sub

    Private Sub Display70sLists()

        Dim birthday As Date

        lstbxNames.Items.Clear()
        lstbxDates.Items.Clear()

        'Display All people born in the 70s'
        For i = 0 To PesonInput.Length - 1 Step 1

            'If the person was born in the 70s, display them'
            birthday = Dates.Item(i).ToString()
            If (birthday.Year >= 1970 And birthday.Year <= 1979) Then
                lstbxNames.Items.Add(Names.Item(i))
                lstbxDates.Items.Add(Dates.Item(i))
            End If

        Next i
    End Sub

    Private Sub AgeLists()

        Dim Today As Date = Date.Now
        Dim birthday As Date
        Dim Age As Integer

        lstbxNames.Items.Clear()
        lstbxDates.Items.Clear()

        'Display All people's age'
        For i = 0 To PesonInput.Length - 1 Step 1

            birthday = Dates.Item(i).ToString()
            Age = Today.Year - birthday.Year
            lstbxNames.Items.Add(Names.Item(i))
            lstbxDates.Items.Add(Age)

        Next
    End Sub

    Private Sub btnLoad_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnLoad.Click
        BuildLists()
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub

    Private Sub btnSort_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSort.Click
        Display70sLists()
    End Sub

    Private Sub btnAge_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnAge.Click
        AgeLists()
    End Sub
End Class
