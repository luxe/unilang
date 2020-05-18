<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmStates
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
        Me.msMenu = New System.Windows.Forms.MenuStrip()
        Me.FileToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.ExitToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.lblTitle = New System.Windows.Forms.Label()
        Me.btnDisplayStates = New System.Windows.Forms.Button()
        Me.btnDisplayStateAndDensity = New System.Windows.Forms.Button()
        Me.btnFindArea = New System.Windows.Forms.Button()
        Me.lblStateAbbreviation = New System.Windows.Forms.Label()
        Me.txtStateAbbreviation = New System.Windows.Forms.TextBox()
        Me.lstbxStates = New System.Windows.Forms.ListBox()
        Me.msMenu.SuspendLayout()
        Me.SuspendLayout()
        '
        'msMenu
        '
        Me.msMenu.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.FileToolStripMenuItem})
        Me.msMenu.Location = New System.Drawing.Point(0, 0)
        Me.msMenu.Name = "msMenu"
        Me.msMenu.Size = New System.Drawing.Size(436, 24)
        Me.msMenu.TabIndex = 0
        '
        'FileToolStripMenuItem
        '
        Me.FileToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.ExitToolStripMenuItem})
        Me.FileToolStripMenuItem.Name = "FileToolStripMenuItem"
        Me.FileToolStripMenuItem.Size = New System.Drawing.Size(37, 20)
        Me.FileToolStripMenuItem.Text = "File"
        '
        'ExitToolStripMenuItem
        '
        Me.ExitToolStripMenuItem.Name = "ExitToolStripMenuItem"
        Me.ExitToolStripMenuItem.Size = New System.Drawing.Size(92, 22)
        Me.ExitToolStripMenuItem.Text = "Exit"
        '
        'lblTitle
        '
        Me.lblTitle.AutoSize = True
        Me.lblTitle.Font = New System.Drawing.Font("Microsoft Sans Serif", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblTitle.Location = New System.Drawing.Point(12, 37)
        Me.lblTitle.Name = "lblTitle"
        Me.lblTitle.Size = New System.Drawing.Size(414, 25)
        Me.lblTitle.TabIndex = 1
        Me.lblTitle.Text = "Information about the American States"
        '
        'btnDisplayStates
        '
        Me.btnDisplayStates.Location = New System.Drawing.Point(78, 71)
        Me.btnDisplayStates.Name = "btnDisplayStates"
        Me.btnDisplayStates.Size = New System.Drawing.Size(82, 54)
        Me.btnDisplayStates.TabIndex = 2
        Me.btnDisplayStates.Text = "Display States Info."
        Me.btnDisplayStates.UseVisualStyleBackColor = True
        '
        'btnDisplayStateAndDensity
        '
        Me.btnDisplayStateAndDensity.Location = New System.Drawing.Point(166, 71)
        Me.btnDisplayStateAndDensity.Name = "btnDisplayStateAndDensity"
        Me.btnDisplayStateAndDensity.Size = New System.Drawing.Size(93, 54)
        Me.btnDisplayStateAndDensity.TabIndex = 3
        Me.btnDisplayStateAndDensity.Text = "Display Abbreviation and density"
        Me.btnDisplayStateAndDensity.UseVisualStyleBackColor = True
        '
        'btnFindArea
        '
        Me.btnFindArea.Location = New System.Drawing.Point(265, 71)
        Me.btnFindArea.Name = "btnFindArea"
        Me.btnFindArea.Size = New System.Drawing.Size(82, 54)
        Me.btnFindArea.TabIndex = 4
        Me.btnFindArea.Text = "Find Area of given state"
        Me.btnFindArea.UseVisualStyleBackColor = True
        '
        'lblStateAbbreviation
        '
        Me.lblStateAbbreviation.AutoSize = True
        Me.lblStateAbbreviation.Location = New System.Drawing.Point(127, 137)
        Me.lblStateAbbreviation.Name = "lblStateAbbreviation"
        Me.lblStateAbbreviation.Size = New System.Drawing.Size(97, 13)
        Me.lblStateAbbreviation.TabIndex = 5
        Me.lblStateAbbreviation.Text = "State Abbreviation:"
        '
        'txtStateAbbreviation
        '
        Me.txtStateAbbreviation.Location = New System.Drawing.Point(230, 134)
        Me.txtStateAbbreviation.Name = "txtStateAbbreviation"
        Me.txtStateAbbreviation.Size = New System.Drawing.Size(100, 20)
        Me.txtStateAbbreviation.TabIndex = 6
        '
        'lstbxStates
        '
        Me.lstbxStates.Font = New System.Drawing.Font("Courier New", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lstbxStates.FormattingEnabled = True
        Me.lstbxStates.ItemHeight = 14
        Me.lstbxStates.Location = New System.Drawing.Point(17, 162)
        Me.lstbxStates.Name = "lstbxStates"
        Me.lstbxStates.Size = New System.Drawing.Size(407, 130)
        Me.lstbxStates.TabIndex = 7
        '
        'frmStates
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(436, 311)
        Me.Controls.Add(Me.lstbxStates)
        Me.Controls.Add(Me.txtStateAbbreviation)
        Me.Controls.Add(Me.lblStateAbbreviation)
        Me.Controls.Add(Me.btnFindArea)
        Me.Controls.Add(Me.btnDisplayStateAndDensity)
        Me.Controls.Add(Me.btnDisplayStates)
        Me.Controls.Add(Me.lblTitle)
        Me.Controls.Add(Me.msMenu)
        Me.MainMenuStrip = Me.msMenu
        Me.Name = "frmStates"
        Me.Text = "U.S. States"
        Me.msMenu.ResumeLayout(False)
        Me.msMenu.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents msMenu As System.Windows.Forms.MenuStrip
    Friend WithEvents FileToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents ExitToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents lblTitle As System.Windows.Forms.Label
    Friend WithEvents btnDisplayStates As System.Windows.Forms.Button
    Friend WithEvents btnDisplayStateAndDensity As System.Windows.Forms.Button
    Friend WithEvents btnFindArea As System.Windows.Forms.Button
    Friend WithEvents lblStateAbbreviation As System.Windows.Forms.Label
    Friend WithEvents txtStateAbbreviation As System.Windows.Forms.TextBox
    Friend WithEvents lstbxStates As System.Windows.Forms.ListBox

End Class
