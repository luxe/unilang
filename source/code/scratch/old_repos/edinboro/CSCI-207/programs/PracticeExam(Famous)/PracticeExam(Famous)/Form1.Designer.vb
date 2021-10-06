<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
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
        Me.lstbxNames = New System.Windows.Forms.ListBox()
        Me.lstbxDates = New System.Windows.Forms.ListBox()
        Me.btnLoad = New System.Windows.Forms.Button()
        Me.btnSort = New System.Windows.Forms.Button()
        Me.btnAge = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lstbxNames
        '
        Me.lstbxNames.FormattingEnabled = True
        Me.lstbxNames.Location = New System.Drawing.Point(12, 41)
        Me.lstbxNames.Name = "lstbxNames"
        Me.lstbxNames.Size = New System.Drawing.Size(120, 95)
        Me.lstbxNames.TabIndex = 0
        '
        'lstbxDates
        '
        Me.lstbxDates.FormattingEnabled = True
        Me.lstbxDates.Location = New System.Drawing.Point(152, 41)
        Me.lstbxDates.Name = "lstbxDates"
        Me.lstbxDates.Size = New System.Drawing.Size(120, 95)
        Me.lstbxDates.TabIndex = 1
        '
        'btnLoad
        '
        Me.btnLoad.Location = New System.Drawing.Point(22, 12)
        Me.btnLoad.Name = "btnLoad"
        Me.btnLoad.Size = New System.Drawing.Size(75, 23)
        Me.btnLoad.TabIndex = 2
        Me.btnLoad.Text = "Load Data"
        Me.btnLoad.UseVisualStyleBackColor = True
        '
        'btnSort
        '
        Me.btnSort.Location = New System.Drawing.Point(184, 12)
        Me.btnSort.Name = "btnSort"
        Me.btnSort.Size = New System.Drawing.Size(75, 23)
        Me.btnSort.TabIndex = 3
        Me.btnSort.Text = "Born in 70s"
        Me.btnSort.UseVisualStyleBackColor = True
        '
        'btnAge
        '
        Me.btnAge.Location = New System.Drawing.Point(103, 12)
        Me.btnAge.Name = "btnAge"
        Me.btnAge.Size = New System.Drawing.Size(75, 23)
        Me.btnAge.TabIndex = 4
        Me.btnAge.Text = "Show Age"
        Me.btnAge.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 351)
        Me.Controls.Add(Me.btnAge)
        Me.Controls.Add(Me.btnSort)
        Me.Controls.Add(Me.btnLoad)
        Me.Controls.Add(Me.lstbxDates)
        Me.Controls.Add(Me.lstbxNames)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents lstbxNames As System.Windows.Forms.ListBox
    Friend WithEvents lstbxDates As System.Windows.Forms.ListBox
    Friend WithEvents btnLoad As System.Windows.Forms.Button
    Friend WithEvents btnSort As System.Windows.Forms.Button
    Friend WithEvents btnAge As System.Windows.Forms.Button

End Class
