<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmEnterPersonalInformation
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
        Me.txtPhoneNumber = New System.Windows.Forms.TextBox()
        Me.txtFullName = New System.Windows.Forms.TextBox()
        Me.lblDirections = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'txtPhoneNumber
        '
        Me.txtPhoneNumber.Location = New System.Drawing.Point(88, 63)
        Me.txtPhoneNumber.Name = "txtPhoneNumber"
        Me.txtPhoneNumber.Size = New System.Drawing.Size(100, 20)
        Me.txtPhoneNumber.TabIndex = 1
        '
        'txtFullName
        '
        Me.txtFullName.Location = New System.Drawing.Point(88, 24)
        Me.txtFullName.Name = "txtFullName"
        Me.txtFullName.Size = New System.Drawing.Size(100, 20)
        Me.txtFullName.TabIndex = 0
        '
        'lblDirections
        '
        Me.lblDirections.AutoSize = True
        Me.lblDirections.Location = New System.Drawing.Point(31, 46)
        Me.lblDirections.Name = "lblDirections"
        Me.lblDirections.Size = New System.Drawing.Size(0, 13)
        Me.lblDirections.TabIndex = 2
        '
        'frmEnterPersonalInformation
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(269, 111)
        Me.Controls.Add(Me.lblDirections)
        Me.Controls.Add(Me.txtFullName)
        Me.Controls.Add(Me.txtPhoneNumber)
        Me.Name = "frmEnterPersonalInformation"
        Me.Text = "Assignment 1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents txtPhoneNumber As System.Windows.Forms.TextBox
    Friend WithEvents txtFullName As System.Windows.Forms.TextBox
    Friend WithEvents lblDirections As System.Windows.Forms.Label

End Class
