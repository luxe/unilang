<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmStateLoad
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
        Me.frmClose = New System.Windows.Forms.Button()
        Me.lstbxStates = New System.Windows.Forms.ListBox()
        Me.SuspendLayout()
        '
        'frmClose
        '
        Me.frmClose.Location = New System.Drawing.Point(226, 258)
        Me.frmClose.Name = "frmClose"
        Me.frmClose.Size = New System.Drawing.Size(75, 23)
        Me.frmClose.TabIndex = 0
        Me.frmClose.Text = "Close"
        Me.frmClose.UseVisualStyleBackColor = True
        '
        'lstbxStates
        '
        Me.lstbxStates.FormattingEnabled = True
        Me.lstbxStates.Location = New System.Drawing.Point(12, 12)
        Me.lstbxStates.Name = "lstbxStates"
        Me.lstbxStates.Size = New System.Drawing.Size(518, 238)
        Me.lstbxStates.TabIndex = 1
        '
        'frmStateLoad
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(542, 307)
        Me.Controls.Add(Me.lstbxStates)
        Me.Controls.Add(Me.frmClose)
        Me.Name = "frmStateLoad"
        Me.Text = "State Load"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents frmClose As System.Windows.Forms.Button
    Friend WithEvents lstbxStates As System.Windows.Forms.ListBox
End Class
