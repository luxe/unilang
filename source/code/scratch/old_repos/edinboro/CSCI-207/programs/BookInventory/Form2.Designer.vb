<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmDetails
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
        Me.txtTitle = New System.Windows.Forms.TextBox()
        Me.txtAuthor = New System.Windows.Forms.TextBox()
        Me.txtStock = New System.Windows.Forms.TextBox()
        Me.TextBox4 = New System.Windows.Forms.TextBox()
        Me.lblTitle = New System.Windows.Forms.Label()
        Me.lblAuthor = New System.Windows.Forms.Label()
        Me.lblStock = New System.Windows.Forms.Label()
        Me.lblPrice = New System.Windows.Forms.Label()
        Me.gbCategory = New System.Windows.Forms.GroupBox()
        Me.rbFiction = New System.Windows.Forms.RadioButton()
        Me.rbNonfiction = New System.Windows.Forms.RadioButton()
        Me.btnRecord = New System.Windows.Forms.Button()
        Me.gbCategory.SuspendLayout()
        Me.SuspendLayout()
        '
        'txtTitle
        '
        Me.txtTitle.Location = New System.Drawing.Point(57, 14)
        Me.txtTitle.Name = "txtTitle"
        Me.txtTitle.Size = New System.Drawing.Size(146, 20)
        Me.txtTitle.TabIndex = 0
        '
        'txtAuthor
        '
        Me.txtAuthor.Location = New System.Drawing.Point(57, 43)
        Me.txtAuthor.Name = "txtAuthor"
        Me.txtAuthor.Size = New System.Drawing.Size(146, 20)
        Me.txtAuthor.TabIndex = 1
        '
        'txtStock
        '
        Me.txtStock.Location = New System.Drawing.Point(57, 69)
        Me.txtStock.Name = "txtStock"
        Me.txtStock.Size = New System.Drawing.Size(43, 20)
        Me.txtStock.TabIndex = 2
        '
        'TextBox4
        '
        Me.TextBox4.Location = New System.Drawing.Point(57, 95)
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.Size = New System.Drawing.Size(43, 20)
        Me.TextBox4.TabIndex = 3
        '
        'lblTitle
        '
        Me.lblTitle.AutoSize = True
        Me.lblTitle.Location = New System.Drawing.Point(21, 17)
        Me.lblTitle.Name = "lblTitle"
        Me.lblTitle.Size = New System.Drawing.Size(30, 13)
        Me.lblTitle.TabIndex = 4
        Me.lblTitle.Text = "Title:"
        '
        'lblAuthor
        '
        Me.lblAuthor.AutoSize = True
        Me.lblAuthor.Location = New System.Drawing.Point(10, 46)
        Me.lblAuthor.Name = "lblAuthor"
        Me.lblAuthor.Size = New System.Drawing.Size(41, 13)
        Me.lblAuthor.TabIndex = 5
        Me.lblAuthor.Text = "Author:"
        '
        'lblStock
        '
        Me.lblStock.AutoSize = True
        Me.lblStock.Location = New System.Drawing.Point(13, 72)
        Me.lblStock.Name = "lblStock"
        Me.lblStock.Size = New System.Drawing.Size(38, 13)
        Me.lblStock.TabIndex = 6
        Me.lblStock.Text = "Stock:"
        '
        'lblPrice
        '
        Me.lblPrice.AutoSize = True
        Me.lblPrice.Location = New System.Drawing.Point(17, 98)
        Me.lblPrice.Name = "lblPrice"
        Me.lblPrice.Size = New System.Drawing.Size(34, 13)
        Me.lblPrice.TabIndex = 7
        Me.lblPrice.Text = "Price:"
        '
        'gbCategory
        '
        Me.gbCategory.Controls.Add(Me.rbNonfiction)
        Me.gbCategory.Controls.Add(Me.rbFiction)
        Me.gbCategory.Location = New System.Drawing.Point(106, 69)
        Me.gbCategory.Name = "gbCategory"
        Me.gbCategory.Size = New System.Drawing.Size(98, 68)
        Me.gbCategory.TabIndex = 8
        Me.gbCategory.TabStop = False
        Me.gbCategory.Text = "Category"
        '
        'rbFiction
        '
        Me.rbFiction.AutoSize = True
        Me.rbFiction.Location = New System.Drawing.Point(7, 20)
        Me.rbFiction.Name = "rbFiction"
        Me.rbFiction.Size = New System.Drawing.Size(56, 17)
        Me.rbFiction.TabIndex = 0
        Me.rbFiction.TabStop = True
        Me.rbFiction.Text = "Fiction"
        Me.rbFiction.UseVisualStyleBackColor = True
        '
        'rbNonfiction
        '
        Me.rbNonfiction.AutoSize = True
        Me.rbNonfiction.Location = New System.Drawing.Point(7, 44)
        Me.rbNonfiction.Name = "rbNonfiction"
        Me.rbNonfiction.Size = New System.Drawing.Size(73, 17)
        Me.rbNonfiction.TabIndex = 1
        Me.rbNonfiction.TabStop = True
        Me.rbNonfiction.Text = "Nonfiction"
        Me.rbNonfiction.UseVisualStyleBackColor = True
        '
        'btnRecord
        '
        Me.btnRecord.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnRecord.Location = New System.Drawing.Point(57, 143)
        Me.btnRecord.Name = "btnRecord"
        Me.btnRecord.Size = New System.Drawing.Size(98, 24)
        Me.btnRecord.TabIndex = 9
        Me.btnRecord.Text = "Record Details"
        Me.btnRecord.UseVisualStyleBackColor = True
        '
        'frmDetails
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(215, 177)
        Me.Controls.Add(Me.btnRecord)
        Me.Controls.Add(Me.gbCategory)
        Me.Controls.Add(Me.lblPrice)
        Me.Controls.Add(Me.lblStock)
        Me.Controls.Add(Me.lblAuthor)
        Me.Controls.Add(Me.lblTitle)
        Me.Controls.Add(Me.TextBox4)
        Me.Controls.Add(Me.txtStock)
        Me.Controls.Add(Me.txtAuthor)
        Me.Controls.Add(Me.txtTitle)
        Me.Name = "frmDetails"
        Me.Text = "Details"
        Me.gbCategory.ResumeLayout(False)
        Me.gbCategory.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents txtTitle As System.Windows.Forms.TextBox
    Friend WithEvents txtAuthor As System.Windows.Forms.TextBox
    Friend WithEvents txtStock As System.Windows.Forms.TextBox
    Friend WithEvents TextBox4 As System.Windows.Forms.TextBox
    Friend WithEvents lblTitle As System.Windows.Forms.Label
    Friend WithEvents lblAuthor As System.Windows.Forms.Label
    Friend WithEvents lblStock As System.Windows.Forms.Label
    Friend WithEvents lblPrice As System.Windows.Forms.Label
    Friend WithEvents gbCategory As System.Windows.Forms.GroupBox
    Friend WithEvents rbNonfiction As System.Windows.Forms.RadioButton
    Friend WithEvents rbFiction As System.Windows.Forms.RadioButton
    Friend WithEvents btnRecord As System.Windows.Forms.Button
End Class
