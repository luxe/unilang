<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmMenu
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
        Me.grpboxBurgers = New System.Windows.Forms.GroupBox()
        Me.rbBaconAndCheese = New System.Windows.Forms.RadioButton()
        Me.rbBacon = New System.Windows.Forms.RadioButton()
        Me.rbCheese = New System.Windows.Forms.RadioButton()
        Me.rbRegular = New System.Windows.Forms.RadioButton()
        Me.chkbxBurgers = New System.Windows.Forms.CheckBox()
        Me.grpbxFries = New System.Windows.Forms.GroupBox()
        Me.rbtrnMedium = New System.Windows.Forms.RadioButton()
        Me.rbtnLarge = New System.Windows.Forms.RadioButton()
        Me.rbtnSmall = New System.Windows.Forms.RadioButton()
        Me.chkbxFries = New System.Windows.Forms.CheckBox()
        Me.grpbxDrinks = New System.Windows.Forms.GroupBox()
        Me.rbtnWater = New System.Windows.Forms.RadioButton()
        Me.rbtnSoda = New System.Windows.Forms.RadioButton()
        Me.chkbxDrinks = New System.Windows.Forms.CheckBox()
        Me.btnComputeCost = New System.Windows.Forms.Button()
        Me.txtCost = New System.Windows.Forms.TextBox()
        Me.lblCost = New System.Windows.Forms.Label()
        Me.grpboxBurgers.SuspendLayout()
        Me.grpbxFries.SuspendLayout()
        Me.grpbxDrinks.SuspendLayout()
        Me.SuspendLayout()
        '
        'grpboxBurgers
        '
        Me.grpboxBurgers.Controls.Add(Me.rbBaconAndCheese)
        Me.grpboxBurgers.Controls.Add(Me.rbBacon)
        Me.grpboxBurgers.Controls.Add(Me.rbCheese)
        Me.grpboxBurgers.Controls.Add(Me.rbRegular)
        Me.grpboxBurgers.Location = New System.Drawing.Point(89, 12)
        Me.grpboxBurgers.Name = "grpboxBurgers"
        Me.grpboxBurgers.Size = New System.Drawing.Size(200, 117)
        Me.grpboxBurgers.TabIndex = 0
        Me.grpboxBurgers.TabStop = False
        Me.grpboxBurgers.Text = "Choices of Burgers"
        Me.grpboxBurgers.Visible = False
        '
        'rbBaconAndCheese
        '
        Me.rbBaconAndCheese.AutoSize = True
        Me.rbBaconAndCheese.Location = New System.Drawing.Point(7, 90)
        Me.rbBaconAndCheese.Name = "rbBaconAndCheese"
        Me.rbBaconAndCheese.Size = New System.Drawing.Size(160, 17)
        Me.rbBaconAndCheese.TabIndex = 3
        Me.rbBaconAndCheese.TabStop = True
        Me.rbBaconAndCheese.Text = "w/ bacon and cheese (5.39)"
        Me.rbBaconAndCheese.UseVisualStyleBackColor = True
        '
        'rbBacon
        '
        Me.rbBacon.AutoSize = True
        Me.rbBacon.Location = New System.Drawing.Point(7, 68)
        Me.rbBacon.Name = "rbBacon"
        Me.rbBacon.Size = New System.Drawing.Size(101, 17)
        Me.rbBacon.TabIndex = 2
        Me.rbBacon.TabStop = True
        Me.rbBacon.Text = "w/ bacon (4.79)"
        Me.rbBacon.UseVisualStyleBackColor = True
        '
        'rbCheese
        '
        Me.rbCheese.AutoSize = True
        Me.rbCheese.Location = New System.Drawing.Point(7, 44)
        Me.rbCheese.Name = "rbCheese"
        Me.rbCheese.Size = New System.Drawing.Size(106, 17)
        Me.rbCheese.TabIndex = 1
        Me.rbCheese.TabStop = True
        Me.rbCheese.Text = "w/ cheese (4.79)"
        Me.rbCheese.UseVisualStyleBackColor = True
        '
        'rbRegular
        '
        Me.rbRegular.AutoSize = True
        Me.rbRegular.Checked = True
        Me.rbRegular.Location = New System.Drawing.Point(7, 20)
        Me.rbRegular.Name = "rbRegular"
        Me.rbRegular.Size = New System.Drawing.Size(92, 17)
        Me.rbRegular.TabIndex = 0
        Me.rbRegular.TabStop = True
        Me.rbRegular.Text = "Regular (4.19)"
        Me.rbRegular.UseVisualStyleBackColor = True
        '
        'chkbxBurgers
        '
        Me.chkbxBurgers.AutoSize = True
        Me.chkbxBurgers.Checked = True
        Me.chkbxBurgers.CheckState = System.Windows.Forms.CheckState.Checked
        Me.chkbxBurgers.Location = New System.Drawing.Point(12, 57)
        Me.chkbxBurgers.Name = "chkbxBurgers"
        Me.chkbxBurgers.Size = New System.Drawing.Size(62, 17)
        Me.chkbxBurgers.TabIndex = 1
        Me.chkbxBurgers.Text = "Burgers"
        Me.chkbxBurgers.UseVisualStyleBackColor = True
        '
        'grpbxFries
        '
        Me.grpbxFries.Controls.Add(Me.rbtrnMedium)
        Me.grpbxFries.Controls.Add(Me.rbtnLarge)
        Me.grpbxFries.Controls.Add(Me.rbtnSmall)
        Me.grpbxFries.Location = New System.Drawing.Point(89, 135)
        Me.grpbxFries.Name = "grpbxFries"
        Me.grpbxFries.Size = New System.Drawing.Size(200, 92)
        Me.grpbxFries.TabIndex = 2
        Me.grpbxFries.TabStop = False
        Me.grpbxFries.Text = "Choices for Fries"
        Me.grpbxFries.Visible = False
        '
        'rbtrnMedium
        '
        Me.rbtrnMedium.AutoSize = True
        Me.rbtrnMedium.Location = New System.Drawing.Point(7, 43)
        Me.rbtrnMedium.Name = "rbtrnMedium"
        Me.rbtrnMedium.Size = New System.Drawing.Size(92, 17)
        Me.rbtrnMedium.TabIndex = 2
        Me.rbtrnMedium.TabStop = True
        Me.rbtrnMedium.Text = "Medium (3.09)"
        Me.rbtrnMedium.UseVisualStyleBackColor = True
        '
        'rbtnLarge
        '
        Me.rbtnLarge.AutoSize = True
        Me.rbtnLarge.Location = New System.Drawing.Point(7, 66)
        Me.rbtnLarge.Name = "rbtnLarge"
        Me.rbtnLarge.Size = New System.Drawing.Size(82, 17)
        Me.rbtnLarge.TabIndex = 1
        Me.rbtnLarge.TabStop = True
        Me.rbtnLarge.Text = "Large (4.99)"
        Me.rbtnLarge.UseVisualStyleBackColor = True
        '
        'rbtnSmall
        '
        Me.rbtnSmall.AutoSize = True
        Me.rbtnSmall.Checked = True
        Me.rbtnSmall.Location = New System.Drawing.Point(7, 20)
        Me.rbtnSmall.Name = "rbtnSmall"
        Me.rbtnSmall.Size = New System.Drawing.Size(80, 17)
        Me.rbtnSmall.TabIndex = 0
        Me.rbtnSmall.TabStop = True
        Me.rbtnSmall.Text = "Small (2.39)"
        Me.rbtnSmall.UseVisualStyleBackColor = True
        '
        'chkbxFries
        '
        Me.chkbxFries.AutoSize = True
        Me.chkbxFries.Checked = True
        Me.chkbxFries.CheckState = System.Windows.Forms.CheckState.Checked
        Me.chkbxFries.Location = New System.Drawing.Point(12, 179)
        Me.chkbxFries.Name = "chkbxFries"
        Me.chkbxFries.Size = New System.Drawing.Size(48, 17)
        Me.chkbxFries.TabIndex = 3
        Me.chkbxFries.Text = "Fries"
        Me.chkbxFries.UseVisualStyleBackColor = True
        '
        'grpbxDrinks
        '
        Me.grpbxDrinks.Controls.Add(Me.rbtnWater)
        Me.grpbxDrinks.Controls.Add(Me.rbtnSoda)
        Me.grpbxDrinks.Location = New System.Drawing.Point(89, 233)
        Me.grpbxDrinks.Name = "grpbxDrinks"
        Me.grpbxDrinks.Size = New System.Drawing.Size(200, 70)
        Me.grpbxDrinks.TabIndex = 4
        Me.grpbxDrinks.TabStop = False
        Me.grpbxDrinks.Text = "Choices for Drinks"
        Me.grpbxDrinks.Visible = False
        '
        'rbtnWater
        '
        Me.rbtnWater.AutoSize = True
        Me.rbtnWater.Location = New System.Drawing.Point(7, 43)
        Me.rbtnWater.Name = "rbtnWater"
        Me.rbtnWater.Size = New System.Drawing.Size(120, 17)
        Me.rbtnWater.TabIndex = 1
        Me.rbtnWater.TabStop = True
        Me.rbtnWater.Text = "Bottled Water (1.49)"
        Me.rbtnWater.UseVisualStyleBackColor = True
        '
        'rbtnSoda
        '
        Me.rbtnSoda.AutoSize = True
        Me.rbtnSoda.Checked = True
        Me.rbtnSoda.Location = New System.Drawing.Point(7, 20)
        Me.rbtnSoda.Name = "rbtnSoda"
        Me.rbtnSoda.Size = New System.Drawing.Size(80, 17)
        Me.rbtnSoda.TabIndex = 0
        Me.rbtnSoda.TabStop = True
        Me.rbtnSoda.Text = "Soda (1.69)"
        Me.rbtnSoda.UseVisualStyleBackColor = True
        '
        'chkbxDrinks
        '
        Me.chkbxDrinks.AutoSize = True
        Me.chkbxDrinks.Checked = True
        Me.chkbxDrinks.CheckState = System.Windows.Forms.CheckState.Checked
        Me.chkbxDrinks.Location = New System.Drawing.Point(12, 263)
        Me.chkbxDrinks.Name = "chkbxDrinks"
        Me.chkbxDrinks.Size = New System.Drawing.Size(56, 17)
        Me.chkbxDrinks.TabIndex = 5
        Me.chkbxDrinks.Text = "Drinks"
        Me.chkbxDrinks.UseVisualStyleBackColor = True
        '
        'btnComputeCost
        '
        Me.btnComputeCost.Location = New System.Drawing.Point(12, 309)
        Me.btnComputeCost.Name = "btnComputeCost"
        Me.btnComputeCost.Size = New System.Drawing.Size(277, 33)
        Me.btnComputeCost.TabIndex = 6
        Me.btnComputeCost.Text = "Compute Cost of Meal"
        Me.btnComputeCost.UseVisualStyleBackColor = True
        '
        'txtCost
        '
        Me.txtCost.Location = New System.Drawing.Point(131, 356)
        Me.txtCost.Name = "txtCost"
        Me.txtCost.ReadOnly = True
        Me.txtCost.Size = New System.Drawing.Size(159, 20)
        Me.txtCost.TabIndex = 7
        '
        'lblCost
        '
        Me.lblCost.AutoSize = True
        Me.lblCost.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblCost.Location = New System.Drawing.Point(1, 352)
        Me.lblCost.Name = "lblCost"
        Me.lblCost.Size = New System.Drawing.Size(131, 24)
        Me.lblCost.TabIndex = 8
        Me.lblCost.Text = "Cost of meal:"
        '
        'frmMenu
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(301, 386)
        Me.Controls.Add(Me.lblCost)
        Me.Controls.Add(Me.txtCost)
        Me.Controls.Add(Me.btnComputeCost)
        Me.Controls.Add(Me.chkbxDrinks)
        Me.Controls.Add(Me.grpbxDrinks)
        Me.Controls.Add(Me.chkbxFries)
        Me.Controls.Add(Me.grpbxFries)
        Me.Controls.Add(Me.chkbxBurgers)
        Me.Controls.Add(Me.grpboxBurgers)
        Me.Name = "frmMenu"
        Me.Text = "Menu"
        Me.grpboxBurgers.ResumeLayout(False)
        Me.grpboxBurgers.PerformLayout()
        Me.grpbxFries.ResumeLayout(False)
        Me.grpbxFries.PerformLayout()
        Me.grpbxDrinks.ResumeLayout(False)
        Me.grpbxDrinks.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents grpboxBurgers As System.Windows.Forms.GroupBox
    Friend WithEvents rbBaconAndCheese As System.Windows.Forms.RadioButton
    Friend WithEvents rbBacon As System.Windows.Forms.RadioButton
    Friend WithEvents rbCheese As System.Windows.Forms.RadioButton
    Friend WithEvents rbRegular As System.Windows.Forms.RadioButton
    Friend WithEvents chkbxBurgers As System.Windows.Forms.CheckBox
    Friend WithEvents grpbxFries As System.Windows.Forms.GroupBox
    Friend WithEvents rbtrnMedium As System.Windows.Forms.RadioButton
    Friend WithEvents rbtnLarge As System.Windows.Forms.RadioButton
    Friend WithEvents rbtnSmall As System.Windows.Forms.RadioButton
    Friend WithEvents chkbxFries As System.Windows.Forms.CheckBox
    Friend WithEvents grpbxDrinks As System.Windows.Forms.GroupBox
    Friend WithEvents rbtnWater As System.Windows.Forms.RadioButton
    Friend WithEvents rbtnSoda As System.Windows.Forms.RadioButton
    Friend WithEvents chkbxDrinks As System.Windows.Forms.CheckBox
    Friend WithEvents btnComputeCost As System.Windows.Forms.Button
    Friend WithEvents txtCost As System.Windows.Forms.TextBox
    Friend WithEvents lblCost As System.Windows.Forms.Label

End Class
