Public Class frmGraphics

    Structure PieChart
        Dim graphic As Graphics
        Dim radius As Integer
        Dim center As Integer
    End Structure

    Dim pie As PieChart

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDisplay.Click

        Dim sodaPercentage As Single = 0.529 * 360
        Dim beerPercentage As Single = 0.147 * 360
        Dim bottledWaterPercentage As Single = 0.111 * 360
        Dim OtherPercent As Single = 0.213 * 360

        pie.radius = 100
        pie.center = 105
        pie.graphic = picbxPieChart.CreateGraphics()

        BuildPiePiece(0, sodaPercentage, Brushes.AliceBlue)
        BuildPiePiece(sodaPercentage, beerPercentage, Brushes.BlanchedAlmond)
        BuildPiePiece(sodaPercentage + beerPercentage, bottledWaterPercentage, Brushes.Firebrick)
        BuildPiePiece(sodaPercentage + beerPercentage + bottledWaterPercentage, OtherPercent, Brushes.DarkOrange)
    End Sub


    Private Sub BuildPiePiece(ByVal startDegree As Single, ByVal endDegree As Single, ByVal color As System.Drawing.Brush)

        pie.graphic.FillPie(color, (pie.center - pie.radius), (pie.center - pie.radius), (2 * pie.radius), (2 * pie.radius), startDegree, endDegree)
    End Sub
End Class
