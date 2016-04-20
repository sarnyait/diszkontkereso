<div id="summary">
  <div class="cart-row" data-row="row-x" data-product="<?php print $pid; ?>">

    <div class="content cell"><?php print $product; ?></div>

    <div class="cell no-width">
      <input type="button" value="-" class="cart-minus">
    </div>
    <div class="amount cell"><?php print $amount; ?></div>
    <div class="cell no-width">
      <input type="button" value="+" class="cart-plus">
    </div>
    <div class="markup cell">db</div>
    <div class="weight cell"><?php print $weight; ?></div>
    <div class="markup cell">kg</div>

    <div class="weight cell"><?php print $price; ?></div>
    <div class="markup cell">Ft</div>

    <div class="cell no-width">
      <input type="button" value="x" class="cart-delete">
    </div>
    <div style="clear:both"></div>
  </div>
</div>
