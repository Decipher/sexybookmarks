<?php
/**
 * @file
 * Theme for SexyBookmarks.
 */
?>
<?php if (!$empty) : ?>
<div class="sexybookmarks clear-block">
  <div class="sexybookmarks-inner">
  <?php foreach ($bookmarks as $id => $bookmark) : ?>
    <a href="<?php print $bookmark['url'] ?>" title="<?php print $bookmark['description'] ?>" class="sexy-<?php print $id; ?>"<?php if ($settings['general']['nofollow']) : ?> rel="nofollow"<?php endif; ?><?php if ($settings['general']['window']) : ?> target="_blank"<?php endif; ?>></a>
  <?php endforeach; ?>
  </div>
</div>
<?php endif;
