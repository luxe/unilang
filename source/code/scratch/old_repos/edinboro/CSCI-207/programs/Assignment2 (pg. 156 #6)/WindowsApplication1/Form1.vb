Public Class frmMenu

    'Burger Prices'
    Const PRICE_OF_REGULAR_BURGER As Single = 4.19
    Const PRICE_OF_CHEESE_BURGER As Single = 4.79
    Const PRICE_OF_BACON_BURGER As Single = 4.79
    Const PRICE_OF_BACON_CHEESE_BURGER As Single = 5.39

    'Prices of Fries'
    Const PRICE_OF_SMALL_FRY As Single = 2.39
    Const PRICE_OF_MEDIUM_FRY As Single = 3.09
    Const PRICE_OF_LARGE_FRY As Single = 4.99

    'Price of Drinks'
    Const PRICE_OF_SODA As Single = 1.69
    Const PRICE_OF_BOTTLED_WATER As Single = 1.49

    'Open or close options depending on if the user wants a burger'
    Private Sub chkbxBurgers_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles chkbxBurgers.CheckedChanged
        If chkbxBurgers.Checked Then
            grpboxBurgers.Visible = True
        Else
            grpboxBurgers.Visible = False
        End If
    End Sub

    'Open or close options depending on if the user wants fries'
    Private Sub chkbxFries_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles chkbxFries.CheckedChanged
        If chkbxFries.Checked Then
            grpbxFries.Visible = True
        Else
            grpbxFries.Visible = False
        End If
    End Sub

    'Open or close options depending on if the user wants a drink'
    Private Sub chkbxDrinks_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles chkbxDrinks.CheckedChanged
        If chkbxDrinks.Checked Then
            grpbxDrinks.Visible = True
        Else
            grpbxDrinks.Visible = False
        End If
    End Sub

    'Calculate the cost of the meal and return the price to the user'
    Private Sub btnComputeCost_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnComputeCost.Click

        Dim totalCost As Single = 0

        totalCost += GetCostOfBurger()
        totalCost += GetCostOfFries()
        totalCost += GetCostOfDrink()

        If totalCost = 0 Then
            txtCost.Text = "customer must order something!"
        Else
            txtCost.Text = "$" + Math.Round(totalCost, 2).ToString()
        End If

    End Sub

    'Check if the customer purchased a burger, and return the appropiate price'
    Private Function GetCostOfBurger() As Single

        Dim costOfBurger As Single = 0

        'find the users choice of burger (if they ordered one at all)'
        If (grpboxBurgers.Visible) Then
            If (rbRegular.Checked) Then
                costOfBurger = PRICE_OF_REGULAR_BURGER
            ElseIf (rbCheese.Checked) Then
                costOfBurger = PRICE_OF_CHEESE_BURGER
            ElseIf (rbBacon.Checked) Then
                costOfBurger = PRICE_OF_BACON_BURGER
            ElseIf (rbBaconAndCheese.Checked) Then
                costOfBurger = PRICE_OF_BACON_CHEESE_BURGER
            End If
        End If

        Return costOfBurger
    End Function

    'Check if the customer purchased fries, and return the appropiate price'
    Private Function GetCostOfFries() As Single

        Dim costOfFries As Single = 0

        'find the users choice of fries (if they ordered some at all)'
        If (grpbxFries.Visible) Then
            If (rbtnSmall.Checked) Then
                costOfFries = PRICE_OF_SMALL_FRY
            ElseIf (rbtrnMedium.Checked) Then
                costOfFries = PRICE_OF_MEDIUM_FRY
            ElseIf (rbtnLarge.Checked) Then
                costOfFries = PRICE_OF_LARGE_FRY
            End If
        End If

        Return costOfFries
    End Function

    'Check if the customer purchased a drink, and return the appropiate price'
    Private Function GetCostOfDrink() As Single

        Dim costOfDrink As Single = 0

        'find the users choice of drink (if they ordered one at all)'
        If (grpbxDrinks.Visible) Then
            If (rbtnSoda.Checked) Then
                costOfDrink = PRICE_OF_SODA
            ElseIf (rbtnWater.Checked) Then
                costOfDrink = PRICE_OF_BOTTLED_WATER
            End If
        End If

        Return costOfDrink
    End Function

End Class
