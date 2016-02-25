<section id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($content['comments'] && $node->type != 'forum'): ?>
    <?php print render($title_prefix); ?>
    <h2 class="title"><?php print t('Comments'); ?>&nbsp;
    	<span class="glyphicon glyphicon-info-sign glyphicon-light"
    		data-content="<div class='popover-light-in-heading'><?php t('What are the experiences users have had with the application of the product?'); ?></div>"
    		rel="popover" data-toggle="popover" data-placement="right" data-original-title="Description" data-trigger="click" data-html="true"></span></h2>
    <?php print render($title_suffix); ?>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php if ($content['comment_form']): ?>
    <h2 class="title comment-form"><?php print t('Add new comment'); ?></h2>
    <?php print render($content['comment_form']); ?>
  <?php endif; ?>
</section>