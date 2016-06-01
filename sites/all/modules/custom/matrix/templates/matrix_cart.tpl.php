<div id="cart-popup" class="remodal" data-remodal-id="modal">
  <div class="modal-message"><?php print $message; ?></div>
  <a data-remodal-action="close" class="remodal-close"></a>
  <a data-remodal-action="close" class="remodal-yes" href="#"><?php print $yes; ?></a>
  <a data-remodal-action="cancel" class="remodal-cancel" href="#"><?php print $no; ?></a>
</div>
<div id="summary" class="item item-from-<?php print $shop; ?>" data-pid="<?php print $pid; ?>">
  <div class="cart-row" data-row="row-x" data-product="<?php print $pid; ?>">
    <div class="content cell"><?php print $image; ?></div>
    <div class="content cell"><?php print $product; ?></div>
    <div class="plus-minus">
      <div class="cell no-width">
        <input type="button" value="-" class="cart-minus" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>">
      </div>
      <!-- <div class="amount cell" data-product="<?php print $pid; ?>" data-price="<?php print $origprice; ?>" data-weight="<?php print $origweight; ?>"><?php print $amount; ?></div> -->
      <input class="amount cell" type="number" pattern="[0-9]*" data-shop="<?php print $shop; ?>" data-product="<?php print $pid; ?>" data-price="<?php print $origprice; ?>" data-weight="<?php print $origweight; ?>" value="<?php print $amount; ?>">
      <div class="weight cell element-remove" data-shop="<?php print $shop; ?>" data-product="<?php print $pid; ?>" data-price="<?php print $origprice; ?>" data-weight="<?php print $origweight; ?>"><?php print $weight; ?></div>
      <div class="cell no-width">
        <input type="button" value="+" class="cart-plus" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>">
      </div>
    </div>
    <?php if ($selector) { ?>
    <div class="amount-change">
      <div class="amount piece">
        <div class="markup cell piece-unit" data-product="<?php print $pid; ?>">db</div>
        <div class="markup cell weight-unit element-remove" data-product="<?php print $pid; ?>">kg</div>
      </div>
      <div class="markup cell piece-selector"><span class="label">change</span>
        <div class="amount-selector-popup element-invisible">
          <div class="amount-in-weight" data-product="<?php print $pid; ?>"><?php print t('Weight (kg)'); ?></div>
          <div class="amount-in-piece" data-product="<?php print $pid; ?>"><?php print t('Piece (pc)'); ?></div>
        </div>
      </div>
    </div>
    <?php } ?>


    <div class="price cell" data-product="<?php print $pid; ?>" data-shop="<?php print $shop; ?>"><?php print $price; ?></div>
    <div class="markup cell">Ft</div>
    <div class="percent"><?php if ($percent > 0) { print '-' . $percent; } ?></div>

    <div class="cell no-width">
      <input type="button" value="x" class="cart-delete" data-shop="<?php print $shop; ?>">
    </div>
    <div style="clear:both"></div>
  </div>
</div>
