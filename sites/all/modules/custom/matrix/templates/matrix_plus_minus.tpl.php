<div class="plus-minus">
  <div class="cell no-width">
    <input type="button" value="-" class="cart-inline-minus" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>">
  </div>
  <input class="inline-amount cell" type="number" pattern="[0-9]*" data-product="<?php print $pid; ?>" data-price="<?php print $origprice; ?>" data-weight="<?php print $origweight; ?>" value="1">
  <div class="inline-weight cell element-remove" data-shop="<?php print $shop; ?>" data-product="<?php print $pid; ?>" data-price="<?php print $origprice; ?>" data-weight="<?php print $origweight; ?>"><?php print $origweight; ?></div>
  <div class="cell no-width">
    <input type="button" value="+" class="cart-inline-plus" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>">
  </div>
</div>
<?php if ($selector) { ?>
<div class="amount-change">
  <div class="amount piece">
    <div class="markup cell inline-piece-unit" data-product="<?php print $pid; ?>">db</div>
    <div class="markup cell inline-weight-unit element-remove" data-product="<?php print $pid; ?>">kg</div>
  </div>
    <div class="markup cell inline-piece-selector"><span class="label">change</span>
      <div class="amount-selector-popup element-invisible">
        <div class="amount-in-weight-inline" data-product="<?php print $pid; ?>"><?php print t('Weight (kg)'); ?></div>
        <div class="amount-in-piece-inline" data-product="<?php print $pid; ?>"><?php print t('Piece (pc)'); ?></div>
      </div>
    </div>
</div>
<?php } ?>
<div class="add-to-cart matrixBaseXxx-processed test-class" data-product="<?php print $pid; ?>" style="cursor: pointer;">Kosárba!</div>