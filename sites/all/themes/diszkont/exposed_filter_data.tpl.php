

<?php

/**
 * @file
 * Basic template file
 */

?>
<div class='exposed_filter_data'>
  <div class='title'></div>
  <div class='content'>
    <?php
      foreach ($exposed_filters as $filter => $value) {
      if ($value) {
          print "<div class='filter'><div class='name'>" . $filter . ":</div>";

/*changing start*/
          $taxname=taxonomy_term_load($value);
          print "<div class='value'>" . $taxname->name . "</div></div>";
/*changing end*/

       }
     }
   ?>
  </div>
</div>