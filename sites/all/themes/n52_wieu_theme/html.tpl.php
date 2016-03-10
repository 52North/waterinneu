<?php
/*
 * Copyright (C) 2016
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 *
 * If the program is linked with libraries which are licensed under one of
 * the following licenses, the combination of the program with the linked
 * library is not considered a "derivative work" of the program:
 *
 *     - Apache License, version 2.0
 *     - Apache Software License, version 1.0
 *     - GNU Lesser General Public License, version 3
 *     - Mozilla Public License, versions 1.0, 1.1 and 2.0
 *     - Common Development and Distribution License (CDDL), version 1.0
 *
 * Therefore the distribution of the program linked with libraries licensed
 * under the aforementioned licenses, is permitted by the copyright holders
 * if the distribution is compliant with both the GNU General Public
 * License version 2 and the aforementioned licenses.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 */
 /*
  * Changes to bootstrap business:
  * - removed support for IE version < 10
  * - add javascript sections at the end
  */
 ?>
<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces;?>>
<head profile="<?php print $grddl_profile; ?>">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
	<div id="skip-link">
		<a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
	</div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <?php
  /*
   * This function enables popover and tooltip bootstrap features
   */?>
  <script type="text/javascript">
  (function($) {
  	$(document).ready(function() {
  	  $('[data-toggle="tooltip"]').tooltip();
  	  $('[data-toggle="popover"]').popover();
  	  $('body').on('click', function (e) {
  	    $('[data-toggle="popover"]').each(function () {
  		  //the 'is' for buttons that trigger popups
  		  //the 'has' for icons within a button that triggers a popup
  		  if (!$(this).is(e.target) &&
  		      $(this).has(e.target).length === 0 &&
  		      $('.popover').has(e.target).length === 0) {
  		    $(this).popover('hide');
  		  }
  		});
      });
  	});
  })(jQuery);
  </script>
  <?php
  /*
   *This function enables linking and scrolling to accordion entries
   */?>
  <script type="text/javascript">
  (function($) {
    $(document).ready(function () {
	  if (location.hash){
	    $(location.hash).collapse('show');
	    $(location.hash).parents('.accordion-body').collapse('show');
	    var aTag = $(location.hash);
	    $('html,body').animate({scrollTop: aTag.offset().top-125},'slow');
	  }
	});
  })(jQuery);
  </script>
  <?php
  /*
   * This function allows toggle of alert subscription mockup elements
   */?>
  <script type="text/javascript">
  (function($) {
    $(document).ready(function () {
  	  if ($(location).attr('pathname').match(/matchmaking$/)) {
  	    $('#content-type').change(function() {
  		    switch($(this).val()) {
  	      case 'Organisation' :
  	        $('#organisation-classes').css('display','initial');
  	        $('#service-categories').css('display','none');
  	        $('#product-categories').css('display','none');
  	        break;
  	      case 'Event' :
  	      	$('#organisation-classes').css('display','none');
  	        $('#service-categories').css('display','none');
  	        $('#product-categories').css('display','none');
  	       	break;
  	      case 'Product' :
  	       	$('#organisation-classes').css('display','none');
  	        $('#service-categories').css('display','none');
  	        $('#product-categories').css('display','initial');
  	      	break;
  	      case 'Service Request' :
  	       	$('#organisation-classes').css('display','none');
  	        $('#service-categories').css('display','initial');
  	        $('#product-categories').css('display','none');
  	        $('#service-categories-label').text('Service Request Categories');
  	       	break;
  	      case 'Service Offering' :
  	        $('#organisation-classes').css('display','none');
  	        $('#service-categories').css('display','initial');
  	        $('#product-categories').css('display','none');
  	        $('#service-categories-label').text('Service Offering Categories');
  	        break;
  	      }
  		});
	  }
    });
  })(jQuery);
  </script>
  <?php if ($logged_in) :?>
  <?php
  /*
   * Adjustment to the forum landing page
   * - Change the layout of the Create new thread button
   *
   */?>
  <script type="text/javascript">
  (function($) {
    $(document).ready(function () {
      if ($(location).attr('pathname').match(/forum$/)) {
        $('div.harmony-listing-header > a').addClass('btn btn-primary');
      }
    });
  })(jQuery);
  </script>
  <?php
  else :
  /*
   * Adjustment to the forum landing page
   * - Add info if not logged in
   *
   */?>
  <script type="text/javascript">
  (function($) {
    $(document).ready(function () {
      if ($(location).attr('pathname').match(/forum$/) &&
          !$('#block-menu-menu-top-level-links-registered-').length) {
        $('<div class="view-footer alert alert-warning" style="margin-top: 10px;"><?php print t('For adding adding new content, you need to <a href="/user?destination=forum">login</a>.')?></div>').insertAfter('div.view-content');
      }
    });
  })(jQuery);
  </script>
  <?php endif; ?>
</body>
</html>
