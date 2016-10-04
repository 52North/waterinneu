function resizeFrame(obj) {
  var frame = jQuery(obj);
  frame.height(frame.contents().find("body").height());
  frame.contents().find('body').bind('DOMAttrModified DOMSubtreeModified DOMNodeInserted DOMNodeInsertedIntoDocument', function () {
    frame.height(frame.contents().find("body").height());
  });
  jQuery(obj.contentWindow).resize(function() {
    frame.height(frame.contents().find("body").height());
  });

}
