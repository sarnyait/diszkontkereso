<div id="summary">
  <div class="cart-row" data-row="row-x" data-product="<?php print $pid; ?>">
    <div class="cell no-width">
      <input type="button" value="x" class="cart-delete">
    </div>
    <div class="cell no-width">
      <input type="button" value="-" class="cart-minus">
    </div>
    <div class="amount cell"><?php print $amount; ?></div>
    <div class="cell no-width">
      <input type="button" value="+" class="cart-plus">
    </div>
    <div class="content cell"><?php print $product; ?></div>
    <div style="clear:both"></div>
  </div>
</div>
