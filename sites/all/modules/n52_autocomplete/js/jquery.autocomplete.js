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
	
	function getCaretPosition() {
		var caretPosition = 0;
		// IE Support
        if (document.selection) {
        	domObject.focus();
            var Sel = document.selection.createRange();
            Sel.moveStart('character', -domObject.value.length);
            caretPosition = Sel.text.length;
        }
        // Firefox support
        else if (domObject.selectionStart || domObject.selectionStart == '0') {
        	caretPosition = domObject.selectionStart;
        }
        return caretPosition;
	}
	
	function getWord(caretPosition) {
		var preText = domObject.value.substring(0, caretPosition);
        var word = preText;
        if (preText.indexOf(" ") > 0) {
        	var words = preText.split(" ");
        	// set word to last word
        	word = words[words.length -1 ]; 
        }
        return word;
	}
	
	function processResults(results) {
		// Create list
		if ($.isArray(results) && !results.length == 0) {
			values = new Array();
			$.each(results, function(index, item) {
				if (!$.isEmptyObject(item) && !$.isEmptyObject(item.value) && item.value.length > 0) {
					values[index] = item.value;
				}
			});
			values.length;
		}
		// display list div with interaction elements
    }
	
	Drupal.behaviors.n52_autocomplete = {
		attach: function(context) {
			if (Drupal.settings.n52_autocomplete.selector) {
				$(Drupal.settings.n52_autocomplete.selector).ready(function() {
					$(Drupal.settings.n52_autocomplete.selector).keydown(function( event ) {
						if (event.ctrlKey && event.keyCode == 32) {
							domObject = this;
							var word = getWord(getCaretPosition()); 
				            if (word != null) {
				            	$.getJSON("http://localhost/en/search_autocomplete/autocomplete/4/", "term=" + word, processResults);
				            }
						}
					});
				});
			}
		}
	}
	
})(jQuery);