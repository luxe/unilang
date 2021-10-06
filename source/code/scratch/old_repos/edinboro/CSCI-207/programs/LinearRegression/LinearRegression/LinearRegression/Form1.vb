Public Class frmLinearRegression

    'List of X and Y values for all the given points'
    Dim xValues As New ArrayList
    Dim yValues As New ArrayList

    'Part of Equation'
    Private Function SumOfXs() As Double

        SumOfXs = 0

        'Add all the X values together'
        For Each num In xValues
            SumOfXs += num
        Next

        Return SumOfXs
    End Function

    'Part of Equation'
    Private Function SumOfYs() As Double

        SumOfYs = 0

        'Add all the Y values together'
        For Each num In yValues
            SumOfYs += num
        Next

        Return SumOfYs
    End Function

    'Part of Equation'
    Private Function SumOfXTimesY() As Double

        SumOfXTimesY = 0

        'Multipy The X and Y value of each point'
        'and Add them all together'
        For i = 0 To xValues.Count - 1 Step 1
            SumOfXTimesY += (xValues.Item(i) * yValues.Item(i))
        Next i

        Return SumOfXTimesY
    End Function

    'Part of Equation'
    Private Function SumOfXTimesX() As Double

        SumOfXTimesX = 0

        'Square The X value of each point'
        'and Add them all together'
        For i = 0 To xValues.Count - 1 Step 1
            SumOfXTimesX += (xValues.Item(i) * xValues.Item(i))
        Next i

        Return SumOfXTimesX
    End Function

    'Part of Equation'
    Private Function SumOfXsSquared() As Double
        Return SumOfXs() * SumOfXs()
    End Function

    'Calculate the slope for the linear regression of data points' 'Apply Formula'
    Private Function CalculateSlope() As Double
        'Slope(m) = (NΣXY - (ΣX)(ΣY)) / (NΣX^2 - (ΣX)^2)'
        Return ((xValues.Count()) * (SumOfXTimesY()) - (SumOfXs()) * (SumOfYs())) / ((xValues.Count() * SumOfXTimesX()) - SumOfXsSquared())
    End Function

    'Calculate the y-intercept for the linear regression of data points'
    Private Function CalculateYIntercept() As Double
        'Intercept(b) = (ΣY - b(ΣX)) / N 
        Return (SumOfYs() - (CalculateSlope() * SumOfXs())) / xValues.Count()
    End Function

    'Calculate/Display the slope and y-intercept for the linear regression of data points'
    Private Sub btnCalculate_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCalculate.Click

        'Calculate and display the slope of the linear regression'
        txtMValue.Text = "m = " + CalculateSlope().ToString(("#,##0.00"))

        'Calculate and display the y-intercept of the linear regression'
        txtBValue.Text = "b = " + CalculateYIntercept().ToString(("#,##0.00"))
    End Sub

    'add a data point (entered by the user) into a container'
    'Display the point in a listbox if it was accepted, else display an error message'
    Private Sub btnAddPoint_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnAddPoint.Click
        If (IsNumeric(txtXValue.Text) And IsNumeric(txtYValue.Text)) Then
            xValues.Add(Val(txtXValue.Text))
            yValues.Add(Val(txtYValue.Text))
            lstbxPoints.Items.Add("(" + txtXValue.Text + ", " + txtYValue.Text + ")")
        Else
            MsgBox("Error: Invalid Point.")
            txtXValue.Focus()
        End If
    End Sub

    'clear All the data points to prepare for a new calculation'
    Private Sub btnClear_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnClear.Click
        lstbxPoints.Items.Clear()
        xValues.Clear()
        yValues.Clear()

    End Sub
End Class
