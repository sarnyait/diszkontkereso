<div id="summary" class="item item-from-<?php print $shop; ?>" data-pid="<?php print $pid; ?>">
  <div class="cart-row" data-row="row-x" data-product="<?php print $pid; ?>">
    <div class="content cell image" style="display:none;"><?php print $image; ?></div>
    <div class="plus-minus">
      <div class="cell no-width">
        <input type="button" value="-" class="cart-minus" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>">
      </div>
      <div class="amount cell" data-product="<?php print $pid; ?>" data-price="<?php print $origprice; ?>" data-weight="<?php print $origweight; ?>"><?php print $amount; ?></div>
      <div class="cell no-width">
        <input type="button" value="+" class="cart-plus" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>">
      </div>
    </div>
    <div class="weight cell" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>"><?php print $weight; ?></div>
    <div class="markup cell">kg</div>
    <div class="cell no-width">
      <input type="button" value="x" class="cart-delete" data-shop="<?php print $shop; ?>">
    </div>
    <div class="content cell"><?php print $product; ?></div>

    <div class="price cell" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>"><?php print $price; ?></div>
    <div class="markup cell">Ft</div>
    <div class="percent"><?php print $percent;?></div>


    <div style="clear:both"></div>
  </div>
</div>
