<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmAutoRepair
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
        Me.lblCustomer = New System.Windows.Forms.Label()
        Me.txtCustomer = New System.Windows.Forms.TextBox()
        Me.lblHoursOfLabor = New System.Windows.Forms.Label()
        Me.txtHoursOfLabor = New System.Windows.Forms.TextBox()
        Me.lblPartCost = New System.Windows.Forms.Label()
        Me.lblSupplyCost = New System.Windows.Forms.Label()
        Me.txtCost = New System.Windows.Forms.TextBox()
        Me.lstbxCustomerBill = New System.Windows.Forms.ListBox()
        Me.btnDisplayBill = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'lblCustomer
        '
        Me.lblCustomer.AutoSize = True
        Me.lblCustomer.Location = New System.Drawing.Point(24, 9)
        Me.lblCustomer.Name = "lblCustomer"
        Me.lblCustomer.Size = New System.Drawing.Size(54, 13)
        Me.lblCustomer.TabIndex = 0
        Me.lblCustomer.Text = "Customer:"
        '
        'txtCustomer
        '
        Me.txtCustomer.Location = New System.Drawing.Point(91, 9)
        Me.txtCustomer.Name = "txtCustomer"
        Me.txtCustomer.Size = New System.Drawing.Size(159, 20)
        Me.txtCustomer.TabIndex = 1
        '
        'lblHoursOfLabor
        '
        Me.lblHoursOfLabor.AutoSize = True
        Me.lblHoursOfLabor.Location = New System.Drawing.Point(9, 35)
        Me.lblHoursOfLabor.Name = "lblHoursOfLabor"
        Me.lblHoursOfLabor.Size = New System.Drawing.Size(76, 13)
        Me.lblHoursOfLabor.TabIndex = 2
        Me.lblHoursOfLabor.Text = "Hours of labor:"
        '
        'txtHoursOfLabor
        '
        Me.txtHoursOfLabor.Location = New System.Drawing.Point(91, 35)
        Me.txtHoursOfLabor.Name = "txtHoursOfLabor"
        Me.txtHoursOfLabor.Size = New System.Drawing.Size(75, 20)
        Me.txtHoursOfLabor.TabIndex = 3
        '
        'lblPartCost
        '
        Me.lblPartCost.AutoSize = True
        Me.lblPartCost.Location = New System.Drawing.Point(12, 58)
        Me.lblPartCost.Name = "lblPartCost"
        Me.lblPartCost.Size = New System.Drawing.Size(66, 13)
        Me.lblPartCost.TabIndex = 4
        Me.lblPartCost.Text = "Cost of parts"
        '
        'lblSupplyCost
        '
        Me.lblSupplyCost.AutoSize = True
        Me.lblSupplyCost.Location = New System.Drawing.Point(13, 71)
        Me.lblSupplyCost.Name = "lblSupplyCost"
        Me.lblSupplyCost.Size = New System.Drawing.Size(69, 13)
        Me.lblSupplyCost.TabIndex = 5
        Me.lblSupplyCost.Text = "and supplies:"
        '
        'txtCost
        '
        Me.txtCost.Location = New System.Drawing.Point(91, 68)
        Me.txtCost.Name = "txtCost"
        Me.txtCost.Size = New System.Drawing.Size(75, 20)
        Me.txtCost.TabIndex = 6
        '
        'lstbxCustomerBill
        '
        Me.lstbxCustomerBill.Font = New System.Drawing.Font("Courier New", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lstbxCustomerBill.FormattingEnabled = True
        Me.lstbxCustomerBill.ItemHeight = 14
        Me.lstbxCustomerBill.Location = New System.Drawing.Point(16, 94)
        Me.lstbxCustomerBill.Name = "lstbxCustomerBill"
        Me.lstbxCustomerBill.Size = New System.Drawing.Size(234, 130)
        Me.lstbxCustomerBill.TabIndex = 7
        '
        'btnDisplayBill
        '
        Me.btnDisplayBill.Location = New System.Drawing.Point(172, 35)
        Me.btnDisplayBill.Name = "btnDisplayBill"
        Me.btnDisplayBill.Size = New System.Drawing.Size(78, 53)
        Me.btnDisplayBill.TabIndex = 8
        Me.btnDisplayBill.Text = "Display Bill"
        Me.btnDisplayBill.UseVisualStyleBackColor = True
        '
        'frmAutoRepair
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(262, 240)
        Me.Controls.Add(Me.btnDisplayBill)
        Me.Controls.Add(Me.lstbxCustomerBill)
        Me.Controls.Add(Me.txtCost)
        Me.Controls.Add(Me.lblSupplyCost)
        Me.Controls.Add(Me.lblPartCost)
        Me.Controls.Add(Me.txtHoursOfLabor)
        Me.Controls.Add(Me.lblHoursOfLabor)
        Me.Controls.Add(Me.txtCustomer)
        Me.Controls.Add(Me.lblCustomer)
        Me.Name = "frmAutoRepair"
        Me.Text = "A-1 Auto Repair"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents lblCustomer As System.Windows.Forms.Label
    Friend WithEvents txtCustomer As System.Windows.Forms.TextBox
    Friend WithEvents lblHoursOfLabor As System.Windows.Forms.Label
    Friend WithEvents txtHoursOfLabor As System.Windows.Forms.TextBox
    Friend WithEvents lblPartCost As System.Windows.Forms.Label
    Friend WithEvents lblSupplyCost As System.Windows.Forms.Label
    Friend WithEvents txtCost As System.Windows.Forms.TextBox
    Friend WithEvents lstbxCustomerBill As System.Windows.Forms.ListBox
    Friend WithEvents btnDisplayBill As System.Windows.Forms.Button

End Class
