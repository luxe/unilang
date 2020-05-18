<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmGraphics
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
        Me.picbxPieChart = New System.Windows.Forms.PictureBox()
        Me.btnDisplay = New System.Windows.Forms.Button()
        Me.txtValue1 = New System.Windows.Forms.TextBox()
        Me.txtValue2 = New System.Windows.Forms.TextBox()
        Me.txtValue3 = New System.Windows.Forms.TextBox()
        Me.txtValue4 = New System.Windows.Forms.TextBox()
        CType(Me.picbxPieChart, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'picbxPieChart
        '
        Me.picbxPieChart.Location = New System.Drawing.Point(12, 12)
        Me.picbxPieChart.Name = "picbxPieChart"
        Me.picbxPieChart.Size = New System.Drawing.Size(717, 438)
        Me.picbxPieChart.TabIndex = 0
        Me.picbxPieChart.TabStop = False
        '
        'btnDisplay
        '
        Me.btnDisplay.Font = New System.Drawing.Font("Microsoft Sans Serif", 21.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnDisplay.Location = New System.Drawing.Point(210, 538)
        Me.btnDisplay.Name = "btnDisplay"
        Me.btnDisplay.Size = New System.Drawing.Size(272, 60)
        Me.btnDisplay.TabIndex = 1
        Me.btnDisplay.Text = "Display"
        Me.btnDisplay.UseVisualStyleBackColor = True
        '
        'txtValue1
        '
        Me.txtValue1.Location = New System.Drawing.Point(104, 495)
        Me.txtValue1.Name = "txtValue1"
        Me.txtValue1.Size = New System.Drawing.Size(100, 20)
        Me.txtValue1.TabIndex = 2
        '
        'txtValue2
        '
        Me.txtValue2.Location = New System.Drawing.Point(104, 521)
        Me.txtValue2.Name = "txtValue2"
        Me.txtValue2.Size = New System.Drawing.Size(100, 20)
        Me.txtValue2.TabIndex = 3
        '
        'txtValue3
        '
        Me.txtValue3.Location = New System.Drawing.Point(104, 547)
        Me.txtValue3.Name = "txtValue3"
        Me.txtValue3.Size = New System.Drawing.Size(100, 20)
        Me.txtValue3.TabIndex = 4
        '
        'txtValue4
        '
        Me.txtValue4.Location = New System.Drawing.Point(104, 573)
        Me.txtValue4.Name = "txtValue4"
        Me.txtValue4.Size = New System.Drawing.Size(100, 20)
        Me.txtValue4.TabIndex = 5
        '
        'frmGraphics
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.SystemColors.AppWorkspace
        Me.ClientSize = New System.Drawing.Size(741, 610)
        Me.Controls.Add(Me.txtValue4)
        Me.Controls.Add(Me.txtValue3)
        Me.Controls.Add(Me.txtValue2)
        Me.Controls.Add(Me.txtValue1)
        Me.Controls.Add(Me.btnDisplay)
        Me.Controls.Add(Me.picbxPieChart)
        Me.Name = "frmGraphics"
        Me.Text = "Graphics"
        CType(Me.picbxPieChart, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents picbxPieChart As System.Windows.Forms.PictureBox
    Friend WithEvents btnDisplay As System.Windows.Forms.Button
    Friend WithEvents txtValue1 As System.Windows.Forms.TextBox
    Friend WithEvents txtValue2 As System.Windows.Forms.TextBox
    Friend WithEvents txtValue3 As System.Windows.Forms.TextBox
    Friend WithEvents txtValue4 As System.Windows.Forms.TextBox

End Class
