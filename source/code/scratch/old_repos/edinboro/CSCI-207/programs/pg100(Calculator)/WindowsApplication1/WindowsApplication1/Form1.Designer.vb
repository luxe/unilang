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
        Me.components = New System.ComponentModel.Container()
        Me.btnAdd = New System.Windows.Forms.Button()
        Me.btnSubtract = New System.Windows.Forms.Button()
        Me.btnMultiply = New System.Windows.Forms.Button()
        Me.NotifyIcon1 = New System.Windows.Forms.NotifyIcon(Me.components)
        Me.lblFirstNumber = New System.Windows.Forms.Label()
        Me.lblSecondNumber = New System.Windows.Forms.Label()
        Me.txtNumber1 = New System.Windows.Forms.MaskedTextBox()
        Me.txtNumber2 = New System.Windows.Forms.MaskedTextBox()
        Me.txtAnswer = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'btnAdd
        '
        Me.btnAdd.Location = New System.Drawing.Point(106, 58)
        Me.btnAdd.Name = "btnAdd"
        Me.btnAdd.Size = New System.Drawing.Size(30, 23)
        Me.btnAdd.TabIndex = 0
        Me.btnAdd.Text = "+"
        Me.btnAdd.UseVisualStyleBackColor = True
        '
        'btnSubtract
        '
        Me.btnSubtract.Location = New System.Drawing.Point(142, 58)
        Me.btnSubtract.Name = "btnSubtract"
        Me.btnSubtract.Size = New System.Drawing.Size(30, 23)
        Me.btnSubtract.TabIndex = 1
        Me.btnSubtract.Text = "-"
        Me.btnSubtract.UseVisualStyleBackColor = True
        '
        'btnMultiply
        '
        Me.btnMultiply.Location = New System.Drawing.Point(178, 58)
        Me.btnMultiply.Name = "btnMultiply"
        Me.btnMultiply.Size = New System.Drawing.Size(30, 23)
        Me.btnMultiply.TabIndex = 2
        Me.btnMultiply.Text = "x"
        Me.btnMultiply.UseVisualStyleBackColor = True
        '
        'NotifyIcon1
        '
        Me.NotifyIcon1.Text = "NotifyIcon1"
        Me.NotifyIcon1.Visible = True
        '
        'lblFirstNumber
        '
        Me.lblFirstNumber.AutoSize = True
        Me.lblFirstNumber.Location = New System.Drawing.Point(24, 9)
        Me.lblFirstNumber.Name = "lblFirstNumber"
        Me.lblFirstNumber.Size = New System.Drawing.Size(69, 13)
        Me.lblFirstNumber.TabIndex = 3
        Me.lblFirstNumber.Text = "First Number:"
        '
        'lblSecondNumber
        '
        Me.lblSecondNumber.AutoSize = True
        Me.lblSecondNumber.Location = New System.Drawing.Point(6, 35)
        Me.lblSecondNumber.Name = "lblSecondNumber"
        Me.lblSecondNumber.Size = New System.Drawing.Size(87, 13)
        Me.lblSecondNumber.TabIndex = 4
        Me.lblSecondNumber.Text = "Second Number:"
        '
        'txtNumber1
        '
        Me.txtNumber1.Location = New System.Drawing.Point(106, 6)
        Me.txtNumber1.Name = "txtNumber1"
        Me.txtNumber1.Size = New System.Drawing.Size(102, 20)
        Me.txtNumber1.TabIndex = 5
        '
        'txtNumber2
        '
        Me.txtNumber2.Location = New System.Drawing.Point(106, 32)
        Me.txtNumber2.Name = "txtNumber2"
        Me.txtNumber2.Size = New System.Drawing.Size(102, 20)
        Me.txtNumber2.TabIndex = 6
        '
        'txtAnswer
        '
        Me.txtAnswer.Location = New System.Drawing.Point(9, 95)
        Me.txtAnswer.Name = "txtAnswer"
        Me.txtAnswer.ReadOnly = True
        Me.txtAnswer.Size = New System.Drawing.Size(199, 20)
        Me.txtAnswer.TabIndex = 7
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(221, 127)
        Me.Controls.Add(Me.txtAnswer)
        Me.Controls.Add(Me.txtNumber2)
        Me.Controls.Add(Me.txtNumber1)
        Me.Controls.Add(Me.lblSecondNumber)
        Me.Controls.Add(Me.lblFirstNumber)
        Me.Controls.Add(Me.btnMultiply)
        Me.Controls.Add(Me.btnSubtract)
        Me.Controls.Add(Me.btnAdd)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnAdd As System.Windows.Forms.Button
    Friend WithEvents btnSubtract As System.Windows.Forms.Button
    Friend WithEvents btnMultiply As System.Windows.Forms.Button
    Friend WithEvents NotifyIcon1 As System.Windows.Forms.NotifyIcon
    Friend WithEvents lblFirstNumber As System.Windows.Forms.Label
    Friend WithEvents lblSecondNumber As System.Windows.Forms.Label
    Friend WithEvents txtNumber1 As System.Windows.Forms.MaskedTextBox
    Friend WithEvents txtNumber2 As System.Windows.Forms.MaskedTextBox
    Friend WithEvents txtAnswer As System.Windows.Forms.TextBox

End Class
