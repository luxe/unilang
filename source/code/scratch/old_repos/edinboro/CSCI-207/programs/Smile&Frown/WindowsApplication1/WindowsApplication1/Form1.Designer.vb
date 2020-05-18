<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmFace
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
        Me.lblFace = New System.Windows.Forms.Label()
        Me.btnSmile = New System.Windows.Forms.Button()
        Me.btnFrown = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lblFace
        '
        Me.lblFace.AutoSize = True
        Me.lblFace.Font = New System.Drawing.Font("Wingdings", 39.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(2, Byte))
        Me.lblFace.ForeColor = System.Drawing.Color.Black
        Me.lblFace.Location = New System.Drawing.Point(44, 1)
        Me.lblFace.Name = "lblFace"
        Me.lblFace.Size = New System.Drawing.Size(70, 58)
        Me.lblFace.TabIndex = 0
        Me.lblFace.Text = "J"
        Me.lblFace.TextAlign = System.Drawing.ContentAlignment.TopCenter
        '
        'btnSmile
        '
        Me.btnSmile.Location = New System.Drawing.Point(39, 62)
        Me.btnSmile.Name = "btnSmile"
        Me.btnSmile.Size = New System.Drawing.Size(75, 23)
        Me.btnSmile.TabIndex = 1
        Me.btnSmile.Text = "Smile"
        Me.btnSmile.UseVisualStyleBackColor = True
        Me.btnSmile.Visible = False
        '
        'btnFrown
        '
        Me.btnFrown.Location = New System.Drawing.Point(39, 62)
        Me.btnFrown.Name = "btnFrown"
        Me.btnFrown.Size = New System.Drawing.Size(75, 23)
        Me.btnFrown.TabIndex = 2
        Me.btnFrown.Text = "Frown"
        Me.btnFrown.UseVisualStyleBackColor = True
        '
        'frmFace
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.DodgerBlue
        Me.ClientSize = New System.Drawing.Size(161, 104)
        Me.Controls.Add(Me.btnFrown)
        Me.Controls.Add(Me.btnSmile)
        Me.Controls.Add(Me.lblFace)
        Me.Name = "frmFace"
        Me.Text = "Face"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents lblFace As System.Windows.Forms.Label
    Friend WithEvents btnSmile As System.Windows.Forms.Button
    Friend WithEvents btnFrown As System.Windows.Forms.Button

End Class
