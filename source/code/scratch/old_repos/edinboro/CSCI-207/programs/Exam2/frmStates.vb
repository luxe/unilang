'Trevor Hickey'
'Dave Tucker'
'CSCI 207 Fall2011'
'11/03/2011'
'Exam 2'

'This Program Reads in State Sata from a local text file and displays the data to the user in various ways'
'The user can display all the state data, sort and organize the state data by abbreviation and density, and
'Find the area of a given state'

Public Class frmStates

    Structure State
        Dim Name As String
        Dim Abbreviation As String
        Dim landArea As Double
        Dim population As Long
    End Structure

    'Global Variables'
    Const STATE_FILE As String = "USStates.txt" 'This file must be in the current working directory'
    Public amountOfStates As Integer 'This will be the amount of state entries found in the STATE_FILE'
    Public States() As State 'A collection of states and all their corresponding data'

    'Execute this routine before showing the program to the user'
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Try
            'Read data in from a local text file and store the entries into an array of records'
            Dim StatesTemp() = IO.File.ReadAllLines(STATE_FILE)
            amountOfStates = StatesTemp.Count - 1 'counts the number of state entries'
            ReDim States(amountOfStates) 'Now there is some variables to work with'

            Dim line As String 'a line containing all the infor for a particular state'
            Dim data() As String 'and array holding each entry of a particular state'

            'load up the array from the temp array and seperate the data into the fields'
            For i As Integer = 0 To amountOfStates
                line = StatesTemp(i)
                data = line.Split(","c)
                States(i).Name = data(0)
                States(i).Abbreviation = data(1)
                States(i).landArea = data(2)
                States(i).population = data(3)
            Next

            'Inform the user if there was a problem loading in the state data'
        Catch ex As Exception
            MsgBox("State file is missing! Please make sure the file is in the current working directory")
        End Try
    End Sub

    'Close the program when the user clicks File->Exit from the menu strip'
    Private Sub ExitToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExitToolStripMenuItem.Click
        Me.Close()
    End Sub

    'Display the State Abbreviation and the state density of each state(sorted by state Abbreviation: ascending) when the user clicks a button'
    Private Sub btnDisplayStateAndDensity_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDisplayStateAndDensity.Click

        lstbxStates.Items.Clear() 'Clear any current entries in the list box'

        'Sort data by the state abbreviation'
        Dim query = From sortedList In States
                    Order By sortedList.Abbreviation Ascending
                    Select sortedList.Name, sortedList.Abbreviation, sortedList.landArea, sortedList.population

        'Display all the states(sorted by abbreviation) and the amount of People per Sql mi for each'
        For i As Integer = 0 To amountOfStates
            lstbxStates.Items.Add(query(i).Abbreviation + " has " + (query(i).population / query(i).landArea).ToString("#,##0.00") + " People per Sql mi")
        Next

    End Sub

    'Display all the state data when the user clicks a button'
    Private Sub btnDisplayStates_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDisplayStates.Click

        lstbxStates.Items.Clear() 'Clear any current entries in the list box'

        'Display all the states(unsorted) and all of the data that corresponds to each state'
        For i As Integer = 0 To amountOfStates
            lstbxStates.Items.Add(States(i).Name + " " + States(i).Abbreviation + " " + States(i).landArea.ToString("#,##0.") + " " + States(i).population.ToString("#,##0."))
        Next

    End Sub

    'Display the area of a particular state for a user entered state abbreviation'
    'the state abbreviation entered by the user is not case sensitive (ie. "PA" and "pa" will both work)'
    Private Sub btnFindArea_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnFindArea.Click

        lstbxStates.Items.Clear() 'Clear any current entries in the list box'


        Dim stateFound As Boolean = False 'the requested state is not found until proven otherwise'

        'If the state requested is valid, display the land area, else let the user know about the invalid entry'
        For i As Integer = 0 To amountOfStates
            If States(i).Abbreviation = txtStateAbbreviation.Text.ToUpper Then
                lstbxStates.Items.Add("The area of " + States(i).Name + " is " + States(i).landArea.ToString("#,##0.") + " square miles.")
                stateFound = True
            End If
        Next

        'Inform the user if they entered an invalid state, or no state at all
        If stateFound = False Then
            MsgBox("Please enter a valid state abbreviation.")
        End If

    End Sub

End Class
