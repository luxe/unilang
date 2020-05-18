<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmLinearRegression
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
        Me.btnCalculate = New System.Windows.Forms.Button()
        Me.txtMValue = New System.Windows.Forms.TextBox()
        Me.txtBValue = New System.Windows.Forms.TextBox()
        Me.lstbxPoints = New System.Windows.Forms.ListBox()
        Me.txtXValue = New System.Windows.Forms.TextBox()
        Me.lblXValue = New System.Windows.Forms.Label()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.txtYValue = New System.Windows.Forms.TextBox()
        Me.btnAddPoint = New System.Windows.Forms.Button()
        Me.btnClear = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'btnCalculate
        '
        Me.btnCalculate.Location = New System.Drawing.Point(9, 91)
        Me.btnCalculate.Name = "btnCalculate"
        Me.btnCalculate.Size = New System.Drawing.Size(153, 23)
        Me.btnCalculate.TabIndex = 4
        Me.btnCalculate.Text = "Calculate"
        Me.btnCalculate.UseVisualStyleBackColor = True
        '
        'txtMValue
        '
        Me.txtMValue.Location = New System.Drawing.Point(9, 120)
        Me.txtMValue.Name = "txtMValue"
        Me.txtMValue.ReadOnly = True
        Me.txtMValue.Size = New System.Drawing.Size(153, 20)
        Me.txtMValue.TabIndex = 5
        '
        'txtBValue
        '
        Me.txtBValue.Location = New System.Drawing.Point(9, 146)
        Me.txtBValue.Name = "txtBValue"
        Me.txtBValue.ReadOnly = True
        Me.txtBValue.Size = New System.Drawing.Size(153, 20)
        Me.txtBValue.TabIndex = 6
        '
        'lstbxPoints
        '
        Me.lstbxPoints.FormattingEnabled = True
        Me.lstbxPoints.Location = New System.Drawing.Point(168, 33)
        Me.lstbxPoints.Name = "lstbxPoints"
        Me.lstbxPoints.Size = New System.Drawing.Size(148, 108)
        Me.lstbxPoints.TabIndex = 7
        '
        'txtXValue
        '
        Me.txtXValue.Location = New System.Drawing.Point(59, 35)
        Me.txtXValue.Name = "txtXValue"
        Me.txtXValue.Size = New System.Drawing.Size(43, 20)
        Me.txtXValue.TabIndex = 8
        '
        'lblXValue
        '
        Me.lblXValue.AutoSize = True
        Me.lblXValue.Location = New System.Drawing.Point(6, 38)
        Me.lblXValue.Name = "lblXValue"
        Me.lblXValue.Size = New System.Drawing.Size(47, 13)
        Me.lblXValue.TabIndex = 9
        Me.lblXValue.Text = "X Value:"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(6, 68)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(47, 13)
        Me.Label1.TabIndex = 10
        Me.Label1.Text = "Y Value:"
        '
        'txtYValue
        '
        Me.txtYValue.Location = New System.Drawing.Point(59, 65)
        Me.txtYValue.Name = "txtYValue"
        Me.txtYValue.Size = New System.Drawing.Size(43, 20)
        Me.txtYValue.TabIndex = 11
        '
        'btnAddPoint
        '
        Me.btnAddPoint.Location = New System.Drawing.Point(108, 33)
        Me.btnAddPoint.Name = "btnAddPoint"
        Me.btnAddPoint.Size = New System.Drawing.Size(54, 52)
        Me.btnAddPoint.TabIndex = 12
        Me.btnAddPoint.Text = "Add Point"
        Me.btnAddPoint.UseVisualStyleBackColor = True
        '
        'btnClear
        '
        Me.btnClear.Location = New System.Drawing.Point(168, 147)
        Me.btnClear.Name = "btnClear"
        Me.btnClear.Size = New System.Drawing.Size(148, 22)
        Me.btnClear.TabIndex = 13
        Me.btnClear.Text = "Clear"
        Me.btnClear.UseVisualStyleBackColor = True
        '
        'frmLinearRegression
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(328, 187)
        Me.Controls.Add(Me.btnClear)
        Me.Controls.Add(Me.btnAddPoint)
        Me.Controls.Add(Me.txtYValue)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.lblXValue)
        Me.Controls.Add(Me.txtXValue)
        Me.Controls.Add(Me.lstbxPoints)
        Me.Controls.Add(Me.txtBValue)
        Me.Controls.Add(Me.txtMValue)
        Me.Controls.Add(Me.btnCalculate)
        Me.Name = "frmLinearRegression"
        Me.Text = "Linear Regression"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnCalculate As System.Windows.Forms.Button
    Friend WithEvents txtMValue As System.Windows.Forms.TextBox
    Friend WithEvents txtBValue As System.Windows.Forms.TextBox
    Friend WithEvents lstbxPoints As System.Windows.Forms.ListBox
    Friend WithEvents txtXValue As System.Windows.Forms.TextBox
    Friend WithEvents lblXValue As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents txtYValue As System.Windows.Forms.TextBox
    Friend WithEvents btnAddPoint As System.Windows.Forms.Button
    Friend WithEvents btnClear As System.Windows.Forms.Button

End Class
