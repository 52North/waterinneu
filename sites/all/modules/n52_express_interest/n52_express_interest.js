/*
 * Copyright (C) 2015
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
(function ($) {
  
  /**
   * Find Drupal Node ID based on <body> element classes.
   *
   * @return Node ID or false
   */
  function getCurrentNodeId() {
    var $body = $('body.page-node');
    if ( ! $body.length )
      return false;
    var bodyClasses = $body.attr('class').split(/\s+/);
    for ( i in bodyClasses ) {
      var c = bodyClasses[i];
      if ( c.length > 10 && c.substring(0, 10) === "page-node-" )
        return parseInt(c.substring(10), 10);
    }
    return false;
  }
  
  function threeDotsAnimation() {
      if(dots < 3) {
          $('#dots').append('.');
          dots++;
      }
      else {
          $('#dots').html('');
          dots = 0;
      }
  }

  Drupal.behaviors.expressInterest = {
    attach: function (context, settings) {
      
      $('#popover-span').on('shown.bs.popover', function() {
        
        $('button').on('click', function() {
          
          $('#mail-response').html('<div class=\'alert alert-info\'>Sending mail<span id=\'dots\'></span></div>');
          
          var refreshId = setInterval ( threeDotsAnimation, 600 );
          
          setTimeout( function () {}, 5000 );
      
          $.ajax({
            
            // This is the AjAX URL set by the custom Module
            url: Drupal.settings.n52_express_interest.ajaxUrl, 
            method: "GET",
            // Set the number of Li items requested
            data: {
              id : getCurrentNodeId(),
              copy : $('input#send-copy').is(':checked')
            },
            // Type of the content we're expecting in the response
            dataType: "html", 
            
            success: function(data) {
              // Place AJAX content inside the ajax wrapper div
              $('#mail-response').html(data); 
            }
            
          });
          
          $('#send-button > button').addClass('disabled');
          
        });
      
      });
      
      $(".pop").popover({ trigger: "manual" , html: true, animation:false})
      .on("mouseenter", function () {
          var _this = this;
          $(this).popover("show");
          $(".popover").on("mouseleave", function () {
              $(_this).popover('hide');
          });
      }).on("mouseleave", function () {
          var _this = this;
          setTimeout(function () {
              if (!$(".popover:hover").length) {
                  $(_this).popover("hide");
              }
          }, 300);
  });

  }

  };

}(jQuery));