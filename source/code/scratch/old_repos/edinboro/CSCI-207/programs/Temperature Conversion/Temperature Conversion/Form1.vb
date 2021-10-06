Public Class frmTemperatureConversion

    'Convert from Celsius to Fahrenheit'
    Private Function CelsiusToFahrenheit(ByVal temperature As Double) As Double
        Return Math.Round(((temperature - 32) * 5 / 9), 2)
    End Function

    'Convert from Fahrenheit to Celsius'
    Private Function FahrenheitToCelsius(ByVal temperature As Double) As Double
        Return Math.Round(((temperature * 9 / 5) + 32), 2)
    End Function

    'When pressed, Converts a value from Celsius to Fahrenheit and displays it.'
    Private Sub btnCelciusToFahrenheit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCelciusToFahrenheit.Click
        If txtTemperatureValue.TextLength <> 0 And IsNumeric(txtTemperatureValue.Text) = True Then
            txtConvertedTemperature.Text = txtTemperatureValue.Text & "° " & "Celcius = " & CelsiusToFahrenheit(CSng(txtTemperatureValue.Text)).ToString & "° " & "Fahrenheit"
        End If
    End Sub

    'When pressed, Converts a value from Fahrenheit to Celsius and displays it.'
    Private Sub btnFahrenheitToCelcius_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnFahrenheitToCelcius.Click
        If txtTemperatureValue.TextLength <> 0 And IsNumeric(txtTemperatureValue.Text) = True Then
            txtConvertedTemperature.Text = txtTemperatureValue.Text & "° " & "Fahrenheit = " & FahrenheitToCelsius(CSng(txtTemperatureValue.Text)).ToString & "° " & "Celcius"
        End If
    End Sub
End Class
