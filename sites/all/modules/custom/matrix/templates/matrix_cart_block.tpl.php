<div id="summary" class="item item-from-<?php print $shop; ?>" data-pid="<?php print $pid; ?>">
  <div class="cart-row" data-row="row-x" data-product="<?php print $pid; ?>">
    <div class="content cell image" style="display:none;"><?php print $image; ?></div>
    <div class="plus-minus">
      <div class="cell no-width">
        <input type="button" value="-" class="cart-minus" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>">
      </div>
      <div class="amount cell" data-product="<?php print $pid; ?>" data-price="<?php print $origprice; ?>" data-weight="<?php print $origweight; ?>"><?php print $amount; ?></div>
      <div class="weight cell element-remove" data-shop="<?php print $shop; ?>" data-product="<?php print $pid; ?>" data-price="<?php print $origprice; ?>" data-weight="<?php print $origweight; ?>"><?php print $weight; ?></div>
      <div class="cell no-width">
        <input type="button" value="+" class="cart-plus" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>">
      </div>
    </div>
    <div class="amount-change">
      <div class="amount piece">
        <div class="markup cell piece-unit" data-product="<?php print $pid; ?>">db</div>
        <div class="markup cell weight-unit element-remove" data-product="<?php print $pid; ?>">kg</div>
      </div>
      <?php if ($weight > 0) { ?>
        <div class="markup cell piece-selector"><span class="label">change</span>
          <div class="amount-selector-popup element-invisible">
            <div class="amount-in-weight" data-product="<?php print $pid; ?>"><?php print t('Weight (kg)'); ?></div>
            <div class="amount-in-piece" data-product="<?php print $pid; ?>"><?php print t('Piece (pc)'); ?></div>
          </div>
        </div>
      <?php } ?>
    </div>
    <div class="cell no-width">
      <input type="button" value="x" class="cart-delete" data-shop="<?php print $shop; ?>">
    </div>
    <div class="content cell"><?php print $product_short; ?></div>

    <div class="price cell" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>"><?php print $price; ?></div>
    <div class="markup cell">Ft</div>
    <div class="percent"><?php print $percent;?></div>


    <div style="clear:both"></div>
  </div>
</div>
