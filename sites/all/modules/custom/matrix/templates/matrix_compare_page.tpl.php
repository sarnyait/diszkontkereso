<div id="cart-popup" class="remodal" data-remodal-id="modal">
  <div class="modal-message"><?php print $message; ?></div>
  <a data-remodal-action="close" class="remodal-close"></a>
  <a data-remodal-action="close" class="remodal-none" href="#"><?php print $keep; ?></a>
  <a data-remodal-action="cancel" class="remodal-cancel" href="#"><?php print $change; ?></a>
  <a data-remodal-action="confirm" class="remodal-confirm" href="#"><?php print $keepboth; ?></a>
</div>
<div id="cart-popup-2" class="remodal" data-remodal-id="modalSameShop">
  <div class="modal-message"><?php print $message2; ?></div>
  <a data-remodal-action="close" class="remodal-close"></a>
  <a data-remodal-action="cancel" class="remodal-none" href="#"><?php print $cancel; ?></a>
  <a data-remodal-action="confirm" class="remodal-confirm" href="#"><?php print $add; ?></a>
</div>

<div class="compare-page">
<?php
  print $table;
?>
</div>


