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
  <?php print $styles;?>
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
   * This function enables linking and scrolling to accordion entries
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
   */
  if (n52_endsWith(request_path(),'matchmaking')) { ?>
  <script type="text/javascript">
  (function($) {
    $(document).ready(function () {
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
  	        $('#service-categories-label').text('<?php print t('Service Request Categories'); ?>');
  	       	break;
  	      case 'Service Offering' :
  	        $('#organisation-classes').css('display','none');
  	        $('#service-categories').css('display','initial');
  	        $('#product-categories').css('display','none');
  	        $('#service-categories-label').text('<?php print t('Service Offering Categories'); ?>');
  	        break;
  	      }
  		});
    });
  })(jQuery);
  </script>
  <?php 
  /*
   * This function clones the search form on the match making page and puts it 
   * to the regarding accordion section.
   * In addition the original search form is disabled.
   */
  ?>
  <script type="text/javascript">
  (function($) {
    $(document).ready(function () {
  	   $('#custom-search-blocks-form-1').clone(true,true).appendTo('#search-form-duplicate');
  	   var elem = $('div.content > form > div > div > input#edit-custom-search-blocks-form-1--2');
	   elem.prop('disabled','true');
	   elem.attr('placeholder','<?php print t('disabled here'); ?>');
	   elem.attr('title','<?php print t('please use the search form down below!'); ?>');
	   var elem2 = $('div#search-form-duplicate > form > div > div > #edit-custom-search-blocks-form-1--2'); 
  	   elem2.css('width','100%');
  	   elem2.attr('size','60');
  	   $('div#search-form-duplicate > form').css('float','initial');
    });
  })(jQuery);
  </script>
  <?php } ?>
  <?php
  /*
   * Adjustment to the forum landing page
   * - Change the layout of the Create new thread button
   * - Add search button which links to advanced search
   */?>
  <?php if (n52_endsWith(request_path(),'forum*',TRUE)) { ?>
  <?php $search_button = '<a href="search/advanced#posts" style="margin-left: 5px;" class="btn btn-primary"><span class="glyphicon glyphicon-search">&nbsp;</span>' . t('Search forum') . '</a>'; ?>
  <script type="text/javascript">
  (function($) {
	$(document).ready(function () {
    	var elem = $('div.harmony-listing-header > a')
    	elem.addClass('btn btn-primary');
    	elem.prepend('<span class="glyphicon glyphicon-plus">&nbsp;</span>');
    });
  })(jQuery);
  </script>
  <?php if ($logged_in) { ?>
  	<script type="text/javascript">
  	(function($) {
	    $(document).ready(function () {
      		var searchButton = '<?php print $search_button; ?>';
      		$(searchButton).insertAfter('div.harmony-listing-header > a'); 
    	});
  	})(jQuery);
  	</script>
  	<?php } else { ?> 
  		<script type="text/javascript">
  		(function($) {
  			$(document).ready(function () {
  				var searchButton = '<div class="view-header">' +
  					'<div class="harmony-listing-header clearfix">' +
  					'<?php print $search_button; ?>' +
  					'</div>' +
  					'</div>';
  				$(searchButton).insertBefore('div.view-content');
  			});
  		})(jQuery);
  		</script>
  	<?php
  	/*
   	* Adjustment to the forum landing page
   	* - Add info if not logged in
   	*
   	*/?>
  	<script type="text/javascript">
  	(function($) {
	    $(document).ready(function () {
        if (!$('#block-menu-menu-top-level-links-registered-').length) {
          var link = $(location).attr('pathname').replace('forum','user') + '?destination=forum';
          var messageDiv = '<div class="view-footer alert alert-info" style="margin-top: 10px;"><?php print t('For adding adding new content, you need to ')?><a href="' + link + '"><?php print t('login')?></a>.</div>';
          if ($('div.view-content').length) {
            $(messageDiv).insertAfter('div.view-content');
          } else
            $(messageDiv).insertAfter('div.view-empty');
          }
    	});
  	})(jQuery);
  	</script>
  	<?php } ?>
  <?php } ?>
  <?php
  /*
   * This function enables linking and scrolling to bootstrap tabs
   */?>
  <script type="text/javascript">
  (function($) {
    $(document).ready(function () {
	  if (location.hash){
		  $('.nav-tabs a[href="' + location.hash + '"]').tab('show');
	  }
	});
  })(jQuery);
  </script>
  <?php
  /*
   * This function fixes the add comment link, hence is clicks on the comment
   * accordion heading when the link is clicked and scrolles down to the 
   * add comment form.
   */?>
  <script type="text/javascript">
  (function($) {
    $(document).ready(function () {
    	if ($('li.comment-add.last.active').length) {
        	$('li.comment-add.last.active > a.active').on('click', function() {
            	$('#comments-accordion > section > div > div').trigger('click');
            	var aTag = $('#comment-form');
            	$('html,body').animate({scrollTop: aTag.offset().top-125},'slow');
        	});
    	}
	});
  })(jQuery);
  </script>
  <?php 
  /* 
   * This function expands the comment accordion if the location hash 
   * contains #comment- to enable direct linking to comments
   */
  ?>
  <script type="text/javascript">
  (function($) {
	  $(document).ready(function () {
		  if (location.hash && location.hash.startsWith('#comment-')) {
			  $('#comments-panel').collapse('show');
			  var aTag = $(location.hash);
			  $('html,body').animate({scrollTop: aTag.offset().top-125},'slow');
		  }
	  });
  })(jQuery); 
  </script>
  <?php 
  /* 
   * This function hides the old venue field in events when adding new events
   */
  ?>
  <?php if (n52_endsWith(request_path(),'node/add/event')) { ?>
  <script type="text/javascript">
  (function($) {
	  $(document).ready(function () {
		  $('#edit-field-venue').css('display','none');
	  });
  })(jQuery); 
  </script>
  <?php } ?>
  <?php 
  /* 
   * This function changes the header background image randomly if theme setting
   * is active.
   */
  ?>
  <?php if (theme_get_setting('n52_header_background_images','n52_wieu_theme')) { ?>
  <script type="text/javascript">
  (function($) {
	  $(document).ready(function () {
		  var header = $('#header');
		  header.css('background', 'none');
		  header.css('background-image','url(<?php print n52_random_header_background_image_path(); ?>)');
		  header.css('background-repeat', 'no-repeat');
	      header.css('background-position', 'center center');
	      var slogan = $('#site-slogan');
	      slogan.css('font-weight', 'bold');
	      slogan.css('font-size', '16px');
	      slogan.css('color', '#29648C');
	  });
  })(jQuery); 
  </script>
  <?php } ?>
  <?php 
  /* 
   * This function fixes the position of the floating/sticky nav div and pre-header
   */
  ?>
  <?php if (user_is_logged_in()) {?>
    <script type="text/javascript">
    (function($) {
	  $(document).ready(function () {
		  setTimeout(function () {
			  if ($('#admin-menu').length && $('body').hasClass('logged-in')) {
				  $('#pre-header').css('padding-top', '50px');
			  }
		  },200);
		  setInterval( function() {
			  if ($('#admin-menu').length) {
				  if ($('#main-navigation-inside').hasClass('stickynav-active')) {
					  $('#main-navigation-inside').css('top', '50px');
				  } else {
					  $('#main-navigation-inside').css('top', '0px');
				  }
			  }
		  },500);
	  });
  })(jQuery); 
  </script>
  <?php }?>
  <?php
  /*
   * This function fixes bug with some advanced search blocks which display all
   * content if search text field is empty.
   */
  ?>
  <?php if (n52_endsWith(request_path(),'search/advanced')) { ?>
  	<script type="text/javascript">
    (function($) {
	  $(document).ready(function () {
		  $('#edit-submit-n52-views-advanced-search-forum').trigger('click');
		  $('#edit-submit-advanced-event-search').trigger('click');
		  $('#edit-submit-view-advanced-search-organsations').trigger('click');
	  });
  	})(jQuery); 
  	</script>
  <?php } ?>
  <?php 
  /*
   * Add destination to login link.
   */
  ?>
  <?php if (!user_is_logged_in() && !$is_front) {?>
  	<script type="text/javascript">
    (function($) {
	  $(document).ready(function () {
		  var elem = $('#block-menu-menu-top-links > div > ul > li.first > a');
		  var href = elem.attr('href') + '?destination=<?php print n52_get_destination_alias() ?>';
		  elem.attr('href', href);
	  });
  	})(jQuery);
  	</script>
  <?php } ?>
  <?php 
  /*
   * Add destination to logout link.
   */
  ?>
  <?php if (user_is_logged_in() && !$is_front) {?>
  	<script type="text/javascript">
    (function($) {
	  $(document).ready(function () {
		  var elem = $('#block-system-user-menu > div > ul > li.last > a').last();
		  var href = elem.attr('href') + '?destination=<?php print n52_get_destination_alias() ?>';
		  elem.attr('href', href);
	  });
  	})(jQuery);
  	</script>
  <?php } ?>
  <?php 
  /*
   * Add label informing about language fallback and to keep first version in
   * neutral language setting
   */
  ?>
  <?php if (user_is_logged_in() && n52_endsWith(request_path(), 'node/add*', TRUE)) {?>
  	<script type="text/javascript">
	(function($) {
		$(document).ready(function () {
			var elem = $('.form-item-language').last();
			var messageDiv = '<div class="alert alert-info"><?php print t(
				'For the initial version of any content, please select the ' . 
				'language "<i>language neutral</i>". This ensures that for each ' .
				'language something is rendered. Translations for different ' . 
				'languages should be added after the first version is ' .
				'published as "<i>language neutral</i>".') ?></div>';
			$(messageDiv).insertAfter(elem);
		});
	})(jQuery);
  	</script>
  <?php } ?>
</body>
</html>
