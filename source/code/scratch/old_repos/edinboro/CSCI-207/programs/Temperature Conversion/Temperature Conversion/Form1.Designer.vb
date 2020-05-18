<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmTemperatureConversion
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.txtTemperatureValue = New System.Windows.Forms.TextBox()
        Me.txtConvertedTemperature = New System.Windows.Forms.TextBox()
        Me.btnCelciusToFahrenheit = New System.Windows.Forms.Button()
        Me.btnFahrenheitToCelcius = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'txtTemperatureValue
        '
        Me.txtTemperatureValue.Location = New System.Drawing.Point(115, 12)
        Me.txtTemperatureValue.Name = "txtTemperatureValue"
        Me.txtTemperatureValue.Size = New System.Drawing.Size(55, 20)
        Me.txtTemperatureValue.TabIndex = 0
        '
        'txtConvertedTemperature
        '
        Me.txtConvertedTemperature.Location = New System.Drawing.Point(65, 67)
        Me.txtConvertedTemperature.Name = "txtConvertedTemperature"
        Me.txtConvertedTemperature.ReadOnly = True
        Me.txtConvertedTemperature.Size = New System.Drawing.Size(157, 20)
        Me.txtConvertedTemperature.TabIndex = 1
        '
        'btnCelciusToFahrenheit
        '
        Me.btnCelciusToFahrenheit.Location = New System.Drawing.Point(12, 38)
        Me.btnCelciusToFahrenheit.Name = "btnCelciusToFahrenheit"
        Me.btnCelciusToFahrenheit.Size = New System.Drawing.Size(127, 23)
        Me.btnCelciusToFahrenheit.TabIndex = 2
        Me.btnCelciusToFahrenheit.Text = "Celcius To Fahrenheit"
        Me.btnCelciusToFahrenheit.UseVisualStyleBackColor = True
        '
        'btnFahrenheitToCelcius
        '
        Me.btnFahrenheitToCelcius.Location = New System.Drawing.Point(145, 38)
        Me.btnFahrenheitToCelcius.Name = "btnFahrenheitToCelcius"
        Me.btnFahrenheitToCelcius.Size = New System.Drawing.Size(127, 23)
        Me.btnFahrenheitToCelcius.TabIndex = 3
        Me.btnFahrenheitToCelcius.Text = "Fahrenheit To Celcius"
        Me.btnFahrenheitToCelcius.UseVisualStyleBackColor = True
        '
        'frmTemperatureConversion
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 109)
        Me.Controls.Add(Me.btnFahrenheitToCelcius)
        Me.Controls.Add(Me.btnCelciusToFahrenheit)
        Me.Controls.Add(Me.txtConvertedTemperature)
        Me.Controls.Add(Me.txtTemperatureValue)
        Me.Name = "frmTemperatureConversion"
        Me.Text = "Temperature Conversion"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents txtTemperatureValue As System.Windows.Forms.TextBox
    Friend WithEvents txtConvertedTemperature As System.Windows.Forms.TextBox
    Friend WithEvents btnCelciusToFahrenheit As System.Windows.Forms.Button
    Friend WithEvents btnFahrenheitToCelcius As System.Windows.Forms.Button

End Class
