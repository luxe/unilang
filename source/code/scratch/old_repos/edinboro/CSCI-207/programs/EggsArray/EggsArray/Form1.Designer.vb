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
        Me.btnLoad = New System.Windows.Forms.Button()
        Me.lstbxEggs = New System.Windows.Forms.ListBox()
        Me.SuspendLayout()
        '
        'btnLoad
        '
        Me.btnLoad.Location = New System.Drawing.Point(42, 12)
        Me.btnLoad.Name = "btnLoad"
        Me.btnLoad.Size = New System.Drawing.Size(75, 23)
        Me.btnLoad.TabIndex = 0
        Me.btnLoad.Text = "Load Array"
        Me.btnLoad.UseVisualStyleBackColor = True
        '
        'lstbxEggs
        '
        Me.lstbxEggs.FormattingEnabled = True
        Me.lstbxEggs.Location = New System.Drawing.Point(12, 41)
        Me.lstbxEggs.Name = "lstbxEggs"
        Me.lstbxEggs.Size = New System.Drawing.Size(133, 82)
        Me.lstbxEggs.TabIndex = 1
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(158, 141)
        Me.Controls.Add(Me.lstbxEggs)
        Me.Controls.Add(Me.btnLoad)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents btnLoad As System.Windows.Forms.Button
    Friend WithEvents lstbxEggs As System.Windows.Forms.ListBox

End Class
